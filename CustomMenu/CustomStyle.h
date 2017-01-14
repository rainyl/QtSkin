#pragma once
#include <QObject>
#include <QProxyStyle>
#include <QStyleOption>

// �ο�QtԴ��, qfunsionstyle

/**@brief ���Ʋ˵�style
	@author  lwh 
*/
class CCustomStyle : public QProxyStyle
{
	Q_OBJECT

public:
	CCustomStyle(QStyle *style = 0); 

	void drawControl(ControlElement control, const QStyleOption *option,
		QPainter *painter, const QWidget *widget) const;

	void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
		QPainter *painter, const QWidget *widget) const; 

	int pixelMetric ( PixelMetric pm, const QStyleOption * opt, const QWidget * widget) const; 

private:
	void _DrawMenuItem(const QStyleOption *option,
		QPainter *painter, const QWidget *widget) const; 
	QPixmap 	_pixShadow	 ; //��ӰͼƬ	
};