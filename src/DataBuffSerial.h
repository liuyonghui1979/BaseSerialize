#ifndef _DATABUFFSERIAL_H
#define _DATABUFFSERIAL_H 

#include "serialinterface.h"
#include "BaseSerializeIncude.h"

class BASESERIALIZE_DLL CDataBuffSerial : public CSerialInterface
{
public:
	CDataBuffSerial(char* pData = 0, unsigned int len = 0, bool create = false);
	CDataBuffSerial(const CDataBuffSerial& data);
	~CDataBuffSerial(void);

	void SetData(char* pData, unsigned int len, bool create = false);

	CDataBuffSerial& operator=(const CDataBuffSerial& data);
	char* GetDataPtr(){return _pBuffer;}
	unsigned int GetDataLen(){return _dataLen;}
	virtual void SerialData(CSerialOperator& oper);
	virtual void ParseData(CSerialOperator& oper);
	virtual unsigned int GetSerialLen(){return _dataLen+4;}
private:
	char* _pBuffer;
	unsigned int _dataLen;
	bool _create;
};
#endif
