#pragma once

#include <QWidget>
#include "ui_TestArcBoxView.h"

class TestArcBoxView : public QWidget
{
	Q_OBJECT

public:
	TestArcBoxView(QWidget *parent = nullptr);
	~TestArcBoxView();
	
	// ��ӹ�������
	void setFaceText(const QString& text);
	void setEdgeText(const QString& text);

	void onButtonClicked();

	int o_nStartPointCount;
	int o_nEndPointCount;
	double* o_dStartPoint;
	double* o_dEndPoint;
	double* o_dStartTanVector;
	int o_nStartVectorSize;
	double* o_dEndTanVector;
	int o_nEndVectorSize;

	double* DX;
	double* DY;
	double* DZ;

	bool EdgeIfReady=false;
	bool FaceIfReady=false;
	QString m_faceName;
	QString m_lineName;

	
signals:
	// ����ź�
	void selectionChanged(const QString& face, const QString& line);
	
private slots:
	// ���˽�вۺ���


	
private:
	Ui::TestArcBoxViewClass ui;
	// ���˽�г�Ա����

};

