
// ProgressTest2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ProgressTest2.h"
#include "ProgressTest2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProgressTest2Dlg 对话框




CProgressTest2Dlg::CProgressTest2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProgressTest2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProgressTest2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_Progress);
}

BEGIN_MESSAGE_MAP(CProgressTest2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CProgressTest2Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CProgressTest2Dlg::OnBnClickedCancel)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CProgressTest2Dlg 消息处理程序

BOOL CProgressTest2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetTimer(1,1000,NULL);//设置定时器
	m_Progress.MoveWindow(100,10,200,20);//设置进度条外边框位置
 	m_Progress.SetRange(1,100);//设置进度条范围
	m_Progress.SetStep(5);//设置进度条步长
 	m_Progress.SetPos(0);//设置进度条当前
	m_Progress.SendMessage(PBM_SETBKCOLOR, 0, RGB(0, 0, 0));//设置背景色(不好使)
    m_Progress.SendMessage(PBM_SETBARCOLOR, 0, RGB(0, 255, 0));//设置前景色(不好使)

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CProgressTest2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CProgressTest2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProgressTest2Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	exit(0);
}


void CProgressTest2Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	exit(0);
}


void CProgressTest2Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
    int nPos=rand()%100;//根据随机数值 动态改变进度条的数值
	m_Progress.SetPos(nPos);
	//m_Progress.StepIt();
	//int nPos=m_Progress.GetPos();
    CString  str;
	str.Format(_T("%d"),nPos);
	SetDlgItemText(IDC_STATIC,str);

	CDialogEx::OnTimer(nIDEvent);
}
