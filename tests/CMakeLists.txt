add_executable(testmain testMain.cpp)

target_link_libraries(testmain PUBLIC ctest)

add_test(
    NAME mytest
    COMMAND testmain
)