#pragma once
#include "afxwin.h"


// CAddService �Ի���

class CAddService : public CDialogEx
{
	DECLARE_DYNAMIC(CAddService)

public:
	CAddService(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddService();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_DIAAddService };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
