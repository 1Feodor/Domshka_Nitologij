# CMakeList.txt: проект CMake для my_first_cmake_project2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("my_first_cmake_project2" VERSION 1.0 LANGUAGES CXX)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (my_first_cmake_project2 "Figures_ Info2.cpp" "Class_Figure.cpp" "Class_Triangle.cpp" 
"Class_Quadrangle.cpp" "Class_Parallelogram.cpp" "Class_Reectangle.cpp" "Class_Rhombu.cpp" "Class_Square.cpp" 
"Class_Right_Triangle.cpp" "Class_Isosceles_Triangle.cpp" "Class_Equilateral_Triangle.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET my_first_cmake_project2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
