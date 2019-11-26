#include "DAO.h"

class BorrowRecord
{
private:
	string cnum;
	string barcode;
	COleDateTime btime;
	COleDateTime rtime;
public:
	string getCnum()
	{
		return cnum;
	}
	string getBarcode()
	{
		return barcode;
	}
	COleDateTime getBtime()
	{
		return btime;
	}
	COleDateTime getRtime()
	{
		return rtime;
	}
	void setCnum(string cnum)
	{
		this->cnum = cnum;
	}
	void setBarcode(string barcode)
	{
		this->barcode = barcode;
	}
	void setBtime(COleDateTime btime)
	{
		this->btime = btime;
	}
	void setRtime(COleDateTime rtime)
	{
		this->rtime = rtime;
	}
};

class BorrowRecordDAO
{
	virtual void InsertBorrowRecord(BorrowRecord borrowrecord) = 0;
	virtual void DeleteBorrowRecord(string cnum, string barcode) = 0;
	virtual void UpdateBorrowRecord(string cnum, string barcode, string field, string value) = 0;
	virtual vector<BorrowRecord> SearchBorrowRecord(string cnum, string barcode) = 0;
};

class BorrowRecordDAOImpl : public BorrowRecordDAO, public DAObase
{
	void InsertBorrowRecord(BorrowRecord borrowrecord) = 0;
	void DeleteBorrowRecord(string cnum, string barcode) = 0;
	void UpdateBorrowRecord(string cnum, string barcode, string field, string value) = 0;
	vector<BorrowRecord> SearchBorrowRecord(string cnum, string barcode) = 0;
};
