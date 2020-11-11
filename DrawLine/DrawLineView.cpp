
// DrawLineView.cpp : CDrawLineView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_DRAWPIC, &CDrawLineView::OnDrawpic)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CDrawLineView ����/����

CDrawLineView::CDrawLineView()
{
	// TODO: �ڴ˴���ӹ������

}

CDrawLineView::~CDrawLineView()
{
}

BOOL CDrawLineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDrawLineView ����

void CDrawLineView::OnDraw(CDC* /*pDC*/)
{
	CDrawLineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CDrawLineView ��ӡ

BOOL CDrawLineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDrawLineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDrawLineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CDrawLineView ���

#ifdef _DEBUG
void CDrawLineView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawLineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawLineDoc* CDrawLineView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawLineDoc)));
	return (CDrawLineDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawLineView ��Ϣ�������



void CDrawLineView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	p0.x = point.x;
	p0.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CDrawLineView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	p1.x = point.x;
	p1.y = point.y;
	CLine *line = new CLine;
	CDC *pDC = GetDC();                                   //�����豸������ָ��
	line->MoveTo(pDC, p0);
	line->LineTo(pDC, p1);
	delete line;
	ReleaseDC(pDC);
	CView::OnLButtonUp(nFlags, point);
}

void CDrawLineView::OnDrawpic()
{
	MessageBox(TEXT("�밴����������ͼ��"), TEXT("��ʾ"), MB_ICONEXCLAMATION | MB_OK);
	RedrawWindow();
	// TODO: �ڴ���������������
}


void CDrawLineView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString stringX, stringY;
	CMainFrame * pFrame = (CMainFrame *)AfxGetMainWnd();  //��ô���ָ��
	CStatusBar*pStatus = &pFrame->m_wndStatusBar;  //���״̬��ָ��
	if (pStatus != NULL)
	{
		//_T��һ���꣬����������ĳ���֧��Unicode����(˫�ֽڱ���)
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
