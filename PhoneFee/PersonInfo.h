#pragma once
#include "afxwin.h"


// CPersonInfo �Ի���

class CPersonInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CPersonInfo)

public:
	CPersonInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPersonInfo();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_PersonInfo };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListBox PersonInfoL;
};
