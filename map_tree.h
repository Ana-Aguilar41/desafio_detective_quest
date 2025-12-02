#ifndef MAP_TREE_H
#define MAP_TREE_H

typedef struct Room {
    char name[50];
    struct Room *left;
    struct Room *right;
} Room;

Room* createRoom(const char *name);
Room* insertRoom(Room *root, const char *name, const char *path);
void printMap(Room *root, int level);
void freeMap(Room *root);

#endif
