cmake_minimum_required(VERSION 3.13)
project(PublicTestProject)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
    src/main.cpp
    src/PublicTestProject.cpp
    src/PublicTestProject.h
    src/TestProject.cpp
    src/TestProject.h
    src/gui/gtkmm3/Gtkmm3Project.cpp
    src/gui/gtkmm3/Gtkmm3Project.h
    src/gui/gtkmm3/Window.cpp
    src/gui/gtkmm3/Window.h
    src/multithreading/Buffer.cpp
    src/multithreading/Buffer.h
    src/multithreading/producerConsumer/Consumer.cpp
    src/multithreading/producerConsumer/Consumer.h
    src/multithreading/producerConsumer/Producer.cpp
    src/multithreading/producerConsumer/Producer.h
    src/multithreading/producerConsumer/ProducerConsumerProject.cpp
    src/multithreading/producerConsumer/ProducerConsumerProject.h)

include(FindPkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
include_directories(${GTKMM_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${GTKMM_LIBRARIES})