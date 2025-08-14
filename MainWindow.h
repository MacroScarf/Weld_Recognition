#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#import "RPC.tlb" no_namespace, named_guids, raw_interfaces_only, raw_native_types

#include <QMainWindow>
#include <QCloseEvent>
#include <QMessageBox>
#include <QVector>
#include <QString>

#include "PQKitCallback.h"
#include "TestArcBoxView.h"
#include "..\include\C++\PQKitError.h"
#include <MainWindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

	void InitAction();
	void InitMenu();
	void InitToolBar();

	void InitPQKit();
	void ShowPQKitWindown();
	void GetObjIDByName(int i_nType, std::wstring i_wsName, ULONG &o_uID);
	void GetFirstPointOfPath(ULONG i_ulPathID, ULONG& o_ulPointIDe);

    struct EdgeInfo {
        QString name;
        int startPointCount = 0;
        int endPointCount = 0;
        int startVectorSize = 0;
        int endVectorSize = 0;
        QVector<double> startPoint;
        QVector<double> endPoint;
        QVector<double> startTanVector;
        QVector<double> endTanVector;
        QVector<QString> faceNames; // 存储包含这条边的面名称
    };

    struct EdgeGroup {
        QString groupName;           // 组名
        QVector<EdgeInfo> edges;    // 该组下的所有边
    };

	struct FaceInfo {
		QString name;
		QVector<double> normal; // size 3: [dx, dy, dz]
	};

    struct FaceGroup {
        QString groupName;           // 组名
        QVector<FaceInfo> faces;    // 该组下的所有面
    };

    struct WeldPair {
        EdgeInfo edgeInfo;    // 存储完整的边信息
        FaceInfo faceInfo;    // 存储完整的面信息
    };


private:
    Ui::MainWindow *ui;
	QAction* m_openAction;
	QAction* m_saveasAction;
	QAction* m_compileAction;
	QAction* m_simulateAction;
	QAction* m_insertpathAction;
	QAction* m_closefileAction;
	QAction* m_import3dAction;
	QAction* m_measureAction;
	QAction* m_arcboxAction;
	QAction* m_arcboxAction2; 
	QAction* m_weldRecognize;
	QAction* m_alignpartAction;
	QAction* m_generatepathAction;
	QAction* m_postAction; 
	QAction* m_getpathpoint;
	
	CComPtr<IPQPlatformComponent> m_ptrKit;
	CPQKitCallback* m_ptrKitCallback;

	QWidget* m_pPQPlatformView;
	QWidget* m_pPQModeTreeView;
	QWidget* m_pPQDebugView;

	TestArcBoxView* pArcBoxView;

private:
	void closeEvent(QCloseEvent* event);

protected slots:
	//owner
	void OnOpenRobx();
	void OnSaveAsRobx();
	void OnCompile();
	void OnSimulate();
	void OnInsertPath();
	void CloseFile();
	void Import3DObj();
	void Measure();
	void ArcBox();
	void WeldRecognize();
	void GetAllFacesGrouped(ULONG uID, QVector<FaceGroup>& outFaceGroups);
	void GetAllEdgesGrouped(ULONG uID, QVector<EdgeGroup>& outEdgeGroups);
	void GetAllEdges(ULONG uID, QVector<EdgeInfo>& outEdges);
	void GetAllFaces(ULONG uID, QVector<FaceInfo>& outFaces);
	void ArcBox2();
	void PickUpFace();
	void onPushButtonClicked();
	void PickUpEdge();
	void EndPickup();
	void AlignPart();
	void Generatepath();
	void Post();
	void GetPathPointInfo();

	//PQKit slots
	void OnInitializeResult(long lResult);
	void OnLoginResult(int i_nLoginType);
	void OnElementPickup(unsigned long i_ulObjID, LPWSTR i_lEntityID, int i_nEntityType,
		double i_dPointX, double i_dPointY, double i_dPointZ);
	void OnFaceElementPickup(unsigned long i_ulObjID, LPWSTR i_lEntityID, int i_nEntityType,
		double i_dPointX, double i_dPointY, double i_dPointZ);
	void OnEdgeElementPickup(unsigned long i_ulObjID, LPWSTR i_lEntityID, int i_nEntityType,
		double i_dPointX, double i_dPointY, double i_dPointZ);
	void OnElementSelection(LPWSTR i_wObjNames, LPWSTR i_wFaceNames, double* i_dPointXYZ, int i_nSize);

	void OnInitializeKitThread();

};
#endif // MAINWINDOW_H
