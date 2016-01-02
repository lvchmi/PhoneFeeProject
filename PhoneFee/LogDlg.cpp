// LogDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PhoneFee.h"
#include "LogDlg.h"
#include "afxdialogex.h"
#include "PhoneFeeDlg.h"

#include <sql.h>
#include <sqlext.h>
#include <afxdb.h>

// CLogDlg 对话框

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
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

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

// 注意: 我们添加 IID_ILogDlg 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {FD68E661-58AD-4F96-BEB5-99C0BE0AF12E}
static const IID IID_ILogDlg =
{ 0xFD68E661, 0x58AD, 0x4F96, { 0xBE, 0xB5, 0x99, 0xC0, 0xBE, 0xA, 0xF1, 0x2E } };

BEGIN_INTERFACE_MAP(CLogDlg, CDialog)
	INTERFACE_PART(CLogDlg, IID_ILogDlg, Dispatch)
END_INTERFACE_MAP()


// CLogDlg 消息处理程序


void CLogDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CLogDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
	HBITMAP   hBitmap;   
	hBitmap = LoadBitmap(AfxGetInstanceHandle(),   
		MAKEINTRESOURCE(IDB_button)); // IDB_BITMAP_TEST为资源图片ID 
	((CButton *)GetDlgItem(IDOKLog))->SetBitmap(hBitmap); 
	CRect rect;
	GetClientRect(&rect);
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_LogBk);//IDB_BITMAP是你自己的图对应的ID   ，由于我刚刚加入的位图资源
	BITMAP bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap *pbmpOld=dcMem.SelectObject(&bmpBackground);
	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);
	CDialogEx::OnPaint();
}


HBRUSH CLogDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)//无用代码
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	return hbr;
}


void CLogDlg::OnClickedIdoklog()//点击确定发生的事件
{
	// TODO: 在此添加控件通知处理程序代码
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
			out="密码或用户名错误！";
			//MessageBox(out);
			record.Close();
			FeeDatabase.Close();
			FeeDatabase.Open(_T("PhoneFee"));
			record.m_pDatabase=&FeeDatabase;
			record.Open(CRecordset::dynaset,check1);
			n1=record.GetRecordCount();
			if (n1<=0)
			{
				out="密码或用户名错误！";
				MessageBox(out);
			}else{
				record.GetFieldValue(_T("cus_passwd"),out);
				out=out.Trim();
				if (pwd!=out)
				{
					out="密码或用户名错误！";
					MessageBox(out);
				}
			}
		}else{
			record.GetFieldValue(_T("sal_passwd"),out);
			out=out.Trim();
			if (pwd!=out)
			{
				out="密码或用户名错误！";
				MessageBox(out);
			}
		}
		//FeeDatabase.ExecuteSQL(checkUser);
		
		if (out==pwd)
		{
			WCHAR txt[20];
			CString txt1, h, t;
			h="欢迎"; t="登陆！";
			userName.GetWindowTextW(txt1);
			txt1=h+txt1+t;
			CStringW strWide = CT2CW(txt1); // 将T字符转换成宽字符
			wcscpy(txt, strWide); 
			MessageBox(txt);
			//MessageBox((LPCTSTR)"欢迎");
			CLogDlg::OnOK();
		}
} 
else
{
	if (pwd=="keKR6e")
	{
		CLogDlg::OnOK();
	}else{
		MessageBox(_T("管理员密码错误！"));
	}
}
}


BOOL CLogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
