#include "Course.h"
#include "Reader.h"

class Factory			//工厂类
{
private:
	Factory() {}
public:
	static Factory* GetInstance();			//实现单例模式
	DAObase *getDAO(string type);			//生产DAO对象
};