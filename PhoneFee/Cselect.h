#pragma once
#include "afxwin.h"


// Cselect �Ի���

class Cselect : public CDialogEx
{
	DECLARE_DYNAMIC(Cselect)

public:
	Cselect(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cselect();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_SelectDialog };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	afx_msg void OnCbnSelchangeComboboxex2();
	CListBox ResultBox;
	afx_msg void OnClickedAllservice();
	afx_msg void OnClickedClient();
	afx_msg void OnClickedDel();
	afx_msg void OnClickedBackmain();
	CEdit phoneInput;
	virtual BOOL OnInitDialog();
	afx_msg void OnLbnSelchangeResultlist();
	CStatic S1;
	CStatic S1C;
	CStatic S2;
	CStatic S2C;
	CStatic S3;
	CStatic S3C;
	CStatic S4;
	CStatic S4C;
	CStatic S5;
	CComboBox S5C;
	CStatic S6;
	CStatic S6C;
	CButton Sok;
	CButton Scancle;
	CButton serviceChange;
	afx_msg void OnClickedEditservice();
	afx_msg void OnClickedEditok();
	afx_msg void OnClickedEditcancle();
	CButton Hfee;
	afx_msg void OnClickedFee();
	CButton AllService;
};
