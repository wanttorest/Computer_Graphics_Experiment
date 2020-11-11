
// DrawLineView.h : CDrawLineView 类的接口
//

#pragma once
#include "Line.h"

class CDrawLineView : public CView
{
protected: // 仅从序列化创建
	CDrawLineView();
	DECLARE_DYNCREATE(CDrawLineView)

// 特性
public:
	CDrawLineDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDrawLineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // DrawLineView.cpp 中的调试版本
inline CDrawLineDoc* CDrawLineView::GetDocument() const
   { return reinterpret_cast<CDrawLineDoc*>(m_pDocument); }
#endif

