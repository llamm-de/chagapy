set(SOURCE "Point.cpp"
           "GeometricBase.cpp"
           "Game.cpp"
           "RegularConvexPolygon.cpp"
           "Rule.cpp"
           "UniqueRule.cpp"
           "NeighborRule.cpp"
           "NoNeighborRule.cpp")

add_library(cgp ${SOURCE})