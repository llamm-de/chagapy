#include "Rule.h"

Rule::Rule() : m_jump_factor(0.5f){};

Rule::Rule(const double &jump_factor) : m_jump_factor(jump_factor){};

bool Rule::is_fullfilled(int dice) { return true; };

double Rule::get_jump_factor() const { return m_jump_factor; };
