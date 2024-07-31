cmake_minimum_required(VERSION 3.30)
project(Lock)

enable_testing()

# Tests
add_executable (a.out src/main.c src/virtual_machine.c)

# add_test(test-0 test0)
