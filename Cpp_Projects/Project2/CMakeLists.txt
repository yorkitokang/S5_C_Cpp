cmake_minimum_required(VERSION 3.10)

project(Pro2)

aux_source_directory(./src DIR_SRCS)

add_executable(Pro2 ${DIR_SRCS})

include_directories(include)