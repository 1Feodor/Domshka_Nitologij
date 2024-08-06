project ("Figures_Infos")

include_directories ("../Figure_Class")

add_executable (Figures_Infos "Figures_ Info2.cpp" )

target_link_libraries ( Figures_Infos Figure_Class_Lib )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Figures_Infos PROPERTY CXX_STANDARD 20)
endif()