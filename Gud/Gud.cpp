#include "GameManager.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    GameManager game;
    game.startGame();

    return 0;
}