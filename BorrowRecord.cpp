#include "BorrowRecord.h"	/*****�����Course���������ݿ⣬ʵ�ֽ��ı�����ɾ�Ĳ�DAO����*****/
void BorrowRecordDAOImpl::InsertBorrowRecord(BorrowRecord borrowrecord)
{
	CDaoDatabase* conn = Getconnection();
	CString sql;
	sql.Format("insert into BOOKB(CNUM,BARCODE,BTIME,RTIME) values('%s','%s','%s','%s')",
		borrowrecord.getCnum().c_str(), borrowrecord.getBarcode().c_str(),
		borrowrecord.getBtime().GetYear(),borrowrecord.getBtime().GetMonth(),borrowrecord.getBtime().GetDay(),
		borrowrecord.getRtime().GetYear(), borrowrecord.getRtime().GetMonth(), borrowrecord.getRtime().GetDay());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}

void BorrowRecordDAOImpl::DeleteBorrowRecord(string cnum, string barcode)
{
	CDaoDatabase* conn = Getconnection();
	CString sql;
	sql.Format("delete from BOOKB where CNUM = '%s' and BARCODE = '%s'", cnum.c_str(), barcode.c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}

void BorrowRecordDAOImpl::UpdateBorrowRecord(string cnum, string barcode, string field, string value)
{
	CDaoDatabase* conn = Getconnection();
	CString sql;
	sql.Format("update BOOKB set %s = '%s' where  CNUM = '%s' and BARCODE = '%s'", field.c_str(),
		value.c_str(), cnum.c_str(), barcode.c_str());
	conn->Execute(sql, dbSeeChanges);
	conn->Close();
	delete conn;
}

vector<BorrowRecord> BorrowRecordDAOImpl::SearchBorrowRecord(string cnum, string barcode)
{
	CDaoDatabase* conn = Getconnection();
	CDaoRecordset rs(conn);
	BorrowRecord borrowrecord;
	CString sql;
	sql.Format("select * from BOOKB where CNUM = '%s' and BARCODE = '%s'", cnum.c_str(), barcode.c_str());
	vector<BorrowRecord> v = vector<BorrowRecord>();
	rs.Open(AFX_DAO_USE_DEFAULT_TYPE, sql, dbSeeChanges);
	COleVariant value;
	rs.GetFieldValue("CNUM", value);
	borrowrecord.setCnum((LPCTSTR)value.pbstrVal);
	rs.GetFieldValue("BARCODE", value);
	borrowrecord.setBarcode((LPCTSTR)value.pbstrVal);
	rs.GetFieldValue("BTIME", value);
	borrowrecord.setBtime((LPCTSTR)value);
	rs.GetFieldValue("RTIME", value);
	borrowrecord.setRtime((LPCTSTR)value);
	v.push_back(comment);
	rs.MoveNext();
	conn->Close();
	rs.Close();
	delete conn;
	return v;
}
