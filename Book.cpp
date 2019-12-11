#include "Book.h"	 /*****请仿照Course并参照数据库，实现书籍(部)表的增删改查DAO操作*****/

void BookDAOImpl::InsertBook(Book book)
{
	CDaoDatabase* conn = Getconnection();
	CString sql;
	sql.Format("insert into pkbook values('%s','%s','%s','%s','%s','%s','%s','%s')",
		book.getName().c_str(), book.getTopic().c_str(), book.getIsbn().c_str(),
		book.getPublishInfo().c_str(), book.getCnLibClass().c_str(),
		book.getPersonInCharge().c_str(), book.getSubPersonInCharge().c_str(),
		book.getCarrierShapeItem().c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}

void BookDAOImpl::DeleteBook(string id)
{
	CDaoDatabase* conn = Getconnection();
	CString sql;
	sql.Format("delete from pkbook where isbn = '%s'", id.c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}

void BookDAOImpl::UpdateBook(string id, string field, string value)
{
	CDaoDatabase* conn = Getconnection();
	CString sql;
	sql.Format("update pkbook set %s = '%s' where isbn = '%s'", field.c_str(),
		value.c_str(), id.c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}

vector<Book> BookDAOImpl::SearchBook(string par, string mode)
{
	CDaoDatabase* conn = Getconnection();
	CDaoRecordset rs(conn);
	CString sql;
	sql.Format("select * from pkbook where %s like'%%%s%%' ", mode.c_str(), par.c_str());
	rs.Open(AFX_DAO_USE_DEFAULT_TYPE, sql, dbSeeChanges);
	vector<Book> v;
	while (!rs.IsEOF())
	{
		Book book;
		COleVariant value;
		rs.GetFieldValue("bn", value);
		book.setName((LPCTSTR)value.pbstrVal);
		rs.GetFieldValue("stheme", value);
		book.setTopic((LPCTSTR)value.pbstrVal);
		rs.GetFieldValue("isbn", value);
		book.setIsbn((LPCTSTR)value.pbstrVal);
		rs.GetFieldValue("pubitem", value);
		book.setPublishInfo((LPCTSTR)value.pbstrVal);
		rs.GetFieldValue("cpknum", value);
		book.setCnLibClass((LPCTSTR)value.pbstrVal);
		rs.GetFieldValue("privp", value);
		book.setPersonInCharge((LPCTSTR)value.pbstrVal);
		rs.GetFieldValue("privnp", value);
		book.setSubPersonInCharge((LPCTSTR)value.pbstrVal);
		rs.GetFieldValue("formitem", value);
		book.setCarrierShapeItem((LPCTSTR)value.pbstrVal);
		v.push_back(book);
		rs.MoveNext();
	}
	conn->Close();
	rs.Close();
	delete conn;
	return v;
}

Book::Book()
{
}

Book::Book(string name, string topic, string isbn, string publishInfo, string cnLibClass, string personInCharge, string subPersonInCharge, string carrierShapeItem)
{
	this->name = name;
	this->topic = topic;
	this->isbn = isbn;
	this->publishInfo = publishInfo;
	this->cnLibClass = cnLibClass;
	this->personInCharge = personInCharge;
	this->subPersonInCharge = subPersonInCharge;
	this->carrierShapeItem = carrierShapeItem;
}
