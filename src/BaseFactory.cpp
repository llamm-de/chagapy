#include "BaseFactory.h"

std::shared_ptr<GeometricBase> BaseFactory::create(const std::string &base_name, const int &num_vertices)
{
    return std::make_shared<RegularConvexPolygon>(num_vertices, 1);
}