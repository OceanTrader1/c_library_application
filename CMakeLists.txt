cmake_minimum_required(VERSION 3.24)
project(library C)

set(CMAKE_C_STANDARD 11)

# https://stackoverflow.com/questions/55165172/static-linking-of-openssl-crypto-in-cmake
set(OPENSSL_USE_STATIC_LIBS TRUE)

find_package(OpenSSL REQUIRED)

# https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/
#find_package(GTest REQUIRED)

# https://google.github.io/googletest/quickstart-cmake.html
#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
#)
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)  # For Windows: Prevent overriding the
# parent project's compiler/linker settings
#FetchContent_MakeAvailable(googletest)
#include(GoogleTest)

add_executable(library src/main.c include/customer.h src/customer.c include/object.h include/checksum.h src/checksum.c src/book.c include/book.h src/date.c include/date.h src/linkedlist.c include/linkedlist.h)

target_link_libraries(library OpenSSL::Crypto)

