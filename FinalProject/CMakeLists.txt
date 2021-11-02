find_package(wxWidgets COMPONENTS aui adv html xml net richtext core base REQUIRED)
 
# include wxWidgets while include everything related 
include( "${wxWidgets_USE_FILE}" )

#includes all .cpp files
file(GLOB SOURCES "*.cpp") 
#Add source files
set(SOURCE_FILES ${SOURCES}) 

# If statement for when compiling and building in Windows
if(WIN32)
 set(SOURCE_FILES ${SOURCE_FILES} sample.rc)
endif(WIN32)

# the above paths and defines will be used in this build
add_executable(${CMAKE_PROJECT_NAME} WIN32 ${SOURCE_FILES})

# Other needed libraries can be added here
target_link_libraries(${CMAKE_PROJECT_NAME} ${wxWidgets_LIBRARIES})
