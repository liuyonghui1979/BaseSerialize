// SerialObject.h: interface for the CSerialObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERIALOBJECT_H__62A98E9C_FFE0_4190_B0FD_69CC23034EB0__INCLUDED_)
#define AFX_SERIALOBJECT_H__62A98E9C_FFE0_4190_B0FD_69CC23034EB0__INCLUDED_

#include "BaseSerializeIncude.h"
#include "SerialInterface.h"
#include "RPCBaseObject.h"



class BASESERIALIZE_DLL CBaseSerialObject : public CRPCBaseObject, public CSerialInterface
{
public:
	CBaseSerialObject(unsigned short nID);
	virtual ~CBaseSerialObject();
protected:
	// 序列化数据部分
	virtual void SerialMember(CSerialOperator& oper) = 0;
	// 解析数据部分
	virtual void ParseMember(CSerialOperator& oper) = 0;
public:
	// 序列化
	virtual void SerialData(CSerialOperator& oper);
	// 解析
	virtual void ParseData(CSerialOperator& oper);
	// 当前版本号
	unsigned int _version;
};

#endif // !defined(AFX_SERIALOBJECT_H__62A98E9C_FFE0_4190_B0FD_69CC23034EB0__INCLUDED_)
