#include "DAO.h"

CDaoDatabase* DAObase::Getconnection()
{
	CDaoDatabase *conn = new CDaoDatabase(NULL);
	conn->Open(NULL, 0, 0, "driver={SQL Server}; server=; uid=; pwd=; database=");
	return conn;
}
