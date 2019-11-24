#include "DAO.h"

class EachBook
{
private:
	string indexNum;
	string isbnAndPrice;
	string barCode;
	string volume;
	string location;
	string status;
public:
	string getIndexNum()
	{
		return indexNum;
	}
	string getIsbnAndPrice()
	{
		return isbnAndPrice;
	}
	string getBarCode()
	{
		return barCode;
	}
	string getVolume()
	{
		return volume;
	}
	string getLocation()
	{
		return location;
	}
	string getStatus()
	{
		return status;
	}
	void setIndexNum(string indexNum)
	{
		this->indexNum = indexNum;
	}
	void setIsbnAndPrice(string isbnAndPrice)
	{
		this->isbnAndPrice = isbnAndPrice;
	}
	void setBarCode(string barCode)
	{
		this->barCode = barCode;
	}
	void setVolume(string volume)
	{
		this->volume = volume;
	}
	void setLocation(string location)
	{
		this->location = location;
	}
	void setStatus(string status)
	{
		this->status = status;
	}
};

class EachBookDAO
{
	virtual void InsertBook(EachBook book) = 0;
	virtual void DeleteBook(string id) = 0;
	virtual void UpdateBook(string id, string field, string value) = 0;
	virtual EachBook SearchBook(string id) = 0;
};

class EachBookDAOImpl : public EachBookDAO, public DAObase
{
	void InsertBook(EachBook book);
	void DeleteBook(string id) = 0;
	void UpdateBook(string id, string field, string value) = 0;
	EachBook SearchBook(string id) = 0;
};