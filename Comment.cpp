#include "Comment.h"	/*****�����Course���������ݿ⣬ʵ�����۱�����ɾ�Ĳ�DAO����*****/

void CommentDAOImpl::InsertComment(Comment comment)
{
	CDaoDatabase* conn = Getconnection();
	CString sql;
	sql.Format("insert into BOOKHAVECOMMENTS(ISBNPRICE,COM,CNUM) values('%s','%s','%s')",
		comment.getISBNprice().c_str(), comment.getCom().c_str(),
		comment.getCnum().c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}

void CommentDAOImpl::DeleteComment(string ISBNprice, string cnum)
{
	CDaoDatabase* conn = Getconnection();
	CString sql;
	sql.Format("delete from BOOKHAVECOMMENTS where ISBNPRICE = '%s' and CNUM = '%s'", ISBNprice.c_str(),cnum.c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}

void CommentDAOImpl::UpdateComment(string ISBNprice, string cnum, string field, string value)
{
	CDaoDatabase* conn = Getconnection();
	CString sql;
	sql.Format("update BOOKHAVECOMMENTS set %s = '%s' where  ISBNPRICE = '%s' and CNUM = '%s'", field.c_str(),
		value.c_str(), ISBNprice.c_str(), cnum.c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}

vector<Comment> CommentDAOImpl::SearchComment(string ISBNprice, string cnum)
{
	CDaoDatabase* conn = Getconnection();
	CDaoRecordset rs(conn);
	Comment comment;
	CString sql;
	sql.Format("select * from BOOKHAVECOMMENTS where ISBNPRICE = '%s' and CNUM = '%s'", ISBNprice.c_str(), cnum.c_str());
	vector<Comment> v = vector<Comment>();
	rs.Open(AFX_DAO_USE_DEFAULT_TYPE, sql, dbSeeChanges);

	COleVariant value;
	rs.GetFieldValue("ISBNPRICE", value);
	comment.setISBNprice((LPCTSTR)value.pbstrVal);
	rs.GetFieldValue("COM", value);
	comment.setCom((LPCTSTR)value.pbstrVal);
	rs.GetFieldValue("CNUM", value);
	comment.setCnum((LPCTSTR)value.pbstrVal);
	v.push_back(comment);
	rs.MoveNext();
	conn->Close();
	rs.Close();
	delete conn;
	return v;
}
