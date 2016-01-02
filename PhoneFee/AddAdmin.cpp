// AddAdmin.cpp : 实现文件
//

#include "stdafx.h"
#include "PhoneFee.h"
#include "AddAdmin.h"
#include "afxdialogex.h"

#include <afxdb.h>
#include <sql.h>
#include <sqlext.h>
// CAddAdmin 对话框

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
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

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

// 注意: 我们添加 IID_IAddAdmin 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {5B41D559-5CB2-4390-8651-247ED901F482}
static const IID IID_IAddAdmin =
{ 0x5B41D559, 0x5CB2, 0x4390, { 0x86, 0x51, 0x24, 0x7E, 0xD9, 0x1, 0xF4, 0x82 } };

BEGIN_INTERFACE_MAP(CAddAdmin, CDialogEx)
	INTERFACE_PART(CAddAdmin, IID_IAddAdmin, Dispatch)
END_INTERFACE_MAP()


// CAddAdmin 消息处理程序


void CAddAdmin::OnClickedAdmin()
{
	// TODO: 在此添加控件通知处理程序代码
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
		MessageBox(_T("添加套餐成功！"));
	}else{
		MessageBox(_T("添加套餐失败！"));
	}
	FeeDatabase.Close();
	OnOK();
}
