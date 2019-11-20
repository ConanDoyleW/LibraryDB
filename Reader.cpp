#include "Reader.h"		/*****请仿照Course并参照数据库，实现借阅用户表的增删改查DAO操作*****/

Reader::Reader(string id, string pw)
{
	usrid = id;
	pwd = pw;
}
string Reader::getusrid() { return usrid; }
string Reader::getpwd() { return pwd; }
void Reader::setusrid(string id) { usrid = id; }
void Reader::setpwd(string pw) { pwd = pw; }

void ReaderDAOImpl::InsertReader(Reader reader)
{
	CDaoDatabase *conn = Getconnection();
	CString sql;
	sql.Format("insert into PERSON(CNUM,SNODE) values('%s','%s')",reader.getusrid().c_str(),reader.getpwd().c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}
void ReaderDAOImpl::DeleteReader(string id)
{
	CDaoDatabase *conn = Getconnection();
	CString sql;
	sql.Format("delete from PERSON where CNUM = '%s'",id.c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}
void ReaderDAOImpl::UpdateReader(string id, string field, string value)
{
	CDaoDatabase *conn = Getconnection();
	CString sql;
	sql.Format("update PERSON set %s = '%s' where CNUM = '%s'", field.c_str(), value.c_str(), id.c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}
Reader ReaderDAOImpl::SearchReader(string id)
{
	CDaoDatabase *conn = Getconnection();
	CDaoRecordset rs(conn);
	Reader reader;
	CString sql;
	sql.Format("select * from PERSON where CNUM = '%s'", id.c_str());
	rs.Open(AFX_DAO_USE_DEFAULT_TYPE, sql, dbSeeChanges);
	COleVariant value;
	rs.GetFieldValue("CNUM", value);
	reader.setusrid((LPCTSTR)value.pbstrVal);
	rs.GetFieldValue("SNODE", value);
	reader.setpwd((LPCTSTR)value.pbstrVal);
	conn->Close();
	rs.Close();
	delete conn;
	return reader;
}
