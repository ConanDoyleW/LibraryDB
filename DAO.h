#include <iostream>
#include <string>
#include <afxdao.h>
#pragma once

using namespace std;

class DAO				//DAO����
{
public:
	virtual CDaoDatabase* Getconnection() = 0;
};

class DAObase : public DAO
{
public:
	CDaoDatabase* Getconnection();
};
