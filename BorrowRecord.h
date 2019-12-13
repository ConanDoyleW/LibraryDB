#include "DAO.h"

class BorrowRecord
{
private:
	string cnum;
	string barcode;
	string btime;
	string rtime;
public:
	string getCnum()
	{
		return cnum;
	}
	string getBarcode()
	{
		return barcode;
	}
	string getBtime()
	{
		return btime;
	}
	string getRtime()
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
	void setBtime(string btime)
	{
		this->btime = btime;
	}
	void setRtime(string rtime)
	{
		this->rtime = rtime;
	}
	BorrowRecord() {};
	BorrowRecord(string cnum, string barcode, string btime, string rtime);
};

class BorrowRecordDAO
{
public:
	virtual void InsertBorrowRecord(BorrowRecord borrowrecord) = 0;
	virtual void DeleteBorrowRecord(string cnum, string barcode) = 0;
	virtual void UpdateBorrowRecord(string cnum, string barcode, string field, string value) = 0;
	virtual vector<BorrowRecord> SearchBorrowRecord(string par, string mode) = 0;
};

class BorrowRecordDAOImpl : public BorrowRecordDAO, public DAObase
{
public:
	void InsertBorrowRecord(BorrowRecord borrowrecord);
	void DeleteBorrowRecord(string cnum, string barcode);
	void UpdateBorrowRecord(string cnum, string barcode, string field, string value);
	vector<BorrowRecord> SearchBorrowRecord(string par, string mode);
};
