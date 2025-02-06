#include <iostream>
#include<fstream>
#include <string>
#include <Windows.h>
#include <vector>

class Warnings_and_Errors
{
public:
	virtual void warning_message(Warnings_and_Errors& handler, const std::string& message) = 0;
	virtual void set_next_handler(Warnings_and_Errors* handler) = 0;
};

class Warning_message : public Warnings_and_Errors
{
	Warnings_and_Errors* next_handler_ptr = nullptr;
public:
	void set_next_handler(Warnings_and_Errors* handler) override
	{
		this->next_handler_ptr = handler;
	}

	void warning_message(Warnings_and_Errors& handler, const std::string& message) override
	{
		if (typeid(Warning_message) == typeid(handler))
		{
			std::cout << message << std::endl;
		}
		else if (next_handler_ptr != nullptr)
		{
			next_handler_ptr->warning_message(handler, message);
		}
	}
};

class Error_message : public Warnings_and_Errors
{
	std::string file_name;
	Warnings_and_Errors* next_handler_ptr = nullptr;
public:
	Error_message(const std::string& file_name = "test_message.txt") : file_name{ file_name } {}

	void set_next_handler(Warnings_and_Errors* handler) override
	{
		this->next_handler_ptr = handler;
	}

	void warning_message(Warnings_and_Errors& handler, const std::string& message) override
	{
		if (typeid(Error_message) == typeid(handler))
		{
			std::ofstream myFile(this->file_name, std::ios::app);

			if (!myFile.is_open()) throw std::exception("File opening error!");
			else myFile << message << std::endl;

			myFile.close();
		}
		else if (next_handler_ptr != nullptr)
		{
			next_handler_ptr->warning_message(handler, message);
		}
	}
};

class FatalError_message : public Warnings_and_Errors
{
	Warnings_and_Errors* next_handler_ptr = nullptr;
public:
	void set_next_handler(Warnings_and_Errors* handler) override
	{
		this->next_handler_ptr = handler;
	}

	void warning_message(Warnings_and_Errors& handler, const std::string& message) override
	{
		if (typeid(FatalError_message) == typeid(handler))
		{
			throw std::exception(message.c_str());
		}
		else if (next_handler_ptr != nullptr)
		{
			next_handler_ptr->warning_message(handler, message);
		}
	}
};

class Unknown_type : public Warnings_and_Errors
{
public:
	void set_next_handler(Warnings_and_Errors* handler) override{}

	void warning_message(Warnings_and_Errors& handler, const std::string& message) override
	{
		throw std::exception("Unknown message. Impossible to process.");
	}
};

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	Warning_message warning;
	Error_message error;
	FatalError_message fatalError;
	Unknown_type unknownType;

	fatalError.set_next_handler(&error);
	error.set_next_handler(&warning);
	warning.set_next_handler(&unknownType);

	try
	{
		fatalError.warning_message(warning, "Alarm! I'm just learning.");
	}
	catch (const std::exception& err)
	{
		std::cout << err.what() << std::endl;
	}
	return 0;
}