#include "Factory.h"

class Business					//ҵ���
{
public:
	//void CreatCourse(Course c) //������ӿγ�
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
	//���ԣ����һ����¼
	/*Course c1("K001", "�����ͼ��ѧ", 2.5, 40, "������");
	bus.CreatCourse(c1);*/



	AfxDaoTerm();			//��������ڽ���ǰ�����������
	return 0;
}