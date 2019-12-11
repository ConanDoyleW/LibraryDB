#include "Factory.h"

class Business					//ҵ���
{
public:
	//�����û�
	void InsertReader(Reader reader);		//�����û�
	void DeleteReader(string id);			//ɾ���û�
	void UpdateReader(string id, string field, string value);		//�����û�
	Reader SearchReader(string id);			//�����û�
	//����Ա
	void InsertManager(Manager manager);
	void DeleteManager(string id);
	void UpdateManager(string id, string field, string value);
	Manager SearchManager(string id);
	//���ļ�¼
	void InsertBorrowRecord(BorrowRecord br);
	void DeleteBorrowRecord(string cnum, string barcode);
	void UpdateBorrowRecord(string cnum, string barcode, string field, string value);
	vector<BorrowRecord> SearchBorrowRecord(string par, string mode);	//��modeģʽ��������par
	//�鼮(��)
	void InsertBook(Book book);
	void DeleteBook(string id);
	void UpdateBook(string id, string field, string value);
	vector<Book> SearchBook(string par, string mode);
	//����
	void InsertComment(Comment comment);
	void DeleteComment(string isbn, string cnum);
	void UpdateComment(string isbn, string cnum, string field, string value);
	vector<Comment> SearchComment(string par, string mode);
	//�鼮(��)
	void InsertEachBook(EachBook book);
	void DeleteEachBook(string id);
	void UpdateEachBook(string id, string field, string value);
	vector<EachBook> SearchEachBook(string par, string mode);
};
