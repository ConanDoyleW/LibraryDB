#include "Business.h"

void Business::InsertReader(Reader reader)
{
	ReaderDAOImpl* ptr = static_cast<ReaderDAOImpl*>(Factory::GetInstance()->getDAO("Reader"));
	ptr->InsertReader(reader);
	delete ptr;
}
void Business::DeleteReader(string id)
{
	ReaderDAOImpl* ptr = static_cast<ReaderDAOImpl*>(Factory::GetInstance()->getDAO("Reader"));
	ptr->DeleteReader(id);
	delete ptr;
}
void Business::UpdateReader(string id, string field, string value)
{
	ReaderDAOImpl* ptr = static_cast<ReaderDAOImpl*>(Factory::GetInstance()->getDAO("Reader"));
	ptr->UpdateReader(id, field, value);
	delete ptr;
}
Reader Business::SearchReader(string id)
{
	ReaderDAOImpl* ptr = static_cast<ReaderDAOImpl*>(Factory::GetInstance()->getDAO("Reader"));
	Reader temp = ptr->SearchReader(id);
	delete ptr;
	return temp;
}

void Business::InsertManager(Manager manager)
{
	ManagerDAOImpl* ptr = static_cast<ManagerDAOImpl*>(Factory::GetInstance()->getDAO("Manager"));
	ptr->InsertManager(manager);
	delete ptr;
}
void Business::DeleteManager(string id)
{
	ManagerDAOImpl* ptr = static_cast<ManagerDAOImpl*>(Factory::GetInstance()->getDAO("Manager"));
	ptr->DeleteManager(id);
	delete ptr;
}
void Business::UpdateManager(string id, string field, string value)
{
	ManagerDAOImpl* ptr = static_cast<ManagerDAOImpl*>(Factory::GetInstance()->getDAO("Manager"));
	ptr->UpdateManager(id, field, value);
	delete ptr;
}
Manager Business::SearchManager(string id)
{
	ManagerDAOImpl* ptr = static_cast<ManagerDAOImpl*>(Factory::GetInstance()->getDAO("Manager"));
	Manager temp = ptr->SearchManager(id);
	delete ptr;
	return temp;
}

void Business::InsertBorrowRecord(BorrowRecord br)
{
	BorrowRecordDAOImpl* ptr = static_cast<BorrowRecordDAOImpl*>(Factory::GetInstance()->getDAO("BR"));
	ptr->InsertBorrowRecord(br);
	delete ptr;
}
void Business::DeleteBorrowRecord(string cnum, string barcode)
{
	BorrowRecordDAOImpl* ptr = static_cast<BorrowRecordDAOImpl*>(Factory::GetInstance()->getDAO("BR"));
	ptr->DeleteBorrowRecord(cnum, barcode);
	delete ptr;
}
void Business::UpdateBorrowRecord(string cnum, string barcode, string field, string value)
{
	BorrowRecordDAOImpl* ptr = static_cast<BorrowRecordDAOImpl*>(Factory::GetInstance()->getDAO("BR"));
	ptr->UpdateBorrowRecord(cnum, barcode, field, value);
	delete ptr;
}
vector<BorrowRecord> Business::SearchBorrowRecord(string par, string mode)
{
	BorrowRecordDAOImpl* ptr = static_cast<BorrowRecordDAOImpl*>(Factory::GetInstance()->getDAO("BR"));
	vector<BorrowRecord> temp = ptr->SearchBorrowRecord(par, mode);
	delete ptr;
	return temp;
}

void Business::InsertBook(Book book)
{
	BookDAOImpl* ptr = static_cast<BookDAOImpl*>(Factory::GetInstance()->getDAO("Book"));
	ptr->InsertBook(book);
	delete ptr;
}
void Business::DeleteBook(string id)
{
	BookDAOImpl* ptr = static_cast<BookDAOImpl*>(Factory::GetInstance()->getDAO("Book"));
	ptr->DeleteBook(id);
	delete ptr;
}
void Business::UpdateBook(string id, string field, string value)
{
	BookDAOImpl* ptr = static_cast<BookDAOImpl*>(Factory::GetInstance()->getDAO("Book"));
	ptr->UpdateBook(id, field, value);
	delete ptr;
}
vector<Book*> Business::SearchBook(string par, string mode)
{
	BookDAOImpl* ptr = static_cast<BookDAOImpl*>(Factory::GetInstance()->getDAO("Book"));
	vector<Book*> temp = ptr->SearchBook(par, mode);
	delete ptr;
	return temp;
}

void Business::InsertComment(Comment comment)
{
	CommentDAOImpl* ptr = static_cast<CommentDAOImpl*>(Factory::GetInstance()->getDAO("Comment"));
	ptr->InsertComment(comment);
	delete ptr;
}
void Business::DeleteComment(string isbn, string cnum)
{
	CommentDAOImpl* ptr = static_cast<CommentDAOImpl*>(Factory::GetInstance()->getDAO("Comment"));
	ptr->DeleteComment(isbn, cnum);
	delete ptr;
}
void Business::UpdateComment(string isbn, string cnum, string field, string value)
{
	CommentDAOImpl* ptr = static_cast<CommentDAOImpl*>(Factory::GetInstance()->getDAO("Comment"));
	ptr->UpdateComment(isbn, cnum, field, value);
	delete ptr;
}
vector<Comment> Business::SearchComment(string par, string mode)
{
	CommentDAOImpl* ptr = static_cast<CommentDAOImpl*>(Factory::GetInstance()->getDAO("Comment"));
	vector<Comment> temp = ptr->SearchComment(par, mode);
	delete ptr;
	return temp;
}

void Business::InsertEachBook(EachBook ebook)
{
	EachBookDAOImpl* ptr = static_cast<EachBookDAOImpl*>(Factory::GetInstance()->getDAO("EachBook"));
	ptr->InsertBook(ebook);
	delete ptr;
}
void Business::DeleteEachBook(string id)
{
	EachBookDAOImpl* ptr = static_cast<EachBookDAOImpl*>(Factory::GetInstance()->getDAO("EachBook"));
	ptr->DeleteBook(id);
	delete ptr;
}
void Business::UpdateEachBook(string id, string field, string value)
{
	EachBookDAOImpl* ptr = static_cast<EachBookDAOImpl*>(Factory::GetInstance()->getDAO("EachBook"));
	ptr->UpdateBook(id, field, value);
	delete ptr;
}
vector<EachBook*> Business::SearchEachBook(string par, string mode)
{
	EachBookDAOImpl* ptr = static_cast<EachBookDAOImpl*>(Factory::GetInstance()->getDAO("EachBook"));
	vector<EachBook*> temp = ptr->SearchBook(par, mode);
	delete ptr;
	return temp;
}