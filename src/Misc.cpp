#include "Misc.h"

#include <string>

void print_string(const std::string &str)
{
    std::cout << str << std::endl;
}

void print_welcome(const std::string &rule_name, const int &num_vertices, const double &jump_size, const unsigned int &num_rounds, const std::string &out_file)
{
    print_string("");
    print_string("");
    print_string("                                  1                ");
    print_string("                                 111               ");
    print_string("                                1   1              ");
    print_string("                               111 111             ");
    print_string("                              1       1            ");
    print_string("                             111     111           ");
    print_string("                            1   1   1   1          ");
    print_string("                           111 111 111 111         ");
    print_string("                          1               1        ");
    print_string("                         111             111       ");
    print_string("                        1   1           1   1      ");
    print_string("                       111 111         111 111     ");
    print_string("                      1       1       1       1    ");
    print_string("                     111     111     111     111   ");
    print_string("                    1   1   1   1   1   1   1   1  ");
    print_string("                   111 111 111 111 111 111 111 111 ");
    print_string("");
    print_string("");
    print_string("                             WELCOME TO                              ");
    print_string("             _____  _   _   ___  _____   ___  ________   __          ");
    print_string("            /  __ \\| | | | / _ \\|  __ \\ / _ \\ | ___ \\ \\ / /          ");
    print_string("            | /  \\/| |_| |/ /_\\ \\ |  \\// /_\\ \\| |_/ /\\ V /           ");
    print_string("            | |    |  _  ||  _  | | __ |  _  ||  __/  \\ /            ");
    print_string("            | \\__/\\| | | || | | | |_\\ \\| | | || |     | |            ");
    print_string("             \\____/\\_| |_/\\_| |_/\\____/\\_| |_/\\_|     \\_/            ");
    print_string("");
    print_string("                     A CHAOS GAME IMPLEMENTATION                     ");
    print_string("");
    printf("   Rule       : %s \n", rule_name.c_str());
    printf("   Rounds     : %i \n", num_rounds);
    printf("   Vertices   : %i \n", num_vertices);
    printf("   Jump size  : %f \n", jump_size);
    printf("   Output file: %s \n", out_file.c_str());
    print_string("");
}