#pragma once


// CPhoneFeeAdd �Ի���

class CPhoneFeeAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CPhoneFeeAdd)

public:
	CPhoneFeeAdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPhoneFeeAdd();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_PhoneFeeDialog };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	afx_msg void OnClickedConfirm();
	afx_msg void OnClickedBack();
};
