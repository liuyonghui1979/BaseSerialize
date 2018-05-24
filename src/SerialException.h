// SerialException.h: interface for the CSerialException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERIALEXCEPTION_H__B68F54D9_EE2C_4364_AB1A_41D34CA112E8__INCLUDED_)
#define AFX_SERIALEXCEPTION_H__B68F54D9_EE2C_4364_AB1A_41D34CA112E8__INCLUDED_

#include "BaseSerializeIncude.h"
class CSerialOperator;

class BASESERIALIZE_DLL CSerialException  
{

public:
	CSerialException();
	CSerialException(const CSerialException& exp);
	CSerialException& operator=(const CSerialException& exp);

	virtual ~CSerialException();
	enum SERIAL_ERROR
	{
		ERROR_WRITE_BUFFERLEN,
		ERROR_READ_DATALEN,
		ERROR_READ_DATAINFO,
		ERROR_SERIAL_OBJECT
	};
public:	
	unsigned int _dataSize;
	SERIAL_ERROR _errInfo;
};

#endif // !defined(AFX_SERIALEXCEPTION_H__B68F54D9_EE2C_4364_AB1A_41D34CA112E8__INCLUDED_)
