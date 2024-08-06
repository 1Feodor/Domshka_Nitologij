project ("Leaver_CMake")

include_directories ("../Leaver_Class")

add_executable (Leaver_CMake "Leaver_CMake.cpp" )

target_link_libraries ( Leaver_CMake Leaver_Class_Lib )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Leaver_CMake PROPERTY CXX_STANDARD 20)
endif()