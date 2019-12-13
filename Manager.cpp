#include "Manager.h"	/*****请仿照Course并参照数据库，实现管理员表的增删改查DAO操作*****/

Manager::Manager(string id, string pw)
{
	usrid = id;
	pwd = pw;
}
string Manager::getusrid() { return usrid; }
string Manager::getpwd() { return pwd; }
void Manager::setusrid(string id) { usrid = id; }
void Manager::setpwd(string pw) { pwd = pw; }

void ManagerDAOImpl::InsertManager(Manager manager)
{
	CDaoDatabase *conn = Getconnection();
	CString sql;
	sql.Format("insert into PERSON(CNUM,SNODE) values('%s','%s')", manager.getusrid().c_str(), manager.getpwd().c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}
void ManagerDAOImpl::DeleteManager(string id)
{
	CDaoDatabase *conn = Getconnection();
	CString sql;
	sql.Format("delete from PERSON where CNUM = '%s'", id.c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}
void ManagerDAOImpl::UpdateManager(string id, string field, string value)
{
	CDaoDatabase *conn = Getconnection();
	CString sql;
	sql.Format("update PERSON set %s = '%s' where CNUM = '%s'", field.c_str(), value.c_str(), id.c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}
Manager ManagerDAOImpl::SearchManager(string id)
{
	CDaoDatabase *conn = Getconnection();
	CDaoRecordset rs(conn);
	Manager manager;
	CString sql;
	sql.Format("select * from PERSON where CNUM = '%s'", id.c_str());
	rs.Open(AFX_DAO_USE_DEFAULT_TYPE, sql, dbSeeChanges);
	COleVariant value;
	rs.GetFieldValue("CNUM", value);
	manager.setusrid((LPCTSTR)value.pbstrVal);
	rs.GetFieldValue("SNODE", value);
	manager.setpwd((LPCTSTR)value.pbstrVal);
	conn->Close();
	rs.Close();
	delete conn;
	return manager;
}
