
// ProgressTest2.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CProgressTest2App:
// �йش����ʵ�֣������ ProgressTest2.cpp
//

class CProgressTest2App : public CWinApp
{
public:
	CProgressTest2App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CProgressTest2App theApp;