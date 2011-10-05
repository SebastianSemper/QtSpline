#ifndef BEZIER_H
#define BEZIER_H

#include <QGraphicsItem>
#include "spline_point.h"
#include <QPointF>
#include <iostream>
#include <QList>

using namespace std;

class bezier{
	private:
		//QPointF *p;
		QList<QPointF> p;
		
	public:
		bezier();
		~bezier();
		bezier(spline_point*, spline_point*, spline_point*, spline_point*);
		void curvepoints();
		QList<QPointF> getp();
		friend QList<QPointF> teile(QList<QPointF>*, int);
};

#endif
