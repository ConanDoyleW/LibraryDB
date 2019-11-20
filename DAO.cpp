#include "DAO.h"

CDaoDatabase* DAObase::Getconnection()
{
	CDaoDatabase *conn = new CDaoDatabase(NULL);
	conn->Open(NULL, 0, 0, "driver={SQL Server}; server=LAPTOP-FJ1IEH2R; uid=sa; pwd=123456; database=Librarytest");
	return conn;
}