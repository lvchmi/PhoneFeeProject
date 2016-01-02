// AddService.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PhoneFee.h"
#include "AddService.h"
#include "afxdialogex.h"

#include <sql.h>
#include <sqlext.h>
#include <afxdb.h>
// CAddService �Ի���

IMPLEMENT_DYNAMIC(CAddService, CDialogEx)

CAddService::CAddService(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddService::IDD, pParent)
{

	EnableAutomation();

}

CAddService::~CAddService()
{
}

void CAddService::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CDialogEx::OnFinalRelease();
}

void CAddService::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMService, AddS);
}


BEGIN_MESSAGE_MAP(CAddService, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddService::OnBnClickedOk)
	ON_BN_CLICKED(serviceOk, &CAddService::OnClickedServiceok)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CAddService::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CAddService, CDialogEx)
END_DISPATCH_MAP()

// ע��: ������� IID_IAddService ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {9607B686-6FEB-42A1-B71D-E0CAD5F0F4E4}
static const IID IID_IAddService =
{ 0x9607B686, 0x6FEB, 0x42A1, { 0xB7, 0x1D, 0xE0, 0xCA, 0xD5, 0xF0, 0xF4, 0xE4 } };

BEGIN_INTERFACE_MAP(CAddService, CDialogEx)
	INTERFACE_PART(CAddService, IID_IAddService, Dispatch)
END_INTERFACE_MAP()


// CAddService ��Ϣ�������


void CAddService::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
}

void CAddService::OnClickedServiceok()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDatabase FeeDatabase;
	CRecordset recordset;
	recordset.m_pDatabase=&FeeDatabase;
	FeeDatabase.Open(_T("PhoneFee"));
	CString Sno, InsertS, SnoName, SMoney, SpMoney;
	GetDlgItemTextW(IDC_COMService, Sno);
	GetDlgItemTextW(IDC_serviceName, SnoName);
	GetDlgItemTextW(IDC_serviceM, SMoney);
	GetDlgItemTextW(IDC_serviceMd, SpMoney);
	double sm, spm;
	sm=_wtof(SMoney), spm=_wtof(SpMoney);
	InsertS.Format(_T("insert into Package_info values('%s', '%s', '%s', '%s')"), Sno, SnoName, SMoney, SpMoney);
	FeeDatabase.ExecuteSQL(InsertS);
	if (FeeDatabase.IsOpen())
	{
		MessageBox(_T("����ײͳɹ���"));
	}else{
		MessageBox(_T("����ײ�ʧ�ܣ�"));
	}
	FeeDatabase.Close();
	OnOK();
}


void CAddService::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


BOOL CAddService::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	/*CDatabase FeeDatabase;
	CRecordset recordset;
	recordset.m_pDatabase=&FeeDatabase;
	FeeDatabase.Open(_T("PhoneFee"));
	CString sNoSelect;
	sNoSelect.Format(_T("select pacNo from Package_info"));
	recordset.Open(CRecordset::dynaset,sNoSelect);
	int n=recordset.GetRecordCount();

	AddS.ResetContent();
	for (int i=0; i<=n; i++)
	{
		CString Snotemp;
		recordset.GetFieldValue(_T("pacNo"),Snotemp);
		AddS.AddString(Snotemp);
		recordset.MoveNext();
	}*/
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
