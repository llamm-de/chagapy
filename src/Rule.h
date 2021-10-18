#ifndef RULE_H
#define RULE_H

class Rule
{
private:
    double m_jump_factor;

public:
    Rule();
    Rule(const double &jump_factor);
    virtual bool is_fullfilled(int dice);
    virtual double get_jump_factor() const;
};

#endif