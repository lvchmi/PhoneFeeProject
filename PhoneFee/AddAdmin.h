#pragma once


// CAddAdmin �Ի���

class CAddAdmin : public CDialogEx
{
	DECLARE_DYNAMIC(CAddAdmin)

public:
	CAddAdmin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddAdmin();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_Admin };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	afx_msg void OnClickedAdmin();
};
