
// TestMFCAppliView.cpp : implementation of the CTestMFCAppliView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestMFCAppli.h"
#endif

#include "TestMFCAppliDoc.h"
#include "TestMFCAppliView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestMFCAppliView

IMPLEMENT_DYNCREATE(CTestMFCAppliView, CView)

BEGIN_MESSAGE_MAP(CTestMFCAppliView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTestMFCAppliView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTestMFCAppliView construction/destruction

CTestMFCAppliView::CTestMFCAppliView()
{
	// TODO: add construction code here

}

CTestMFCAppliView::~CTestMFCAppliView()
{
}

BOOL CTestMFCAppliView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTestMFCAppliView drawing

void CTestMFCAppliView::OnDraw(CDC* /*pDC*/)
{
	CTestMFCAppliDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTestMFCAppliView printing


void CTestMFCAppliView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTestMFCAppliView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestMFCAppliView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestMFCAppliView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTestMFCAppliView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestMFCAppliView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestMFCAppliView diagnostics

#ifdef _DEBUG
void CTestMFCAppliView::AssertValid() const
{
	CView::AssertValid();
}

void CTestMFCAppliView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestMFCAppliDoc* CTestMFCAppliView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestMFCAppliDoc)));
	return (CTestMFCAppliDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestMFCAppliView message handlers
