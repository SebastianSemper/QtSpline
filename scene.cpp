#include "scene.h"

using namespace std;


void scene::mousePressEvent(QGraphicsSceneMouseEvent *event){
	
	if (event->buttons() & Qt::LeftButton) {		
		pos_klick = event->scenePos();
		
		//SpNode neu(pos_klick,QPointF(0,0),QPointF(0,0));
		
		SpNode *neu = new SpNode(pos_klick,QPointF(0,0),QPointF(0,0));
		
		//SpNode *p1 = points[0];
		
		//points.insert(points.size(), neu);
		points.append(neu);
		
		//numpoints += 1;
		
		this->addItem(neu);
		
		
		
    	}
    	this->update();	
}

void scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
	if(points.size() > 1){
		SpNode *p1 = points[points.size()-2], *p2 = points[points.size()-1];
		SpBezier *neu2 = new SpBezier(*p1, *p2);
		curves.insert(curves.size(), neu2);
		this->addItem(neu2);
	}
}

void scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    	
	points.last()->getLef()->SetPosition(QPointF(0,0)-pos_klick+event->scenePos());
	points.last()->getLef()->setPos(points.last()->getLef()->GetPosition());	
	points.last()->getRig()->SetPosition(pos_klick-event->scenePos());
	points.last()->getRig()->setPos(points.last()->getRig()->GetPosition());
	this->update();
	
}


