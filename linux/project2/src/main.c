#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include "../inc/parent.h"
#include "../inc/child.h"

void my_sig(int signo)
{
	//printf("my_sig(%d)\n", signo);
	while(waitpid(-1,0,WNOHANG) > 0)
		;
}

int main(int argc, char *argv[])
{
	pid_t pid = 0;

	signal(SIGCHLD, my_sig);

	if(argc < 2) 
	{
		printf("input filename \n");
		return 0;
	}

	pid = fork();
	if(pid == 0) // child process
	{		
		start_child_job(argv[1]);
		exit(3);
	}
	else 
	{		
		if(start_parent_job(argv[1]) < 0)
		{
			kill(pid,SIGKILL); 
		}
	}

	return 0;
}

	
