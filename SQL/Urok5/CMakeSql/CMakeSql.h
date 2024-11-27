#pragma once

#include <iostream>
#include <Windows.h>
#include <pqxx/pqxx>
#include <vector>

class Persons
{
public:
	Persons();
	~Persons();
	void add_client(const std::vector<std::string>&);
	void add_phone(const std::vector<std::string>&);
	void update_client(const std::vector<std::string>&);
	void delete_phone(const std::vector<std::string>&);
	void delete_client(const std::vector<std::string>&);
	pqxx::work& get();		// Каким образом реализовать метод для поика клиента по его данным
							// у меня идей нет. 
	void create_table();
	void drop_table();
private:
	pqxx::connection info_person{
		"host=localhost "
		"port=5432 "
		"dbname=customer_base "
		"user=postgres "
		"password=2345" };		//Укажите свои данные
	pqxx::work ip{ info_person };
	pqxx::result r;
};