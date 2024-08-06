# CMakeList.txt: проект CMake для Leaver; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../Leaver_CMake)

project ("Leaver_Class")

set (Leaver_Lib "Leaver.h" "Leaver.cpp")

add_library (Leaver_Class_Lib SHARED ${Leaver_Lib})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Leaver_Class_Lib PROPERTY CXX_STANDARD 20)
endif()
