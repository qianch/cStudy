message(STATUS "CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")

add_executable(newFeature newFeature.cpp)
find_package(spdlog REQUIRED)
message(STATUS "${CMAKE_SYSTEM_NAME}")
if(spdlog_FOUND)
      target_link_libraries(newFeature PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>)
else(spdlog_FOUND)
      MESSAGE(FATAL_ERROR "spdlog library not found")
endif(spdlog_FOUND)