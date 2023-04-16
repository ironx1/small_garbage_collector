cmake_minimum_required(VERSION 3.25)
project(SmallGarbageCollector C)

set(CMAKE_C_STANDARD 11)

#add_library(SmallGarbageCollector garbage_collector.c garbage_collector.h)

add_executable(test main.c garbage_collector.c garbage_collector.h)