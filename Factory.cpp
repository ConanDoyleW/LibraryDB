#include "Factory.h"

Factory* Factory::GetInstance()
{
	static Factory Instance;
	return &Instance;
}
DAObase* Factory::getDAO(string type)
{
	DAObase* DAO = NULL;
	if (type == "course")
	{
		DAO = new CourseDAOImpl();
	}
	else if (type == "Reader")
	{
		DAO = new ReaderDAOImpl();
	}
	/*else if(){}*/

	return DAO;
}
