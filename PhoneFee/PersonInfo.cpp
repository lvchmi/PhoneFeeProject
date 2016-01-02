// PersonInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "PhoneFee.h"
#include "PersonInfo.h"
#include "afxdialogex.h"

#include <sql.h>
#include <sqlext.h>
#include <afxdb.h>
// CPersonInfo 对话框

IMPLEMENT_DYNAMIC(CPersonInfo, CDialogEx)

CPersonInfo::CPersonInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPersonInfo::IDD, pParent)
{

	EnableAutomation();

}

CPersonInfo::~CPersonInfo()
{
}

void CPersonInfo::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void CPersonInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PersonInfoList, PersonInfoL);
}


BEGIN_MESSAGE_MAP(CPersonInfo, CDialogEx)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CPersonInfo, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IPersonInfo 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {099D3927-0C51-4381-BDA5-9B5B334B219F}
static const IID IID_IPersonInfo =
{ 0x99D3927, 0xC51, 0x4381, { 0xBD, 0xA5, 0x9B, 0x5B, 0x33, 0x4B, 0x21, 0x9F } };

BEGIN_INTERFACE_MAP(CPersonInfo, CDialogEx)
	INTERFACE_PART(CPersonInfo, IID_IPersonInfo, Dispatch)
END_INTERFACE_MAP()


// CPersonInfo 消息处理程序


BOOL CPersonInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CDatabase FeeDatabase;
	CRecordset record;
	record.m_pDatabase=&FeeDatabase;
	FeeDatabase.Open(_T("PhoneFee"));
	CString Info, sal_name, workplace, sal_password, nameNo, empty;
	empty.Empty();
	if (nameNo.IsEmpty())
	{
		GetParent()->GetDlgItemTextW(IDC_Temp, nameNo);
	}
	//MessageBox(nameNo);
	//PersonInfoL.InsertString(0, nameNo);
	Info.Format(_T("select * from Salesman where sal_no='%s'"), nameNo);
	record.Open(CRecordset::dynaset,Info);
	record.GetFieldValue(_T("sal_name"),sal_name);
	record.GetFieldValue(_T("workplace"),workplace);
	record.GetFieldValue(_T("sal_passwd"),sal_password);
	nameNo=_T("工号：")+nameNo;
	sal_name=_T("姓名：")+sal_name;
	workplace=_T("工作地点：")+workplace;
	sal_password=_T("登陆密码：")+sal_password;
	PersonInfoL.InsertString(0, nameNo);
	PersonInfoL.InsertString(1, empty);
	PersonInfoL.InsertString(2, sal_name);
	PersonInfoL.InsertString(3, empty);
	PersonInfoL.InsertString(4, workplace);
	PersonInfoL.InsertString(5, empty);
	PersonInfoL.InsertString(6, sal_password);
	PersonInfoL.InsertString(7, empty);
	record.Close();
	FeeDatabase.Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
