#include "test.cpp"
// #include <iostream>
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

TEST_CASE("TEST1", "SUB1")
{
    int expected = 3;
    int res = sum(1, 2);
    REQUIRE(res == expected);
}