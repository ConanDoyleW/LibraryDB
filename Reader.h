#include "DAO.h"

class Reader
{
private:
	string usrid;
	string pwd;
public:
	Reader() {};
	Reader(string id, string pw);
	string getusrid();
	string getpwd();
	void setusrid(string id);
	void setpwd(string pw);
};

class ReaderDAO
{
public:
	virtual void InsertReader(Reader reader) = 0;
	virtual void DeleteReader(string id) = 0;
	virtual void UpdateReader(string id, string field, string value) = 0;
	virtual Reader SearchReader(string id) = 0;
};

class ReaderDAOImpl : public ReaderDAO, public DAObase
{
public:
	void InsertReader(Reader reader);
	void DeleteReader(string id);
	void UpdateReader(string id, string field, string value);
	Reader SearchReader(string id);
};