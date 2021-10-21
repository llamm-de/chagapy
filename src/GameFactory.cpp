#include "GameFactory.h"
#include "RegularCovexPolygon.h"
#include "Rule.h"
#include "UniqueRule.h"
#include "NeighborRule.h"
#include "NoNeighborRule.h"

#include <string>

GameFactory::GameFactory() : m_game_name("default"), m_num_rounds(100000){};

GameFactory::GameFactory(const std::string &game_name, const unsigned int &num_rounds)
    : m_game_name(game_name), m_num_rounds(num_rounds){};

Game GameFactory::create(const int &num_vertices, const double &jump_size) const
{

    if (m_game_name.compare("Polygon_StdRule") == 0)
    {
        return create_polygon_stdRule(num_vertices, jump_size);
    }
    else if (m_game_name.compare("Polygon_UniqueRule") == 0)
    {
        return create_polygon_UniqueRule(num_vertices, jump_size);
    }
    else if (m_game_name.compare("Polygon_NeighborRule") == 0)
    {
        return create_polygon_NeighborRule(num_vertices, jump_size);
    }
    else if (m_game_name.compare("Polygon_NoNeighborRule") == 0)
    {
        return create_polygon_NoNeighborRule(num_vertices, jump_size);
    }
    else
    {
        return create_default();
    }
}

Game GameFactory::create_default() const
{
    return create_polygon_stdRule(3, 0.5f);
}

Game GameFactory::create_polygon_stdRule(const int &num_vertices, const double &jump_size) const
{
    std::shared_ptr<RegularConvexPolygon> base = std::make_shared<RegularConvexPolygon>(num_vertices, 1);
    std::shared_ptr<Rule> rule = std::make_shared<Rule>(jump_size);
    return Game(m_num_rounds, base, rule);
}

Game GameFactory::create_polygon_UniqueRule(const int &num_vertices, const double &jump_size) const
{
    std::shared_ptr<RegularConvexPolygon> base = std::make_shared<RegularConvexPolygon>(num_vertices, 1);
    std::shared_ptr<UniqueRule> rule = std::make_shared<UniqueRule>(jump_size);
    return Game(m_num_rounds, base, rule);
}

Game GameFactory::create_polygon_NeighborRule(const int &num_vertices, const double &jump_size) const
{
    std::shared_ptr<RegularConvexPolygon> base = std::make_shared<RegularConvexPolygon>(num_vertices, 1);
    std::shared_ptr<NeighborRule> rule = std::make_shared<NeighborRule>(num_vertices, jump_size);
    return Game(m_num_rounds, base, rule);
}

Game GameFactory::create_polygon_NoNeighborRule(const int &num_vertices, const double &jump_size) const
{
    std::shared_ptr<RegularConvexPolygon> base = std::make_shared<RegularConvexPolygon>(num_vertices, 1);
    std::shared_ptr<NoNeighborRule> rule = std::make_shared<NoNeighborRule>(num_vertices, jump_size);
    return Game(m_num_rounds, base, rule);
}