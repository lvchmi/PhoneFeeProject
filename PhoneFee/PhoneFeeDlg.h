
// PhoneFeeDlg.h : ͷ�ļ�
//
#include "LogDlg.h"

#include <sql.h>
#include <sqlext.h>
#include <afxdb.h>

#pragma once


// CPhoneFeeDlg �Ի���
class CPhoneFeeDlg : public CDialogEx
{
// ����
public:
	CString nameN;
	CPhoneFeeDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CLogDlg m_log;
// �Ի�������
	enum { IDD = IDD_PHONEFEE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedCount();
	afx_msg void OnClickedSelect();
	afx_msg void OnPersoninfo();
	afx_msg void OnExit();
	afx_msg void OnClickedAllservice();
	afx_msg void OnClickedAddphonefee();
	afx_msg void OnSalman();
	afx_msg void OnService();
};
