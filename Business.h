#include "Factory.h"

class Business					//业务层
{
public:
	//借阅用户
	void InsertReader(Reader reader);		//插入用户
	void DeleteReader(string id);			//删除用户
	void UpdateReader(string id, string field, string value);		//更新用户
	Reader SearchReader(string id);			//搜索用户
	//管理员
	void InsertManager(Manager manager);
	void DeleteManager(string id);
	void UpdateManager(string id, string field, string value);
	Manager SearchManager(string id);
	//借阅记录
	void InsertBorrowRecord(BorrowRecord br);
	void DeleteBorrowRecord(string cnum, string barcode);
	void UpdateBorrowRecord(string cnum, string barcode, string field, string value);
	vector<BorrowRecord> SearchBorrowRecord(string par, string mode);	//以mode模式搜索参数par
	//书籍(部)
	void InsertBook(Book book);
	void DeleteBook(string id);
	void UpdateBook(string id, string field, string value);
	vector<Book> SearchBook(string par, string mode);
	//评论
	void InsertComment(Comment comment);
	void DeleteComment(string isbn, string cnum);
	void UpdateComment(string isbn, string cnum, string field, string value);
	vector<Comment> SearchComment(string par, string mode);
	//书籍(本)
	void InsertEachBook(EachBook book);
	void DeleteEachBook(string id);
	void UpdateEachBook(string id, string field, string value);
	vector<EachBook> SearchEachBook(string par, string mode);
};
