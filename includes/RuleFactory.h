#ifndef RULEFACTORY_H
#define RULEFACTORY_H

#include "Rule.h"
#include "UniqueRule.h"
#include "NeighborRule.h"
#include "NoNeighborRule.h"
#include "GeometricBase.h"

#include <memory>
#include <string>

class RuleFactory
{
public:
    std::shared_ptr<Rule> create(const std::string &rule_name, std::shared_ptr<GeometricBase> base, const double &jump_size = 0.5f);
};

#endif