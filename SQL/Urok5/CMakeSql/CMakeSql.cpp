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
		per.add_client(1, "Владислав", "Кочетков", "VladKochet@mail.ru");
		per.add_client(2, "Антон", "Ласточкин", "AntonLastoch@mail.ru");
		per.add_client(3, "Владислав", "Хорев", "VladHor@mail.ru");
		per.add_client(4, "Фёдор", "Омшев", "FedorOmsh@mail.ru");
		std::cout << "Список добавленных клиентов: " << std::endl;
		for (auto& [id, fName, lName, email] : per.find_client("select * from person;"))
		{
			std::cout << id << "\t" << fName << "\t" << lName << "\t" << email << std::endl;
		}
		//	Заполняю таблицу номеров телефонов
		per.add_phone(1, 1, "(+7)123-321-11-22");
		per.add_phone(2, 1, "(800)123-456-78-90");
		per.add_phone(3, 2, "(+7)989-454-33-21");
		per.add_phone(4, 2, "(+7)111-333-55-77");
		std::cout << "\nСписок добавленных номеров телефонов клиентов: " << std::endl;
		for (auto [id, id_person, person_phone] : per.find_phone("select * from phone;"))
		{
			std::cout << id << "\t" << id_person << "\t" << person_phone << std::endl;
		}
		//	Изменяю данные клиентов
		per.update_client(3, "ИзМеНеНияТут@mail.com");
		std::cout << "\nСписок c изменёнными данными клиентов: " << std::endl;
		for (auto& [id, fName, lName, email] : per.find_client("select * from person;"))
		{
			std::cout << id << "\t" << fName << "\t" << lName << "\t" << email << std::endl;
		}
		//	Удаляю номер телефона
		per.delete_phone("(800)123-456-78-90");
		std::cout << "\nИзменённый список номеров телефонов клиентов: " << std::endl;
		for (auto [id, id_person, person_phone] : per.find_phone("select * from phone;"))
		{
			std::cout << id << "\t" << id_person << "\t" << person_phone << std::endl;
		}
		//	Удаляю клиента
		per.delete_client(3);
		per.delete_client(2);
		std::cout << "\nСписок после удаления клиента: " << std::endl;
		for (auto& [id, fName, lName, email] : per.find_client("select * from person;"))
		{
			std::cout << id << "\t" << fName << "\t" << lName << "\t" << email << std::endl;
		}
		std::cout << "\nСписок номеров телефонов после удаления клиента: " << std::endl;
		for (auto [id, id_person, person_phone] : per.find_phone("select * from phone;"))
		{
			std::cout << id << "\t" << id_person << "\t" << person_phone << std::endl;
		}
		//	Вывожу список клиентов без номера телефона
		std::cout << "\nСписок клиентов без номера телефона: " << std::endl;
		for (auto& [id, fName, lName, email] : per.find_client(
			"select person_id, firstName, lastName, email "
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
