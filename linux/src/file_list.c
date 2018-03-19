#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

#define LIST 1
#define INODE 2
#define RECUR 4
#define ALL 8

void file_list(DIR *dp, int flag, int depth);
void get_file_stat(const char* f_name, int flag);

int compfunc(const void *const a, const void *const b)
{
	char *lhs = (*(struct dirent **) a)->d_name;
	char *rhs = (*(struct dirent **) b)->d_name;

	//lhs = ((lhs[1] != '\0') && (lhs[0] == '.' && lhs[1] != '.')) ? lhs + 1 : lhs;
	//rhs = ((rhs[1] != '\0') && (rhs[0] == '.' && rhs[1] != '.')) ? rhs + 1 : rhs;

    return strcmp(lhs, rhs);
}

void file_list(DIR *dp, int flag, int depth)
{
	struct dirent *p;
	struct dirent **d_list = NULL;
	struct stat buf;

	int count = 0;
	int i = 0;
	int max_link = 0;
	int max_user = 0;
	int max_group = 0;
	int max_size = 0;

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

		lstat(p->d_name, &buf);
		
		
	}
	rewinddir(dp);

	qsort(d_list, count, sizeof(*d_list), compfunc);

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


