// PhoneFeeAdd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PhoneFee.h"
#include "PhoneFeeAdd.h"
#include "afxdialogex.h"

#include <sql.h>
#include <sqlext.h>
#include <afxdb.h>
// CPhoneFeeAdd �Ի���

IMPLEMENT_DYNAMIC(CPhoneFeeAdd, CDialogEx)

CPhoneFeeAdd::CPhoneFeeAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPhoneFeeAdd::IDD, pParent)
{

	EnableAutomation();

}

CPhoneFeeAdd::~CPhoneFeeAdd()
{
}

void CPhoneFeeAdd::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CDialogEx::OnFinalRelease();
}

void CPhoneFeeAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPhoneFeeAdd, CDialogEx)
	ON_BN_CLICKED(IDC_Confirm, &CPhoneFeeAdd::OnClickedConfirm)
	ON_BN_CLICKED(IDC_Back, &CPhoneFeeAdd::OnClickedBack)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CPhoneFeeAdd, CDialogEx)
END_DISPATCH_MAP()

// ע��: ������� IID_IPhoneFeeAdd ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {AF0FBC87-7B76-46C4-A8D2-E5A70F9CFA41}
static const IID IID_IPhoneFeeAdd =
{ 0xAF0FBC87, 0x7B76, 0x46C4, { 0xA8, 0xD2, 0xE5, 0xA7, 0xF, 0x9C, 0xFA, 0x41 } };

BEGIN_INTERFACE_MAP(CPhoneFeeAdd, CDialogEx)
	INTERFACE_PART(CPhoneFeeAdd, IID_IPhoneFeeAdd, Dispatch)
END_INTERFACE_MAP()


// CPhoneFeeAdd ��Ϣ�������


void CPhoneFeeAdd::OnClickedConfirm()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDatabase FeeDatabase;
	CRecordset record;
	record.m_pDatabase=&FeeDatabase;
	FeeDatabase.Open(_T("PhoneFee"));
	CTime t;
	t=GetCurrentTime();
	CString InsertG, phoneNo, Money, sal_no, paytime, m_f, select_m;
	paytime=t.Format("%Y-%m-%d %X");
	//MessageBox(paytime);
	GetParent()->GetDlgItemTextW(IDC_Temp, sal_no);
	//MessageBox(sal_no);
	GetDlgItemTextW(IDC_PhoneNo, phoneNo);
	GetDlgItemTextW(IDC_money, Money);
	select_m.Format(_T("select * from Customer where cus_pno='%s'"), phoneNo);
	record.Open(CRecordset::dynaset,select_m);
	int n; n=record.GetRecordCount();
	if (n>0)
{
	    record.GetFieldValue(_T("balance"),m_f);
		//MessageBox(m_f);
		m_f.Format(_T("%.2f"), _wtof(m_f)+_wtof(Money));
		InsertG.Format(_T("insert into Payment values('%s', '%s', '%s', '%s', '%s')"), phoneNo, paytime, Money, sal_no, m_f);
		FeeDatabase.ExecuteSQL(InsertG);
		if (FeeDatabase.IsOpen())
		{
			MessageBox(_T("�ɷѳɹ���"));
		}else{
			MessageBox(_T("�ɷ�ʧ�ܣ�"));
		}
} 
else
{
	MessageBox(_T("���û������ڣ�"));
}
}


void CPhoneFeeAdd::OnClickedBack()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnCancel();
}
