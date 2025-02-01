#pragma once
#include <vector>
#include <string>
#include <map>

struct SqlSelectQuery
{
	std::vector<std::string> column;
	std::string from;
	std::map<std::string, std::string> where;
};


class SqlSelectQueryBuilder
{
	SqlSelectQuery select_;

public:
	SqlSelectQueryBuilder& AddColumn(const std::string& column)
	{
		select_.column.push_back(column);
		return *this;
	}
	SqlSelectQueryBuilder& AddFrom(const std::string& table_name)
	{
		select_.from = table_name;
		return *this;
	}
	SqlSelectQueryBuilder& AddWhere(const std::string& column_name, const std::string& value)
	{
		select_.where.emplace(column_name, value);
		return *this;
	}
	std::string BuildQuery()
	{
		if (select_.from.empty()) throw std::exception("Error: the table name is not specified");
		
		std::string resul{ "SELECT" };
		if (select_.column.empty()) resul += " *";
		else
		{
			for (auto column : select_.column)
			{
				resul += " " + column;
				if (column != select_.column.back()) resul += ",";
			}
		}
		resul += " FROM " + select_.from;
		if (!select_.where.empty())
		{
			for (const auto & criterion : select_.where)
			{
				if (criterion == *select_.where.begin()) resul += " WHERE ";
				else resul += " AND ";

				resul += criterion.first + "=" + criterion.second;
			}
		}
		return resul + ";";
	}
};

