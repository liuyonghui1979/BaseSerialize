// SerialOperator.h: interface for the CSerialOperator class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERIALOPERATOR_H__D81A70D0_AF78_4FFC_85E5_EC05ACB9B4E7__INCLUDED_)
#define AFX_SERIALOPERATOR_H__D81A70D0_AF78_4FFC_85E5_EC05ACB9B4E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BaseSerializeIncude.h"
#include "SerialException.h"
#include "SerialInterface.h"


#include <vector>
#include <list>
#include <string>
using namespace std;

template <typename T, typename TBase>
class TIsDerived 
{ 
public: 
	static int t(TBase* base) 
	{ 
		return 1; 
	} 
	static char t(void* t2)
	{ 
		return 0; 
	} 

	enum   
	{ 
		Result = (sizeof(int) == sizeof(t((T*)NULL))),
	}; 
};


class CDataBuffSerial;
class BASESERIALIZE_DLL CSerialOperator  
{
	friend class CDataBuffSerial;
public:
	CSerialOperator(char* pData = NULL, unsigned int len = 0);
	virtual ~CSerialOperator();
	template <typename Type> CSerialOperator& operator<<(Type& data)
	{
		WriteData(data);
		return *this;
	}
	template <typename Type> CSerialOperator& operator>>(Type& data)
	{
		ReadData(data);
		return *this;
	}
	void SetDataBuffer(char* pData, unsigned int len);
	unsigned int GetDataLen();
	void SetDataBgn(unsigned int data);
	unsigned int GetDataBgn();
	void SetDataEnd(unsigned int data);
	unsigned int GetDataEnd();
	void SetDataPostion(unsigned int bgn, unsigned int end);
	char* GetDataBgnPtr();
	char* GetBufferPtr();
	unsigned int GetBufferLen();
	
protected:
	void WriteData(const char* data, unsigned int len);
	void ReadData(char* data, unsigned int len);
	void WriteData(CSerialInterface* data);
	void ReadData(CSerialInterface* data);	

	template <typename Type> void WriteData(Type& data)
	{
		bool bIsDerived = TIsDerived <Type, CSerialInterface>::Result; 
		if(bIsDerived == false)
		{
			unsigned short nLen = sizeof(data);
			WriteData((const char*)&data, nLen);
		}
		else
		{
			CSerialInterface* pobj = (CSerialInterface*)&data;	
			if(pobj->_serialItfID == CSerialInterface::SERIALITF_ID)
			{
				WriteData(pobj);	
			}
			else
			{
				CSerialException excep;
				excep._dataSize = 0;
				excep._errInfo = CSerialException::ERROR_SERIAL_OBJECT;
				throw excep;
			}
		}		
	};
	template <typename Type> void ReadData(Type& data)
	{
		bool bIsDerived = TIsDerived <Type, CSerialInterface>::Result; 	
		if(bIsDerived == false)
		{
			unsigned short nLen = sizeof(data);
			ReadData((char*)&data, nLen);
		}
		else
		{
			CSerialInterface* pobj = (CSerialInterface*)&data;
			if(pobj->_serialItfID == CSerialInterface::SERIALITF_ID)
			{
				ReadData(pobj);		
			}
			else
			{
				CSerialException excep;
				excep._dataSize = 0;
				excep._errInfo = CSerialException::ERROR_SERIAL_OBJECT;
				throw excep;
			}
		}
	};	

	void WriteData(string& data);
	void ReadData(string& data);
	void WriteData(wstring& data);
	void ReadData(wstring& data);

	template <typename Type> void WriteData(vector<Type>& data)
	{
		unsigned short nSize = data.size();
		WriteData(nSize);
		for(unsigned short i = 0; i < nSize; i++)
		{
			WriteData(data[i]);
		}
	};
	template <typename Type> void ReadData(vector<Type>& data)
	{
		data.clear();
		unsigned short nSize = 0;
		ReadData(nSize);	
		data.resize(nSize);
		for(unsigned short i = 0; i < nSize; i++)
		{
			ReadData(data[i]);
		}
	};	
	template <typename Type> void WriteData(list<Type>& data)
	{
		unsigned short nSize = data.size();
		WriteData(nSize);
		typename list<Type>::iterator dataIt = data.begin();
		while(dataIt != data.end())
		{
			WriteData(*dataIt);
			dataIt++;
		}
	};
	template <typename Type> void ReadData(list<Type>& data)
	{
		data.clear();
		unsigned short nSize = 0;
		ReadData(nSize);
		data.resize(nSize);
		typename list<Type>::iterator dataIt = data.begin();
		while(dataIt != data.end())
		{
			ReadData(*dataIt);
			dataIt++;
		}	
	};

private:
	char* _pBuffer;
	unsigned int _buffLen;	
	unsigned int _dataEnd;
	unsigned int _dataBgn;
};



#endif // !defined(AFX_SERIALOPERATOR_H__D81A70D0_AF78_4FFC_85E5_EC05ACB9B4E7__INCLUDED_)
