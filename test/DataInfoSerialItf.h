#pragma once
#include <string>
#include "serialinterface.h"

class CSerialOperator;
class CDataInfoSerialItf :	public CSerialInterface
{
public:
	CDataInfoSerialItf(void);
	~CDataInfoSerialItf(void);

	CDataInfoSerialItf(const CDataInfoSerialItf& data);
	CDataInfoSerialItf& operator=(const CDataInfoSerialItf& data);

	// ���л�
	virtual void SerialData(CSerialOperator& oper);
	// ����
	virtual void ParseData(CSerialOperator& oper);
public:
	int _value;
	std::string _string;
};

