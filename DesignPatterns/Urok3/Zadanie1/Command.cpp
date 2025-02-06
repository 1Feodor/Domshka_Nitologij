#include <iostream>
#include<fstream>
#include <string>
#include <vector>
#include <Windows.h>


class LogCommand {
public:
	virtual ~LogCommand() = default;
	virtual void print(const std::string& message) = 0;
};

class ConsoleCommand : public LogCommand
{
public:
	void print(const std::string& message) override
	{
		std::cout << message << std::endl;
	}
};

class File_txt_Command : public LogCommand
{
	std::string file_name;
public:
	File_txt_Command(const std::string& file_name = "test_message.txt") : file_name{ file_name } {}

	void print(const std::string& message) override
	{
		std::ofstream myFile(this->file_name, std::ios::app);

		if (!myFile.is_open()) throw std::exception("File opening error!");
		else myFile << message << std::endl;

		myFile.close();
	}
};


void print(LogCommand& command)
	{
	command.print("Hello world");
	}


int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	ConsoleCommand printConsole;
	File_txt_Command printFile;
	print(printConsole);
	//print(printFile);  // создаст файл "test_message.txt" в папке с программой
	std::cout << std::endl;

	return 0;
}