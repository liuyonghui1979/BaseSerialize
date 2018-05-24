// SerialOperator.cpp: implementation of the CSerialOperator class.
//
//////////////////////////////////////////////////////////////////////
#include "stdio.h"

#include "SerialInterface.h"
#include "SerialOperator.h"



#include <assert.h>
#include <string.h>


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSerialOperator::CSerialOperator(char* pData, unsigned int len)
{
	SetDataBuffer(pData, len);
}

CSerialOperator::~CSerialOperator()
{

}

// 设置缓冲区
void CSerialOperator::SetDataBuffer(char* pData, unsigned int len)
{
	_pBuffer = pData;
	_buffLen = len;
	_dataEnd = 0;
	_dataBgn = 0;
}

void CSerialOperator::SetDataPostion(unsigned int bgn, unsigned int end)
{
	assert(bgn <= end);
	assert(end <= _buffLen);
	_dataBgn = bgn;
	_dataEnd = end;
}

// 得到数据长度
unsigned int CSerialOperator::GetDataLen()
{
	return _dataEnd - _dataBgn;
}

void CSerialOperator::SetDataBgn(unsigned int data)
{
	if(_dataBgn > _dataEnd || _dataBgn >= _buffLen)
		return;
	_dataBgn = data;
}
unsigned int CSerialOperator::GetDataBgn()
{
	return _dataBgn;
}

char* CSerialOperator::GetDataBgnPtr()
{
	return _pBuffer + _dataBgn;
}

char* CSerialOperator::GetBufferPtr()
{
	return _pBuffer;
}

unsigned int CSerialOperator::GetBufferLen()
{
	return _buffLen;
}


void  CSerialOperator::SetDataEnd(unsigned int data)
{
	if(_dataEnd < _dataBgn || _dataEnd >= _buffLen)
		return;
	_dataEnd = data;
}

unsigned int CSerialOperator::GetDataEnd()
{
	return _dataEnd;
}

// string
void CSerialOperator::WriteData(string& data)
{
	unsigned short nlen = data.length()+1;
	WriteData(nlen);
	WriteData((const char*)data.data(), nlen);
}

void CSerialOperator::ReadData(string& data)
{
	unsigned short nlen = 0;
	ReadData(nlen);
	if(nlen > GetDataLen())
	{
		CSerialException excep;
		excep._dataSize = nlen;
		excep._errInfo = CSerialException::ERROR_READ_DATALEN;
		throw excep;	
	}
	if(_pBuffer[_dataBgn + nlen - 1] != 0)
	{
		CSerialException excep;
		excep._dataSize = 0;
		excep._errInfo = CSerialException::ERROR_READ_DATAINFO;
		throw excep;	
	}
	char* pTemp = new char[nlen];
	ReadData(pTemp, nlen);
	data = pTemp;
	delete[] pTemp;
}

void CSerialOperator::WriteData(wstring& data)
{
	unsigned short nlen = (data.length()+1)*2;
	WriteData(nlen);
	WriteData((const char*)data.data(), nlen);
}

void CSerialOperator::ReadData(wstring& data)
{
	unsigned short nlen = 0;
	ReadData(nlen);
	if(nlen > GetDataLen())
	{
		CSerialException excep;
		excep._dataSize = nlen;
		excep._errInfo = CSerialException::ERROR_READ_DATALEN;
		throw excep;	
	}
	if(nlen%2 != 0 || _pBuffer[_dataBgn + nlen - 1] != 0 ||  _pBuffer[_dataBgn + nlen - 2] != 0)
	{
		CSerialException excep;
		excep._dataSize = 0;
		excep._errInfo = CSerialException::ERROR_READ_DATAINFO;
		throw excep;	
	}
	// 数据生成
	char* pTemp = new char[nlen];
	ReadData(pTemp, nlen);
	data = (wchar_t*)pTemp;
	delete[] pTemp;
}

void CSerialOperator::WriteData(const char* data, unsigned int len)
{
	if(_dataEnd + len > _buffLen)
	{
		CSerialException excep;
		excep._dataSize = len;
		excep._errInfo = CSerialException::ERROR_WRITE_BUFFERLEN;		
		throw excep;
	}
	memcpy(_pBuffer + _dataEnd, data, len);
	_dataEnd += len;
}

void CSerialOperator::ReadData(char* data, unsigned int len)
{
	if(_dataBgn + len > _dataEnd)
	{
		CSerialException excep;
		excep._dataSize = len;
		excep._errInfo = CSerialException::ERROR_READ_DATALEN;
		throw excep;
	}
	memcpy(data, _pBuffer+_dataBgn, len);
	_dataBgn += len;
}		

void CSerialOperator::WriteData(CSerialInterface* data)
{
	if(data != NULL)
	{
		data->SerialData(*this);
	}
}

void CSerialOperator::ReadData(CSerialInterface* data)
{
	if(data != NULL)
	{
		data->ParseData(*this);
	}
}
