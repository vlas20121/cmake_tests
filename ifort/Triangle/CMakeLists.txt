cmake_minimum_required(VERSION 3.15)
project(TryFortran Fortran)

file(GLOB f90 "*.f90")

add_executable(Main ${f90})