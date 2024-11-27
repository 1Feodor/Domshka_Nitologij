#include "CMakeSql.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try
	{
		Persons per;
		per.create_table();		//	Создаю таблицы
		//	Заполняю таблицу клиентов
		std::vector<std::string> str_per{ "1","Владислав","Кочетков","VladKochet@mail.ru" };
		per.add_client(str_per);
		str_per[0] = "2";
		str_per[1] = "Антон";
		str_per[2] = "Ласточкин";
		str_per[3] = "AntonLastoch@mail.ru";
		per.add_client(str_per);
		str_per[0] = "3";
		str_per[1] = "Владислав";
		str_per[2] = "Хорев";
		str_per[3] = "VladHor@mail.ru";
		per.add_client(str_per);
		str_per[0] = "4";
		str_per[1] = "Фёдор";
		str_per[2] = "Омшев";
		str_per[3] = "FedorOmsh@mail.ru";
		per.add_client(str_per);
		std::cout << "Список добавленных клиентов: " << std::endl;
		for (auto [id, fName, lName, email] : per.get().query<int, std::string, std::string, std::string>("select * from person;"))
		{
			std::cout << id << "\t" << fName << "\t" << lName << "\t" << email << std::endl;
		}
		//	Заполняю таблицу номеров телефонов
		str_per.clear();
		str_per.push_back("1");
		str_per.push_back("1");
		str_per.push_back("(+7)123-321-11-22");
		per.add_phone(str_per);
		str_per[0] = "2";
		str_per[1] = "1";
		str_per[2] = "(800)123-456-78-90";
		per.add_phone(str_per);
		str_per[0] = "3";
		str_per[1] = "2";
		str_per[2] = "(+7)989-454-33-21";
		per.add_phone(str_per);
		str_per[0] = "4";
		str_per[1] = "2";
		str_per[2] = "(+7)111-333-55-77";
		per.add_phone(str_per);
		std::cout << "\nСписок добавленных номеров телефонов клиентов: " << std::endl;
		for (auto [id, id_person, person_phone] : per.get().query<int, int, std::string>("select * from phone;"))
		{
			std::cout << id << "\t" << id_person << "\t" << person_phone << std::endl;
		}
		//	Изменяю данные клиентов
		str_per.clear();
		str_per.push_back("3");
		str_per.push_back("ИзМеНеНияТут@mail.com");
		per.update_client(str_per);
		std::cout << "\nСписок c изменёнными данными клиентов: " << std::endl;
		for (auto [id, fName, lName, email] : per.get().query<int, std::string, std::string, std::string>("select * from person;"))
		{
			std::cout << id << "\t" << fName << "\t" << lName << "\t" << email << std::endl;
		}
		//	Удаляю номер телефона
		str_per.clear();
		str_per.push_back("(800)123-456-78-90");
		per.delete_phone(str_per);
		std::cout << "\nИзменённый список номеров телефонов клиентов: " << std::endl;
		for (auto [id, id_person, person_phone] : per.get().query<int, int, std::string>("select * from phone;"))
		{
			std::cout << id << "\t" << id_person << "\t" << person_phone << std::endl;
		}
		//	Удаляю клиента
		str_per.clear();
		str_per.push_back("3");
		per.delete_client(str_per);
		str_per[0] = "2";
		per.delete_client(str_per);
		std::cout << "\nСписок после удаления клиента: " << std::endl;
		for (auto [id, fName, lName, email] : per.get().query<int, std::string, std::string, std::string>("select * from person;"))
		{
			std::cout << id << "\t" << fName << "\t" << lName << "\t" << email << std::endl;
		}
		std::cout << "\nСписок номеров телефонов после удаления клиента: " << std::endl;
		for (auto [id, id_person, person_phone] : per.get().query<int, int, std::string>("select * from phone;"))
		{
			std::cout << id << "\t" << id_person << "\t" << person_phone << std::endl;
		}
		//	Вывожу список клиентов без номера телефона
		std::cout << "\nСписок клиентов без номера телефона: " << std::endl;
		for (auto [id, fName, lName, email] : per.get().query<int, std::string, std::string, std::string>
			("select person_id, firstName, lastName, email "
			"from person p "
			"left join phone ph on p.person_id = ph.id_person "
			"where phonenumber is null;"))
		{
			std::cout << id << "\t" << fName << "\t" << lName << "\t" << email << std::endl;
		}
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
