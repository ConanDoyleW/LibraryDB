#include "Factory.h"

Factory* Factory::GetInstance()
{
	static Factory Instance;
	return &Instance;
}
DAObase* Factory::getDAO(string type)
{
	DAObase* DAO = NULL;
	if (type == "Reader")
	{
		DAO = new ReaderDAOImpl();
	}
	else if (type == "BR")
	{
		DAO = new BorrowRecordDAOImpl();
	}
	else if (type == "Book")
	{
		DAO = new BookDAOImpl();
	}
	else if (type == "Comment")
	{
		DAO = new CommentDAOImpl();
	}
	else if (type == "Manager")
	{
		DAO = new ManagerDAOImpl();
	}
	else if (type == "EachBook")
	{
		DAO = new EachBookDAOImpl();
	}
	/*else if(){}*/

	return DAO;
}
