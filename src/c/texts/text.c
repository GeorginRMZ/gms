#include <stdio.h>
#include "../include/gms.h"
#include "example.h"

int main() {
    printf("Enter text: ");
    scanf("%19[^\n]", message);

    *crypt = (GMS*)malloc(sizeof(GMS));
    if (NULL == crypt){
    	printf("Memory allocate error.");
    	ReleaseMemory();
    	system("pause");
    }
    crypt->data = (BYTE*)message;
    crypt->data_size = gms_strlen(message);
    gms(crypt);

    printf("%llx\n", crypt->hash);
    system("pause");
}

void ReleaseMemory() {
    free(message);
    free(crypt);
}