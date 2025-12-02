#ifndef SUSPECTS_HASH_H
#define SUSPECTS_HASH_H

#define HASH_SIZE 31

typedef struct Node {
    char clue[100];
    char suspect[50];
    struct Node *next;
} Node;

void hashInsert(const char *clue, const char *suspect);
const char* hashSearch(const char *clue);
void hashPrint();
void hashFree();

#endif
