#include "custommenu.h"

#include <QContextMenuEvent>
//#include "dwmapi.h"
//#pragma comment( lib, "dwmapi.lib" )
#include <windows.h>

TestDialog::TestDialog(QWidget *parent)
	: QWidget(parent)
{
	this->setStyleSheet("TestDialog {background-color: #99AAC1}");
}

TestDialog::~TestDialog()
{

}

void TestDialog::contextMenuEvent( QContextMenuEvent *event )
{
	auto *menu = new CCustomMenu(this); 
	auto item1 = new QAction(QIcon("E16.png"), "&item1...", this);
	auto itme2 = new QAction("&item2...", this);
	auto item3 = new QAction("&itme3...", this);
	auto item4 = new QAction(QIcon("E16.png"), "&item4...", this);

	menu->addAction(item1); 
	menu->addAction(itme2);
	menu->addSeparator(); 
	auto pSubMenu = menu->addMenu(QIcon("E16.png"), "sub menu");
	pSubMenu->addAction(item3); 
	pSubMenu->addAction(item4); 
	menu->exec(event->globalPos()); 
}


CCustomMenu::CCustomMenu( const QString &title, QWidget *parent /*= 0*/ )
	:QMenu(title, parent)
{
	_Init(); 
}

CCustomMenu::CCustomMenu( QWidget *parent /*= 0*/ )
	:QMenu(parent)
{
	_Init(); 
}

CCustomMenu::~CCustomMenu()
{

}

bool CCustomMenu::event(QEvent *event)
{
	static bool class_amended = false;
	if (event->type() == QEvent::WinIdChange)
	{
		HWND hwnd = reinterpret_cast<HWND>(winId());
		if (class_amended == false)
		{
			class_amended = true;
			DWORD class_style = ::GetClassLong(hwnd, GCL_STYLE);
			class_style &= ~CS_DROPSHADOW;
			::SetClassLong(hwnd, GCL_STYLE, class_style);
		}
		// dwn代码实现阴影, 要求vista+, 开启aero
		//DWMNCRENDERINGPOLICY val = DWMNCRP_ENABLED;
		//::DwmSetWindowAttribute(hwnd, DWMWA_NCRENDERING_POLICY, &val, sizeof(DWMNCRENDERINGPOLICY));

		//// This will turn OFF the shadow
		//// MARGINS m = {0};
		//// This will turn ON the shadow
		//MARGINS m = {-1};
		//HRESULT hr = ::DwmExtendFrameIntoClientArea(hwnd, &m);
		//if( SUCCEEDED(hr) )
		//{
		//	//do more things
		//}
	}
	return QWidget::event(event);
}

QAction * CCustomMenu::addMenu( CCustomMenu *menu )
{
	return QMenu::addMenu(menu); 
}

CCustomMenu * CCustomMenu::addMenu( const QString &title )
{
	CCustomMenu *menu = new CCustomMenu(title, this);
	addAction(menu->menuAction());
	return menu;
}

CCustomMenu * CCustomMenu::addMenu( const QIcon &icon, const QString &title )
{
	CCustomMenu *menu = new CCustomMenu(title, this);
	menu->setIcon(icon);
	addAction(menu->menuAction());
	return menu;
}

void CCustomMenu::_Init()
{
	// 必须设置popup, 因为QMenuPrivate::activateAction中使用QApplication::activePopupWidget()函数
	this->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint); 
	this->setAttribute(Qt::WA_TranslucentBackground); 
	this->setObjectName("CustomMenu");  // 以objectname 区分Qt内置菜单和CCustomMenu

}


