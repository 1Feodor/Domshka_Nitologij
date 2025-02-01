#include <iostream>
#include <Windows.h>
#include "SqlSelectQueryBuilder_advanced.h"


int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	
	SqlSelectQueryBuilder query_builder;
	query_builder.AddColumn("name");
	query_builder.AddFrom("students");
	query_builder.AddWhere("id", "42");
	query_builder.AddWhere(std::map<std::string, std::string>{ {"name_id", "11"}, { "name", "John" } });
	query_builder.AddColumns(std::vector<std::string>{ "id","phone" });

	std::cout << query_builder.BuildQuery() << std::endl;
	return 0;
}