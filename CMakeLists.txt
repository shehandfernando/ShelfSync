cmake_minimum_required(VERSION 3.10)
project(ShelfSync VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SQLite3 on your system
find_package(SQLite3 REQUIRED)

# Include header files
include_directories(include)

# Create the executable
add_executable(ShelfSync src/main.cpp src/DatabaseManager.cpp)

# Link the SQLite3 library
target_link_libraries(ShelfSync SQLite3::SQLite3)