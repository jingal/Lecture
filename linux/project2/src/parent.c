#include <stdio.h>
#include <unistd.h>
#include "../inc/shmlib.h"
#include "../inc/msglib.h"
#include "../inc/parent.h"
#include <string.h>
#include <errno.h>
#include "../inc/common.h"


extern int errno;

int create_shared_memory(int *shmid, SHM_t **shm)
{
	int ret;

	*shmid = CreateSHM(SHM_KEY);
	if(*shmid < 0)
	{
		if(errno == EEXIST)
		{
			printf("%d is already exist, open shm\n", SHM_KEY);
			*shmid = OpenSHM(SHM_KEY);
			if(*shmid < 0) return -1;
		}
		else
		{
			printf("Error: %s\n", strerror(errno));
			return -1;
		}
	}

	*shm = GetPtrSHM(*shmid);

	printf("Parent: shared memory create: shmid=%d, key=%d\n", *shmid, SHM_KEY);

	return 1;
}

int create_msg_queue(int *qid)
{
	*qid = CreateMQ(MSG_KEY);
	if(*qid < 0)
	{
		if(errno == EEXIST)
		{
			printf("%d is already exist, open msg queue\n", MSG_KEY);
			*qid = OpenMQ(MSG_KEY);
			if(*qid < 0) return -1;
		}
		else
		{
			printf("Parent: msg q open failed : %s\n", strerror(errno));
			return -1;
		}

	}

	printf("Parent: msg queue id=%d, key=%d\n", *qid, MSG_KEY );
	return 1;
}

int start_parent_job(const char* fname)
{
	int shmid, qid, ret;
	SHM_t *shm;
	FILE *fp;
	char buff[256];
	shmmsg_t msg;
	int st = -1;

	printf("Parent: file name - %s\n", fname);

	if(	create_shared_memory(&shmid, &shm) < 0)
	{
		return -1;
	}

	if( create_msg_queue(&qid) < 0)
	{
		RemoveSHM(shmid);
		return -1;
	}

	memset(buff, 0, sizeof(buff)); 

	if((fp = fopen(fname, "rb")) == NULL)
	{
		RemoveSHM(shmid);
		RemoveMQ(qid);

		printf("Parent: cannot open file\n");
		return -1;
	}

	while(1)
	{
		ret = fread(buff, 1, sizeof buff, fp);
		printf("Parent: %d bytes read\n", ret);
	
		if(ret > 0)
		{
			shm->size = ret;
			memcpy(shm->buff, buff, ret);
		}

		memset(&msg, 0, sizeof(shmmsg_t));
		msg.mtype = MSG_SEND_CHILD_TYPE;
		msg.msg = MSG_PROCEED_QUEUE;
		msg.size = ret;

		if(SendMQ(qid, msg.mtype, &msg) <= 0)
		{
			RemoveSHM(shmid);
			RemoveMQ(qid);
			fclose(fp);

			printf("Parent: send error : %d\n", errno);
			return -1;
		}
		printf("Parent: data size %d is added to queue\n", ret);

		memset(&msg, 0, sizeof(shmmsg_t));
		st = -1;
		while(st < 0)
		{
			st = RecvMQ(qid, MSG_SEND_PARENT_TYPE, &msg);
			usleep(1000);
		}
		

		if(msg.msg == MSG_QUIT_QUEUE)
		{
			printf("Parent: receive quit msg\n");
			break;
		}

		memset(buff, 0, sizeof(buff));
	}

	fclose(fp);
	RemoveSHM(shmid);
	RemoveMQ(qid);

	printf("Parent: exiting!\n");

	return 1;
}
