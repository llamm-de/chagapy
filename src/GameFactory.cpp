#include "GameFactory.h"
#include "RuleFactory.h"
#include "BaseFactory.h"
#include "Rule.h"

#include <string>

Game GameFactory::create(const unsigned int &num_rounds, const std::string &rule_name, const int &num_vertices = 3, const double &jump_size = 0.5f)
{
    BaseFactory base_factory;
    RuleFactory rule_factory;
    std::shared_ptr<GeometricBase> base = base_factory.create();
    std::shared_ptr<Rule> rule = rule_factory.create(rule_name, base, jump_size);
    return Game(num_rounds, base, rule);
}