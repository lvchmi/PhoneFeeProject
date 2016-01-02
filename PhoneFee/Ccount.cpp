// Ccount.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PhoneFee.h"
#include "Ccount.h"
#include "afxdialogex.h"
#include "PhoneFeeDlg.h"

// Ccount �Ի���

IMPLEMENT_DYNAMIC(Ccount, CDialogEx)

Ccount::Ccount(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ccount::IDD, pParent)
{

	EnableAutomation();

}

Ccount::~Ccount()
{
}

void Ccount::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CDialogEx::OnFinalRelease();
}

void Ccount::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ServiceBox, Service);
	DDX_Control(pDX, IDC_PhoneNo, phoneNo);
	DDX_Control(pDX, IDC_IdentiNo, identiID);
	DDX_Control(pDX, IDC_CounName, Cname);
}


BEGIN_MESSAGE_MAP(Ccount, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDOKCount, &Ccount::OnClickedIdokcount)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(Ccount, CDialogEx)
END_DISPATCH_MAP()

// ע��: ������� IID_Icount ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {CB6E5D2B-4BD0-4753-AABD-A513358808DC}
static const IID IID_Icount =
{ 0xCB6E5D2B, 0x4BD0, 0x4753, { 0xAA, 0xBD, 0xA5, 0x13, 0x35, 0x88, 0x8, 0xDC } };

BEGIN_INTERFACE_MAP(Ccount, CDialogEx)
	INTERFACE_PART(Ccount, IID_Icount, Dispatch)
END_INTERFACE_MAP()


// Ccount ��Ϣ�������


void Ccount::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDialogEx::OnClose();
}


BOOL Ccount::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CDatabase database;
	CRecordset recordset;
	database.Open(_T("PhoneFee"));
	recordset.m_pDatabase=&database;
	CString sNoSelect;
	int n;
	sNoSelect.Format(_T("select pacNo from Package_info"));
	recordset.Open(CRecordset::dynaset,sNoSelect);
	n=recordset.GetRecordCount();
	for (int i=0; i<=n; i++)
	{
		CString Snotemp;
		recordset.GetFieldValue(_T("pacNo"),Snotemp);
		Service.AddString(Snotemp);
		recordset.MoveNext();
	}
	recordset.Close();
	database.Close();
	//database.Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void Ccount::OnClickedIdokcount()
{
	CDatabase database;
	CRecordset recordset;
	database.Open(_T("phoneFee"));
	recordset.m_pDatabase=&database;
	CString phoneTxt, idetiTxt, nameTxt, serviceTxt;
	phoneNo.GetWindowTextW(phoneTxt);
	identiID.GetWindowTextW(idetiTxt);
	Cname.GetWindowTextW(nameTxt);
	Service.GetWindowTextW(serviceTxt);
	CString newCount, newCount1;
	int n;
	n=phoneTxt.GetLength();
	if (n!=11)
	{
		MessageBox(_T("������ĺ�������"));
	}else{
		newCount.Format(_T("select * from Customer where cus_pno ='%s'"), phoneTxt);
		recordset.Open(CRecordset::dynaset,newCount);
		n=recordset.GetRecordCount();
		recordset.Close();
		if (n>0)
		{
			MessageBox(_T("���ֻ����Ѵ��ڣ�"));
		}else{
			newCount1.Format(_T("exec Add_Customer  '%s','%s', '%s', '%s'"), phoneTxt, idetiTxt,nameTxt, serviceTxt);
			database.ExecuteSQL(newCount1);
			if (database.IsOpen())
			{
				MessageBox(_T("�˻���ͨ�ɹ���"));
				recordset.Close();
				database.Close();
				OnOK();
			}else{
				MessageBox(_T("�˻���ͨʧ�ܣ�"));
				recordset.Close();
			}
		}
	}
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
