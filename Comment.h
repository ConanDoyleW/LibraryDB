#include "DAO.h"

class Comment
{
private:
	string ISBNprice;
	string com;
	string cnum;
public:
	string getISBNprice()
	{
		return ISBNprice;
	}
	string getCom()
	{
		return com;
	}
	string getCnum()
	{
		return cnum;
	}
	void setISBNprice(string ISBNprice)
	{
		this->ISBNprice = ISBNprice;
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
	virtual void InsertComment(Comment comment) = 0;
	virtual void DeleteComment(string ISBNprice, string cnum) = 0;
	virtual void UpdateComment(string ISBNprice, string cnum, string field, string value) = 0;
	virtual vector<Comment> SearchComment(string ISBNprice, string cnum) = 0;
};

class CommentDAOImpl : public CommentDAO, public DAObase
{
	void InsertComment(Comment comment);
	void DeleteComment(string ISBNprice, string cnum);
	void UpdateComment(string ISBNprice, string cnum, string field, string value);
	vector<Comment> SearchComment(string ISBNprice, string cnum);
};
