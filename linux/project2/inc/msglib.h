#ifndef MSGLIG_H_
#define MSGLIB_H_

#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct shmmsg
{
	long mtype;		// 1: parent -> child, 2:child -> parent
	int msg; 		// 0 : preceed queue, 1: quit from queue
	int size;		// buffer size(bytes)
} shmmsg_t;


int  CreateMQ( long key_t );
int  OpenMQ( long key_t );
long RecvMQ( int qid, long mtype, shmmsg_t *msgbuf );
long SendMQ( int qid, long mtype, shmmsg_t *msgbuf );
int GetFreeSizeMQ(int qid, long *freesize);
int  RemoveMQ( int qid );

#endif //MSGLIB_H_
