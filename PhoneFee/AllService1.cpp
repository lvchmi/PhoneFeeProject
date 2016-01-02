// AllService1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PhoneFee.h"
#include "AllService1.h"
#include "afxdialogex.h"

#include <sql.h>
#include <sqlext.h>
#include <afxdb.h>
// CAllService1 �Ի���

IMPLEMENT_DYNAMIC(CAllService1, CDialogEx)

CAllService1::CAllService1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAllService1::IDD, pParent)
{

	EnableAutomation();

}

CAllService1::~CAllService1()
{
}

void CAllService1::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CDialogEx::OnFinalRelease();
}

void CAllService1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ServiceLIst, Service);
}


BEGIN_MESSAGE_MAP(CAllService1, CDialogEx)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CAllService1, CDialogEx)
END_DISPATCH_MAP()

// ע��: ������� IID_IAllService1 ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {154EA2BE-594C-4D49-B913-FCE4242C4528}
static const IID IID_IAllService1 =
{ 0x154EA2BE, 0x594C, 0x4D49, { 0xB9, 0x13, 0xFC, 0xE4, 0x24, 0x2C, 0x45, 0x28 } };

BEGIN_INTERFACE_MAP(CAllService1, CDialogEx)
	INTERFACE_PART(CAllService1, IID_IAllService1, Dispatch)
END_INTERFACE_MAP()


// CAllService1 ��Ϣ�������


BOOL CAllService1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CDatabase FeeDatabase;
	CRecordset recordset;
	recordset.m_pDatabase=&FeeDatabase;
	FeeDatabase.Open(_T("PhoneFee"));
	CString serviceSelect, Title;
	int n;
	serviceSelect.Format(_T("select *  from Package_info"));
	recordset.Open(CRecordset::dynaset,serviceSelect);
	Service.ResetContent();
	n=recordset.GetRecordCount();
	//CString t; t.Format(_T("%d"), n); MessageBox(t);
	Title="�ײͺ�  �ײ�����               ����     ͨ������";
	Service.InsertString(0,Title);
	Title.Empty();
	Service.InsertString(1,Title);
	for (int i=0; i<=n; i++)
	{
		CString pacno, pacname, month_cost, unit_cost, servicetemp;
		recordset.GetFieldValue(_T("pacNo"),pacno);
		recordset.GetFieldValue(_T("pacName"),pacname);
		recordset.GetFieldValue(_T("month_cost"),month_cost);
		recordset.GetFieldValue(_T("unit_cost"),unit_cost);
		servicetemp=pacno+"  "+pacname+"  "+month_cost+"  "+unit_cost;
		Service.InsertString(i+2,servicetemp);
		recordset.MoveNext();
	}
	recordset.Close();
	FeeDatabase.Close();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
