cmake_minimum_required(VERSION 3.27)
project(Wallet_Management_Tester)

set(CMAKE_CXX_STANDARD 17)

add_executable(Wallet_Management_Tester main.cpp)

set(PROJECT_HEADERS_DIR ../Wallet_Management/headers)
set(PROJECT_SOURCES_DIR ../Wallet_Management/sources)

include_directories(${PROJECT_HEADERS_DIR})
include_directories(${PROJECT_SOURCES_DIR})

set(GOOGLE_TEST_LIB ${PROJECT_SOURCE_DIR}/googleTestLib/googletest-main)
set(GOOGLE_TEST_LIB_INCLUDE ${GOOGLE_TEST_LIB}/googletest/include)

add_subdirectory(${GOOGLE_TEST_LIB})
include_directories(${GOOGLE_TEST_LIB_INCLUDE})

set(SOURCE_FILES
        main.cpp
        ${PROJECT_HEADERS_DIR}/factorial.h
        ${PROJECT_SOURCES_DIR}/factorial.cpp
)

add_executable(FirstProjectTester ${SOURCE_FILES})
target_link_libraries(Wallet_Management_Tester gtest gtest_main)