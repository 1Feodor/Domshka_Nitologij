#минимальная версия cmake
cmake_minimum_required(VERSION 3.10)
#имя проекта
project(testListNode2)
#добавляем поддиректорию, в которой будет catch2
add_subdirectory(catch2)
add_subdirectory (List_class)
include_directories (List_class)
#добавляем цель - приложение, у которого исходник с единственным приложением
add_executable(${PROJECT_NAME} "ListTest2.cpp" "List_class/List_class.h")
#линкуемся к catch2, в котором уже есть main
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2 Catch2::Catch2WithMain List_Class_Lib)