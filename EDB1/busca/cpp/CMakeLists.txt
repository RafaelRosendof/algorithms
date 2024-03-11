cmake_minimum_required(VERSION 3.10)
project(MyProject)

#set c++ standard library
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add your source files
set(SOURCES
    main_class.cpp
    main_test.cpp
)

#add the headers
set(HEADERS head.h)

#add executable targets
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})