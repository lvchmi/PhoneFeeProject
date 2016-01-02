// AddService.cpp : 实现文件
//

#include "stdafx.h"
#include "PhoneFee.h"
#include "AddService.h"
#include "afxdialogex.h"

#include <sql.h>
#include <sqlext.h>
#include <afxdb.h>
// CAddService 对话框

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
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

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

// 注意: 我们添加 IID_IAddService 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {9607B686-6FEB-42A1-B71D-E0CAD5F0F4E4}
static const IID IID_IAddService =
{ 0x9607B686, 0x6FEB, 0x42A1, { 0xB7, 0x1D, 0xE0, 0xCA, 0xD5, 0xF0, 0xF4, 0xE4 } };

BEGIN_INTERFACE_MAP(CAddService, CDialogEx)
	INTERFACE_PART(CAddService, IID_IAddService, Dispatch)
END_INTERFACE_MAP()


// CAddService 消息处理程序


void CAddService::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
}

void CAddService::OnClickedServiceok()
{
	// TODO: 在此添加控件通知处理程序代码
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
		MessageBox(_T("添加套餐成功！"));
	}else{
		MessageBox(_T("添加套餐失败！"));
	}
	FeeDatabase.Close();
	OnOK();
}


void CAddService::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


BOOL CAddService::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
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
	// 异常: OCX 属性页应返回 FALSE
}
