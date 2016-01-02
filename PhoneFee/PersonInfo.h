#pragma once
#include "afxwin.h"


// CPersonInfo 对话框

class CPersonInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CPersonInfo)

public:
	CPersonInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPersonInfo();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_PersonInfo };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListBox PersonInfoL;
};
