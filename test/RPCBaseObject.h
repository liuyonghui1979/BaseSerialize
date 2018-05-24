// RPCObjectBase.h: interface for the CRPCObjectBase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RPCOBJECTBASE_H__51BFB890_939A_40E0_B22B_76B1771EA3B9__INCLUDED_)
#define AFX_RPCOBJECTBASE_H__51BFB890_939A_40E0_B22B_76B1771EA3B9__INCLUDED_


class CRPCBaseObject  
{
public:
	CRPCBaseObject(unsigned short nID) : _classID(nID) {};
	virtual ~CRPCBaseObject(){};

public:
	// classID
	const unsigned short _classID; 
};




#endif // !defined(AFX_RPCOBJECTBASE_H__51BFB890_939A_40E0_B22B_76B1771EA3B9__INCLUDED_)
