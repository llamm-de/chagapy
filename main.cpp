#include "GameFactory.h"
#include "Game.h"

#include "CLI/App.hpp"
#include "CLI/Formatter.hpp"
#include "CLI/Config.hpp"

#include <memory>
#include <iostream>

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

    CLI::App app{"CHAGAPY - A Chaos Game Implementation"};

    std::string rules = "default";
    int num_vertices = 3;
    double jump_size = 0.5f;
    unsigned int num_rounds = 100000;
    std::string out_file = "test.csv";
    app.add_option("-g,--game", rules, "Rules for the game.");
    app.add_option("-r,--rounds", num_rounds, "Number of rounds to play");
    app.add_option("-v,--vertices", num_vertices, "Number of vertices for polygon base.");
    app.add_option("-j,--jump-size", jump_size, "Jump size factor.");
    app.add_option("-o,--out", out_file, "Output file");

    CLI11_PARSE(app, argc, argv);

    GameFactory factory(rules, num_rounds);
    Game game = factory.create(num_vertices);

    std::cout << "Running game..." << std::endl;
    game.run();

    std::cout << "Exporting results..." << std::endl;
    export_csv(out_file, game);
}