#include "RegularCovexPolygon.h"
#include "Rule.h"
#include "Game.h"
#include <memory>

int main(int argc, char **argv)
{
    std::shared_ptr<RegularConvexPolygon> base = std::make_shared<RegularConvexPolygon>(3, 1);
    std::shared_ptr<Rule> rule = std::make_shared<Rule>(0.45f);
    Game game(100000, base, rule);
    game.run();
    export_csv("test.csv", game);
}