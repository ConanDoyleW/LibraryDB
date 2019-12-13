#include "DAO.h"

class Manager
{
private:
	string usrid;
	string pwd;
public:
	Manager() {};
	Manager(string id, string pw);
	string getusrid();
	string getpwd();
	void setusrid(string id);
	void setpwd(string pw);
};

class ManagerDAO
{
public:
	virtual void InsertManager(Manager manager) = 0;
	virtual void DeleteManager(string id) = 0;
	virtual void UpdateManager(string id, string field, string value) = 0;
	virtual Manager SearchManager(string id) = 0;
};

class ManagerDAOImpl : public ManagerDAO, public DAObase
{
public:
	void InsertManager(Manager manager);
	void DeleteManager(string id);
	void UpdateManager(string id, string field, string value);
	Manager SearchManager(string id);
};
