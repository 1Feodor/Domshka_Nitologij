#include "Class_Domain_error.h"

Domain_error::Domain_error(const char* ddd)
{
	throw std::domain_error{ ddd };
}

Domain_error::~Domain_error()
{
}