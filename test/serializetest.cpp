#include "serializetest.h"
#include "DataInfoSerialItf.h"
#include "TestSerialObject.h"

#include "SerialOperator.h"
#include "DataBuffSerial.h"
#include "SerialPointer.h"


#include <stdio.h>
#define GLOBAL_BUFSIZE 1000

struct RPC_FUNCHEADER
{
	unsigned int sequenceID;
};


SerializeTest::SerializeTest(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	/*
	QPushButton *structBtn;
	QPushButton *stringBtn;
	QPushButton *DataBufferBtn;
	QPushButton *SerialPointerBtn;
	QPushButton *vectorBtn;
	QPushButton *vectorPtrBtn;
	QPushButton *InterfaceBtn;
	QPushButton *SerialObjectBtn;
	QPushButton *ExceptionBtn;
	*/
	connect(ui.structBtn, SIGNAL(clicked()), this, SLOT(OnBnClickedButtonStruct()));
	connect(ui.stringBtn, SIGNAL(clicked()), this, SLOT(OnBnClickedButtonString()));
	connect(ui.DataBufferBtn, SIGNAL(clicked()), this, SLOT(OnBnClickedButtonDatabuffer()));
	connect(ui.SerialPointerBtn, SIGNAL(clicked()), this, SLOT(OnBnClickedButtonSerialpointer()));
	connect(ui.vectorBtn, SIGNAL(clicked()), this, SLOT(OnBnClickedButtonVector()));
	connect(ui.vectorPtrBtn, SIGNAL(clicked()), this, SLOT(OnBnClickedButtonVectorptr()));
	connect(ui.InterfaceBtn, SIGNAL(clicked()), this, SLOT(OnBnClickedButtonInterface()));
	connect(ui.SerialObjectBtn, SIGNAL(clicked()), this, SLOT(OnBnClickedButtonSerialobject()));
	connect(ui.ExceptionBtn, SIGNAL(clicked()), this, SLOT(OnBnClickedButtonException()));
}

SerializeTest::~SerializeTest()
{

}


void SerializeTest::OnBnClickedButtonStruct()
{
	// TODO: 在此添加控件通知处理程序代码
	int data = 1, data1;
	RPC_FUNCHEADER header, header1;
	header.sequenceID = 12;
	char szBuffer[GLOBAL_BUFSIZE] = "\0";
	CSerialOperator oper;
	oper.SetDataBuffer(szBuffer, GLOBAL_BUFSIZE);
	try
	{
		oper << data << header;
		oper >> data1 >> header1;
	}
	catch (CSerialException& e)
	{
		printf("%d %d", e._dataSize, e._errInfo);	
	}
}


void SerializeTest::OnBnClickedButtonString()
{
	// TODO: 在此添加控件通知处理程序代码
	string data = "12345678" , data1;
	wstring wdata = L"123344", wdata1;

	char szBuffer[GLOBAL_BUFSIZE] = "\0";
	CSerialOperator oper;
	oper.SetDataBuffer(szBuffer, GLOBAL_BUFSIZE);
	try
	{
		oper << data << wdata;
		oper >> data1 >> wdata1;
	}
	catch (CSerialException& e)
	{
		printf("%d %d", e._dataSize, e._errInfo);	
	}
}


void SerializeTest::OnBnClickedButtonDatabuffer()
{
	// TODO: 在此添加控件通知处理程序代码
	char* pData = "12345678901";
	CDataBuffSerial databuff(pData, strlen(pData));
	CDataBuffSerial databuff1;
	char szBuffer[GLOBAL_BUFSIZE] = "\0";
	CSerialOperator oper;
	oper.SetDataBuffer(szBuffer, GLOBAL_BUFSIZE);
	try
	{
		oper << databuff;
		oper >> databuff1;
	}
	catch (CSerialException& e)
	{
		printf("%d %d", e._dataSize, e._errInfo);	
	}
}


void SerializeTest::OnBnClickedButtonSerialpointer()
{
	// TODO: 在此添加控件通知处理程序代码
	RPC_FUNCHEADER header;
	header.sequenceID = 12;
	CSerialPointer<RPC_FUNCHEADER> data(&header);
	CSerialPointer<RPC_FUNCHEADER> data1;


	char szBuffer[GLOBAL_BUFSIZE] = "\0";
	CSerialOperator oper;
	oper.SetDataBuffer(szBuffer, GLOBAL_BUFSIZE);
	try
	{
		oper << data;
		header.sequenceID = 0;
		oper >> data;
		// 自动创建
		oper << data;
		oper >> data1;
		// 对象指针

		// 对象指针自动创建

	}
	catch (CSerialException& e)
	{
		printf("%d %d", e._dataSize, e._errInfo);	
	}
}


void SerializeTest::OnBnClickedButtonVector()
{
	// TODO: 在此添加控件通知处理程序代码
	char szBuffer[GLOBAL_BUFSIZE] = "\0";
	CSerialOperator oper;
	oper.SetDataBuffer(szBuffer, GLOBAL_BUFSIZE);
	// vector 
	CDataInfoSerialItf info1, info2;
	vector< CDataInfoSerialItf > vect, vect1;
	vect.push_back(info1);
	vect.push_back(info2);
	try
	{
		oper << vect;
		oper >> vect1;
	}
	catch (CSerialException& e)
	{
		printf("%d %d", e._dataSize, e._errInfo);	
	}
	// list
	list< CDataInfoSerialItf > listInfo, listInfo1;
	listInfo.push_back(info1);
	listInfo.push_back(info2);
	try
	{
		oper << listInfo;
		oper >> listInfo1;
	}
	catch (CSerialException& e)
	{
		printf("%d %d", e._dataSize, e._errInfo);	
	}
}


void SerializeTest::OnBnClickedButtonVectorptr()
{
	// TODO: 在此添加控件通知处理程序代码
	char szBuffer[GLOBAL_BUFSIZE] = "\0";
	CSerialOperator oper;
	oper.SetDataBuffer(szBuffer, GLOBAL_BUFSIZE);
	// 测试接口对象的序列化和解析
	char* pData = "123456789";
	CDataBuffSerial* pSerial1 = new  CDataBuffSerial(pData, strlen(pData));
	CDataBuffSerial* pSerial2 = new  CDataBuffSerial(pData, strlen(pData));
	CSerialPointer<CDataBuffSerial> pointer1(pSerial1);
	CSerialPointer<CDataBuffSerial> pointer2(pSerial2);
	vector< CSerialPointer<CDataBuffSerial> > vecPoint;
	printf("vecPoint.push_back(pointer1)\n");
	vecPoint.push_back(pointer1);
	vecPoint.push_back(pointer2);
	printf("vecPoint.push_back(pointer2)\n");
	try
	{
		oper << vecPoint;
		oper >> vecPoint;
	}
	catch (CSerialException& e)
	{
		printf("%d %d", e._dataSize, e._errInfo);	
	}
	// 
	vector<CDataBuffSerial> vecPoint1;
	vecPoint1.push_back(*pSerial1);
	vecPoint1.push_back(*pSerial2);
	printf("vecPoint1.push_back(*pSerial2)\n");
	try
	{
		oper << vecPoint1;
		oper >> vecPoint1;
	}
	catch (CSerialException& e)
	{
		printf("%d %d", e._dataSize, e._errInfo);	
	}
	delete pSerial1;
	delete pSerial2;
}


void SerializeTest::OnBnClickedButtonInterface()
{
	// TODO: 在此添加控件通知处理程序代码
	char szBuffer[GLOBAL_BUFSIZE] = "\0";
	CSerialOperator oper;
	oper.SetDataBuffer(szBuffer, GLOBAL_BUFSIZE);
	CDataInfoSerialItf data, data1;
	data._value = 2;
	data._string = "123";
	try
	{
		oper << data;
		oper >> data1;
	}
	catch (CSerialException& e)
	{
		printf("%d %d", e._dataSize, e._errInfo);	
	}	
}


void SerializeTest::OnBnClickedButtonSerialobject()
{
	// TODO: 在此添加控件通知处理程序代码
	char szBuffer[GLOBAL_BUFSIZE] = "\0";
	CSerialOperator oper;
	oper.SetDataBuffer(szBuffer, GLOBAL_BUFSIZE);
	CTestSerialObject data, data1;
	data.m_nData = 5;
	try
	{
		oper << data;
		oper >> data1;
	}
	catch (CSerialException& e)
	{
		printf("%d %d", e._dataSize, e._errInfo);	
	}

	CTestSerialObject *pdata, *pdata1;
	pdata = new CTestSerialObject;
	pdata->m_nData = 5;
	pdata1 = new CTestSerialObject;
	pdata1->m_nData = 3;
	CSerialPointer<CTestSerialObject> pointer1(pdata);
	CSerialPointer<CTestSerialObject> pointer2(pdata1);
	vector< CSerialPointer<CTestSerialObject> > vecPoint;
	printf("vecPoint.push_back(pointer1)\n");
	vecPoint.push_back(pointer1);
	vecPoint.push_back(pointer2);
	printf("vecPoint.push_back(pointer2)\n");
	try
	{
		oper << vecPoint;
		oper >> vecPoint;
	}
	catch (CSerialException& e)
	{
		printf("%d %d", e._dataSize, e._errInfo);	
	}
	delete pdata;
	delete pdata1;
}


void SerializeTest::OnBnClickedButtonException()
{
	// TODO: 在此添加控件通知处理程序代码	
	try
	{
		char szBuffer[GLOBAL_BUFSIZE] = "1234567";
		CSerialOperator test1(szBuffer, 2);
		int i = 5;		
		test1 << i;	
	}
	catch(CSerialException& exp)
	{
		int j = 0;		
	}
}
