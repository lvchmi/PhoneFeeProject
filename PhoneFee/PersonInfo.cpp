// PersonInfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PhoneFee.h"
#include "PersonInfo.h"
#include "afxdialogex.h"

#include <sql.h>
#include <sqlext.h>
#include <afxdb.h>
// CPersonInfo �Ի���

IMPLEMENT_DYNAMIC(CPersonInfo, CDialogEx)

CPersonInfo::CPersonInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPersonInfo::IDD, pParent)
{

	EnableAutomation();

}

CPersonInfo::~CPersonInfo()
{
}

void CPersonInfo::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CDialogEx::OnFinalRelease();
}

void CPersonInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PersonInfoList, PersonInfoL);
}


BEGIN_MESSAGE_MAP(CPersonInfo, CDialogEx)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CPersonInfo, CDialogEx)
END_DISPATCH_MAP()

// ע��: ������� IID_IPersonInfo ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {099D3927-0C51-4381-BDA5-9B5B334B219F}
static const IID IID_IPersonInfo =
{ 0x99D3927, 0xC51, 0x4381, { 0xBD, 0xA5, 0x9B, 0x5B, 0x33, 0x4B, 0x21, 0x9F } };

BEGIN_INTERFACE_MAP(CPersonInfo, CDialogEx)
	INTERFACE_PART(CPersonInfo, IID_IPersonInfo, Dispatch)
END_INTERFACE_MAP()


// CPersonInfo ��Ϣ�������


BOOL CPersonInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CDatabase FeeDatabase;
	CRecordset record;
	record.m_pDatabase=&FeeDatabase;
	FeeDatabase.Open(_T("PhoneFee"));
	CString Info, sal_name, workplace, sal_password, nameNo, empty;
	empty.Empty();
	if (nameNo.IsEmpty())
	{
		GetParent()->GetDlgItemTextW(IDC_Temp, nameNo);
	}
	//MessageBox(nameNo);
	//PersonInfoL.InsertString(0, nameNo);
	Info.Format(_T("select * from Salesman where sal_no='%s'"), nameNo);
	record.Open(CRecordset::dynaset,Info);
	record.GetFieldValue(_T("sal_name"),sal_name);
	record.GetFieldValue(_T("workplace"),workplace);
	record.GetFieldValue(_T("sal_passwd"),sal_password);
	nameNo=_T("���ţ�")+nameNo;
	sal_name=_T("������")+sal_name;
	workplace=_T("�����ص㣺")+workplace;
	sal_password=_T("��½���룺")+sal_password;
	PersonInfoL.InsertString(0, nameNo);
	PersonInfoL.InsertString(1, empty);
	PersonInfoL.InsertString(2, sal_name);
	PersonInfoL.InsertString(3, empty);
	PersonInfoL.InsertString(4, workplace);
	PersonInfoL.InsertString(5, empty);
	PersonInfoL.InsertString(6, sal_password);
	PersonInfoL.InsertString(7, empty);
	record.Close();
	FeeDatabase.Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
