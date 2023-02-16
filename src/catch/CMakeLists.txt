message(STATUS "CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")

set(SRC_LIST catch.cpp)
add_executable(catchDemo ${SRC_LIST})
find_package(Catch2 REQUIRED)
message("cmake_module_path: " ${CMAKE_MODULE_PATH})

IF(Catch2_FOUND)
       INCLUDE_DIRECTORIES(${Catch2_INCLUDE_DIR})
       TARGET_LINK_LIBRARIES(catchDemo ${Catch2_LIBRARY})
ELSE(Catch2_FOUND)
       MESSAGE(FATAL_ERROR "Catch2 library not found")
ENDIF(Catch2_FOUND)

message(STATUS "${Catch2_FOUND},${Catch2_INCLUDE_DIRS},${Catch2_INCLUDES_LIBRARY}")
