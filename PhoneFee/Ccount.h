#pragma once
#include "afxwin.h"


// Ccount 对话框

class Ccount : public CDialogEx
{
	DECLARE_DYNAMIC(Ccount)

public:
	Ccount(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Ccount();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_CounDialog };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	afx_msg void OnClose();
	CComboBox Service;
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedIdokcount();
	CEdit phoneNo;
	CEdit identiID;
	CEdit Cname;
};
