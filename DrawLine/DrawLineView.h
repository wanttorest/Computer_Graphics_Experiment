
// DrawLineView.h : CDrawLineView ��Ľӿ�
//

#pragma once
#include "Line.h"

class CDrawLineView : public CView
{
protected: // �������л�����
	CDrawLineView();
	DECLARE_DYNCREATE(CDrawLineView)

// ����
public:
	CDrawLineDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CDrawLineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnDrawpic();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()	
private:
	CP2 p0;
	CP2 p1;
	CRect rect;
public:
	
};

#ifndef _DEBUG  // DrawLineView.cpp �еĵ��԰汾
inline CDrawLineDoc* CDrawLineView::GetDocument() const
   { return reinterpret_cast<CDrawLineDoc*>(m_pDocument); }
#endif

