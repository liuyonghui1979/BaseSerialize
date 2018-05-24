
#if !defined(AFX_SERIALPOINTER_H__D81A70D0_AF78_4FFC_85E5_EC05ACB9B4E7__INCLUDED_)
#define AFX_SERIALPOINTER_H__D81A70D0_AF78_4FFC_85E5_EC05ACB9B4E7__INCLUDED_

#include <assert.h>
#include "SerialOperator.h"

template <typename T>
class CSerialPointer
{
public:
	CSerialPointer(T* ptr = 0);
	~CSerialPointer();

	CSerialPointer(const CSerialPointer<T>& data);
	CSerialPointer& operator=(const CSerialPointer<T>& data);

	// 请求控制权
	bool SetRelease(const CSerialPointer<T>& data);

	T* GetData();
private:
	T*  _pData;
	bool _create;
public:
	// 序列化
	void SerialData(CSerialOperator& oper);
	// 解析
	void ParseData(CSerialOperator& oper);
};

template <typename T>
CSerialPointer<T>::CSerialPointer(T* ptr)
{
	_pData = ptr;
	_create = false;
}

template <typename T>
CSerialPointer<T>::~CSerialPointer()
{
	if(_create == true && _pData != 0)
		delete _pData;
}

template <typename T>
CSerialPointer<T>::CSerialPointer(const CSerialPointer<T>& data)
{
	_pData = data._pData;
	_create = false;
}

// 请求控制权
template <typename T>
bool CSerialPointer<T>::SetRelease(const CSerialPointer<T>& data)
{
	if(_create == false || data._create == true)
		return false;
	// 
	data._create = true;
	_create = false;
}

template <typename T>
CSerialPointer<T>& CSerialPointer<T>::operator=(const CSerialPointer<T>& data)
{
	if(_create == true && _pData != 0)
	{
		delete _pData;
	}
	_pData = data._pData;
	_create = false;
	return *this;
}

template <typename T>
inline T* CSerialPointer<T>::GetData()
{
	return _pData;
}

template <typename T>
void CSerialPointer<T>::SerialData(CSerialOperator& oper)
{
	assert(_pData != 0);
	oper << *_pData;
}

template <typename T>
void CSerialPointer<T>::ParseData(CSerialOperator& oper)
{
	if(_pData == 0)
	{
		_pData = new T;
		_create = true;
	}
	oper >> *_pData;
}

#endif