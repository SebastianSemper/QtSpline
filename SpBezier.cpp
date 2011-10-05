#include "SpBezier.h"

using namespace std;


SpBezier::SpBezier(SpNode &a,SpNode &b){
	QPointF P1 = a.GetPosition(), P2 = b.GetPosition(), A1 = a.getRig()->GetPosition(), A2 = b.getRig()->GetPosition();
	curve.append(P1);
	curve.append(A1);
	curve.append(A2);
	curve.append(P2);
	
	genB();
}

void SpBezier::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
	painter->setRenderHint(QPainter::Antialiasing);
	
        painter->setBrush(Qt::black);
        QPointF *cp;
        cp = new QPointF[curve.size()];
        for(int i = 0; i < curve.size(); i++){
        	cp[i] = curve[i];
        }
        painter->drawPolyline(cp, curve.size());
        
}

QList<QPointF> teile(QList<QPointF> list, int index){
	QPointF tmp;
	
	list.insert(index+3, tmp); list.insert(index+2, tmp); list.insert(index+1, tmp);
	list[index+1].setX(0.5*list[index].x()+0.5*list[index+2].x()); list[index+1].setY(0.5*list[index].y()+0.5*list[index+2].y());
	list[index+5].setX(0.5*list[index+4].x()+0.5*list[index+6].x()); list[index+5].setY(0.5*list[index+4].y()+0.5*list[index+6].y());
	list[index+3].setX(0.5*list[index+2].x()+0.5*list[index+4].x()); list[index+3].setY(0.5*list[index+2].y()+0.5*list[index+4].y());
	list[index+2].setX(0.5*list[index+1].x()+0.5*list[index+3].x()); list[index+2].setY(0.5*list[index+1].y()+0.5*list[index+3].y());
	list[index+4].setX(0.5*list[index+3].x()+0.5*list[index+5].x()); list[index+4].setY(0.5*list[index+3].y()+0.5*list[index+5].y());
	list[index+3].setX(0.5*list[index+2].x()+0.5*list[index+4].x()); list[index+3].setY(0.5*list[index+2].y()+0.5*list[index+4].y());
	
	return list;
}

void SpBezier::genB(){
	curve = teile(curve, 0);
	curve = teile(curve, 3); curve = teile(curve, 0);
}

