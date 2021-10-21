#include "GameFactory.h"
#include "Game.h"
#include <memory>

/*
*   Command line call:
*   
*   chagapy                                  -> Default model (3 vertices, Std.-Rule, 0.5 jump)
*   chagapy GAME_NAME                        -> (3 vertices, 0.5 jump, Rule determined by GAME_NAME)
*   chagapy GAME_NAME NUM_VERTICES           -> (NUM_VERTICES vertices, 0.5 jump, Rule determined by GAME_NAME)
*   chagapy GAME_NAME NUM_VERTICES JUMP_SIZE -> (NUM_VERTICES vertices, JUMP_SIZE jump, Rule determined by GAME_NAME)
*
*/
int main(int argc, char **argv)
{
    int num_vertices = 5;
    unsigned int num_rounds = 100000;
    GameFactory factory("Polygon_UniqueRule", num_rounds);
    Game game = factory.create(num_vertices);
    game.run();
    export_csv("test.csv", game);
}