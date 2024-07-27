#pragma once
//#include <exception>
#include <stdexcept>

class Domain_error : public std::exception
{
public:
	Domain_error(const char*);
	~Domain_error();
};