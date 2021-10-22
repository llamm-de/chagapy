cmake_minimum_required(VERSION 3.10)
project(ChaGaPy VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
add_subdirectory(dependencies/CLI11)
add_executable(chagapy main.cpp)
target_link_libraries(chagapy cgp)
target_include_directories(chagapy PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
${CMAKE_CURRENT_SOURCE_DIR}/dependencies/CLI11/include)


add_custom_target(release
COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release ${CMAKE_SOURCE_DIR}
COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
COMMENT "Switch CMAKE_BUILD_TYPE to Release"
)

add_custom_target(debug
COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
COMMENT "Switch CMAKE_BUILD_TYPE to Debug"
)

add_custom_target(run
    COMMAND chagapy
    DEPENDS chagapy
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)