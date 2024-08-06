# CMakeList.txt: проект CMake для Leaver_CMake; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../Racing_Simulator)

project ("Vehicles_Class")

set (Vehicles_Lib "Class_TC.h" "Class_TC.cpp" "Class_Air_TC.h" "Class_Air_TC.cpp" "Class_Land_TC.h" "Class_Land_TC.cpp"
"Kover_Samolet_Class.h" "Kover_Samolet_Class.cpp" "Metla_Class.h" "Metla_Class.cpp" "Orel_Class.h" "Orel_Class.cpp"
"Kentavr_Class.h" "Kentavr_Class.cpp" "Botinki_Vezdehody_Class.h" "Botinki_Vezdehody_Class.cpp"
"Verblud_Class.h" "Verblud_Class.cpp" "Verblud_Bystrohod_Class.h" "Verblud_Bystrohod_Class.cpp")

add_library (Vehicles_Class_Lib SHARED ${Vehicles_Lib})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Vehicles_Class_Lib PROPERTY CXX_STANDARD 20)
endif()