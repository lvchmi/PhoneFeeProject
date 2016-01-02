// HisrotyFee.cpp : 实现文件
//

#include "stdafx.h"
#include "PhoneFee.h"
#include "HisrotyFee.h"
#include "afxdialogex.h"

#include <sql.h>
#include <sqlext.h>
#include <afxdb.h>
// CHisrotyFee 对话框

IMPLEMENT_DYNAMIC(CHisrotyFee, CDialogEx)

CHisrotyFee::CHisrotyFee(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHisrotyFee::IDD, pParent)
{

	EnableAutomation();

}

CHisrotyFee::~CHisrotyFee()
{
}

void CHisrotyFee::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void CHisrotyFee::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DateStart, StartT);
	DDX_Control(pDX, IDC_DateEnd, EndT);
	DDX_Control(pDX, IDC_LIST1, HFeeList);
}


BEGIN_MESSAGE_MAP(CHisrotyFee, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CHisrotyFee::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_HFeeConfirm, &CHisrotyFee::OnClickedHfeeconfirm)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CHisrotyFee, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IHisrotyFee 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {4D3D4D36-BF80-4CA0-AE3E-02CA3A9776B6}
static const IID IID_IHisrotyFee =
{ 0x4D3D4D36, 0xBF80, 0x4CA0, { 0xAE, 0x3E, 0x2, 0xCA, 0x3A, 0x97, 0x76, 0xB6 } };

BEGIN_INTERFACE_MAP(CHisrotyFee, CDialogEx)
	INTERFACE_PART(CHisrotyFee, IID_IHisrotyFee, Dispatch)
END_INTERFACE_MAP()


// CHisrotyFee 消息处理程序


BOOL CHisrotyFee::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// TODO:  在此添加额外的初始化
HFeeList.InsertColumn(0, _T("手机号"), 140, 100);
HFeeList.InsertColumn(1, _T("缴费日期"), 140, 100);
HFeeList.InsertColumn(2, _T("缴费金额"), 140, 100);
HFeeList.InsertColumn(3, _T("业务员"), 140, 100);
HFeeList.InsertColumn(4, _T("当前余额"), 140, 100);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CHisrotyFee::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CHisrotyFee::OnClickedHfeeconfirm()
{
	// TODO: 在此添加控件通知处理程序代码
	HFeeList.DeleteAllItems();
	CDatabase FeeDatabase;
	CRecordset record;
	record.m_pDatabase=&FeeDatabase;
	FeeDatabase.Open(_T("PhoneFee"));
	//SQLDATE pay_time;
	CTime start_time, end_time;
	CString cus_pno,  pay_cost, sal_no, FeeSelect, pay_time, now_m;
	StartT.GetTime(start_time); EndT.GetTime(end_time);
	
	GetParent()->GetDlgItemTextW(IDC_Temp, cus_pno);
	FeeSelect.Format(_T("select * from Payment where cus_pno='%s'"), cus_pno);
	record.Open(CRecordset::dynaset,FeeSelect);
	int n; 
	n=record.GetRecordCount();
	//HFeeList.InsertColumn( 0, _T("ID"), LVCFMT_LEFT, 30 );// 插入列 
	// HFeeList.InsertColumn( 1, _T("Time"), LVCFMT_LEFT, 50 );
	// HFeeList.InsertColumn( 2, _T("Cost"), LVCFMT_LEFT, 40 );
	// HFeeList.InsertColumn( 3, _T("sal"), LVCFMT_LEFT, 40 );

	//int nRow = HFeeList.InsertItem(0, _T("11"));// 插入行
	// HFeeList.InsertItem(1, _T("12"));
	if (n>0)
{
	int r=0;
	
		for (int i=0; i<=n&&!record.IsEOF(); i++)
		{
			record.GetFieldValue(_T("cus_pno"),cus_pno);
			record.GetFieldValue(_T("pay_time"),pay_time);
			record.GetFieldValue(_T("pay_cost"),pay_cost);
			record.GetFieldValue(_T("sal_no"),sal_no);
			record.GetFieldValue(_T("now_m"),now_m);
			int         nYear   = 0;
			int         nMonth  = 0;
			int         nDay    = 0;
			int         nHour   = 0;
			int         nSecond = 0;
			int         nMinute = 0;
		//	CTime time;
			CString  str     = pay_time;

			_stscanf(str, _T("%d-%d-%d %d:%d:%d"), &nYear, &nMonth, &nDay, &nHour, &nMinute, &nSecond);
		CTime	time(nYear, nMonth, nDay, 0, 0, 0);
		FeeSelect=time.Format("%Y-%m-%d %X");
		//MessageBox(FeeSelect);
			if (time>start_time && time<end_time)
			{
				HFeeList.InsertItem(r, _T("yi"));
				HFeeList.SetItemText(r, 0, cus_pno);
				HFeeList.SetItemText(r, 1, pay_time);
				HFeeList.SetItemText(r, 2, pay_cost);
				HFeeList.SetItemText(r, 3, sal_no);
				HFeeList.SetItemText(r++, 4, now_m);
			}
			record.MoveNext();
		}
} 
else
{
}
	record.Close();
	FeeDatabase.Close();
}
