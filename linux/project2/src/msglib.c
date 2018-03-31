#include "../inc/msglib.h"

int CreateMQ(long key)
{
	return( msgget(key, IPC_CREAT | 0777) );
}

int OpenMQ(long key)
{
	return( msgget(key, 0) );
}

long SendMQ(int qid, long mtype, shmmsg_t* msg)
{
	int st, pid;

	msg->mtype = mtype;
	pid = getpid();

	/* msgsnd() : Return 0 if OK, -1 on error */    
	st = msgsnd(qid, msg, (sizeof(shmmsg_t)-sizeof(long)), IPC_NOWAIT);

	if(st < 0)
		return -1L;

	return pid;
}

long RecvMQ(int qid, long mtype, shmmsg_t *msg)
{
	int st;

	/* msgrcv() : Return recv bytes if OK, -1 on error */
	st = msgrcv(qid, msg,sizeof(shmmsg_t)- sizeof(long), 
			mtype, IPC_NOWAIT);
	if(st < 0)
		return -1L;
	return msg->mtype;
}

int GetFreeSizeMQ(int qid, long *freesize)
{
	int rtn;
	struct msqid_ds stat_q;

	if(qid<0)
		return -1;

	/* msgctl() : Return  0 if OK, -1 on error */
	rtn = msgctl(qid,IPC_STAT,&stat_q);
	if(rtn < 0)
		return -1;

	*freesize = stat_q.msg_qbytes - stat_q.msg_cbytes;

	return rtn;
}

int RemoveMQ(int qid)
{
    return(msgctl(qid, IPC_RMID, 0));
}

