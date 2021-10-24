#ifndef GAMEFACTORY_H
#define GAMEFACTORY_H

#include <string>
#include "Game.h"

class GameFactory
{
public:
    Game create(const unsigned int &num_rounds, const std::string &rule_name, const int &num_vertices, const double &jump_size);
};

#endif