#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "../include/gms.h"

int main() {
    char message[512];

    printf("Enter text: ");
    scanf("%19[^\n]", message);

    GMS crypt;
    crypt.data = (BYTE*)message;
    crypt.data_size = strlen(message);
    gms(&crypt);

    printf("%llx\n", *(crypt.hash));
    free(message);
    system("pause");  
}