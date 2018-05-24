#include "serializetest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SerializeTest w;
	w.show();
	return a.exec();
}
