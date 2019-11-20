#include "Course.h"

Course::Course(string cnu, string cna, float cre, int per, string tna)
{
	cnum = cnu;
	cname = cna;
	credit = cre;
	period = per;
	tname = tna;
}
string Course::getcnum() { return cnum; }
string Course::getcname() { return cname; }
float Course::getcredit() { return credit; }
int Course::getperiod() { return period; }
string Course::gettname() { return tname; }
void Course::setcnum(string cnu) { cnum = cnu; }
void Course::setcname(string cna) { cname = cna; }
void Course::setcredit(float cre) { credit = cre; }
void Course::setperiod(int per) { period = per; }
void Course::settname(string tna) { tname = tna; }

void CourseDAOImpl::InsertCourse(Course course)
{
	CDaoDatabase *conn = Getconnection();
	CString sql;
	sql.Format("insert into 课程表(课程号,课程名,学分数,学时数,任课教师) values('%s','%s',%f,%d,'%s')", course.getcnum().c_str(), course.getcname().c_str(), course.getcredit(), course.getperiod(), course.gettname().c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}


//连接数据库
	//CDaoDatabase db(NULL);
	//db.Open(NULL, 0, 0, "driver={SQL Server};server=; uid=; pwd=; database=");

//用一个记录集存储执行一次查询结果
	//CDaoRecordset rs(db);
	//rs.Open(AFX_DAO_USE_DEFAULT_TYPE, "select * from 学生表", dbSeeChanges);	//打开记录集
	//rs.MoveFirst();								//转到第一条
	//COleVariant value;
	//rs.GetFieldValue("专业班级", value);			//以字段取值
	//cout << (LPCTSTR)value.pbstrVal << endl;
	/*rs.MoveNext();								//下一条
	rs.GetFieldValue("专业班级", value);
	cout << (LPCTSTR)value.pbstrVal << endl;*/

	//执行一条SQL语句
		//db.Execute("insert into 课程表(课程号,课程名,学分数,学时数,任课教师) values('K001','计算机图形学',2.5,40,'胡晶晶')", dbSeeChanges);

	//关闭连接
		//rs.Close();
		//db.Close();
	//以及其他各种函数用法参照微软文档 https://docs.microsoft.com/en-us/cpp/mfc/reference/cdaodatabase-class?view=vs-2019