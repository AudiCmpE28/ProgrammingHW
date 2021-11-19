#------------------------------- HW_3 Terminal -------------------------------#
# cd "$cwd" ; if ($?) { g++ Game.cpp main.cpp CPU.cpp Player.cpp RandomCPU.cpp 
# printUI.cpp ChooserFactory.cpp SmartCPU.cpp GeniusCPU.cpp -o main } ; if ($?) { .\main }

#------------------------------- HW_4 CMAKE -------------------------------#
#/* This Format: Folder HW_4 does not need its own CMakeLists.txt */
# cmake_minimum_required(VERSION 3.0.0)

# project(Smart_CPU) # name of build

# set(EXECUTABLE_OUTPUT_PATH ./${CMAKE_BUILD_TYPE})

# include_directories(include) #includes all directories
# file(GLOB SOURCES "HW_4/*.cpp") #includes all .cpp files in directory
# add_executable(HW_4 ${SOURCES}) #./test

#### HOW to RUN: 
    # mkdir build && cd build
    # cmake ..
    # make 
    # ./projectName
#------------------------------- HW_5 CMAKE -------------------------------#
#/* This Format: Will call Folder HW_5's CMakeLists.txt */

cmake_minimum_required(VERSION 3.0.0)
project(GUI_RPS) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Will put exe in the "build" folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

add_subdirectory(HW_5)

#--------------------------- HelloWorldApp CMAKE ---------------------------#
# /* This Format: Will call Folder HelloWorldApp's CMakeLists.txt */

# cmake_minimum_required(VERSION 3.0.0)
# project(HelloWorld_APP) 

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # Will put exe in the "build" folder
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

# add_subdirectory(HelloWorldApp)

cmake_minimum_required(VERSION 3.0.0)
project(FinalProject) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Will put exe in the "build" folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

add_subdirectory(Blackjack)


cmake_minimum_required(VERSION 3.0.0)
project(Jacks_Bank_GUI) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Will put exe in the "build" folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

add_subdirectory(Jacks_Bank)