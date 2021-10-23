#include "GameFactory.h"
#include "Game.h"
#include "Misc.h"

#include "CLI/App.hpp"
#include "CLI/Formatter.hpp"
#include "CLI/Config.hpp"

#include <iostream>

int main(int argc, char **argv)
{

    print_welcome();

    CLI::App app{"CHAGAPY - A Chaos Game Implementation"};

    std::string rules = "default";
    int num_vertices = 3;
    double jump_size = 0.5f;
    unsigned int num_rounds = 100;
    std::string out_file = "test.csv";
    app.add_option("-g,--game", rules, "Rules for the game.");
    app.add_option("-r,--rounds", num_rounds, "Number of rounds to play");
    app.add_option("-v,--vertices", num_vertices, "Number of vertices for polygon base.");
    app.add_option("-j,--jump-size", jump_size, "Jump size factor.");
    app.add_option("-o,--out", out_file, "Output file");

    CLI11_PARSE(app, argc, argv);

    GameFactory factory(rules, num_rounds);
    Game game = factory.create(num_vertices);

    std::cout << "   Running game...";
    game.run();
    std::cout << "DONE!" << std::endl;

    std::cout << "   Exporting results...";
    export_csv(out_file, game);
    std::cout << "DONE!" << std::endl;
    print_string("");
}