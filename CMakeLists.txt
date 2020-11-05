
SET(EXECUTABLE_OUTPUT_PATH ../)

cmake_minimum_required(VERSION 3.13)

project(sa2)

add_subdirectory(shiki_api)
add_subdirectory(smotret-anime_api)

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

target_include_directories(event_handlers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/resources)
target_include_directories(event_handlers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/shiki_api/include)
target_include_directories(event_handlers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/smotret-anime_api/include)
target_include_directories(my_frame PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/resources)
target_link_libraries(app my_frame event_handlers ui shiki_api smotret-anime_api ${wxWidgets_LIBRARIES})

