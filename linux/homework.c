#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>

#define LIST 1
#define INODE 2
#define RECUR 4
#define ALL 8

void file_list(DIR *dp, int flag, int depth);
void get_dir_list(const char *d_name, int flag, int depth);
void get_file_stat(const char* f_name, int flag);

int compfunc(const void *const a, const void *const b)
{
	char *lhs = (*(struct dirent **) a)->d_name;
	char *rhs = (*(struct dirent **) b)->d_name;

	lhs = ((lhs[1] != '\0') && (lhs[0] == '.' && lhs[1] != '.')) ? lhs + 1 : lhs;
	rhs = ((rhs[1] != '\0') && (rhs[0] == '.' && rhs[1] != '.')) ? rhs + 1 : rhs;

    return strcmp(lhs, rhs);
}

void file_list(DIR *dp, int flag, int depth)
{
	struct dirent *p;
	struct dirent **d_list = NULL;
	struct stat buf;

	int count = 0;
	int i = 0;

	while(p = readdir(dp))
	{
		if(p->d_name[0] == '.' && !(flag & ALL))
			continue;
		count++;
	}
	rewinddir(dp);

	d_list = malloc(count * sizeof(*d_list));

	i = 0;
	while((p = readdir(dp)) != NULL)
	{
		if(p->d_name[0] == '.' && !(flag & ALL))
			continue;
		d_list[i++] = p;
	}
	rewinddir(dp);

	qsort(d_list, count, sizeof(*d_list), compfunc);


	i = 0;
	while((p = readdir(dp)) != NULL)
	{
		lstat(d_list[i]->d_name, &buf);

		if(p->d_name[0] == '.' && !(flag & ALL))
			continue;
		d_list[i++] = p;
	}
	rewinddir(dp);



	if(flag & RECUR && depth == 0) printf(".:\n");
	for(i = 0;i < count; ++i)
	{
		lstat(d_list[i]->d_name, &buf);
		if(flag & INODE)
		{
			printf("%lu ", buf.st_ino);
		}

		if(flag & LIST)
			get_file_stat(d_list[i]->d_name, flag);
		else
			printf("%s  ", d_list[i]->d_name);
	}
	printf("\n");

	free(d_list);
	d_list = NULL;
	return;
}

void get_dir_list(const char *d_name, int flag, int depth)
{
	DIR *dp;
	struct dirent *p;
	struct stat buf;

	chdir(d_name);
	dp = opendir(".");
	if(dp == NULL)
	{
		printf("cannot open : %s\n", d_name);
		closedir(dp);
		return;
	}

	file_list(dp, flag, depth);

	if(flag & RECUR) 
	{
		while(p = readdir(dp))
		{
			lstat(p->d_name, &buf);
			if(S_ISDIR(buf.st_mode))
			{
				if(strcmp(p->d_name, ".") && strcmp(p->d_name, ".."))
				{
					printf("\n./%s:\n", p->d_name);
					get_dir_list(p->d_name, flag, ++depth);
				}
			}
		}	
	}

	closedir(dp);
	chdir("..");
}


void print_date(struct stat *buf)
{
	struct tm *tmp;

	tmp = localtime(&buf->st_mtime);
	printf("%2d월 %2d %02d:%02d ", tmp->tm_mon+1, tmp->tm_mday, tmp->tm_hour, tmp->tm_min);
}

void get_file_stat(const char* f_name, int flag)
{
	int i;
	struct stat buf;
	struct passwd *pwd;
	struct group *grp;

	char perm[] = "----------";
	char rwx[] = "rwx";
	char sst[] = "sst";
	char *ptr;

	lstat(f_name, &buf);

	if		(S_ISDIR(buf.st_mode))	perm[0] = 'd';
	else if	(S_ISCHR(buf.st_mode))	perm[0] = 'c';
	else if	(S_ISBLK(buf.st_mode))	perm[0] = 'b';
	else if	(S_ISFIFO(buf.st_mode))	perm[0] = 'p';
	else if	(S_ISLNK(buf.st_mode))	perm[0] = 'l';
	else if	(S_ISSOCK(buf.st_mode))	perm[0] = 's';

	for(i = 0; i < 9; i++)
	{
		if((buf.st_mode >> (8-i)) & 0x1)
		{
			perm[1+i] = rwx[i%3];
		}
	}

	for(i = 0; i < 3; i++)
	{
		if((buf.st_mode >> (11-i)) & 0x1)
		{
			if(perm[(i+1)*3] == '-')
				perm[(i+1)*3] = sst[i] - ('a'-'A');
			else
				perm[(i+1)*3] = sst[i];
		}
	}

	printf("%s ", perm);
	printf("%lu ", buf.st_nlink);
	pwd = getpwuid(buf.st_uid);
	printf("%s ", pwd->pw_name);
	grp = getgrgid(buf.st_gid);
	printf("%s ", grp->gr_name);
	if(perm[0] == 'c' || perm[0] == 'b')
		printf("%lu, %lu ", (buf.st_rdev>>8)&0xff, buf.st_rdev&0xff);
	else
		printf("%lu ", buf.st_size);

	print_date(&buf);

	if(perm[0] =='l')
	{
		char buff[256];
		int ret;
		ret = readlink(f_name, buff, sizeof buff);
		buff[ret] = 0;
		printf("%s -> %s\n", f_name, buff);		
	}
	else
		printf("%s\n", f_name);
}




int main(int argc, char** argv)
{
	int ch;
	int flag = 0;
	while( (ch = getopt(argc, argv, "liRa")) != -1)
	{
		switch(ch)
		{
			case 'l' : flag |= LIST; break;
			case 'i' : flag |= INODE; break;
			case 'R' : flag |= RECUR; break;
			case 'a' : flag |= ALL; break;
		}
	}

	if(argc > 1) 
		get_dir_list(argv[1], flag, 0);
	else 
		get_dir_list(".", flag, 0);
	return 0;
}
