#ifndef NONEIGHBORRULE_H
#define NONEIGHBORRULE_H

#include "Rule.h"

class NoNeighborRule : public Rule
{
private:
    int m_last_point;
    int m_num_vertices;

public:
    NoNeighborRule(const int &num_vertices);
    NoNeighborRule(const int &num_vertices, const double &jump_factor);
    virtual bool is_fullfilled(int dice) override;
    virtual double get_jump_factor() const override;
};

#endif