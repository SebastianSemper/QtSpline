#include "bezier.h"

using namespace std;

static int P_ANZ = 13;

bezier::bezier(){
	//p = 0;
}

bezier::bezier(spline_point *p1, spline_point *p2, spline_point *a1, spline_point *a2){
	
	//p = new QPointF[P_ANZ];
	//p << new QPointF << new QPointF << new QPointF << new QPointF;
	QPointF tmp;
	p.append(tmp);
	p.append(tmp);
	p.append(tmp);
	p.append(tmp);
	
	p[0].setX(p1->getX()); p[0].setY(p1->getY());
	p[1].setX(p2->getX()); p[1].setY(p2->getY());
	p[2].setX(a1->getX()); p[2].setY(a1->getY());
	p[3].setX(a2->getX()); p[3].setY(a2->getY());
	
	for(int i = 0; i < 4; i++){
		cout << p[i].x() << " - " << p[i].y() << endl;
	}
	
	curvepoints();
	
	for(int i = 0; i < 6; i++){
		cout << p[i].x() << " - " << p[i].y() << endl;
	}
}

bezier::~bezier(){
	//if(p != 0) delete[] p;
}

QList<QPointF> teile(QList<QPointF> list, int index){
	QPointF p[4], tmp;
	p[0] = list[index]; p[1] = list[index+1]; p[2] = list[index+2]; p[3] = list[index+3];
	
	list[index+1].setX(0.5*p[0].x()+0.5*p[1].x()); list[index+1].setY(0.5*p[0].y()+0.5*p[1].y());
	list[index+2].setX(0.5*p[2].x()+0.5*p[3].x()); list[index+2].setY(0.5*p[2].y()+0.5*p[3].y());
	list.insert(index+1, tmp);
	list[index+2].setX(0.5*p[1].x()+0.5*p[2].x()); list[index+2].setY(0.5*p[1].y()+0.5*p[2].y());
	list.insert(index+2, tmp); list.insert(index+1, tmp);
	
	for(int i = 0; i < 6; i++){
		cout << list[i].x() << " - " << list[i].y() << endl;
	}
	
	list[index+2].setX(0.5*list[index+1].x()+0.5*list[index+3].x()); list[index+2].setY(0.5*list[index+1].y()+0.5*list[index+3].y());
	list[index+4].setX(0.5*list[index+3].x()+0.5*list[index+5].x()); list[index+4].setY(0.5*list[index+3].y()+0.5*list[index+5].y());
	//list.removeAt(index+3);
	//list.insert(index+2, tmp);
	list[index+3].setX(0.5*list[index+2].x()+0.5*list[index+4].x()); list[index+3].setY(0.5*list[index+2].y()+0.5*list[index+4].y());
	
	for(int i = 0; i < 6; i++){
		cout << list[i].x() << " - " << list[i].y() << endl;
	}
	
	return list;
}

void bezier::curvepoints(){
	p = teile(p,0);
	//teile(p,0); teile(p,4);
	
}

QList<QPointF> bezier::getp(){
	return p;
}

