// Ccount.cpp : 实现文件
//

#include "stdafx.h"
#include "PhoneFee.h"
#include "Ccount.h"
#include "afxdialogex.h"
#include "PhoneFeeDlg.h"

// Ccount 对话框

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
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

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

// 注意: 我们添加 IID_Icount 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {CB6E5D2B-4BD0-4753-AABD-A513358808DC}
static const IID IID_Icount =
{ 0xCB6E5D2B, 0x4BD0, 0x4753, { 0xAA, 0xBD, 0xA5, 0x13, 0x35, 0x88, 0x8, 0xDC } };

BEGIN_INTERFACE_MAP(Ccount, CDialogEx)
	INTERFACE_PART(Ccount, IID_Icount, Dispatch)
END_INTERFACE_MAP()


// Ccount 消息处理程序


void Ccount::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialogEx::OnClose();
}


BOOL Ccount::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
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
	// 异常: OCX 属性页应返回 FALSE
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
		MessageBox(_T("您输入的号码有误！"));
	}else{
		newCount.Format(_T("select * from Customer where cus_pno ='%s'"), phoneTxt);
		recordset.Open(CRecordset::dynaset,newCount);
		n=recordset.GetRecordCount();
		recordset.Close();
		if (n>0)
		{
			MessageBox(_T("该手机号已存在！"));
		}else{
			newCount1.Format(_T("exec Add_Customer  '%s','%s', '%s', '%s'"), phoneTxt, idetiTxt,nameTxt, serviceTxt);
			database.ExecuteSQL(newCount1);
			if (database.IsOpen())
			{
				MessageBox(_T("账户开通成功！"));
				recordset.Close();
				database.Close();
				OnOK();
			}else{
				MessageBox(_T("账户开通失败！"));
				recordset.Close();
			}
		}
	}
	
	// TODO: 在此添加控件通知处理程序代码
}
