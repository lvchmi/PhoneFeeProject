// Cselect.cpp : 实现文件
//

#include "stdafx.h"
#include "PhoneFee.h"
#include "Cselect.h"
#include "afxdialogex.h"
#include "HisrotyFee.h"

#include <sql.h>
#include <sqlext.h>
#include <afxdb.h>
// Cselect 对话框
int serviceFlag=0;
IMPLEMENT_DYNAMIC(Cselect, CDialogEx)

Cselect::Cselect(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cselect::IDD, pParent)
{

	EnableAutomation();

}

Cselect::~Cselect()
{
}

void Cselect::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void Cselect::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ResultList, ResultBox);
	DDX_Control(pDX, IDC_editPhone, phoneInput);
	DDX_Control(pDX, IDC_S1, S1);
	DDX_Control(pDX, IDC_NoInput, S1C);
	DDX_Control(pDX, IDC_S2, S2);
	DDX_Control(pDX, IDC_IDIput, S2C);
	DDX_Control(pDX, IDC_S3, S3);
	DDX_Control(pDX, IDC_NameInput, S3C);
	DDX_Control(pDX, IDC_S4, S4);
	DDX_Control(pDX, IDC_timeInput, S4C);
	DDX_Control(pDX, IDC_S5, S5);
	DDX_Control(pDX, IDC_serviceCom, S5C);
	DDX_Control(pDX, IDC_S6, S6);
	DDX_Control(pDX, IDC_money, S6C);
	DDX_Control(pDX, IDC_editOk, Sok);
	DDX_Control(pDX, IDC_editCancle, Scancle);
	DDX_Control(pDX, IDC_editService, serviceChange);
	DDX_Control(pDX, IDC_Fee, Hfee);
	DDX_Control(pDX, IDC_allService, AllService);
}


BEGIN_MESSAGE_MAP(Cselect, CDialogEx)
	//ON_CBN_SELCHANGE(IDC_COMBOBOXEX2, &Cselect::OnCbnSelchangeComboboxex2)
	ON_BN_CLICKED(IDC_allService, &Cselect::OnClickedAllservice)
	ON_BN_CLICKED(IDC_Client, &Cselect::OnClickedClient)
	ON_BN_CLICKED(IDC_del, &Cselect::OnClickedDel)
	ON_BN_CLICKED(ID_backMain, &Cselect::OnClickedBackmain)
	ON_LBN_SELCHANGE(IDC_ResultList, &Cselect::OnLbnSelchangeResultlist)
	ON_BN_CLICKED(IDC_editService, &Cselect::OnClickedEditservice)
	ON_BN_CLICKED(IDC_editOk, &Cselect::OnClickedEditok)
	ON_BN_CLICKED(IDC_editCancle, &Cselect::OnClickedEditcancle)
	ON_BN_CLICKED(IDC_Fee, &Cselect::OnClickedFee)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(Cselect, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_Iselect 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {717CC617-B16C-43BA-A550-6FD19F5AD037}
static const IID IID_Iselect =
{ 0x717CC617, 0xB16C, 0x43BA, { 0xA5, 0x50, 0x6F, 0xD1, 0x9F, 0x5A, 0xD0, 0x37 } };

BEGIN_INTERFACE_MAP(Cselect, CDialogEx)
	INTERFACE_PART(Cselect, IID_Iselect, Dispatch)
END_INTERFACE_MAP()


// Cselect 消息处理程序


void Cselect::OnCbnSelchangeComboboxex2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Cselect::OnClickedAllservice()
{
	// TODO: 在此添加控件通知处理程序代码
	S1.ShowWindow(SW_HIDE);
	S1C.ShowWindow(SW_HIDE);
	S2.ShowWindow(SW_HIDE);
	S2C.ShowWindow(SW_HIDE);
	S3.ShowWindow(SW_HIDE);
	S3C.ShowWindow(SW_HIDE);
	S4.ShowWindow(SW_HIDE);
	S4C.ShowWindow(SW_HIDE);
	S5.ShowWindow(SW_HIDE);
	S5C.ShowWindow(SW_HIDE);
	S6.ShowWindow(SW_HIDE);
	S6C.ShowWindow(SW_HIDE);
	Sok.ShowWindow(SW_HIDE);
	Scancle.ShowWindow(SW_HIDE);
	Hfee.ShowWindow(SW_HIDE);
	if (serviceFlag==0)
{
	   ResultBox.ResetContent();
	   ResultBox.ShowWindow(SW_SHOW);
	    CDatabase database;
		CRecordset recordset;
		database.Open(_T("PhoneFee"));
		recordset.m_pDatabase=&database;
		CString serviceSelect, Title;
		int n;
		serviceSelect.Format(_T("select *  from Package_info"));
		recordset.Open(CRecordset::forwardOnly,serviceSelect);
		n=recordset.GetRecordCount();
		Title="套餐号  套餐名称               月租     通话单价";
		ResultBox.InsertString(0,Title);
		Title.Empty();
		ResultBox.InsertString(1,Title);
		for (int i=0; i<=n; i++)
		{
			CString pacno, pacname, month_cost, unit_cost, servicetemp;
			recordset.GetFieldValue(_T("pacNo"),pacno);
			recordset.GetFieldValue(_T("pacName"),pacname);
			recordset.GetFieldValue(_T("month_cost"),month_cost);
			recordset.GetFieldValue(_T("unit_cost"),unit_cost);
			servicetemp=pacno+"  "+pacname+"  "+month_cost+"  "+unit_cost;
			ResultBox.InsertString(i+2,servicetemp);
			recordset.MoveNext();
		}
		recordset.Close();
		database.Close();
		serviceFlag=1;
}
}

void Cselect::OnClickedClient()
{
	serviceFlag=0;
	ResultBox.ResetContent();
	// TODO: 在此添加控件通知处理程序代码
	ResultBox.ShowWindow(SW_SHOW);
	S1.ShowWindow(SW_HIDE);
	S1C.ShowWindow(SW_HIDE);
	S2.ShowWindow(SW_HIDE);
	S2C.ShowWindow(SW_HIDE);
	S3.ShowWindow(SW_HIDE);
	S3C.ShowWindow(SW_HIDE);
	S4.ShowWindow(SW_HIDE);
	S4C.ShowWindow(SW_HIDE);
	S5.ShowWindow(SW_HIDE);
	S5C.ShowWindow(SW_HIDE);
	S6.ShowWindow(SW_HIDE);
	S6C.ShowWindow(SW_HIDE);
	Sok.ShowWindow(SW_HIDE);
	Scancle.ShowWindow(SW_HIDE);
	serviceChange.ShowWindow(SW_HIDE);
	Hfee.ShowWindow(SW_HIDE);
	CDatabase database;
	CRecordset recordset;
	database.Open(_T("PhoneFee"));
	recordset.m_pDatabase=&database;
	CString  phoneNo, clientInfo, cus_id, cus_name, enroll_time, pacNo, balance, empty;
	empty.Empty();
	int n;
	phoneInput.GetWindowTextW(phoneNo);
	if (!phoneNo.IsEmpty())
{
	clientInfo.Format(_T("select * from Customer where cus_pno='%s'"), phoneNo);
		recordset.Open(CRecordset::dynaset,clientInfo);
		n=recordset.GetRecordCount();
		if (n>0)
{        
	      serviceChange.ShowWindow(SW_SHOW);
		  Hfee.ShowWindow(SW_SHOW);
	       recordset.GetFieldValue(_T("cus_id"),cus_id);
			recordset.GetFieldValue(_T("cus_name"),cus_name);
			recordset.GetFieldValue(_T("enroll_time"),enroll_time);
			recordset.GetFieldValue(_T("pacNo"),pacNo);
			recordset.GetFieldValue(_T("balance"),balance);
			//
			GetParent()->SetDlgItemTextW(IDC_Temp, phoneNo);
			phoneNo=_T("手机号*     ")+phoneNo;
			ResultBox.InsertString(0, phoneNo);
			ResultBox.InsertString(1, empty);
			cus_id=_T("身份证号*     ")+cus_id;
			ResultBox.InsertString(2, cus_id);
			ResultBox.InsertString(3, empty);
			cus_name=_T("姓      名*     ")+cus_name;
			ResultBox.InsertString(4, cus_name);
			ResultBox.InsertString(5, empty);
			enroll_time=_T("开户时间*     ")+enroll_time;
			ResultBox.InsertString(6, enroll_time);
			ResultBox.InsertString(7, empty);
			pacNo=_T("套餐号*     ")+pacNo;
			ResultBox.InsertString(8, pacNo);
			ResultBox.InsertString(9, empty);
			balance=_T("账户余额*     ")+balance;
			ResultBox.InsertString(10, balance);
			ResultBox.InsertString(11, empty);
			recordset.Close();
			database.Close();
} else
{
	MessageBox(_T("请输入正确的手机号！"));
}
}else{
	MessageBox(_T("请输入手机号！"));
	}
}


void Cselect::OnClickedDel()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_editPhone, _T(""));
}


void Cselect::OnClickedBackmain()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
}


BOOL Cselect::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	ResultBox.ShowWindow(SW_HIDE);
	S1.ShowWindow(SW_HIDE);
	S1C.ShowWindow(SW_HIDE);
	S2.ShowWindow(SW_HIDE);
	S2C.ShowWindow(SW_HIDE);
	S3.ShowWindow(SW_HIDE);
	S3C.ShowWindow(SW_HIDE);
	S4.ShowWindow(SW_HIDE);
	S4C.ShowWindow(SW_HIDE);
	S5.ShowWindow(SW_HIDE);
	S5C.ShowWindow(SW_HIDE);
	S6.ShowWindow(SW_HIDE);
	S6C.ShowWindow(SW_HIDE);
	Sok.ShowWindow(SW_HIDE);
	Scancle.ShowWindow(SW_HIDE);
	serviceChange.ShowWindow(SW_HIDE);
	AllService.ShowWindow(SW_HIDE);
	Hfee.ShowWindow(SW_HIDE);
	CString no;
	GetParent()->   GetDlgItemTextW(IDC_Temp, no);
	CDatabase FeeDatabase;//连接数据库
	CRecordset recordSet;
	CString databaseName, selectN;
	databaseName="PhoneFee";
	FeeDatabase.Open(databaseName);
	recordSet.m_pDatabase=&FeeDatabase;
	selectN.Format(_T("select cus_pno from Customer"));
	//MessageBox(no);
	recordSet.Open(CRecordset::dynaset,selectN);
	int n=recordSet.GetRecordCount(); int f=1;
	for (int i=0; i<=n; i++)
	{
		CString notemp;
		recordSet.GetFieldValue(_T("cus_pno"),notemp);
		if (notemp==no){f=0;}
		recordSet.MoveNext();
	}
	if (f==0)
	{
		SetDlgItemTextW(IDC_editPhone, no);
		GetDlgItem(IDC_editPhone)->EnableWindow(FALSE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Cselect::OnLbnSelchangeResultlist()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Cselect::OnClickedEditservice()
{
	// TODO: 在此添加控件通知处理程序代码
	ResultBox.ShowWindow(SW_HIDE);
	serviceChange.ShowWindow(SW_HIDE);
	S1.ShowWindow(SW_SHOW);
	S1C.ShowWindow(SW_SHOW);
	S2.ShowWindow(SW_SHOW);
	S2C.ShowWindow(SW_SHOW);
	S3.ShowWindow(SW_SHOW);
	S3C.ShowWindow(SW_SHOW);
	S4.ShowWindow(SW_SHOW);
	S4C.ShowWindow(SW_SHOW);
	S5.ShowWindow(SW_SHOW);
	S5C.ShowWindow(SW_SHOW);
	S6.ShowWindow(SW_SHOW);
	S6C.ShowWindow(SW_SHOW);
	Sok.ShowWindow(SW_SHOW);
	Scancle.ShowWindow(SW_SHOW);
	CDatabase database;
	CRecordset recordset;
	database.Open(_T("PhoneFee"));
	recordset.m_pDatabase=&database;
	CString  phoneNo, clientInfo, cus_id, cus_name, enroll_time, pacNo, balance, empty, sNoSelect;
	int n;
	phoneInput.GetWindowTextW(phoneNo);
	if (!phoneNo.IsEmpty())
{
	clientInfo.Format(_T("select * from Customer where cus_pno='%s'"), phoneNo);
		recordset.Open(CRecordset::dynaset,clientInfo);
		n=recordset.GetRecordCount();
		if (n>0)
			{
				recordset.GetFieldValue(_T("cus_id"),cus_id);
				recordset.GetFieldValue(_T("cus_name"),cus_name);
				recordset.GetFieldValue(_T("enroll_time"),enroll_time);
				recordset.GetFieldValue(_T("pacNo"),pacNo);
				recordset.GetFieldValue(_T("balance"),balance);
				SetDlgItemText(IDC_NoInput, phoneNo);
				SetDlgItemText(IDC_IDIput, cus_id);
				SetDlgItemText(IDC_NameInput, cus_name);
				SetDlgItemText(IDC_timeInput, enroll_time);
				SetDlgItemText(IDC_serviceCom, pacNo);
				SetDlgItemText(IDC_money, balance);
				recordset.Close();
			}
			sNoSelect.Format(_T("select pacNo from Package_info"));
			recordset.Open(CRecordset::dynaset,sNoSelect);
			n=recordset.GetRecordCount();

	S5C.ResetContent();
	for (int i=0; i<=n; i++)
	{
		CString Snotemp;
		recordset.GetFieldValue(_T("pacNo"),Snotemp);
		S5C.AddString(Snotemp);
		recordset.MoveNext();
	}
	} 
	else
	{
		MessageBox(_T("请输入正确的手机号！"));
	}
	recordset.Close();
	database.Close();
}


void Cselect::OnClickedEditok()
{
	// TODO: 在此添加控件通知处理程序代码
	CString phoneNo, serviceNo1, changeService;
	S1C.GetWindowTextW(phoneNo);
	S5C.GetWindowTextW(serviceNo1);
	changeService.Format(_T("update Customer set pacNo='%s' where cus_pno='%s'"), serviceNo1, phoneNo);
	CDatabase database;
	CRecordset recordset;
	database.Open(_T("PhoneFee"));
	recordset.m_pDatabase=&database;
	if (database.IsOpen())
	{
		//MessageBox(_T("是否变更！"));
		if(MessageBox(_T("是否变更套餐"),_T("标题") ,MB_ICONEXCLAMATION|MB_OKCANCEL)==IDOK){
			database.ExecuteSQL(changeService);
			MessageBox(_T("套餐变更成功！"));
		}else
		{MessageBox(_T("套餐未变更！"));}
	}else{
		MessageBox(_T("套餐变更失败！"));
	}
	database.Close();
}


void Cselect::OnClickedEditcancle()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("套餐未变更！"));
}


void Cselect::OnClickedFee()
{
	// TODO: 在此添加控件通知处理程序代码
	CHisrotyFee *HFee= new CHisrotyFee;
	HFee->Create(IDD_HistoryFee);
	HFee->ShowWindow(SW_SHOW);
}
