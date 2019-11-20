#include "DAO.h"

class Course			//����γ̶���
{
private:
	string cnum;
	string cname;
	float credit;
	int period;
	string tname;
public:
	Course() {};
	Course(string cnu, string cna, float cre, int per, string tna);
	string getcnum();
	string getcname();
	float getcredit();
	int getperiod();
	string gettname();

	void setcnum(string cnu);
	void setcname(string cna);
	void setcredit(float cre);
	void setperiod(int per);
	void settname(string tna);
};

class CourseDAO			//�γ�DAO����
{
public:
	virtual void InsertCourse(Course course) = 0;				//���ݲ�������
};

class CourseDAOImpl : public CourseDAO, public DAObase			//�γ�DAOʵ�ֶ���
{
public:
	void InsertCourse(Course course);
};