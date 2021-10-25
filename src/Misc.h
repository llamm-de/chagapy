#ifndef MISC_H
#define MISC_H

#include <iostream>
#include <string>

void print_string(const std::string &str);
void print_welcome(const std::string &rule_name, const int &num_vertices, const double &jump_size, const unsigned int &num_rounds, const std::string &out_file);

#endif