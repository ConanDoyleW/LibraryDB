#include "DAO.h"

class Course			//定义课程对象
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

class CourseDAO			//课程DAO对象
{
public:
	virtual void InsertCourse(Course course) = 0;				//数据操作方法
};

class CourseDAOImpl : public CourseDAO, public DAObase			//课程DAO实现对象
{
public:
	void InsertCourse(Course course);
};