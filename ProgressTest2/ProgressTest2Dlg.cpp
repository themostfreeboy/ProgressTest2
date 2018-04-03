
// ProgressTest2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ProgressTest2.h"
#include "ProgressTest2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProgressTest2Dlg �Ի���




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


// CProgressTest2Dlg ��Ϣ�������

BOOL CProgressTest2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetTimer(1,1000,NULL);//���ö�ʱ��
	m_Progress.MoveWindow(100,10,200,20);//���ý�������߿�λ��
 	m_Progress.SetRange(1,100);//���ý�������Χ
	m_Progress.SetStep(5);//���ý���������
 	m_Progress.SetPos(0);//���ý�������ǰ
	m_Progress.SendMessage(PBM_SETBKCOLOR, 0, RGB(0, 0, 0));//���ñ���ɫ(����ʹ)
    m_Progress.SendMessage(PBM_SETBARCOLOR, 0, RGB(0, 255, 0));//����ǰ��ɫ(����ʹ)

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CProgressTest2Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CProgressTest2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProgressTest2Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	exit(0);
}


void CProgressTest2Dlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
	exit(0);
}


void CProgressTest2Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
    int nPos=rand()%100;//���������ֵ ��̬�ı����������ֵ
	m_Progress.SetPos(nPos);
	//m_Progress.StepIt();
	//int nPos=m_Progress.GetPos();
    CString  str;
	str.Format(_T("%d"),nPos);
	SetDlgItemText(IDC_STATIC,str);

	CDialogEx::OnTimer(nIDEvent);
}
