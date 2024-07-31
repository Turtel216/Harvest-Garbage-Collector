cmake_minimum_required(VERSION 3.30)
project(Lock)

enable_testing()

# Tests
add_executable (test0 test/test-0.c src/virtual_machine.c src/garbage_collector.c)
add_executable (test1 test/test-1.c src/virtual_machine.c src/garbage_collector.c)
add_executable (test2 test/test-2.c src/virtual_machine.c src/garbage_collector.c)
add_executable (test3 test/test-3.c src/virtual_machine.c src/garbage_collector.c)

add_test(test-0 test0)
add_test(test-1 test1)
add_test(test-2 test2)
add_test(test-3 test3)
