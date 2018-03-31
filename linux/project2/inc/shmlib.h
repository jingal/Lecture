#ifndef SHMLIB_H_
#define SHMLIB_H_

#include <sys/ipc.h>
#include <sys/shm.h>
typedef struct 
{
	int size;
	char buff[256];
} SHM_t;


int CreateSHM(long key);
int OpenSHM(long key);
SHM_t *GetPtrSHM(int shmid);
int FreePtrSHM(SHM_t *shmptr);
int RemoveSHM(int shmid);

#endif //SHMLIB_H_
