#pragma once
#include "afxwin.h"


// Ccount �Ի���

class Ccount : public CDialogEx
{
	DECLARE_DYNAMIC(Ccount)

public:
	Ccount(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Ccount();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_CounDialog };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
