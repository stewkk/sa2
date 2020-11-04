
SET(EXECUTABLE_OUTPUT_PATH ../)

cmake_minimum_required(VERSION 3.13)

project(test)

set(SOURCE_EXE src/main.cpp)

set(SOURCE_LIB_UI src/ui.cpp)

set(SOURCE_LIB_MYFRAME src/MyFrameMain.cpp)

set(SOURCE_LIB_EVENT_HANDLERS src/event_handlers.cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(ui STATIC ${SOURCE_LIB_UI})

add_library(my_frame STATIC ${SOURCE_LIB_MYFRAME})

add_library(event_handlers STATIC ${SOURCE_LIB_EVENT_HANDLERS})

add_executable(app ${SOURCE_EXE})

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

target_link_libraries(app my_frame event_handlers ui ${wxWidgets_LIBRARIES})

