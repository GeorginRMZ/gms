#ifndef _EXAMPLE_H_
#define _EXAMPLE_H_


#define BUFFER 512
char filename[BUFFER];
FILE* fileptr;
BYTE* buffer;
GMS* filecrypt;
long int* filelen;

void ReleaseMemory();


#endif