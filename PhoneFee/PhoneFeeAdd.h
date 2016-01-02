#pragma once


// CPhoneFeeAdd 对话框

class CPhoneFeeAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CPhoneFeeAdd)

public:
	CPhoneFeeAdd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPhoneFeeAdd();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_PhoneFeeDialog };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	afx_msg void OnClickedConfirm();
	afx_msg void OnClickedBack();
};
