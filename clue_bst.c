#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clue_bst.h"

Clue* insertClue(Clue *root, const char *text) {
    if (!root) {
        Clue *c = malloc(sizeof(Clue));
        strcpy(c->text, text);
        c->left = c->right = NULL;
        return c;
    }
    if (strcmp(text, root->text) < 0)
        root->left = insertClue(root->left, text);
    else
        root->right = insertClue(root->right, text);

    return root;
}

void printClues(Clue *root) {
    if (!root) return;
    printClues(root->left);
    printf("• %s\n", root->text);
    printClues(root->right);
}

Clue* searchClue(Clue *root, const char *text) {
    if (!root) return NULL;
    int cmp = strcmp(text, root->text);
    if (cmp == 0) return root;
    if (cmp < 0) return searchClue(root->left, text);
    return searchClue(root->right, text);
}

void freeClues(Clue *root) {
    if (!root) return;
    freeClues(root->left);
    freeClues(root->right);
    free(root);
}
