#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

#define RECUR 4
void file_list(DIR *dp, int flag, int depth);
void dir_traverse(const char *d_name, int flag, int depth);

void dir_traverse(const char *d_name, int flag, int depth)
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
					dir_traverse(p->d_name, flag, ++depth);
				}
			}
		}	
	}

	closedir(dp);
	chdir("..");
}
