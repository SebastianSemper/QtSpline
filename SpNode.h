#ifndef SPNODE_H
#define SPNODE_H

#include <QGraphicsItemGroup>
#include <QPointF>
#include <QRectF>
#include <QPainter>
#include <QPainterPath>
#include <QWidget>
#include <iostream>
#include "SpHook.h"


using namespace std;

class SpNode:public QGraphicsItemGroup {
	private:
		QPointF position;
		SpHook *mid;
		SpHook *lef;
		SpHook *rig;
	public:
		SpNode(QPointF, QPointF, QPointF);
		~SpNode();
		QRectF boundingRect() const;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
		QPointF GetPosition();
		void SetPosition(QPointF);
};



#endif 
