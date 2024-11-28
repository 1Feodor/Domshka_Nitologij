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
	void add_client(const int person_Id, const std::string& firstName, const std::string& lastName, const std::string& email);
	void add_phone(const int phone_Id, const int id_person, const std::string& phoneNumber);
	void update_client(const int person_Id, const std::string& email);
	void delete_phone(const std::string& phoneNumber);
	void delete_client(const int person_Id);
	pqxx::internal::result_iteration<int, std::string, std::string, std::string> find_client(const std::string& select_from_person);
	pqxx::internal::result_iteration<int, int, std::string> find_phone(const std::string& select_from_phone);
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