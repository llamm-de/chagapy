#include "NoNeighborRule.h"

NoNeighborRule::NoNeighborRule(const int &num_vertices)
    : Rule(0.5f), m_last_point(-1), m_num_vertices(num_vertices){};

NoNeighborRule::NoNeighborRule(const int &num_vertices, const double &jump_factor)
    : Rule(jump_factor), m_last_point(-1), m_num_vertices(num_vertices){};

bool NoNeighborRule::is_fullfilled(int dice)
{
    bool success = false;
    int right_neighbor = m_last_point + 1;
    int left_neighbor = m_last_point - 1;

    if (right_neighbor > m_num_vertices - 1)
    {
        right_neighbor = 0;
    }
    if (left_neighbor < 0)
    {
        left_neighbor = m_num_vertices - 1;
    }

    if ((dice != right_neighbor) && (dice != left_neighbor))
    {
        success = true;
        m_last_point = dice;
    }
    return success;
};

double NoNeighborRule::get_jump_factor() const { return Rule::get_jump_factor(); };