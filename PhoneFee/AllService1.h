#pragma once
#include "afxwin.h"


// CAllService1 对话框

class CAllService1 : public CDialogEx
{
	DECLARE_DYNAMIC(CAllService1)

public:
	CAllService1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAllService1();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_AllService1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListBox Service;
};
