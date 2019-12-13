#include <iostream>
#include <string>
#include <afxdao.h>
#include <vector>
#pragma warning(disable:4995)
#pragma once

using namespace std;

class DAO				//DAO对象
{
public:
	virtual CDaoDatabase* Getconnection() = 0;
};

class DAObase : public DAO
{
public:
	CDaoDatabase* Getconnection();
};
