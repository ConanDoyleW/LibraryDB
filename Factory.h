#include "Course.h"
#include "Reader.h"

class Factory			//������
{
private:
	Factory() {}
public:
	static Factory* GetInstance();			//ʵ�ֵ���ģʽ
	DAObase *getDAO(string type);			//����DAO����
};