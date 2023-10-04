#include <stdio.h>
#include "../include/gms.h"
#include "example.h"

int main() {
    printf("Write file path: ");
    scanf("%19[^\n]", filename);

    fileptr = fopen(filename, "rb");
    fseek(fileptr, 0, SEEK_END);
    filelen = ftell(fileptr);
    rewind(fileptr);
    buffer = (BYTE*)malloc(filelen * sizeof(BYTE));
    if (NULL == buffer) {
    	printf("Memory allocate error.");
    	ReleaseMemory();
    	system("pause");
    }
    fread(buffer, filelen, 1, fileptr);
    fclose(fileptr);

    *filecrypt = (GMS*)malloc(sizeof(GMS));;
    filecrypt->data = buffer;
    filecrypt->data_size = *filelen;
    gms(filecrypt);

    printf("%llx\n", filecrypt->hash);
    ReleaseMemory();
    system("pause");
}

void ReleaseMemory() {
    free(filename);
    free(fileptr);
    free(buffer);
    free(filecrypt);
    free(filelen);
}