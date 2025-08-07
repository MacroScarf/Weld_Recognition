#pragma once

#include <QObject>
#include "..\include\C++\PQKitCallBackBase.h"

class CPQKitCallback : public QObject, public CPQKitCallbackBase
{
	Q_OBJECT

public:
	CPQKitCallback(QObject* parent = nullptr);
	~CPQKitCallback();

public:
	//
	HRESULT Fire_Initialize_Result(long lResult);
	HRESULT Fire_Login_Result(int i_nLoginType);
	HRESULT Fire_Element_Pickup(unsigned long i_ulObjID, LPWSTR i_wsEntityName, int i_nEntityType,
		double i_dPointX, double i_dPointY, double i_dPointZ);
	HRESULT Fire_Element_Selection(LPWSTR i_wObjNames, LPWSTR i_wFaceNames, double* i_dPointXYZ, int i_nSize);

signals:                
	void signalInitializeResult(long lResult);
	void signalLoginResult(int i_nLoginType);
	void signalElementPickup(unsigned long i_ulObjID, LPWSTR i_wsEntityName, int i_nEntityType,
		double i_dPointX, double i_dPointY, double i_dPointZ);
	void signalElementSelection(LPWSTR i_wObjNames, LPWSTR i_wFaceNames, double* i_dPointXYZ, int i_nSize);

};
