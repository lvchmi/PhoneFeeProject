// AddAdmin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PhoneFee.h"
#include "AddAdmin.h"
#include "afxdialogex.h"

#include <afxdb.h>
#include <sql.h>
#include <sqlext.h>
// CAddAdmin �Ի���

IMPLEMENT_DYNAMIC(CAddAdmin, CDialogEx)

CAddAdmin::CAddAdmin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddAdmin::IDD, pParent)
{

	EnableAutomation();

}

CAddAdmin::~CAddAdmin()
{
}

void CAddAdmin::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CDialogEx::OnFinalRelease();
}

void CAddAdmin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddAdmin, CDialogEx)
	ON_BN_CLICKED(IDC_admin, &CAddAdmin::OnClickedAdmin)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CAddAdmin, CDialogEx)
END_DISPATCH_MAP()

// ע��: ������� IID_IAddAdmin ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {5B41D559-5CB2-4390-8651-247ED901F482}
static const IID IID_IAddAdmin =
{ 0x5B41D559, 0x5CB2, 0x4390, { 0x86, 0x51, 0x24, 0x7E, 0xD9, 0x1, 0xF4, 0x82 } };

BEGIN_INTERFACE_MAP(CAddAdmin, CDialogEx)
	INTERFACE_PART(CAddAdmin, IID_IAddAdmin, Dispatch)
END_INTERFACE_MAP()


// CAddAdmin ��Ϣ�������


void CAddAdmin::OnClickedAdmin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDatabase FeeDatabase;
	CRecordset recordset;
	recordset.m_pDatabase=&FeeDatabase;
	FeeDatabase.Open(_T("PhoneFee"));
	CString Sno, InsertS, SnoName, SMoney, SpMoney;
	GetDlgItemTextW(IDC_no, Sno);
	GetDlgItemTextW(IDC_placeAd, SnoName);
	GetDlgItemTextW(IDC_AdCode, SMoney);
	GetDlgItemTextW(IDC_AdName, SpMoney);
	InsertS.Format(_T("insert into Salesman values('%s', '%s', '%s', '%s')"), Sno,SpMoney ,SnoName , SMoney);
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
