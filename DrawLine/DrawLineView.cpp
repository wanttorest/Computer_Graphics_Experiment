
// DrawLineView.cpp : CDrawLineView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DrawLine.h"
#endif

#include "DrawLineDoc.h"
#include "DrawLineView.h"
#include "MainFrm.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawLineView

IMPLEMENT_DYNCREATE(CDrawLineView, CView)

BEGIN_MESSAGE_MAP(CDrawLineView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_DRAWPIC, &CDrawLineView::OnDrawpic)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CDrawLineView 构造/析构

CDrawLineView::CDrawLineView()
{
	// TODO: 在此处添加构造代码

}

CDrawLineView::~CDrawLineView()
{
}

BOOL CDrawLineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDrawLineView 绘制

void CDrawLineView::OnDraw(CDC* /*pDC*/)
{
	CDrawLineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDrawLineView 打印

BOOL CDrawLineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawLineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDrawLineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDrawLineView 诊断

#ifdef _DEBUG
void CDrawLineView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawLineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawLineDoc* CDrawLineView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawLineDoc)));
	return (CDrawLineDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawLineView 消息处理程序



void CDrawLineView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	p0.x = point.x;
	p0.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CDrawLineView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	p1.x = point.x;
	p1.y = point.y;
	CLine *line = new CLine;
	CDC *pDC = GetDC();                                   //定义设备上下文指针
	line->MoveTo(pDC, p0);
	line->LineTo(pDC, p1);
	delete line;
	ReleaseDC(pDC);
	CView::OnLButtonUp(nFlags, point);
}

void CDrawLineView::OnDrawpic()
{
	MessageBox(TEXT("请按下鼠标左键绘图！"), TEXT("提示"), MB_ICONEXCLAMATION | MB_OK);
	RedrawWindow();
	// TODO: 在此添加命令处理程序代码
}


void CDrawLineView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString stringX, stringY;
	CMainFrame * pFrame = (CMainFrame *)AfxGetMainWnd();  //获得窗口指针
	CStatusBar*pStatus = &pFrame->m_wndStatusBar;  //获得状态栏指针
	if (pStatus != NULL)
	{
		//_T是一个宏，作用是让你的程序支持Unicode编码(双字节编码)
		stringX.Format(_T("x=%d"), point.x);
		stringY.Format(_T("y=%d"), point.y);

		CClientDC dc(this);
		CSize sizeX = dc.GetTextExtent(stringX);
		CSize sizeY = dc.GetTextExtent(stringY);
		pStatus->SetPaneInfo(1, nFlags, SBPS_NORMAL, sizeX.cx);
		pStatus->SetPaneText(1, stringX);
		pStatus->SetPaneInfo(2, nFlags, SBPS_NORMAL, sizeY.cx);
		pStatus->SetPaneText(2, stringY);

	}
}
