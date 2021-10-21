#ifndef NEIGHBORRULE_H
#define NEIGHBORRULE_H

#include "Rule.h"

class NeighborRule : public Rule
{
private:
    int m_last_point;
    int m_num_vertices;

public:
    NeighborRule(const int &num_vertices);
    NeighborRule(const int &num_vertices, const double &jump_factor);
    virtual bool is_fullfilled(int dice) override;
    virtual double get_jump_factor() const override;
};

#endif