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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	//init menu/toolbar
	InitAction();
	InitMenu();
	InitToolBar();

	//load pqkit
	InitPQKit();
}

MainWindow::~MainWindow()
{
	CoUninitialize();
    delete ui;
}

void MainWindow::InitAction()
{
	m_openAction = new QAction(QIcon(":/Images/open.png"), QString::fromLocal8Bit("打开"), this);
	m_saveasAction = new QAction(QIcon(":/Images/save.png"), QString::fromLocal8Bit("另存"), this);
	m_compileAction = new QAction(QIcon(":/Images/compile.png"), QString::fromLocal8Bit("编译"), this);
	m_simulateAction = new QAction(QIcon(":/Images/simulate.png"), QString::fromLocal8Bit("仿真"), this);
	m_insertpathAction = new QAction(QIcon(":/Images/insertpath.png"), QString::fromLocal8Bit("导入轨迹点"), this);
	m_closefileAction = new QAction(QIcon(":/Images/closefile.png"), QString::fromLocal8Bit("关闭文档"), this);
	m_import3dAction = new QAction(QIcon(":/Images/import3d.png"), QString::fromLocal8Bit("导入3d文件"), this);
	m_measureAction= new QAction(QIcon(":/Images/measure.png"), QString::fromLocal8Bit("测量"), this);
	m_arcboxAction= new QAction(QIcon(":/Images/arcbox.png"), QString::fromLocal8Bit("三维球"), this);

	m_arcboxAction2 = new QAction(QIcon(":/Images/generatepath.png"), QString::fromLocal8Bit("测试生成轨迹"), this);

	m_alignpartAction = new QAction(QIcon(":/Images/alignpart.png"), QString::fromLocal8Bit("三点校准"), this);
	m_generatepathAction= new QAction(QIcon(":/Images/generatepath.png"), QString::fromLocal8Bit("生成轨迹"), this);
	m_postAction= new QAction(QIcon(":/Images/post.png"), QString::fromLocal8Bit("后置"), this);
	m_getpathpoint= new QAction(QIcon(":/Images/getpathpoint.png"), QString::fromLocal8Bit("轨迹点信息"), this);

	connect(m_openAction, SIGNAL(triggered()), this, SLOT(OnOpenRobx()));
	connect(m_saveasAction, SIGNAL(triggered()), this, SLOT(OnSaveAsRobx()));
	connect(m_compileAction, SIGNAL(triggered()), this, SLOT(OnCompile()));
	connect(m_simulateAction, SIGNAL(triggered()), this, SLOT(OnSimulate()));
	connect(m_insertpathAction, SIGNAL(triggered()), this, SLOT(OnInsertPath()));
	connect(m_closefileAction, SIGNAL(triggered()), this, SLOT(CloseFile()));
	connect(m_import3dAction, SIGNAL(triggered()), this, SLOT(Import3DObj()));
	connect(m_measureAction, SIGNAL(triggered()), this, SLOT(Measure()));
	connect(m_arcboxAction, SIGNAL(triggered()), this, SLOT(ArcBox()));
	connect(m_arcboxAction2, SIGNAL(triggered()), this, SLOT(ArcBox2()));
	connect(m_alignpartAction, SIGNAL(triggered()), this, SLOT(AlignPart()));
	connect(m_generatepathAction, SIGNAL(triggered()), this, SLOT(Generatepath()));
	connect(m_postAction, SIGNAL(triggered()), this, SLOT(Post()));
	connect(m_getpathpoint, SIGNAL(triggered()), this, SLOT(GetPathPointInfo()));

}

void MainWindow::InitMenu()
{
	QMenuBar *mBar = menuBar();
	QMenu *pFile = mBar->addMenu("PQKit");

	//
	pFile->addAction(m_openAction);
	pFile->addAction(m_saveasAction);
	pFile->addAction(m_closefileAction);
	pFile->addSeparator();
	pFile->addAction(m_compileAction);
	pFile->addAction(m_simulateAction);
	pFile->addSeparator();
	pFile->addAction(m_insertpathAction);
	pFile->addAction(m_generatepathAction);
	pFile->addAction(m_getpathpoint);
	pFile->addAction(m_import3dAction);
	pFile->addSeparator();
	pFile->addAction(m_measureAction);
	pFile->addAction(m_arcboxAction);
	pFile->addAction(m_arcboxAction2);
	pFile->addAction(m_alignpartAction);
	pFile->addAction(m_postAction);
	pFile->addSeparator();

}

void MainWindow::InitToolBar()
{
	ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	ui->toolBar->addAction(m_openAction);
	ui->toolBar->addAction(m_saveasAction);
	ui->toolBar->addAction(m_closefileAction);
	ui->toolBar->addSeparator();
	ui->toolBar->addAction(m_compileAction);
	ui->toolBar->addAction(m_simulateAction);
	ui->toolBar->addSeparator();
	ui->toolBar->addAction(m_insertpathAction);
	ui->toolBar->addAction(m_getpathpoint);
	ui->toolBar->addAction(m_generatepathAction);
	ui->toolBar->addAction(m_import3dAction);
	ui->toolBar->addSeparator();
	ui->toolBar->addAction(m_measureAction);
	ui->toolBar->addAction(m_arcboxAction);
	ui->toolBar->addAction(m_arcboxAction2);
	ui->toolBar->addAction(m_alignpartAction);
	ui->toolBar->addAction(m_postAction);
	ui->toolBar->addSeparator();
}

void MainWindow::InitPQKit()
{
	//
	CoInitializeEx(0, COINIT_APARTMENTTHREADED);
	HRESULT hr = m_ptrKit.CoCreateInstance(__uuidof(PQPlatformComponent));
	if (S_OK != hr)
	{
		QString strError = QString::fromLocal8Bit("PQKit创建失败！\n请排查当前启动或调试exe同目录是否有PQKit环境。\nPQkit环境包含PQkit文件夹、PQKit.manifest文件、启动或调试exe的manifest文件。");
		QMessageBox::information(NULL, "PQKit", strError, QMessageBox::Ok);
	}

	//
	m_ptrKitCallback = new CPQKitCallback(this);
	connect(m_ptrKitCallback, &CPQKitCallback::signalInitializeResult, this, &MainWindow::OnInitializeResult);
	connect(m_ptrKitCallback, &CPQKitCallback::signalLoginResult, this, &MainWindow::OnLoginResult);
	connect(m_ptrKitCallback, &CPQKitCallback::signalElementPickup, this, &MainWindow::OnElementPickup);
	connect(m_ptrKitCallback, &CPQKitCallback::signalElementPickup, this, &MainWindow::OnEdgeElementPickup);
	connect(m_ptrKitCallback, &CPQKitCallback::signalElementPickup, this, &MainWindow::OnFaceElementPickup);
	connect(m_ptrKitCallback, &CPQKitCallback::signalElementSelection, this, &MainWindow::OnElementSelection);

	//
	QThread *ptrThread = new QThread;
	connect(ptrThread, &QThread::started, this, &MainWindow::OnInitializeKitThread);
	ptrThread->start();
}

void MainWindow::OnInitializeKitThread()
{
	//initialize pqkit
	CComBSTR bsName = L"18379115061";
	CComBSTR bsPWD = L"115061";
	HRESULT hr = m_ptrKit->pq_InitPlatformComponent(m_ptrKitCallback, (int)(this->winId()), bsName, bsPWD);
	if (S_OK != hr)
	{
		QString strError = QString::fromLocal8Bit("PQKit初始化失败！\n请参考Fire_Initialize_Result或Fire_Login_Result函数中的具体lResult值。");
		QMessageBox::information(NULL, "PQKit", strError, QMessageBox::Ok);
	}
}



void MainWindow::ShowPQKitWindown()
{
	int nHWND = 0;
	m_ptrKit->pq_GetPlatformView(&nHWND);
	HWND hWnd = (HWND)(UINT_PTR)nHWND;
	if (nullptr == hWnd)
	{
		return;
	}
	m_pPQPlatformView = QWidget::createWindowContainer(QWindow::fromWinId((WId)hWnd), this);

	ULONG_PTR nModelDoc = NULL;
	m_ptrKit->pq_GetModelTreeView(&nModelDoc);
	HWND hModelWnd = (HWND)nModelDoc;
	if (nullptr != hModelWnd)
	{
		m_pPQModeTreeView = QWidget::createWindowContainer(QWindow::fromWinId((WId)hModelWnd), this);
	}

	ULONG_PTR nDebugDoc = NULL;
	m_ptrKit->pq_GetDebugTreeView(&nDebugDoc);
	HWND hDebugWnd = (HWND)nDebugDoc;
	if (nullptr != hDebugWnd)
	{
		m_pPQDebugView = QWidget::createWindowContainer(QWindow::fromWinId((WId)hDebugWnd), this);
	}

	auto splitter = new QSplitter;
	splitter->addWidget(m_pPQModeTreeView);
	splitter->addWidget(m_pPQPlatformView);
	splitter->addWidget(m_pPQDebugView);
	splitter->setStretchFactor(0, 1);
	splitter->setStretchFactor(1, 5);
	splitter->setStretchFactor(2, 1);
	setCentralWidget(splitter);
}

void MainWindow::closeEvent(QCloseEvent* event)
{
	if (m_ptrKit)
	{
		m_ptrKit->pq_CloseComponent();
	}

	event->accept();
}

void MainWindow::OnOpenRobx()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("open robx file"), "",
		tr("Robx files(*.robx)"));
	if (fileName.isEmpty())
	{
		return;
	}
	//
	std::wstring wsFilePath = fileName.toStdWString();
	m_ptrKit->Doc_open_robx((LPWSTR)(wsFilePath.c_str()));
	
}

void MainWindow::OnSaveAsRobx()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("open robx file"), "",
		tr("Robx files(*.robx)"));
	if (fileName.isEmpty())
	{
		return;
	}
	//
	std::wstring wsFilePath = fileName.toStdWString();
	m_ptrKit->Doc_saveas_robx((LPWSTR)(wsFilePath.c_str()));
	
}

void MainWindow::OnCompile()
{
	wchar_t whMoudle[256] = L"RO_CMD_COMPILE";
	m_ptrKit->Doc_start_module((LPWSTR)whMoudle);
	
}

void MainWindow::OnSimulate()
{
	wchar_t whMoudle[256] = L"RO_CMD_SIMULATE";
	m_ptrKit->Doc_start_module((LPWSTR)whMoudle);

}

void MainWindow::OnInsertPath()
{
	InsertPathDlg dlg;
	if (QDialog::Rejected == dlg.exec())
	{
		return;
	}
		
	//默认取第一个机器人
	ULONG uRobotID = 0;
	GetObjIDByName(32, _T(""), uRobotID);

	//
	int nType = 1;
	double dPosition[6] = { 0.0 };
	dlg.GetPosture(dPosition[0], dPosition[1], dPosition[2], dPosition[3], dPosition[4], dPosition[5], nType);

	int nInstruction[1] = { 1 };
	double dVel[1] = { 200.0 };
	double dSpeedP[1] = { 100.0 };
	int nApproach[1] = { -1 };
	CComBSTR bsPathName = "Test_Path";
	CComBSTR bsPathGroupName = "Test_Group";

	ULONG uPathID = 0;
	m_ptrKit->Path_insert_from_point(uRobotID, 1, dPosition, nType, nInstruction, dVel, dSpeedP, nApproach, bsPathName, bsPathGroupName, 0, FALSE, &uPathID, TRUE);
}

void MainWindow::GetObjIDByName(int i_nType, std::wstring i_wsName, ULONG &o_uID)
{
	VARIANT vNamePara;
	vNamePara.parray = NULL;
	VARIANT vIDPara;
	vIDPara.parray = NULL;
	m_ptrKit->Doc_get_obj_bytype(i_nType, &vNamePara, &vIDPara);
	if (NULL == vNamePara.parray || NULL == vIDPara.parray)
	{
		return;
	}
	//缓存指定对象名称
	BSTR* bufName;
	long lenName = vNamePara.parray->rgsabound[0].cElements;
	SafeArrayAccessData(vNamePara.parray, (void**)&bufName);
	int nTarIndex = 0;
	if (!i_wsName.empty())
	{
		for (int i = 0; i < lenName; i++)
		{
			if (0 == i_wsName.compare(bufName[i]))
			{
				nTarIndex = i;
			}
		}
	}
	SafeArrayUnaccessData(vNamePara.parray);


	//缓存指定对象ID
	ULONG* bufID;
	long lenID = vIDPara.parray->rgsabound[0].cElements;
	SafeArrayAccessData(vIDPara.parray, (void**)&bufID);
	o_uID = bufID[nTarIndex];
	SafeArrayUnaccessData(vIDPara.parray);
}

void MainWindow:: GetFirstPointOfPath(ULONG i_ulPathID, ULONG& o_ulPointID)
{
	VARIANT vPointPara;
	vPointPara.parray = NULL;
	m_ptrKit->PQAPIGetPointsID(i_ulPathID, &vPointPara);
	long lenPointCount = vPointPara.parray->rgsabound[0].cElements;
	ULONG* t_bufPoint = NULL;
	SafeArrayAccessData(vPointPara.parray, (void**)&t_bufPoint);
	if (1 <= lenPointCount)
	{
		o_ulPointID = t_bufPoint[0];
	}
	SafeArrayUnaccessData(vPointPara.parray);
}

void MainWindow::GetPathPointInfo()
{
	//以取第一条轨迹的第一个点为例
	ULONG uPathID=0;
	GetObjIDByName(80, _T(""), uPathID);

	ULONG uPointID = 0;
	GetFirstPointOfPath(uPathID, uPointID);

	int nType = 1;
	int nPostureCount=0;
	double* dPointPosture = nullptr;
	double dVelocity = 0.0;
	double dSpeedPercent = 0.0;
	int iInstruct = 0;
	int iApproach = 0;
	m_ptrKit->PQAPIGetPointInfo(uPointID, nType, &nPostureCount, &dPointPosture, &dVelocity, &dSpeedPercent, &iInstruct, &iApproach);
	QString result = "PostureCount :";
	result += QString::number(nPostureCount);
	QString Linebreaks = "\n";
	result += Linebreaks;
	result += "Posture :";
	for (int i=0;i<nPostureCount;i++)
	{
		result += QString::number(dPointPosture[i]);
		result += ", ";
	}
	result += Linebreaks;
	result += "Velocity :";
	result += QString::number(dVelocity);
	result += Linebreaks;
	result += "Speedpercent :";
	result += QString::number(dSpeedPercent);
	result += Linebreaks;
	result += "Instruct :";
	switch (iInstruct)
	{
	case(0):
		result += "Line";
		result += Linebreaks;
		break;
	case(1):
		result += "Circle";
		result += Linebreaks;
		break;
	case(2):
		result += "Spline";
		result += Linebreaks;
		break;
	case(3):
		result += "Joint";
		result += Linebreaks;
		break;
	case(4):
		result += "AbsJoint";
		result += Linebreaks;
		break;
	default:
		break;
	}
	result += "Approach :";
	result += QString::number(iApproach);
	result += Linebreaks;
	QMessageBox::information(this,"PointInfo",result);
	m_ptrKit->PQAPIFreeArray((LONG_PTR*)dPointPosture);
}


void MainWindow::CloseFile()
{
	CComBSTR strFilePath = "";
	m_ptrKit->Doc_get_name(&strFilePath);
	m_ptrKit->pq_CloseDocument(strFilePath);
}

void MainWindow::Import3DObj()
{
	CComBSTR strCMD = "RO_CMD_IMPORT_ACCESSORY_PART";
	m_ptrKit->Doc_start_module(strCMD);
}

void MainWindow::Measure()
{
	CComBSTR strCMD = "RO_CMD_MEASUREMENT";
	m_ptrKit->Doc_start_module(strCMD);
}

void MainWindow::ArcBox()
{
	CComBSTR strCMD = "RO_CMD_ARCBALL_PROXY";
	m_ptrKit->Doc_start_module(strCMD);
}

void MainWindow::ArcBox2()
{
	// 创建TestArcBoxView实例
	pArcBoxView = new TestArcBoxView(this);
	
	// 初始化指针成员为nullptr
	pArcBoxView->DX = nullptr;
	pArcBoxView->DY = nullptr;
	pArcBoxView->DZ = nullptr;
	pArcBoxView->o_dStartPoint = nullptr;
	pArcBoxView->o_dEndPoint = nullptr;
	pArcBoxView->o_dStartTanVector = nullptr;
	pArcBoxView->o_dEndTanVector = nullptr;
	
	// 重置状态
	pArcBoxView->EdgeIfReady = false;
	pArcBoxView->FaceIfReady = false;
	
	// 设置初始值
	pArcBoxView->setFaceText(QString::fromLocal8Bit("测试面"));
	pArcBoxView->setEdgeText(QString::fromLocal8Bit("测试线"));
	
	// 获取按钮并连接到MainWindow的Pickup函数
	QPushButton* btnStartLine = pArcBoxView->findChild<QPushButton*>("btnStartLine");
	QPushButton* btnStartFace = pArcBoxView->findChild<QPushButton*>("btnStartFace");
	QPushButton* pushButton = pArcBoxView->findChild<QPushButton*>("pushButton");
	QPushButton* pushButton_2 = pArcBoxView->findChild<QPushButton*>("pushButton_2");
	
	if (btnStartLine) {
		connect(btnStartLine, &QPushButton::clicked, this, &MainWindow::PickUpEdge);
	}
	
	if (btnStartFace) {
		connect(btnStartFace, &QPushButton::clicked, this, &MainWindow::PickUpFace);
	}
	if (pushButton) {
		connect(pushButton, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
	}else {
		QMessageBox::information(NULL, "PQKit Info", QString::fromLocal8Bit("没有找到按钮"), QMessageBox::Ok);
	}
	if (pushButton_2) {
		connect(pushButton_2, &QPushButton::clicked, this, [this]() {
			pArcBoxView->close();
			delete pArcBoxView;
			pArcBoxView = nullptr;
		});
	}else {
		QMessageBox::information(NULL, "PQKit Info", QString::fromLocal8Bit("没有找到按钮"), QMessageBox::Ok);
	}
	
	// 显示对话框
	pArcBoxView->show();
	pArcBoxView->raise();
	pArcBoxView->activateWindow();
	
	// 移动到父窗口中央
	QPoint center = this->mapToGlobal(this->rect().center());
	pArcBoxView->move(
		center.x() - pArcBoxView->width() / 2,
		center.y() - pArcBoxView->height() / 2
	);
}

void MainWindow::onPushButtonClicked() {

	// 按钮点击处理
	qDebug() << QString::fromLocal8Bit("按钮被点击");
	emit pArcBoxView->selectionChanged(pArcBoxView->m_faceName, pArcBoxView->m_lineName);
	//开始处理并生成轨迹
	if (pArcBoxView->EdgeIfReady && pArcBoxView->FaceIfReady) {
		double dFaceVector[3] = {*pArcBoxView->DX,*pArcBoxView->DY,*pArcBoxView->DZ };
		double* o_dStartPosture = nullptr;
		int o_nStartPostureArraySize = 0;
		m_ptrKit->Math_trans_vector_to_posture(pArcBoxView->o_dStartPoint, pArcBoxView->o_dStartTanVector, dFaceVector, 1, &o_dStartPosture, &o_nStartPostureArraySize);
		double* o_dEndPosture = nullptr;
		int o_nEndPostureArraySize = 0;
		m_ptrKit->Math_trans_vector_to_posture(pArcBoxView->o_dEndPoint, pArcBoxView->o_dEndTanVector, dFaceVector, 1, &o_dEndPosture, &o_nEndPostureArraySize);
		
		ULONG uRobotID = 0;
		GetObjIDByName(32, _T("KUKA-KR16-2"), uRobotID);

		// 正确分配内存
		double* i_dPosition = new double[12]; // 分配12个元素的数组（6个起点+6个终点）
		for (int i = 0; i < 6; i++) {
			i_dPosition[i] = o_dStartPosture[i];
		}
		for (int i = 0; i < 6; i++) {
			i_dPosition[6 + i] = o_dEndPosture[i];
		}
		
		int nInstruct[2] = {1,1};
		double dVelocity[2] = {200.0,200};
		double dSpeedPercent[2] = {100.0,100};
		int nApproach[2] = { -1,-1 };
		
		// 生成唯一的路径名称，避免轨迹被覆盖
		static int pathCounter = 0;
		pathCounter++;
		QString uniquePathName = QString("testPath_%1").arg(pathCounter);
		QString uniqueGroupName = QString("testGroupPath_%1").arg(pathCounter);
		
		CComBSTR sPathname = uniquePathName.toStdWString().c_str();
		CComBSTR sGroupName = uniqueGroupName.toStdWString().c_str();
		ULONG uCoordianteID = 0;
		LONG bToolEndPosture = 0;
		ULONG uPathID = 0;
		
		m_ptrKit->Path_insert_from_point(uRobotID, 2, i_dPosition, 1, nInstruct, dVelocity, dSpeedPercent, nApproach, sPathname, sGroupName, uCoordianteID, bToolEndPosture, &uPathID, false);
		
		// 释放分配的内存
		delete[] i_dPosition;
		
		// 如果API提供了释放方法，使用API的方法释放内存
		if (o_dStartPosture) m_ptrKit->PQAPIFreeArray((LONG_PTR*)o_dStartPosture);
		if (o_dEndPosture) m_ptrKit->PQAPIFreeArray((LONG_PTR*)o_dEndPosture);
	}
	else {
		QMessageBox::information(pArcBoxView, "PQKit Info", QString::fromLocal8Bit("请先拾取面或线。"), QMessageBox::Ok);
	}
	
	// 关闭窗口并释放资源
	if (pArcBoxView) {
		// 释放内存
		if (pArcBoxView->DX) {
			delete pArcBoxView->DX;
			pArcBoxView->DX = nullptr;
		}
		if (pArcBoxView->DY) {
			delete pArcBoxView->DY;
			pArcBoxView->DY = nullptr;
		}
		if (pArcBoxView->DZ) {
			delete pArcBoxView->DZ;
			pArcBoxView->DZ = nullptr;
		}
		
		pArcBoxView->close();
		delete pArcBoxView;
		pArcBoxView = nullptr;
	}
}


void MainWindow::PickUpEdge() 
{ 
     PQPickupType ePickupType = PQ_SELECT_EDGE;
     m_ptrKit->Doc_start_pickup_element(ePickupType); 
} 

void MainWindow::PickUpFace()
{
	PQPickupType ePickupType = PQ_SELECT_FACE;
	m_ptrKit->Doc_start_pickup_element(ePickupType);
}
void MainWindow::EndPickup() 
{ 
     m_ptrKit->Doc_stop_pickup_element(); 
} 









void MainWindow::AlignPart()
{
	CComBSTR strCMD = "RO_CMD_AlignPart3Point";
	m_ptrKit->Doc_start_module(strCMD);
}

void MainWindow::Generatepath()
{
	CComBSTR strCMD = "RO_CMD_EXTERNAL_PATH_GENERATE";
	m_ptrKit->Doc_start_module(strCMD);
}

void MainWindow::Post()
{
	CComBSTR strCMD = "RO_CMD_POST";
	m_ptrKit->Doc_start_module(strCMD);
}

void MainWindow::OnInitializeResult(long lResult)
{
	if (lResult > 0)
	{
		//show kit
		ShowPQKitWindown();
	}
	else
	{
		QString strError = QString::fromLocal8Bit("组件初始化失败:\n");
		switch (lResult)
		{
		case -1:
			strError.append(QString::fromLocal8Bit("未知错误"));
			break;
		case -2:
			strError.append(QString::fromLocal8Bit("初始化超时"));
			break;
		case -3:
		case -4:
		case -6:
			strError.append(QString::fromLocal8Bit("加载组件动态库错误"));
			break;
		case -7:
			strError.append(QString::fromLocal8Bit("组件重复初始化"));
			break;
		case -9:
		case -10:
		case -11:
		case -12:
			strError.append(QString::fromLocal8Bit("内部数据错误"));
			break;
		case -14:
			strError.append(QString::fromLocal8Bit("非开发版账号不能登录开发版"));
			break;
		default:
			strError.append(QString::fromLocal8Bit("错误码: "));
			strError.append(QString::number(lResult, 10));
			break;
		}

		QMessageBox::information(NULL, "PQKit Info", strError, QMessageBox::Ok);
	}
}

void MainWindow::OnLoginResult(int i_nLoginType)
{
	if (i_nLoginType < 0)
	{
		QString strError = QString::fromLocal8Bit("用户校验失败:\n");
		switch (i_nLoginType)
		{
		case -1:
			strError.append(QString::fromLocal8Bit("密码错误"));
			break;
		case -2:
			strError.append(QString::fromLocal8Bit("用户不存在"));
			break;
		case -4:
			strError.append(QString::fromLocal8Bit("用户已过期"));
			break;
		case -6:
			strError.append(QString::fromLocal8Bit("网络连接失败"));
			break;
		case -7:
			strError.append(QString::fromLocal8Bit("用户未激活"));
			break;
		case -14:
			strError.append(QString::fromLocal8Bit("账号与产品不匹配"));
			break;
		default:
			strError.append(QString::fromLocal8Bit("错误码: "));
			strError.append(QString::number(i_nLoginType));
			break;
		}

		QMessageBox::information(NULL, "PQKit Info", strError, QMessageBox::Ok);

	}
}

//没用的槽函数
void MainWindow::OnElementPickup(unsigned long i_ulObjID, LPWSTR i_lEntityID, int i_nEntityType,
	double i_dPointX, double i_dPointY, double i_dPointZ)
{
	qDebug() << QString::fromLocal8Bit("当前拾取到的元素是： ") << QString::fromWCharArray(i_lEntityID);

}

//拾取面后的槽函数
void MainWindow::OnFaceElementPickup(unsigned long i_ulObjID, LPWSTR i_lEntityID, int i_nEntityType,
	double i_dPointX, double i_dPointY, double i_dPointZ)
{
	if (i_nEntityType == 2) {
		pArcBoxView->setFaceText(QString::fromWCharArray(i_lEntityID));
		
		// 释放之前分配的内存
		if (pArcBoxView->DX) {
			delete pArcBoxView->DX;
			pArcBoxView->DX = nullptr;
		}
		if (pArcBoxView->DY) {
			delete pArcBoxView->DY;
			pArcBoxView->DY = nullptr;
		}
		if (pArcBoxView->DZ) {
			delete pArcBoxView->DZ;
			pArcBoxView->DZ = nullptr;
		}
		
		// 分配新的内存
		pArcBoxView->DX = new double(0.0);
		pArcBoxView->DY = new double(0.0);
		pArcBoxView->DZ = new double(0.0);
		
		m_ptrKit->Part_get_face_normal_by_name(i_lEntityID, i_dPointX, i_dPointY, i_dPointZ, pArcBoxView->DX, pArcBoxView->DY, pArcBoxView->DZ);
		pArcBoxView->FaceIfReady = true;
	}
	EndPickup();
}

//拾取线后的槽函数
void MainWindow::OnEdgeElementPickup(unsigned long i_ulObjID, LPWSTR i_lEntityID, int i_nEntityType,
	double i_dPointX, double i_dPointY, double i_dPointZ)
{
	if (i_nEntityType == 4) {
		pArcBoxView->setEdgeText(QString::fromWCharArray(i_lEntityID));
		
		// 释放之前分配的内存
		if (pArcBoxView->o_dStartPoint) {
			m_ptrKit->PQAPIFreeArray((LONG_PTR*)pArcBoxView->o_dStartPoint);
			pArcBoxView->o_dStartPoint = nullptr;
		}
		if (pArcBoxView->o_dEndPoint) {
			m_ptrKit->PQAPIFreeArray((LONG_PTR*)pArcBoxView->o_dEndPoint);
			pArcBoxView->o_dEndPoint = nullptr;
		}
		if (pArcBoxView->o_dStartTanVector) {
			m_ptrKit->PQAPIFreeArray((LONG_PTR*)pArcBoxView->o_dStartTanVector);
			pArcBoxView->o_dStartTanVector = nullptr;
		}
		if (pArcBoxView->o_dEndTanVector) {
			m_ptrKit->PQAPIFreeArray((LONG_PTR*)pArcBoxView->o_dEndTanVector);
			pArcBoxView->o_dEndTanVector = nullptr;
		}
		
		int o_nStartPointCount = 0;
		int o_nEndPointCount = 0;
		double* o_dStartPoint = nullptr;
		double* o_dEndPoint = nullptr;
		double* o_dStartTanVector = nullptr;
		int o_nStartVectorSize = 0;
		double* o_dEndTanVector = nullptr;
		int o_nEndVectorSize = 0;
		m_ptrKit->Part_get_extreme_point_of_edge_by_name(i_lEntityID, &o_dStartPoint, &o_nStartPointCount, &o_dStartTanVector, &o_nStartVectorSize, &o_dEndPoint, &o_nEndPointCount, &o_dEndTanVector, &o_nEndVectorSize);
		pArcBoxView->o_nStartPointCount = o_nStartPointCount;
		pArcBoxView->o_nEndPointCount = o_nEndPointCount;
		pArcBoxView->o_dStartPoint = o_dStartPoint;
		pArcBoxView->o_dEndPoint = o_dEndPoint;
		pArcBoxView->o_dStartTanVector = o_dStartTanVector;
		pArcBoxView->o_dEndTanVector = o_dEndTanVector;	
		pArcBoxView->o_nStartVectorSize = o_nStartVectorSize;
		pArcBoxView->o_nEndVectorSize = o_nEndVectorSize;
		pArcBoxView->EdgeIfReady = true;
	}
	EndPickup();
}


void MainWindow::OnElementSelection(LPWSTR i_wObjNames, LPWSTR i_wFaceNames, double* i_dPointXYZ, int i_nSize)
{
	qDebug() << QString::fromLocal8Bit("当前拾取到的元素是： ") << QString::fromWCharArray(i_wObjNames);
}

