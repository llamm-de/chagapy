#include "RegularCovexPolygon.h"
#include "Rule.h"
#include "Game.h"
#include <vector>

int main()
{
    Game game(10000000);
    game.run();
    std::vector<Point> results = game.get_results();

    results.at(9000000).print();
}