#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "suspects_hash.h"

static Node* table[HASH_SIZE];

static int hash(const char *str) {
    int h = 0;
    for (int i = 0; str[i]; i++)
        h = (h * 31 + str[i]) % HASH_SIZE;
    return h;
}

void hashInsert(const char *clue, const char *suspect) {
    int index = hash(clue);
    Node *n = malloc(sizeof(Node));
    strcpy(n->clue, clue);
    strcpy(n->suspect, suspect);
    n->next = table[index];
    table[index] = n;
}

const char* hashSearch(const char *clue) {
    int index = hash(clue);
    Node *cur = table[index];
    while (cur) {
        if (strcmp(cur->clue, clue) == 0)
            return cur->suspect;
        cur = cur->next;
    }
    return NULL;
}

void hashPrint() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *cur = table[i];
        while (cur) {
            printf("[%s] -> %s\n", cur->clue, cur->suspect);
            cur = cur->next;
        }
    }
}

void hashFree() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *cur = table[i];
        while (cur) {
            Node *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
}
