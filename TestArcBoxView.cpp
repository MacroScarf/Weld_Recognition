#include "TestArcBoxView.h"
#include <QDebug>
#include <QPalette>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>
#include <QSplitter>
#include <QWindow>
#include <QThread>
#include "InsertPathDlg.h"
#include <QDebug>
#include <QMessageBox>
#include "TestArcBoxView.h"


TestArcBoxView::TestArcBoxView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	// 初始化界面
	setWindowTitle(QString::fromLocal8Bit("轨迹生成测试"));
	
	// 设置背景色
	QPalette pal = palette();
	pal.setColor(QPalette::Window, QColor(240, 240, 240));
	setAutoFillBackground(true);
	setPalette(pal);
	
	// 固定大小
	setMinimumSize(400, 300);
	
	// 设置窗口标志，确保窗口显示在顶层
	setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
	

	

}

TestArcBoxView::~TestArcBoxView()
{
	// 释放内存
	if (DX) {
		delete DX;
		DX = nullptr;
	}
	if (DY) {
		delete DY;
		DY = nullptr;
	}
	if (DZ) {
		delete DZ;
		DZ = nullptr;
	}
	
	// 注意：o_dStartPoint, o_dEndPoint, o_dStartTanVector, o_dEndTanVector 
	// 这些指针的内存由PQKit API管理，在MainWindow中已经释放
}

void TestArcBoxView::setFaceText(const QString& text)
{
	m_faceName = text;
	ui.label_4->setText(text);
}

void TestArcBoxView::setEdgeText(const QString& text)
{
	m_lineName = text;
	ui.label_3->setText(text);
}

void TestArcBoxView::onButtonClicked()
{
}


