set(SOURCE "Point.cpp"
           "GeometricBase.cpp"
           "Game.cpp"
           "RegularConvexPolygon.cpp"
           "Rule.cpp"
           "UniqueRule.cpp"
           "NeighborRule.cpp"
           "NoNeighborRule.cpp"
           "GameFactory.cpp"
           "BaseFactory.cpp"
           "RuleFactory.cpp"
           "Misc.cpp")

add_library(cgp ${SOURCE})
target_include_directories(cgp PUBLIC ${CMAKE_SOURCE_DIR}/includes)