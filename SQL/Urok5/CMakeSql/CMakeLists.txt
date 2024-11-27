cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CMakeSql")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakeSql "CMakeSql.cpp" "CMakeSql.h" "Class_Persons.cpp")
add_subdirectory("C:/Users/rozza/OneDrive/Рабочий стол/libpqxx-7.9.2" libpqxx-build)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeSql PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(CMakeSql pqxx)