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
	sql.Format("insert into �γ̱�(�γ̺�,�γ���,ѧ����,ѧʱ��,�ον�ʦ) values('%s','%s',%f,%d,'%s')", course.getcnum().c_str(), course.getcname().c_str(), course.getcredit(), course.getperiod(), course.gettname().c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}


//�������ݿ�
	//CDaoDatabase db(NULL);
	//db.Open(NULL, 0, 0, "driver={SQL Server};server=; uid=; pwd=; database=");

//��һ����¼���洢ִ��һ�β�ѯ���
	//CDaoRecordset rs(db);
	//rs.Open(AFX_DAO_USE_DEFAULT_TYPE, "select * from ѧ����", dbSeeChanges);	//�򿪼�¼��
	//rs.MoveFirst();								//ת����һ��
	//COleVariant value;
	//rs.GetFieldValue("רҵ�༶", value);			//���ֶ�ȡֵ
	//cout << (LPCTSTR)value.pbstrVal << endl;
	/*rs.MoveNext();								//��һ��
	rs.GetFieldValue("רҵ�༶", value);
	cout << (LPCTSTR)value.pbstrVal << endl;*/

	//ִ��һ��SQL���
		//db.Execute("insert into �γ̱�(�γ̺�,�γ���,ѧ����,ѧʱ��,�ον�ʦ) values('K001','�����ͼ��ѧ',2.5,40,'������')", dbSeeChanges);

	//�ر�����
		//rs.Close();
		//db.Close();
	//�Լ��������ֺ����÷�����΢���ĵ� https://docs.microsoft.com/en-us/cpp/mfc/reference/cdaodatabase-class?view=vs-2019