// SerialInterface.h: interface for the CSerialInterface class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERIALINTERFACE_H__064610D4_BFD6_4632_AED9_7CD5FE7B3011__INCLUDED_)
#define AFX_SERIALINTERFACE_H__064610D4_BFD6_4632_AED9_7CD5FE7B3011__INCLUDED_

class CSerialOperator;
class CSerialInterface  
{
public:
	CSerialInterface() : _serialItfID(SERIALITF_ID){};
	virtual ~CSerialInterface(){};
public:	
	virtual void SerialData(CSerialOperator& oper) = 0;
	virtual void ParseData(CSerialOperator& oper) = 0;
	virtual unsigned int GetSerialLen(){return 0;}

	const static unsigned int SERIALITF_ID = 0xfefefefe;
	const unsigned int _serialItfID;
};

#endif // !defined(AFX_SERIALINTERFACE_H__064610D4_BFD6_4632_AED9_7CD5FE7B3011__INCLUDED_)
