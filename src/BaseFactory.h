#ifndef BASEFACTORY_H
#define BASEFACTORY_H

#include "GeometricBase.h"
#include "RegularCovexPolygon.h"

#include <memory>
#include <string>

class BaseFactory
{
public:
    std::shared_ptr<GeometricBase> create(const std::string &base_name = "RegularConvexPolygon", const int &num_vertices = 3);
};

#endif