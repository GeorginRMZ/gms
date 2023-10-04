#ifndef _GMS_H_
#define _GMS_H_

typedef unsigned char BYTE;
typedef unsigned short int WORD;
typedef unsigned long long int uint64_t;

typedef struct {
    BYTE* data;
    long int data_size;
    uint64_t* hash;
} GMS;

WORD gms_strlen(const char* s) {
    const char* cur = s;
    for (; *cur; ++cur);
    return cur - s;
}

void gms(GMS* ctx) {
    ctx->hash = (uint64_t*)calloc(1, sizeof(uint64_t));
    switch (ctx->data_size) {
    case 1:
        *ctx->hash = *ctx->data;
        break;
    case 2:
        for (long int i = 0; i < ctx->data_size; i++) {
            *ctx->hash += ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *ctx->data)) *
                ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *(ctx->data + 1)));
        }
        break;
    case 3:
        for (long int i = 0; i < ctx->data_size; i++) {
            *ctx->hash += ((uint64_t)(*(ctx->data) + i) + (uint64_t)(*(ctx->data + i) ^ *ctx->data)) *
                ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *(ctx->data + 1))) *
                ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *(ctx->data + 2)));
        }
        break;
    case 4:
        for (long int i = 0; i < ctx->data_size; i++) {
            *ctx->hash += ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *ctx->data)) *
                ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *(ctx->data + 1))) *
                ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *(ctx->data + 2))) *
                ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *(ctx->data + 3)));
        }
        break;
    case 5:
        for (long int i = 0; i < ctx->data_size; i++) {
            *ctx->hash += ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *ctx->data)) *
                ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *(ctx->data + 1))) *
                ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *(ctx->data + 2))) *
                ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *(ctx->data + 3))) *
                ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *(ctx->data + 4)));
        }
        break;
    default:
        for (long int i = 0; i < ctx->data_size; i++) {
            if (i >= ctx->data_size - 5) {
                *ctx->hash += ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *ctx->data)) *
                    ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *(ctx->data + 1))) *
                    ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *(ctx->data + 2))) *
                    ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *(ctx->data + 3))) *
                    ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *(ctx->data + 4)));
            }
            else {
                *ctx->hash += ((uint64_t)(*(ctx->data + i)) + (*(ctx->data + i) ^ *(ctx->data + i + 1))) *
                    ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *(ctx->data + i + 2))) *
                    ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *(ctx->data + i + 3))) *
                    ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *(ctx->data + i + 4))) *
                    ((uint64_t)(*(ctx->data + i)) + (uint64_t)(*(ctx->data + i) ^ *(ctx->data + i + 5)));
            }
        }
        break;
    }
}

#endif // _GMS_H_