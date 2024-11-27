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

void Persons::add_client(const std::vector<std::string>& client)
{
	this->r = this->ip.exec_prepared("insert_person", client[0], client[1], client[2], client[3]);
}

void Persons::add_phone(const std::vector<std::string>& number)
{
	this->r = this->ip.exec_prepared("insert_phone", number[0], number[1], number[2]);
}

void Persons::update_client(const std::vector<std::string>& updatePerson)
{
	this->r = this->ip.exec_prepared("update_person_email", updatePerson[0], updatePerson[1]);
}

void Persons::delete_phone(const std::vector<std::string>& deletePhone)
{
	this->r = this->ip.exec_prepared("delete_phone", deletePhone[0]);
}

void Persons::delete_client(const std::vector<std::string>& deletePerson)
{
	this->r = this->ip.exec_prepared("delete_id_phone", deletePerson[0]);
	this->r = this->ip.exec_prepared("delete_person", deletePerson[0]);
}

pqxx::work& Persons::get()
{
	return this->ip;
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
