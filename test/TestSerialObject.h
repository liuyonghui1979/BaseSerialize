#ifndef _TESTSERIALOBJECT_H
#define _TESTSERIALOBJECT_H
#include "baseserialobject.h"
class CTestSerialObject : public CBaseSerialObject
{
public:
	CTestSerialObject(void);
	~CTestSerialObject(void);
	int m_nData;
protected:
	// 序列化数据部分
	virtual void SerialMember(CSerialOperator& oper);
	// 解析数据部分
	virtual void ParseMember(CSerialOperator& oper);	
public:
	static const unsigned short BASECLASS_ID = 0x01;	
};

#endif