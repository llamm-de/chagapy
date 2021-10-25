#ifndef UNIQUERULE_H
#define UNIQUERULE_H

#include "Rule.h"

class UniqueRule : public Rule
{
private:
    int m_last_point;

public:
    UniqueRule();
    UniqueRule(const double &jump_factor);
    virtual bool is_fullfilled(int dice) override;
    virtual double get_jump_factor() const override;
};

#endif