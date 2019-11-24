#include "EachBook.h"	 /*****请仿照Course，实现书籍(本)表的增删改查DAO操作*****/

void EachBookDAOImpl::InsertBook(EachBook book)
{
	CDaoDatabase* conn = Getconnection();
	CString sql;
	sql.Format("insert into pbook values('%s','%s','%s','%s','%s','%s')",
		book.getIndexNum().c_str,book.getIsbnAndPrice().c_str(),
		book.getBarCode().c_str(),book.getVolume().c_str(),
		book.getLocation().c_str(),book.getStatus().c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}

void EachBookDAOImpl::DeleteBook(string id)
{
	CDaoDatabase* conn = Getconnection();
	CString sql;
	sql.Format("delete from pbook where barcode = '%s'", id.c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}

void EachBookDAOImpl::UpdateBook(string id, string field, string value)
{
	CDaoDatabase* conn = Getconnection();
	CString sql;
	sql.Format("update pbook set %s = '%s' where barcode = '%s'", field.c_str(),
		value.c_str(), id.c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}

vector<EachBook> EachBookDAOImpl::SearchBook(string id)
{
	CDaoDatabase* conn = Getconnection();
	CDaoRecordset rs(conn);
	EachBook book;
	CString sql;
	sql.Format("select * from pbook where barcode= '%s'", id.c_str());
	vector<EachBook> v = vector<EachBook>();
	rs.Open(AFX_DAO_USE_DEFAULT_TYPE, sql, dbSeeChanges);
	if (rs.IsEOF())
		;
	else
	{
		while (true)
		{
			COleVariant value;
			rs.GetFieldValue("callnum", value);
			book.setIndexNum((LPCTSTR)value.pbstrVal);
			rs.GetFieldValue("isbnprice", value);
			book.setIsbnAndPrice((LPCTSTR)value.pbstrVal);
			rs.GetFieldValue("barcode", value);
			book.setBarCode((LPCTSTR)value.pbstrVal);
			rs.GetFieldValue("volumeissue", value);
			book.setVolume((LPCTSTR)value.pbstrVal);
			rs.GetFieldValue("collect", value);
			book.setLocation((LPCTSTR)value.pbstrVal);
			rs.GetFieldValue("bookcond", value);
			book.setStatus((LPCTSTR)value.pbstrVal);
			v.push_back(book);
			rs.MoveNext();
		}
	}
	conn->Close();
	rs.Close();
	delete conn;
	return v;
}
