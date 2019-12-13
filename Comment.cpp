#include "Comment.h"	/*****请仿照Course并参照数据库，实现评论表的增删改查DAO操作*****/

void CommentDAOImpl::InsertComment(Comment comment)
{
	CDaoDatabase* conn = Getconnection();
	CString sql;
	sql.Format("insert into BOOKHAVECOMMENTS(isbn,COM,CNUM) values('%s','%s','%s')",
		comment.getIsbn().c_str(), comment.getCom().c_str(),
		comment.getCnum().c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}

void CommentDAOImpl::DeleteComment(string isbn, string cnum)
{
	CDaoDatabase* conn = Getconnection();
	CString sql;
	sql.Format("delete from BOOKHAVECOMMENTS where isbn = '%s' and CNUM = '%s'", isbn.c_str(), cnum.c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}

void CommentDAOImpl::UpdateComment(string isbn, string cnum, string field, string value)
{
	CDaoDatabase* conn = Getconnection();
	CString sql;
	sql.Format("update BOOKHAVECOMMENTS set %s = '%s' where  isbn = '%s' and CNUM = '%s'", field.c_str(),
		value.c_str(), isbn.c_str(), cnum.c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}

vector<Comment> CommentDAOImpl::SearchComment(string par, string mode)
{
	CDaoDatabase* conn = Getconnection();
	CDaoRecordset rs(conn);
	CString sql;
	sql.Format("select * from BOOKHAVECOMMENTS where %s = '%s' ", mode.c_str(), par.c_str());
	vector<Comment> v = vector<Comment>();
	rs.Open(AFX_DAO_USE_DEFAULT_TYPE, sql, dbSeeChanges);
	while (!rs.IsEOF())
	{
		Comment comment;
		COleVariant value;
		rs.GetFieldValue("isbn", value);
		comment.setIsbn((LPCTSTR)value.pbstrVal);
		rs.GetFieldValue("COM", value);
		comment.setCom((LPCTSTR)value.pbstrVal);
		rs.GetFieldValue("CNUM", value);
		comment.setCnum((LPCTSTR)value.pbstrVal);
		v.push_back(comment);
		rs.MoveNext();
	}
	conn->Close();
	rs.Close();
	delete conn;
	return v;
}

Comment::Comment(string isbn, string com, string cnum)
{
	this->isbn = isbn;
	this->com = com;
	this->cnum = cnum;
}
