#ifndef RULE_H
#define RULE_H

class Rule
{
public:
    bool is_fullfilled(int dice) const;
    double get_jump_factor() const;
};

#endif