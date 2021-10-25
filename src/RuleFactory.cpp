#include "RuleFactory.h"

std::shared_ptr<Rule> RuleFactory::create(const std::string &rule_name, std::shared_ptr<GeometricBase> base, const double &jump_size)
{
    if (rule_name.compare("Unique") == 0)
    {
        return std::make_shared<UniqueRule>(jump_size);
    }
    else if (rule_name.compare("Neighbor") == 0)
    {
        return std::make_shared<NeighborRule>(base->get_num_vertices(), jump_size);
    }
    else if (rule_name.compare("NoNeighbor") == 0)
    {
        return std::make_shared<NoNeighborRule>(base->get_num_vertices(), jump_size);
    }
    else
    {
        return std::make_shared<Rule>(jump_size);
    }
}