set(Catch2d "D:\\source\\Catch2\\build\\src\\Debug\\Catch2d.lib")
set(Catch2Maind "D:\\source\\Catch2\\build\\src\\Debug\\Catch2Maind.lib")

link_libraries("${Catch2d}" "${Catch2Maind}")
set(Catch_SRCS catch.cpp)
add_executable(catch ${Catch_SRCS})

set(catch2Dir "D:\\source\\Catch2\\src\\catch2\\..")
set(catch2Includes "D:\\source\\Catch2\\build\\generated-includes")
include_directories("${catch2Dir}" "${catch2Includes}")