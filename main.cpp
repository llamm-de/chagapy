#include "RegularCovexPolygon.h"
#include "Rule.h"
#include "UniqueRule.h"
#include "NoNeighborRule.h"
#include "NeighborRule.h"
#include "Game.h"
#include <memory>

int main(int argc, char **argv)
{
    int num_vertices = 3;
    std::shared_ptr<RegularConvexPolygon> base = std::make_shared<RegularConvexPolygon>(num_vertices, 1);
    std::shared_ptr<NoNeighborRule> rule = std::make_shared<NoNeighborRule>(num_vertices);
    Game game(100000, base, rule);
    game.run();
    export_csv("test.csv", game);
}