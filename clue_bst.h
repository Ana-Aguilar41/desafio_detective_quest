#ifndef CLUE_BST_H
#define CLUE_BST_H

typedef struct Clue {
    char text[100];
    struct Clue *left, *right;
} Clue;

Clue* insertClue(Clue *root, const char *text);
void printClues(Clue *root);
Clue* searchClue(Clue *root, const char *text);
void freeClues(Clue *root);

#endif
