#pragma once
#include "Factory.h"

static class Business					//ҵ���
{
public:
	//�����û�
	static void InsertReader(Reader reader);		//�����û�
	static void DeleteReader(string id);			//ɾ���û�
	static void UpdateReader(string id, string field, string value);		//�����û�
	static Reader SearchReader(string id);			//�����û�
	//����Ա
	static void InsertManager(Manager manager);
	static void DeleteManager(string id);
	static void UpdateManager(string id, string field, string value);
	static Manager SearchManager(string id);
	//���ļ�¼
	static void InsertBorrowRecord(BorrowRecord br);
	static void DeleteBorrowRecord(string cnum, string barcode);
	static void UpdateBorrowRecord(string cnum, string barcode, string field, string value);
	static vector<BorrowRecord> SearchBorrowRecord(string par, string mode);	//��modeģʽ��������par
	//�鼮(��)
	static void InsertBook(Book book);
	static void DeleteBook(string id);
	static void UpdateBook(string id, string field, string value);
	static vector<Book*> SearchBook(string par, string mode);
	//����
	static void InsertComment(Comment comment);
	static void DeleteComment(string isbn, string cnum);
	static void UpdateComment(string isbn, string cnum, string field, string value);
	static vector<Comment> SearchComment(string par, string mode);
	//�鼮(��)
	static void InsertEachBook(EachBook book);
	static void DeleteEachBook(string id);
	static void UpdateEachBook(string id, string field, string value);
	static vector<EachBook*> SearchEachBook(string par, string mode);
};