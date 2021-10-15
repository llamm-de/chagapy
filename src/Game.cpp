#include "Game.h"
#include "RegularCovexPolygon.h"
#include "Point.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

Game::Game()
    : m_num_rounds(100000), m_current_round(0)
{
    m_base = std::make_shared<RegularConvexPolygon>(3, 1);
    m_rule = std::make_shared<Rule>();
    initialize_game();
};

Game::Game(const unsigned int &num_rounds)
    : m_num_rounds(num_rounds), m_current_round(0)
{
    m_base = std::make_shared<RegularConvexPolygon>(3, 1);
    m_rule = std::make_shared<Rule>();
    initialize_game();
};

Game::Game(const unsigned int &num_rounds, std::shared_ptr<GeometricBase> base)
    : m_num_rounds(num_rounds), m_current_round(0), m_base(base)
{
    m_rule = std::make_shared<Rule>();
    initialize_game();
};

Game::Game(const unsigned int &num_rounds, std::shared_ptr<GeometricBase> base, std::shared_ptr<Rule> rule)
    : m_num_rounds(num_rounds), m_current_round(0), m_base(base), m_rule(rule)
{
    initialize_game();
};

int Game::roll_dice()
{
    return rand() % m_base->get_num_vertices();
};

const Point Game::play_round()
{
    if (m_current_round >= m_num_rounds)
    {
        throw "Maximum number of steps reached!";
    }

    int dice = roll_dice();
    while (!m_rule->is_fullfilled(dice))
    {
        dice = roll_dice();
    }

    m_current_round++;
    Point next_pt = m_rule->get_jump_factor() * (m_base->get_item(dice) + m_results.back());
    return next_pt;
};

void Game::run()
{
    for (size_t i = 0; i < m_num_rounds; i++)
    {
        m_results.push_back(play_round());
    }
};

std::vector<Point> Game::get_results() const
{
    return m_results;
};

void Game::initialize_game()
{
    srand(time(NULL)); // Reset random seed
    m_results.reserve(m_num_rounds);
    m_results.emplace_back();
};

// FRIEND FUNCTIONS
void export_csv(const std::string &if_name, const Game &game)
{
    std::ofstream stream;
    stream.open(if_name, std::ios::out);

    for (auto const &point : game.m_results)
    {
        stream << point.get_x() << "," << point.get_y() << std::endl;
    }
    stream.close();
};