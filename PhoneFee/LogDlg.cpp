// LogDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PhoneFee.h"
#include "LogDlg.h"
#include "afxdialogex.h"
#include "PhoneFeeDlg.h"

#include <sql.h>
#include <sqlext.h>
#include <afxdb.h>

// CLogDlg �Ի���

IMPLEMENT_DYNAMIC(CLogDlg, CDialog)

CLogDlg::CLogDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLogDlg::IDD, pParent)
{

	EnableAutomation();

}

CLogDlg::~CLogDlg()
{
}

void CLogDlg::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CDialogEx::OnFinalRelease();
}

void CLogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_UserName, userName);
	DDX_Control(pDX, IDC_PassWord, passWd);
	//DDX_Control(pDX, IDC_CHECK1, checkBox);
}


BEGIN_MESSAGE_MAP(CLogDlg, CDialog)
	ON_BN_CLICKED(IDCANCEL, &CLogDlg::OnBnClickedCancel)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDOKLog, &CLogDlg::OnClickedIdoklog)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CLogDlg, CDialog)
END_DISPATCH_MAP()

// ע��: ������� IID_ILogDlg ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {FD68E661-58AD-4F96-BEB5-99C0BE0AF12E}
static const IID IID_ILogDlg =
{ 0xFD68E661, 0x58AD, 0x4F96, { 0xBE, 0xB5, 0x99, 0xC0, 0xBE, 0xA, 0xF1, 0x2E } };

BEGIN_INTERFACE_MAP(CLogDlg, CDialog)
	INTERFACE_PART(CLogDlg, IID_ILogDlg, Dispatch)
END_INTERFACE_MAP()


// CLogDlg ��Ϣ�������


void CLogDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CLogDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
	HBITMAP   hBitmap;   
	hBitmap = LoadBitmap(AfxGetInstanceHandle(),   
		MAKEINTRESOURCE(IDB_button)); // IDB_BITMAP_TESTΪ��ԴͼƬID 
	((CButton *)GetDlgItem(IDOKLog))->SetBitmap(hBitmap); 
	CRect rect;
	GetClientRect(&rect);
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_LogBk);//IDB_BITMAP�����Լ���ͼ��Ӧ��ID   �������Ҹոռ����λͼ��Դ
	BITMAP bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap *pbmpOld=dcMem.SelectObject(&bmpBackground);
	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);
	CDialogEx::OnPaint();
}


HBRUSH CLogDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)//���ô���
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	return hbr;
}


void CLogDlg::OnClickedIdoklog()//���ȷ���������¼�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDatabase FeeDatabase;
	CRecordset record;
	CString checkUser, name, pwd, out ,check1;
	int n, n1;
	userName.GetWindowTextW(name);
	passWd.GetWindowTextW(pwd);
	checkUser.Format(_T("select sal_passwd from Salesman where sal_no='%s'"), name);
	check1.Format(_T("select cus_passwd from Customer where cus_pno='%s'"), name);
	GetParent()->SetDlgItemTextW(IDC_Temp, name);
	if (name!="sa")
{
	FeeDatabase.Open(_T("PhoneFee"));
		record.m_pDatabase=&FeeDatabase;
		record.Open(CRecordset::dynaset,checkUser);
		n=record.GetRecordCount();
		if (n<=0)
		{
			out="������û�������";
			//MessageBox(out);
			record.Close();
			FeeDatabase.Close();
			FeeDatabase.Open(_T("PhoneFee"));
			record.m_pDatabase=&FeeDatabase;
			record.Open(CRecordset::dynaset,check1);
			n1=record.GetRecordCount();
			if (n1<=0)
			{
				out="������û�������";
				MessageBox(out);
			}else{
				record.GetFieldValue(_T("cus_passwd"),out);
				out=out.Trim();
				if (pwd!=out)
				{
					out="������û�������";
					MessageBox(out);
				}
			}
		}else{
			record.GetFieldValue(_T("sal_passwd"),out);
			out=out.Trim();
			if (pwd!=out)
			{
				out="������û�������";
				MessageBox(out);
			}
		}
		//FeeDatabase.ExecuteSQL(checkUser);
		
		if (out==pwd)
		{
			WCHAR txt[20];
			CString txt1, h, t;
			h="��ӭ"; t="��½��";
			userName.GetWindowTextW(txt1);
			txt1=h+txt1+t;
			CStringW strWide = CT2CW(txt1); // ��T�ַ�ת���ɿ��ַ�
			wcscpy(txt, strWide); 
			MessageBox(txt);
			//MessageBox((LPCTSTR)"��ӭ");
			CLogDlg::OnOK();
		}
} 
else
{
	if (pwd=="keKR6e")
	{
		CLogDlg::OnOK();
	}else{
		MessageBox(_T("����Ա�������"));
	}
}
}


BOOL CLogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
