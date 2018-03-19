#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define LIST 1
#define INODE 2
#define RECUR 4
#define ALL 8

void dir_traverse(const char *d_name, int flag, int depth);

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
		dir_traverse(argv[1], flag, 0);
	else 
		dir_traverse(".", flag, 0);
	return 0;
}
