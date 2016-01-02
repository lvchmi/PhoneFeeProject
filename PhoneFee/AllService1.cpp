// AllService1.cpp : 实现文件
//

#include "stdafx.h"
#include "PhoneFee.h"
#include "AllService1.h"
#include "afxdialogex.h"

#include <sql.h>
#include <sqlext.h>
#include <afxdb.h>
// CAllService1 对话框

IMPLEMENT_DYNAMIC(CAllService1, CDialogEx)

CAllService1::CAllService1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAllService1::IDD, pParent)
{

	EnableAutomation();

}

CAllService1::~CAllService1()
{
}

void CAllService1::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void CAllService1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ServiceLIst, Service);
}


BEGIN_MESSAGE_MAP(CAllService1, CDialogEx)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CAllService1, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IAllService1 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {154EA2BE-594C-4D49-B913-FCE4242C4528}
static const IID IID_IAllService1 =
{ 0x154EA2BE, 0x594C, 0x4D49, { 0xB9, 0x13, 0xFC, 0xE4, 0x24, 0x2C, 0x45, 0x28 } };

BEGIN_INTERFACE_MAP(CAllService1, CDialogEx)
	INTERFACE_PART(CAllService1, IID_IAllService1, Dispatch)
END_INTERFACE_MAP()


// CAllService1 消息处理程序


BOOL CAllService1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CDatabase FeeDatabase;
	CRecordset recordset;
	recordset.m_pDatabase=&FeeDatabase;
	FeeDatabase.Open(_T("PhoneFee"));
	CString serviceSelect, Title;
	int n;
	serviceSelect.Format(_T("select *  from Package_info"));
	recordset.Open(CRecordset::dynaset,serviceSelect);
	Service.ResetContent();
	n=recordset.GetRecordCount();
	//CString t; t.Format(_T("%d"), n); MessageBox(t);
	Title="套餐号  套餐名称               月租     通话单价";
	Service.InsertString(0,Title);
	Title.Empty();
	Service.InsertString(1,Title);
	for (int i=0; i<=n; i++)
	{
		CString pacno, pacname, month_cost, unit_cost, servicetemp;
		recordset.GetFieldValue(_T("pacNo"),pacno);
		recordset.GetFieldValue(_T("pacName"),pacname);
		recordset.GetFieldValue(_T("month_cost"),month_cost);
		recordset.GetFieldValue(_T("unit_cost"),unit_cost);
		servicetemp=pacno+"  "+pacname+"  "+month_cost+"  "+unit_cost;
		Service.InsertString(i+2,servicetemp);
		recordset.MoveNext();
	}
	recordset.Close();
	FeeDatabase.Close();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
