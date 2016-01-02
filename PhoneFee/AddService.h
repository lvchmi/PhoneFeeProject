#pragma once
#include "afxwin.h"


// CAddService 对话框

class CAddService : public CDialogEx
{
	DECLARE_DYNAMIC(CAddService)

public:
	CAddService(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddService();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_DIAAddService };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnClickedServiceok();
	afx_msg void OnCbnSelchangeCombo1();
	virtual BOOL OnInitDialog();
	CComboBox AddS;
};
