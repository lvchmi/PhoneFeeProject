#pragma once
#include "afxwin.h"


// CAllService1 �Ի���

class CAllService1 : public CDialogEx
{
	DECLARE_DYNAMIC(CAllService1)

public:
	CAllService1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAllService1();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_AllService1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListBox Service;
};
