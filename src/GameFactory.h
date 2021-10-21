#ifndef GAMEFACTORY_H
#define GAMEFACTORY_H

#include <string>
#include "Game.h"

class GameFactory
{
private:
    std::string m_game_name;
    unsigned int m_num_rounds;

public:
    GameFactory();
    GameFactory(const std::string &game_name, const unsigned int &num_rounds);
    Game create(const int &num_vertices = 3, const double &jump_size = 0.5f) const;

private:
    Game create_default() const;
    Game create_polygon_stdRule(const int &num_vertices, const double &jump_size) const;
    Game create_polygon_UniqueRule(const int &num_vertices, const double &jump_size) const;
    Game create_polygon_NeighborRule(const int &num_vertices, const double &jump_size) const;
    Game create_polygon_NoNeighborRule(const int &num_vertices, const double &jump_size) const;
};

#endif