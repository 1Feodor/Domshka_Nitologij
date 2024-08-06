# CMakeList.txt: проект CMake для Racing_Simulator; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

project ("Racing_Simulator")

include_directories ("../Menu" "../Gonka_Class" "../Vehicles_Class")

add_executable (Racing_Simulator "Racing_Simulator.cpp" )

target_link_libraries ( Racing_Simulator Menu_Racing_Lib Gonka_Class_Lib Vehicles_Class_Lib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Racing_Simulator PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
