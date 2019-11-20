#include "Factory.h"

class Business					//业务层
{
public:
	//void CreatCourse(Course c) //测试添加课程
	//{
	//	CourseDAOImpl* ptr = static_cast<CourseDAOImpl*>(Factory::GetInstance()->getDAO("course"));
	//	ptr->InsertCourse(c);
	//	delete ptr;
	//}

	void InsertReader(Reader reader)
	{
		ReaderDAOImpl* ptr = static_cast<ReaderDAOImpl*>(Factory::GetInstance()->getDAO("Reader"));
		ptr->InsertReader(reader);
		delete ptr;
	}
	void DeleteReader(string id)
	{
		ReaderDAOImpl* ptr = static_cast<ReaderDAOImpl*>(Factory::GetInstance()->getDAO("Reader"));
		ptr->DeleteReader(id);
		delete ptr;
	}
	void UpdateReader(string id, string field, string value)
	{
		ReaderDAOImpl* ptr = static_cast<ReaderDAOImpl*>(Factory::GetInstance()->getDAO("Reader"));
		ptr->UpdateReader(id, field, value);
		delete ptr;
	}
	void SearchReader(string id)
	{
		ReaderDAOImpl* ptr = static_cast<ReaderDAOImpl*>(Factory::GetInstance()->getDAO("Reader"));
		Reader temp = ptr->SearchReader(id);
		cout << temp.getusrid() << endl << temp.getpwd() << endl;
		delete ptr;
	}
};

int main()
{
	Business bus;
	//测试，添加一条记录
	/*Course c1("K001", "计算机图形学", 2.5, 40, "胡晶晶");
	bus.CreatCourse(c1);*/



	AfxDaoTerm();			//程序必须在结束前调用这个函数
	return 0;
}