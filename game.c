#include <stdio.h>
#include "map_tree.h"
#include "clue_bst.h"
#include "suspects_hash.h"

void startGame() {
    printf("=== Detective Quest ===\n");

    Room *map = NULL;
    map = insertRoom(map, "Entrada", "");
    map = insertRoom(map, "Sala de Estar", "L");
    map = insertRoom(map, "Biblioteca", "R");

    printf("\nMapa da Mansão:\n");
    printMap(map, 0);

    Clue *clues = NULL;
    clues = insertClue(clues, "Pegada de lama");
    clues = insertClue(clues, "Luvas rasgadas");
    clues = insertClue(clues, "Relogio quebrado");

    printf("\nPistas encontradas:\n");
    printClues(clues);

    hashInsert("Pegada de lama", "Jardineiro");
    hashInsert("Luvas rasgadas", "Cozinheiro");

    const char *suspect = hashSearch("Luvas rasgadas");
    printf("\nA pista 'Luvas rasgadas' aponta para: %s\n", suspect);

    freeClues(clues);
    freeMap(map);
}
