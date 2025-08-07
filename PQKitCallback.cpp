#include "PQKitCallback.h"

CPQKitCallback::CPQKitCallback(QObject *parent)
	: QObject(parent)
{

}

CPQKitCallback::~CPQKitCallback()
{
}

HRESULT CPQKitCallback::Fire_Initialize_Result(long lResult)
{
	emit signalInitializeResult(lResult);
	return S_OK;
}

HRESULT CPQKitCallback::Fire_Login_Result(int i_nLoginType)
{
	emit signalLoginResult(i_nLoginType);
	return S_OK;
}

HRESULT CPQKitCallback::Fire_Element_Pickup(unsigned long i_ulObjID, LPWSTR i_wsEntityName, int i_nEntityType, double i_dPointX, double i_dPointY, double i_dPointZ)
{
	emit signalElementPickup(i_ulObjID, i_wsEntityName,i_nEntityType, i_dPointX,i_dPointY,i_dPointZ);
	return S_OK;
}

HRESULT CPQKitCallback::Fire_Element_Selection(LPWSTR i_wObjNames, LPWSTR i_wFaceNames, double* i_dPointXYZ, int i_nSize)
{
	emit signalElementSelection(i_wObjNames, i_wFaceNames, i_dPointXYZ, i_nSize);
	return S_OK;
}
