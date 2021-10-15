#ifndef GAME_H
#define GAME_H

#include "GeometricBase.h"
#include "Rule.h"
#include "Point.h"
#include <vector>
#include <memory>

class Game
{
private:
    unsigned int m_num_rounds;
    unsigned int m_current_round;
    std::shared_ptr<GeometricBase> m_base;
    std::shared_ptr<Rule> m_rule;
    std::vector<Point> m_results;

public:
    Game();
    Game(const unsigned int &num_rounds);
    Game(const unsigned int &num_rounds, std::shared_ptr<GeometricBase> base);
    Game(const unsigned int &num_rounds, std::shared_ptr<GeometricBase> base, std::shared_ptr<Rule> rule);
    int roll_dice();
    const Point play_round();
    void run();
    std::vector<Point> get_results() const;

private:
    void initialize_game();
};

#endif