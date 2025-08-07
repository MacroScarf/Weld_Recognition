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
	
	// ��ʼ������
	setWindowTitle(QString::fromLocal8Bit("�켣���ɲ���"));
	
	// ���ñ���ɫ
	QPalette pal = palette();
	pal.setColor(QPalette::Window, QColor(240, 240, 240));
	setAutoFillBackground(true);
	setPalette(pal);
	
	// �̶���С
	setMinimumSize(400, 300);
	
	// ���ô��ڱ�־��ȷ��������ʾ�ڶ���
	setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
	

	

}

TestArcBoxView::~TestArcBoxView()
{
	// �ͷ��ڴ�
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
	
	// ע�⣺o_dStartPoint, o_dEndPoint, o_dStartTanVector, o_dEndTanVector 
	// ��Щָ����ڴ���PQKit API������MainWindow���Ѿ��ͷ�
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


