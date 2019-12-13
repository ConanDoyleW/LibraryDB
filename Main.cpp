#include <string>
#include "Business.h"

using namespace std;

static Reader *curReader = NULL;		//当前登录借阅用户
static Manager *curManager = NULL;		//当前登录管理员
static Business Library;

void Start()			//启动系统
{
	while (true) {
		cout << static_cast <string>(
			"你的身份是\n")
			+ "[1]用户\n"
			+ "[2]管理员\n";
		char userOrAdmin;
		cin >> userOrAdmin;
		cout << "输入你的用户名\n";
		string username;
		cin >> username;
		cout << "请输入你的密码\n";
		string password;
		cin >> password;
		switch (userOrAdmin)
		{
		case '1': {
			Reader user(username, password);
			bool loginSucceeded = ReaderLogin(user);
			cout << static_cast<string>(
				"请输入你要进行的业务类型：\n")
				+ "[1]对书（部）进行增删改查\n"
				+ "[2]对书（本）进行增删改查\n"
				+ "[3]对书评进行增删改查\n"
				+ "[4]对借阅表进行增删改查\n";
			char selectedNumber;
			cin >> selectedNumber;
			switch (selectedNumber)
			{
			case '1':
			{
				bookVolumeMenu();
				break;
			}
			case '2':
			{
				bookEachMenu();
				break;
			}
			case '3':
			{
				commentMenu();
				break;
			}
			case '4':
			{
				borrowRecordMenu();
				break;
			}
			}
			break;
		}
		case '2': {
			Manager user(username, password);
			bool loginSucceeded = ManagerLogin(user);
			cout << static_cast<string>(
				"请输入你要进行的业务类型：\n")
				+ "[1]对书（部）进行增删改查\n"
				+ "[2]对书（本）进行增删改查\n"
				+ "[3]对用户进行增删改查\n"
				+ "[4]对管理员进行增删改查\n"
				+ "[5]对书评进行增删改查\n"
				+ "[6]对借阅表进行增删改查\n";
			char selectedNumber;
			cin >> selectedNumber;
			switch (selectedNumber)
			{
			case '1':
			{
				bookVolumeMenu();
				break;
			}
			case '2':
			{
				bookEachMenu();
				break;
			}
			case '3':
			{
				readerMenu();
				break;
			}
			case '4':
			{
				managerMenu();
				break;
			}
			case '5':
			{
				commentMenu();
				break;
			}
			case '6':
			{
				borrowRecordMenu();
				break;
			}
			}
            break;
		}
		}
	}
}

void bookVolumeMenu()
{
	cout << static_cast<string>(
		"请输入你想要如何操作书（部）：\n")
		+ "[1]添加书\n"
		+ "[2]删去书\n"
		+ "[3]修改书\n"
		+ "[4]查找书\n";
	char selectedNumber;
	cin >> selectedNumber;
	switch (selectedNumber)
	{
	case '1':
	{
		cout << static_cast<string>("请输入书名、学科主题、ISBN、出版发行项、")
			+"中图法分类号、个人责任人、个人次要责任人和载体形态项\n";
		string name, topic, isbn, publishInfo, cnLibClassm, personInCharge,
			subPersonInCharge, carrierShapeItem;
		cin >> name >> topic >> isbn >> publishInfo >> cnLibClassm >>
			personInCharge >> subPersonInCharge >> carrierShapeItem;
		Book book(name, topic, isbn, publishInfo, cnLibClassm, personInCharge,
			subPersonInCharge, carrierShapeItem);
		Business::InsertBook(book);
		break;
	}
	case '2':
	{
		cout << "请输入需要删去的书的ISBN码\n";
		string isbn;
		cin >> isbn;
		Business::DeleteBook(isbn);
		break;
	}
	case '3':
	{
		cout << "请输入需要修改的书的ISBN、需要修改的键以及新的键值\n";
		string isbn, key, value;
		cin >> isbn >> key >> value;
		Business::UpdateBook(isbn, key, value);
		break;
	}
	case '4':
	{
		cout << static_cast<string>(
			"请输入你想要如何查找书（部）\n")
			+ "[1]按书名找书\n"
			+ "[2]按学科主题找书\n"
			+ "[3]按ISBN找书\n"
			+ "[4]按出版发行项找书\n"
			+ "[5]按中国法分类号找书\n"
			+ "[6]按个人责任人找书\n"
			+ "[7]按个人次要责任人找书\n"
			+ "[8]按载体形态项找书\n";	
		char subSelectedNumber;
		cin >> subSelectedNumber;
		vector<Book*> v;
		switch (subSelectedNumber)
		{
		case '1':
		{
			cout << "请输入需要查找的值\n";
			string value;
			cin >> value;
			v = Business::SearchBook("BN", value);
			break;
		}
		case '2':
		{
			cout << "请输入需要查找的值\n";
			string value;
			cin >> value;
			v = Business::SearchBook("STHEME", value);
			break;
		}
		case '3':
		{
			cout << "请输入需要查找的值\n";
			string value;
			cin >> value;
			v = Business::SearchBook("ISBN", value);
			break;
		}
		case '4':
		{
			cout << "请输入需要查找的值\n";
			string value;
			cin >> value;
			v = Business::SearchBook("PUBITEM", value);
			break;
		}
		case '5':
		{
			cout << "请输入需要查找的值\n";
			string value;
			cin >> value;
			v = Business::SearchBook("CPKNUM", value);
			break;
		}
		case '6':
		{
			cout << "请输入需要查找的值\n";
			string value;
			cin >> value;
			v = Business::SearchBook("PRIVP", value);
			break;
		}
		case '7':
		{
			cout << "请输入需要查找的值\n";
			string value;
			cin >> value;
			v = Business::SearchBook("PRIVNP", value);
			break;
		}
		case '8':
		{
			cout << "请输入需要查找的值\n";
			string value;
			cin >> value;
			v = Business::SearchBook("FORMITEM", value);
			break;
		}
		}
		cout << static_cast<string>("共查询到") + to_string(v.size()) 
			+ "个结果，所查询的书的信息为：\n";
		for (auto book : v) {
			cout << book->getName() << " " << book->getTopic() << " " <<
				book->getIsbn() << " " << book->getPublishInfo() << " " <<
				book->getCnLibClass() << " " << book->getPersonInCharge()
				<< " " << book->getSubPersonInCharge() << " " << 
				book->getCarrierShapeItem() << endl;
		}
		break;
	}
	}
}
void bookEachMenu()
{
	cout << static_cast<string>(
		"请输入你想要如何操作书（本）：\n")
		+ "[1]添加书\n"
		+ "[2]删去书\n"
		+ "[3]修改书\n"
		+ "[4]查找书\n";
	char selectedNumber;
	cin >> selectedNumber;
	switch (selectedNumber)
	{
	case '1':
	{
		cout << "请输入索书号、ISBN、条码号、年卷期、馆藏地和书刊状态\n";
		string indexNum, isbn, barCode, volume, location, status;
		cin >> indexNum >> isbn >> barCode >> volume >> location >> status;
		EachBook eachBook(indexNum, isbn, barCode, volume, location, status);
		Business::InsertEachBook(eachBook);
		break;
	}
	case '2':
	{
		cout << "请输入需要删去的书的条码号\n";
		string barCode;
		cin >> barCode;
		Business::DeleteEachBook(barCode);
		break;
	}
	case '3':
	{
		cout << "请输入需要修改的书的条码号、需要修改的键以及新的键值\n";
		string barCode, key, value;
		cin >> barCode >> key >> value;
		Business::UpdateEachBook(barCode, key, value);
		break;
	}
	case '4':
	{
		cout << static_cast<string>(
			"请输入你想要如何找书：\n")
			+ "[1]按索书号\n"
			+ "[2]按ISBN\n"
			+ "[3]按条码号\n"
			+ "[4]按年卷期\n"
			+ "[5]按馆藏地\n"
			+ "[6]按书刊状态\n";
		char subSelectedNumber;
		cin >> subSelectedNumber;
		vector<EachBook*> v;
		switch (subSelectedNumber)
		{
		case '1':
		{
			cout << "请输入需要查找的值\n";
			string value;
			cin >> value;
			v = Business::SearchEachBook("CALLNUM", value);
			break;
		}
		case '2':
		{
			cout << "请输入需要查找的值\n";
			string value;
			cin >> value;
			v = Business::SearchEachBook("ISBN", value);
			break;
		}
		case '3':
		{
			cout << "请输入需要查找的值\n";
			string value;
			cin >> value;
			v = Business::SearchEachBook("BARCODE", value);
			break;
		}
		case '4':
		{
			cout << "请输入需要查找的值\n";
			string value;
			cin >> value;
			v = Business::SearchEachBook("VOLUMEISSUE", value);
			break;
		}
		case '5':
		{
			cout << "请输入需要查找的值\n";
			string value;
			cin >> value;
			v = Business::SearchEachBook("COLLECT", value);
			break;
		}
		case '6':
		{
			cout << "请输入需要查找的值\n";
			string value;
			cin >> value;
			v = Business::SearchEachBook("BOOKCOND", value);
			break;
		}
		}
		cout << static_cast<string>("共查询到") + to_string(v.size())
			+ "个结果，所查询的书的信息为：\n";
		for (auto eachBook : v) {
			cout << eachBook->getIndexNum() << " " << eachBook->getIsbn()
				<< " " << eachBook->getBarCode() << " " << eachBook->getVolume()
				<< " " << eachBook->getLocation() << " " << eachBook->getStatus()
				<< endl;
		}
		break;
	}
	}
}
void readerMenu()
{
	/*TODO 请完成该模块，之前相关人员各自完成各自的那一部分*/
}
void managerMenu()
{
	/*TODO 请完成该模块，之前相关人员各自完成各自的那一部分*/
}
void commentMenu()
{
	/*TODO 请完成该模块，之前相关人员各自完成各自的那一部分*/
}
void borrowRecordMenu()
{
	/*TODO 请完成该模块，之前相关人员各自完成各自的那一部分*/
}
bool ReaderLogin(Reader reader)			//借阅用户登录
{
	bool isCorrectCredential;
	if (reader.getpwd() == (Library.SearchReader(reader.getusrid())).getpwd())
	{
		*curReader = reader;
		cout << "登录成功！"  << endl;
		isCorrectCredential = true;
	}
	else
	{
		cout << "登录失败，用户名或密码错误！" << endl;
		isCorrectCredential = false;
	}
	return isCorrectCredential;
}

bool ManagerLogin(Manager manager)			//管理员登录
{
	bool isCorrectCredential;
	if (manager.getpwd() == (Library.SearchManager(manager.getusrid())).getpwd())
	{
		*curManager = manager;
		cout << "登录成功！" << endl;
		isCorrectCredential = true;
	}
	else
	{
		cout << "登录失败，用户名或密码错误！" << endl;
		isCorrectCredential = false;
	}
	return isCorrectCredential;
}

int main()
{
	Start();
	AfxDaoTerm();			//程序必须在结束前调用这个函数
	return 0;
}
