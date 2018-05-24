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

	// –Ú¡–ªØ
	virtual void SerialData(CSerialOperator& oper);
	// Ω‚Œˆ
	virtual void ParseData(CSerialOperator& oper);
public:
	int _value;
	std::string _string;
};

