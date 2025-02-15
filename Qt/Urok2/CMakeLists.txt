cmake_minimum_required(VERSION 3.16)

project(new_project_console LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Sql)

add_executable(new_project_console
  main.cpp
)
target_link_libraries(new_project_console PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(new_project_console PRIVATE Qt${QT_VERSION_MAJOR}::Network)
target_link_libraries(new_project_console PRIVATE Qt${QT_VERSION_MAJOR}::Sql)

include(GNUInstallDirs)
install(TARGETS new_project_console
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
