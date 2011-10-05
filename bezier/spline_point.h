#ifndef SPLINE_POINT_H
#define SPLINE_POINT_H

#include <QGraphicsItem>
#include <QPointF>
#include <QRectF>
#include <QPolygonF>
#include <QPainter>
#include <QPainterPath>
#include <QWidget>
#include <iostream>
#include <QGraphicsSceneHoverEvent>

using namespace std;

class spline_point:public QGraphicsItem {
	private:
		QPointF drag_start;
		QPointF position;
		int radius;
		
	public:
		spline_point();
		spline_point(int,int);
		~spline_point();
		QRectF boundingRect() const;
		void setpos(int,int);
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
		void mousePressEvent(QGraphicsSceneMouseEvent *event);
		void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
		void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
		void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
		int getX();
		int getY();
};



#endif 
