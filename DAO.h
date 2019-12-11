#include <iostream>
#include <string>
#include <afxdao.h>
#include <vector>
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
