#include "CMakeSql.h"

Persons::Persons()
{
	this->ip.exec("SET CLIENT_ENCODING TO 'WIN1251';");
	this->info_person.prepare( "insert_person", "INSERT INTO person(person_id, firstName, lastName, email) "
												" VALUES($1, $2, $3, $4)" );
	this->info_person.prepare("insert_phone", "INSERT INTO phone(phone_id, id_person, phoneNumber) "
											  " VALUES($1, $2, $3)");
	this->info_person.prepare("update_person_email", "UPDATE person SET email = $2 WHERE person_id = $1");
	this->info_person.prepare("delete_phone", "DELETE FROM phone WHERE phoneNumber = $1");
	this->info_person.prepare("delete_id_phone", "DELETE FROM phone WHERE id_person = $1");
	this->info_person.prepare("delete_person", "DELETE FROM person WHERE person_id = $1");
}

Persons::~Persons()
{
	this->ip.commit();
	std::cout << "\nПривет CMake." << std::endl;
}

void Persons::add_client(const int person_Id, const std::string& firstName, const std::string& lastName, const std::string& email)
{
	this->r = this->ip.exec_prepared("insert_person", person_Id, firstName, lastName, email);
}

void Persons::add_phone(const int phone_Id, const int id_person, const std::string& phoneNumber)
{
	this->r = this->ip.exec_prepared("insert_phone", phone_Id, id_person, phoneNumber);
}

void Persons::update_client(const int person_Id, const std::string& email)
{
	this->r = this->ip.exec_prepared("update_person_email", person_Id, email);
}

void Persons::delete_phone(const std::string& phoneNumber)
{
	this->r = this->ip.exec_prepared("delete_phone", phoneNumber);
}

void Persons::delete_client(const int person_Id)
{
	this->r = this->ip.exec_prepared("delete_id_phone", person_Id);
	this->r = this->ip.exec_prepared("delete_person", person_Id);
}

pqxx::internal::result_iteration<int, std::string, std::string, std::string> Persons::find_client(const std::string& select_from_person)
{
	return this->ip.query<int, std::string, std::string, std::string>(select_from_person);
}

pqxx::internal::result_iteration<int, int, std::string> Persons::find_phone(const std::string& select_from_phone)
{
	return this->ip.query<int, int, std::string>(select_from_phone);
}

void Persons::create_table()
{
	this->r = this->ip.exec("CREATE TABLE if NOT EXISTS person "
							"(person_Id SERIAL PRIMARY KEY, "
							"firstName VARCHAR(60) NOT NULL, "
							"lastName VARCHAR(60) NOT NULL, "
							"email VARCHAR(60) NOT NULL);");

	this->r = this->ip.exec("CREATE TABLE if NOT EXISTS phone "
							"(phone_Id SERIAL PRIMARY KEY, "
							"id_person INTEGER NOT NULL references person(person_Id), "
							"phoneNumber VARCHAR(60) not null);");
}

void Persons::drop_table()
{
	this->r = this->ip.exec("DROP TABLE person;");
	this->r = this->ip.exec("DROP TABLE phone;");
}
