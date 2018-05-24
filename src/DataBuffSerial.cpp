#include "DataBuffSerial.h"
#include "SerialOperator.h"
#include <string.h>
//#include "DebugLeaks.h"

CDataBuffSerial::CDataBuffSerial(char* pData, unsigned int len, bool create)
{
	_pBuffer = pData;
	_dataLen = len;
	_create = create;
}
void CDataBuffSerial::SetData(char* pData, unsigned int len, bool create)
{
	if(_create)
	{
		delete[] _pBuffer;
		_pBuffer = NULL;
	}
	_pBuffer = pData;
	_dataLen = len;
	_create = create;
}

CDataBuffSerial::~CDataBuffSerial(void)
{
	if(_create)
	{
		delete[] _pBuffer;
		_pBuffer = NULL;
	}
}


CDataBuffSerial::CDataBuffSerial(const CDataBuffSerial& data)
{
	_pBuffer = data._pBuffer;
	_dataLen = data._dataLen;
	_create = false;
}

CDataBuffSerial& CDataBuffSerial::operator=(const CDataBuffSerial& data)
{
	if(_create == true && _pBuffer != 0)
	{
		delete[] _pBuffer;
	}
	_pBuffer = data._pBuffer;
	_dataLen = data._dataLen;
	_create = false;
	return *this;
}

// ���л�
void CDataBuffSerial::SerialData(CSerialOperator& oper)
{
	oper.WriteData(_dataLen);
	oper.WriteData(_pBuffer, _dataLen);
}

// ����
void CDataBuffSerial::ParseData(CSerialOperator& oper)
{
	unsigned int dataLen = 0;
	oper.ReadData(dataLen);
	// �ж��Ƿ��ؽ�������	
	if(_dataLen < dataLen)
	{
		if(_create == true)
		{
			delete[] _pBuffer;
		}
		_pBuffer = new char[dataLen];
		_create = true;	
	}
	// ��ȡ����
	_dataLen = dataLen;
	oper.ReadData(_pBuffer, _dataLen);
}
