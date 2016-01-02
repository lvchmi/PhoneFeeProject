#pragma once


// CAddAdmin 对话框

class CAddAdmin : public CDialogEx
{
	DECLARE_DYNAMIC(CAddAdmin)

public:
	CAddAdmin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddAdmin();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_Admin };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	afx_msg void OnClickedAdmin();
};
