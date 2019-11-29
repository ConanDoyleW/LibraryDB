#include "DAO.h"
#include <vector>
class Book
{
private:
	string name;
	string topic;
	string isbnAndPrice;
	string indexNumber;
	string publishInfo;
	string cnLibClass;
	string personInCharge;
	string subPersonInCharge;
	string carrierShapeItem;
public:
	Book();
	Book(string name, string topic, string isbnAndPrice, string indexNumber, string publishInfo,
		string cnLibClassm, string personInCharge, string subPersonInCharge, string carrierShapeItem);
	void setName(string name)
	{
		this->name = name;
	}
	void setTopic(string topic)
	{
		this->topic = topic;
	}
	void setIsbnAndPrice(string isbnAndPrice)
	{
		this->isbnAndPrice = isbnAndPrice;
	}
	void setIndexNumber(string indexNumber)
	{
		this->indexNumber = indexNumber;
	}
	void setPublishInfo(string publishInfo)
	{
		this->publishInfo = publishInfo;
	}
	void setCnLibClass(string cnLibClass)
	{
		this->cnLibClass = cnLibClass;
	}
	void setPersonInCharge(string personInCharge)
	{
		this->personInCharge = personInCharge;
	}
	void setSubPersonInCharge(string subPersonInCharge)
	{
		this->subPersonInCharge = subPersonInCharge;
	}
	void setCarrierShapeItem(string carrierShapeItem)
	{
		this->carrierShapeItem = carrierShapeItem;
	}
	string getName()
	{
		return name;
	}
	string getTopic()
	{
		return topic;
	}
	string getIsbnAndPrice()
	{
		return isbnAndPrice;
	}
	string getIndexNumber()
	{
		return indexNumber;
	}
	string getPublishInfo()
	{
		return publishInfo;
	}
	string getCnLibClass()
	{
		return cnLibClass;
	}
	string getPersonInCharge()
	{
		return personInCharge;
	}
	string getSubPersonInCharge()
	{
		return subPersonInCharge;
	}
	string getCarrierShapeItem()
	{
		return carrierShapeItem;
	}
};

class BookDAO
{
	virtual void InsertBook(Book book) = 0;
	virtual void DeleteBook(string id) = 0;
	virtual void UpdateBook(string id, string field, string value) = 0;
	virtual vector<Book> SearchBook(string id) = 0;
};

class BookDAOImpl : public BookDAO, public DAObase
{
	void InsertBook(Book book);
	void DeleteBook(string id);
	void UpdateBook(string id, string field, string value);
	vector<Book> SearchBook(string id);
};
