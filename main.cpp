#include "RegularCovexPolygon.h"
#include "Rule.h"
#include "Game.h"
#include <vector>
#include <iostream>
#include <string>
#include <memory>

void print(std::string str)
{
    std::cout << str << std::endl;
};

int main()
{

    std::shared_ptr<RegularConvexPolygon> base = std::make_shared<RegularConvexPolygon>(3, 1);
    Game game(1000, base);
    game.run();
    export_csv("test.csv", game);
}