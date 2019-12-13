#include "DAO.h"

class Comment
{
private:
	string isbn;
	string com;
	string cnum;
public:
	Comment() {};
	Comment(string isbn, string com, string cnum);
	string getIsbn()
	{
		return isbn;
	}
	string getCom()
	{
		return com;
	}
	string getCnum()
	{
		return cnum;
	}
	void setIsbn(string isbn)
	{
		this->isbn = isbn;
	}
	void setCom(string com)
	{
		this->com = com;
	}
	void setCnum(string cnum)
	{
		this->cnum = cnum;
	}
};

class CommentDAO
{
public:
	virtual void InsertComment(Comment comment) = 0;
	virtual void DeleteComment(string isbn, string cnum) = 0;
	virtual void UpdateComment(string isbn, string cnum, string field, string value) = 0;
	virtual vector<Comment> SearchComment(string par, string mode) = 0;
};

class CommentDAOImpl : public CommentDAO, public DAObase
{
public:
	void InsertComment(Comment comment);
	void DeleteComment(string isbn, string cnum);
	void UpdateComment(string isbn, string cnum, string field, string value);
	vector<Comment> SearchComment(string par, string mode);
};
