
// PhoneFeeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PhoneFee.h"
#include "PhoneFeeDlg.h"
#include "afxdialogex.h"
#include "Ccount.h"
#include "Cselect.h"
#include "LogDlg.h"
#include "PersonInfo.h"
#include "AllService1.h"
#include "PhoneFeeAdd.h"
#include "AddAdmin.h"
#include "AddService.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPhoneFeeDlg �Ի���




CPhoneFeeDlg::CPhoneFeeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPhoneFeeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPhoneFeeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPhoneFeeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Count, &CPhoneFeeDlg::OnClickedCount)
	ON_BN_CLICKED(IDC_Select, &CPhoneFeeDlg::OnClickedSelect)
	ON_COMMAND(ID_PersonInfo, &CPhoneFeeDlg::OnPersoninfo)
	ON_COMMAND(ID_Exit, &CPhoneFeeDlg::OnExit)
	ON_BN_CLICKED(IDC_allService, &CPhoneFeeDlg::OnClickedAllservice)
	ON_BN_CLICKED(IDC_AddPhoneFee, &CPhoneFeeDlg::OnClickedAddphonefee)
	ON_COMMAND(ID_salman, &CPhoneFeeDlg::OnSalman)
	ON_COMMAND(ID_Service, &CPhoneFeeDlg::OnService)
END_MESSAGE_MAP()


// CPhoneFeeDlg ��Ϣ�������

BOOL CPhoneFeeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�
	CMenu  *menu;
	menu=new CMenu() ; 
	menu->LoadMenu(IDR_FunWay);
	SetMenu(menu);
		/*CMenu *pmenu;
		pmenu =new CMenu() ; 
		pmenu->LoadMenu(IDR_admin); 
		SetMenu(pmenu);*/
	//SetMenu(pmenu);
	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//�������ݿ�
	
	CDatabase FeeDatabase;//�������ݿ�
	CRecordset recordSet;
	CString databaseName;
	databaseName="PhoneFee";
	FeeDatabase.Open(databaseName);
	if (!FeeDatabase.IsOpen())
	{
		CString warning;
		warning="���ݿ������쳣��";
		MessageBox(warning);
	}
	if(m_log.DoModal() != IDOK)
	{
		OnOK();
	}
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CPhoneFeeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
	
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CPhoneFeeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		HBITMAP   hBitmap, sBitmap, fBitmap, rtBitmap;   
		hBitmap = LoadBitmap(AfxGetInstanceHandle(),   
			MAKEINTRESOURCE(IDB_counBk)); // IDB_BITMAP_TESTΪ��ԴͼƬID 
		((CButton *)GetDlgItem(IDC_Count))->SetBitmap(hBitmap); 
		sBitmap = LoadBitmap(AfxGetInstanceHandle(),   
			MAKEINTRESOURCE(IDB_SelectBk)); // IDB_BITMAP_TESTΪ��ԴͼƬID 
		((CButton *)GetDlgItem(IDC_Select))->SetBitmap(sBitmap); 
		fBitmap = LoadBitmap(AfxGetInstanceHandle(),   
			MAKEINTRESOURCE(IDB_PFeeBk)); // IDB_BITMAP_TESTΪ��ԴͼƬID 
		((CButton *)GetDlgItem(IDC_AddPhoneFee))->SetBitmap(fBitmap); 
		rtBitmap = LoadBitmap(AfxGetInstanceHandle(),   
			MAKEINTRESOURCE(IDB_Service)); // IDB_BITMAP_TESTΪ��ԴͼƬID 
		((CButton *)GetDlgItem(IDC_allService))->SetBitmap(rtBitmap); 
		CDialogEx::OnPaint();
		CString no;
		GetDlgItemTextW(IDC_Temp, no);
		if (no=="sa")
		{
			CMenu *menu, *subMenu;
			menu=GetMenu(); subMenu=menu->GetSubMenu(0);
			subMenu->EnableMenuItem(0, MF_BYPOSITION | MF_DISABLED | MF_GRAYED);
		}
		CDatabase FeeDatabase;//�������ݿ�
		CRecordset recordSet;
		CString databaseName, selectN, selectN1;
		databaseName="PhoneFee";
		FeeDatabase.Open(databaseName);
		recordSet.m_pDatabase=&FeeDatabase;
		selectN.Format(_T("select * from Customer where cus_pno='%s'"), no);
		//MessageBox(no);
		recordSet.Open(CRecordset::dynaset,selectN);
		int n=recordSet.GetRecordCount();
		recordSet.Close();
		FeeDatabase.Close();
		//recordSet.MoveFirst();
		//recordSet.MoveNext();
		if (n>0)
{
	CButton *pBtn, *b1, *b2, *b3;
			pBtn=(CButton *)GetDlgItem(IDC_AddPhoneFee);
			b1=(CButton *)GetDlgItem(IDC_Count);
			//b2=(CButton *)GetDlgItem(IDC_);
			//b1=(CButton *)GetDlgItem(IDC_Count);
			pBtn->EnableWindow(FALSE);
			b1->EnableWindow(FALSE);
			SetMenu(NULL);
			//GetDlgItem(IDD_SelectDialog)->SetDlgItemTextW(IDC_editPhone, no);
			//GetDlgItem(IDD_SelectDialog)->GetDlgItem(IDC_editPhone)->EnableWindow(FALSE);
}
		FeeDatabase.Open(databaseName);
		recordSet.m_pDatabase=&FeeDatabase;
		selectN1.Format(_T("select * from Salesman where sal_no='%s'"), no);
		recordSet.Open(CRecordset::dynaset,selectN1);
		n=recordSet.GetRecordCount();
		if (n>0)
		{
			//MessageBox(no);
			CMenu *menu, *subMenu;
			menu=GetMenu(); subMenu=menu->GetSubMenu(1);
			subMenu->EnableMenuItem(0, MF_BYPOSITION | MF_DISABLED | MF_GRAYED);
			subMenu->EnableMenuItem(1, MF_BYPOSITION | MF_DISABLED | MF_GRAYED);
			//(CMenu *)GetDlgItem(ID_salman)->EnableWindow(FALSE);
		}
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CPhoneFeeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPhoneFeeDlg::OnClickedCount()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//this->ShowWindow(SW_HIDE);
	Ccount  *count=new Ccount ;
	count->Create(IDD_CounDialog);
	count->ShowWindow(SW_SHOW);
}


void CPhoneFeeDlg::OnClickedSelect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Cselect  *select=new Cselect ;
	select->Create(IDD_SelectDialog);
	select->ShowWindow(SW_SHOW);
}



void CPhoneFeeDlg::OnPersoninfo()
{
	// TODO: �ڴ���������������
	CPersonInfo *person=new CPersonInfo;
	person->Create(IDD_PersonInfo);
	person->ShowWindow(SW_SHOW);
}


void CPhoneFeeDlg::OnExit()
{
	// TODO: �ڴ���������������
 OnOK();
}


void CPhoneFeeDlg::OnClickedAllservice()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CAllService1 *service=new CAllService1;
	service->Create(IDD_AllService1);
	service->ShowWindow(SW_SHOW);
}


void CPhoneFeeDlg::OnClickedAddphonefee()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CPhoneFeeAdd  *Fee=new CPhoneFeeAdd ;
	Fee->Create(IDD_PhoneFeeDialog);
	Fee->ShowWindow(SW_SHOW);
}


void CPhoneFeeDlg::OnSalman()
{
	// TODO: �ڴ���������������
	CAddAdmin  *Fee=new CAddAdmin ;
	Fee->Create(IDD_Admin);
	Fee->ShowWindow(SW_SHOW);
}


void CPhoneFeeDlg::OnService()
{
	// TODO: �ڴ���������������
	CAddService  *Fee=new CAddService ;
	Fee->Create(IDD_DIAAddService);
	Fee->ShowWindow(SW_SHOW);
}
