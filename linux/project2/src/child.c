#include <stdio.h>
#include <unistd.h>
#include "../inc/shmlib.h"
#include "../inc/msglib.h"
#include "../inc/parent.h"
#include <string.h>
#include <errno.h>
#include "../inc/common.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


extern int errno;

int open_shared_memory(int *shmid, SHM_t **shm)
{
	int ret;

	*shmid = OpenSHM(SHM_KEY);
	if(*shmid < 0) return -1;

	*shm = GetPtrSHM(*shmid);

	printf("Child: shared memory create: shmid=%d, key=%d\n", *shmid, SHM_KEY);
	return 1;
}

int open_msg_queue(int *qid)
{
	*qid = OpenMQ(MSG_KEY);
	if(*qid < 0) return -1;

	printf("Child: msg queue id=%d, key=%d\n", *qid, MSG_KEY );
	return 1;
}



int file_exist (char *filename)
{
	struct stat   buffer;   
	return (lstat (filename, &buffer) == 0);
}


void gen_copy_filename(char* fname, char* nfname)
{
	char *p = NULL;
	int num = 1;
	int len = 0;
	char temp_fname[512] = {0, };

	p = strtok(fname, ".");

	strcpy(temp_fname, p);
	strcat(temp_fname, "_copy");

	len = strlen(temp_fname);
	
	p = strtok(0, ".");
	if(p != NULL)
	{
		strcat(temp_fname, ".");
		strcat(temp_fname, p);
	}

	while(file_exist(temp_fname))
	{
		char filenum[4] = {0, };
		temp_fname[len] = '\0';

		sprintf(filenum, "_%d", num++);
		strcat(temp_fname, filenum);
		strcat(temp_fname, ".");
		strcat(temp_fname, p);
	}

	strcpy(nfname, temp_fname);
}

void start_child_job(const char* fname)
{
	int shmid, qid, ret;
	SHM_t *shm;
	FILE *fp;
	char nfname[512] = {0, };

	gen_copy_filename((char*)fname, nfname);

	printf("Child: file name - %s\n", nfname);

	if(	open_shared_memory(&shmid, &shm) < 0)
	{
		printf("Child: can not open shared memory\n");
		return;
	}

	if( open_msg_queue(&qid) < 0)
	{
		printf("Child: can not open message queue\n");
		return;
	}

	fp = fopen(nfname, "wb");
	while(1)
	{
		int st = -1;
		shmmsg_t msg;
		memset(&msg, 0, sizeof(shmmsg_t));
		while(st < 0)
		{
			//	printf("Child: st = %d\n", st);
			st = RecvMQ(qid, MSG_SEND_CHILD_TYPE, &msg);
			usleep(1000);
		}

		if(msg.size > 0)
		{
			ret = fwrite(shm->buff, 1, shm->size, fp);
			printf("Child: %d bytes written\n", ret);

			msg.mtype = MSG_SEND_PARENT_TYPE;
			msg.msg = MSG_PROCEED_QUEUE;
			msg.size = ret;

			SendMQ(qid, msg.mtype, &msg);
		}
		else 
		{
			printf("Child: 0 byte received, send quit msg\n");
			msg.mtype = MSG_SEND_PARENT_TYPE;
			msg.msg = MSG_QUIT_QUEUE;

			SendMQ(qid, msg.mtype, &msg);
			break;
		}
	}

	fclose(fp);

	printf("Child: exiting!\n");
	return;
}
