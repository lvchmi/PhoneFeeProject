#pragma once
#include "afxdtctl.h"
#include "afxcmn.h"


// CHisrotyFee 对话框

class CHisrotyFee : public CDialogEx
{
	DECLARE_DYNAMIC(CHisrotyFee)

public:
	CHisrotyFee(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CHisrotyFee();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_HistoryFee };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	virtual BOOL OnInitDialog();
	CDateTimeCtrl StartT;
	CDateTimeCtrl EndT;
	CListCtrl HFeeList;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickedHfeeconfirm();
};
