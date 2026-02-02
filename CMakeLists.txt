cmake_minimum_required(VERSION 3.16)
project(game LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(game source/main.cpp source/board.cpp)

target_include_directories(game PRIVATE ${CMAKE_SOURCE_DIR}/source ${CMAKE_SOURCE_DIR}/lib)

# Link libraries
target_link_libraries(game
    ${CMAKE_SOURCE_DIR}/lib/libraylib.a
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
)
