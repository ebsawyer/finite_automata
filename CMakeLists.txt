cmake_minimum_required(VERSION 3.16)
project(project1 C)

set(CMAKE_C_STANDARD 99)

add_executable(project1 main.c dfa.c dfa.h nfa.c nfa.h BitSet.c BitSet.h translator.c translator.h)