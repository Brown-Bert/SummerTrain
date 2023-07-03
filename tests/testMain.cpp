#include "mymain.cpp"
// #include <iostream>
// #include <cstdio>
// #include <cstdlib>
// using namespace std;

// int main(int argc, char* argv[])
// {
//     float expected = 3;
//     float res = sum(1, 2);
//     if (res == expected){
//         cout<<"测试成功"<<endl;
//     }else{
//         cout<<"测试失败"<<endl;
//     }
//     return 0;
// }

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("TEST1")
{
    int expected = 0;
    int argc = 2;
    // char par0 = "./main";
    // char par1 = "-h";
    char* argv[]= {(char*)"../src/exe/mymain", (char*)"-h"};
    int res = mymain(argc, argv);
    REQUIRE(res == expected);
}
TEST_CASE("TEST2")
{
    int expected = 0;
    int argc = 2;
    // char par0 = "./main";
    // char par1 = "-h";
    char* argv[]= {(char*)"../src/exe/mymain", (char*)"--help"};
    int res = mymain(argc, argv);
    REQUIRE(res == expected);
}
TEST_CASE("TEST3")
{
    int expected = 0;
    int argc = 2;
    // char par0 = "./main";
    // char par1 = "-h";
    char* argv[]= {(char*)"../src/exe/mymain", (char*)"-f", (char*)"keymap.txt", (char*)"-s", (char*)"name"};
    int res = mymain(argc, argv);
    REQUIRE(res == expected);
}

// int main(int argc, char* argv[])
// {
//     int expected = 3;
//     int argc = 2;
//     char* argv[]= {(char*)"../src/exe/mymain", (char*)"-h"};
//     int res = main(argc, argv);
//     if (res == expected){
//         cout<<"测试成功"<<endl;
//     }else{
//         cout<<"测试失败"<<endl;
//     }
//     return 0;
// }