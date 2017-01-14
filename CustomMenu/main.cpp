#include "custommenu.h"
#include <QtWidgets/QApplication>

#include "CustomStyle.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setStyle(new CCustomStyle); 
	TestDialog w;
	w.show();
	return a.exec();
}
