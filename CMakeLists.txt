#------------------------------- HW_4 CMAKE -------------------------------#
cmake_minimum_required(VERSION 3.0.0)

project(Smart_CPU) # name of build

set(EXECUTABLE_OUTPUT_PATH ./${CMAKE_BUILD_TYPE})

include_directories(include) #includes all directories
file(GLOB SOURCES "HW_4/*.cpp") #includes all .cpp files in directory
add_executable(HW_4 ${SOURCES}) #./test

#------------------------------- HW_5 CMAKE -------------------------------#
# cmake_minimum_required(VERSION 3.0.0)

# project(WHO_knows) # name of build

# set(EXECUTABLE_OUTPUT_PATH ./${CMAKE_BUILD_TYPE})

# include_directories(include) #includes all directories
# file(GLOB SOURCES "HW_5/*.cpp") #includes all .cpp files in directory
# add_executable(HW_5 ${SOURCES}) #./test