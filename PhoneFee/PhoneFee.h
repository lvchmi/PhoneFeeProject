
// PhoneFee.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPhoneFeeApp:
// �йش����ʵ�֣������ PhoneFee.cpp
//

class CPhoneFeeApp : public CWinApp
{
public:
	CPhoneFeeApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	//afx_msg void OnPersoninfo();
};

extern CPhoneFeeApp theApp;