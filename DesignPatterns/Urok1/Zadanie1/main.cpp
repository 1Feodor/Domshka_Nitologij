#include <iostream>
#include <Windows.h>
#include "SqlSelectQueryBuilder.h"


int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	SqlSelectQueryBuilder query_builder;
	query_builder.AddColumn("name").AddColumn("phone");
	query_builder.AddFrom("students");
	query_builder.AddWhere("id", "42").AddWhere("name", "John");
	
	std::cout << query_builder.BuildQuery() << std::endl;
	return 0;
}