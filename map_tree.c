#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map_tree.h"

Room* createRoom(const char *name) {
    Room *r = malloc(sizeof(Room));
    strcpy(r->name, name);
    r->left = r->right = NULL;
    return r;
}

// Insere via caminho, ex: "L", "R", "LR"
Room* insertRoom(Room *root, const char *name, const char *path) {
    if (!root) root = createRoom("Entrada");

    Room *cur = root;
    for (int i = 0; path[i]; i++) {
        if (path[i] == 'L') {
            if (!cur->left) cur->left = createRoom("???");
            cur = cur->left;
        } else if (path[i] == 'R') {
            if (!cur->right) cur->right = createRoom("???");
            cur = cur->right;
        }
    }
    strcpy(cur->name, name);
    return root;
}

void printMap(Room *root, int level) {
    if (!root) return;
    for (int i = 0; i < level; i++) printf("  ");
    printf("- %s\n", root->name);
    printMap(root->left, level+1);
    printMap(root->right, level+1);
}

void freeMap(Room *root) {
    if (!root) return;
    freeMap(root->left);
    freeMap(root->right);
    free(root);
}
