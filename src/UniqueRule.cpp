#include "UniqueRule.h"

UniqueRule::UniqueRule() : Rule(0.5f), m_last_point(-1){};

UniqueRule::UniqueRule(const double &jump_factor) : Rule(jump_factor), m_last_point(-1){};

bool UniqueRule::is_fullfilled(int dice)
{
    bool success = (m_last_point != dice);
    if (success)
    {
        m_last_point = dice;
    };
    return success;
};

double UniqueRule::get_jump_factor() const { return Rule::get_jump_factor(); };