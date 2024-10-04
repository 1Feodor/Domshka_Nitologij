project ("List_class")
# Добавьте источник в исполняемый файл этого проекта.
set (List_Lib "List_class.h" "List_class.cpp")
add_library (List_Class_Lib STATIC ${List_Lib})
