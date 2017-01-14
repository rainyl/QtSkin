#ifndef CUSTOMMENU_H
#define CUSTOMMENU_H

#include <QtWidgets/QWidget>
#include <QMenu>

class TestDialog : public QWidget
{
	Q_OBJECT

public:
	TestDialog(QWidget *parent = 0);
	~TestDialog();


protected:
	void contextMenuEvent(QContextMenuEvent *event);

private:

};

/**@brief 定制化的QMenu
	@author  lwh 
*/
class CCustomMenu : public QMenu
{
	Q_OBJECT
public:
	explicit CCustomMenu(const QString &title, QWidget *parent = 0);
	explicit CCustomMenu(QWidget *parent = 0);

	~CCustomMenu();

	// 重写QMenu::addmenu
	QAction *addMenu(CCustomMenu *menu);
	CCustomMenu *addMenu(const QString &title);
	CCustomMenu *addMenu(const QIcon &icon, const QString &title);

protected:
	bool event(QEvent *event);

private:
	void _Init(); 
};



#endif // CUSTOMMENU_H
