add_executable(testmain testMain.cpp)

target_link_libraries(testmain PUBLIC cmain)
target_link_libraries(cmain readline)
add_test(
    NAME test1
    COMMAND $<TARGET_FILE:testmain> --success
)