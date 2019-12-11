#include "Business.h"

static Reader *curReader = NULL;		//当前登录借阅用户
static Manager *curManager = NULL;		//当前登录管理员
static Business Library;

void Start()			//启动系统
{

}

void ReaderLogin(Reader reader)			//借阅用户登录
{
	if (reader.getpwd() == (Library.SearchReader(reader.getusrid())).getpwd())
	{
		*curReader = reader;
		cout << "登录成功！" << endl;
	}
	else
	{
		cout << "登录失败，用户名或密码错误！" << endl;
	}
}

void ManagerLogin(Manager manager)			//管理员登录
{
	if (manager.getpwd() == (Library.SearchManager(manager.getusrid())).getpwd())
	{
		*curManager = manager;
		cout << "登录成功！" << endl;
	}
	else
	{
		cout << "登录失败，用户名或密码错误！" << endl;
	}
}

int main()
{



	AfxDaoTerm();			//程序必须在结束前调用这个函数
	return 0;
}
