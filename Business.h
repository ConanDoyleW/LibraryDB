#pragma once
#include "Factory.h"

static class Business					//业务层
{
public:
	//借阅用户
	static void InsertReader(Reader reader);		//插入用户
	static void DeleteReader(string id);			//删除用户
	static void UpdateReader(string id, string field, string value);		//更新用户
	static Reader SearchReader(string id);			//搜索用户
	//管理员
	static void InsertManager(Manager manager);
	static void DeleteManager(string id);
	static void UpdateManager(string id, string field, string value);
	static Manager SearchManager(string id);
	//借阅记录
	static void InsertBorrowRecord(BorrowRecord br);
	static void DeleteBorrowRecord(string cnum, string barcode);
	static void UpdateBorrowRecord(string cnum, string barcode, string field, string value);
	static vector<BorrowRecord> SearchBorrowRecord(string par, string mode);	//以mode模式搜索参数par
	//书籍(部)
	static void InsertBook(Book book);
	static void DeleteBook(string id);
	static void UpdateBook(string id, string field, string value);
	static vector<Book*> SearchBook(string par, string mode);
	//评论
	static void InsertComment(Comment comment);
	static void DeleteComment(string isbn, string cnum);
	static void UpdateComment(string isbn, string cnum, string field, string value);
	static vector<Comment> SearchComment(string par, string mode);
	//书籍(本)
	static void InsertEachBook(EachBook book);
	static void DeleteEachBook(string id);
	static void UpdateEachBook(string id, string field, string value);
	static vector<EachBook*> SearchEachBook(string par, string mode);
};
