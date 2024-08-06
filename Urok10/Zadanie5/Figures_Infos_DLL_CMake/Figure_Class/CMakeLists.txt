set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../Figures_Infos)

project ("Figure_Class")

set (Figure_List "Class_Figure.h" "Class_Figure.cpp" "Class_Triangle.h" "Class_Triangle.cpp" "Class_Quadrangle.h" "Class_Quadrangle.cpp"
"Class_Right_Triangle.h" "Class_Right_Triangle.cpp" "Class_Isosceles_Triangle.h" "Class_Isosceles_Triangle.cpp"
"Class_Equilateral_Triangle.h" "Class_Equilateral_Triangle.cpp" "Class_Parallelogram.h" "Class_Parallelogram.cpp"
"Class_Reectangle.h" "Class_Reectangle.cpp" "Class_Rhombus.h" "Class_Rhombus.cpp" "Class_Square.h" "Class_Square.cpp")

add_library (Figure_Class_Lib SHARED ${Figure_List})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Figure_Class_Lib PROPERTY CXX_STANDARD 20)
endif()