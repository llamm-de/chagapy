#include "RegularCovexPolygon.h"
#include "Rule.h"
#include "UniqueRule.h"
#include "Game.h"
#include <memory>

int main(int argc, char **argv)
{
    std::shared_ptr<RegularConvexPolygon> base = std::make_shared<RegularConvexPolygon>(4, 1);
    std::shared_ptr<UniqueRule> rule = std::make_shared<UniqueRule>(0.5f);
    Game game(100000, base, rule);
    game.run();
    export_csv("test.csv", game);
}