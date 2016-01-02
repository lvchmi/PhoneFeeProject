
// PhoneFeeDlg.h : 头文件
//
#include "LogDlg.h"

#include <sql.h>
#include <sqlext.h>
#include <afxdb.h>

#pragma once


// CPhoneFeeDlg 对话框
class CPhoneFeeDlg : public CDialogEx
{
// 构造
public:
	CString nameN;
	CPhoneFeeDlg(CWnd* pParent = NULL);	// 标准构造函数
	CLogDlg m_log;
// 对话框数据
	enum { IDD = IDD_PHONEFEE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
