#ifndef serializetest_H
#define serializetest_H


#include <QtWidgets/QDialog>
#include "ui_serializetest.h"

class SerializeTest : public QDialog
{
	Q_OBJECT

public:
	SerializeTest(QWidget *parent = 0);
	~SerializeTest();


public slots:
	void OnBnClickedButtonStruct();
	void OnBnClickedButtonString();
	void OnBnClickedButtonDatabuffer();
	void OnBnClickedButtonSerialpointer();
	void OnBnClickedButtonVector();
	void OnBnClickedButtonVectorptr();
	void OnBnClickedButtonInterface();
	void OnBnClickedButtonSerialobject();
	void OnBnClickedButtonException();
private:
	Ui::SerializeTestClass ui;


};

#endif // RPCCLIENTTEST_H
