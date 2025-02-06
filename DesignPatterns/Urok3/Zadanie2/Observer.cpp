#include <iostream>
#include<fstream>
#include <string>
#include <Windows.h>
#include <vector>

class Observer {
	std::string file_name;
public:
	Observer(const std::string& file_name = "test_message.txt") : file_name{ file_name } {}
	virtual void onWarning(const std::string& message) = 0;
	virtual void onError(const std::string& message) = 0;
	virtual void onFatalError(const std::string& message) = 0;
	void print_file(const std::string& message)
	{
		std::ofstream myFile(this->file_name, std::ios::app);

		if (!myFile.is_open()) throw std::exception("File opening error!");
		else myFile << message << std::endl;

		myFile.close();
	}
};

class WarningMessage
{
	std::vector<Observer*> _followers_;
public:
	void warning(const std::string& message) const
	{
		this->notify_onWarning(message);
	}

	void error(const std::string& message) const
	{
		this->notify_onError(message);
	}

	void fatalError(const std::string& message) const
	{
		this->notify_onFatalError(message);
	}

	void add_observer(Observer* follower)
	{
		this->_followers_.push_back(follower);
	}

	void remove_observer(Observer* follower)
	{
		auto it{ std::remove(this->_followers_.begin(), this->_followers_.end(), follower) };
		this->_followers_.erase(it, this->_followers_.end());
	}

	void notify_onWarning(const std::string& message) const
	{
		for (auto follower: this->_followers_)
		{
			follower->onWarning(message);
		}
	}

	void notify_onError(const std::string& message) const
	{
		for (auto follower : this->_followers_)
		{
			follower->onError(message);
		}
	}

	void notify_onFatalError(const std::string& message) const
	{
		for (auto follower : this->_followers_)
		{
			follower->onFatalError(message);
		}
	}
};

class ConsoleObserver : public Observer
{
public:
	void onWarning(const std::string& message) override
	{
		std::cout << "Print message console" << std::endl;
		std::cout << message << std::endl;
	}
	void onError(const std::string& message) override {}
	void onFatalError(const std::string& message) override {}
};

class File_txt_Observer : public Observer
{
public:
	File_txt_Observer(const std::string& file_name = "test_message.txt") : Observer(file_name){}
	void onWarning(const std::string& message) override {}
	void onError(const std::string& message) override
	{
		if (false)
		{
			this->print_file(message);
		}
		else
		{
			std::cout << "Print message file" << std::endl;
			std::cout << message << std::endl;
		}
	}
	void onFatalError(const std::string& message) override {}
};

class File_Console_Observer : public Observer
{
public:
	File_Console_Observer(const std::string& file_name = "test_message_Fatal.txt") : Observer(file_name) {}
	void onWarning(const std::string& message) override {}
	void onError(const std::string& message) override {}
	void onFatalError(const std::string& message) override	
	{
		std::cout << "Print message console and file" << std::endl;
		std::cout << message << std::endl;
		if (false)
		{
			this->print_file(message);
		}
	}	
};

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	WarningMessage WM;

	ConsoleObserver CO;
	File_txt_Observer FO;
	File_Console_Observer FCO;

	WM.add_observer(&CO);
	WM.add_observer(&FO);
	WM.add_observer(&FCO);

	WM.warning("Warning...!");
	WM.error("Error...!!");
	WM.fatalError("Fatal Error...!!!");
	std::cout << std::endl;

	return 0;
}