# CMakeList.txt: проект CMake для Leaver_CMake; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../Racing_Simulator)

project ("Gonka_Class")

include_directories ("../Vehicles_Class")

set (Gonka_Lib "Gonka_Class.h" "Gonka_Class.cpp" "Broadcast_Gonki_Class.h" "Broadcast_Gonki_Class.cpp")

add_library (Gonka_Class_Lib SHARED ${Gonka_Lib})

target_link_libraries ( Gonka_Class_Lib Vehicles_Class_Lib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Gonka_Class_Lib PROPERTY CXX_STANDARD 20)
endif()