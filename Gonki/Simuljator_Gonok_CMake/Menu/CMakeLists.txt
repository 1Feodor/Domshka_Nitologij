# CMakeList.txt: ������ CMake ��� Leaver_CMake; �������� �������� ��� � �����������,
# ������� ����� ������ ��� ����������� �������.
#

project ("Menu")

include_directories ("../Gonka_Class" "../Vehicles_Class")

set (Menu_Lib "Menu.h" "Menu.cpp")

add_library (Menu_Racing_Lib STATIC ${Menu_Lib})

target_link_libraries (Menu_Racing_Lib Gonka_Class_Lib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Menu_Racing_Lib PROPERTY CXX_STANDARD 20)
endif()