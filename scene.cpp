#include "scene.h"

using namespace std;

void scene::mousePressEvent(QGraphicsSceneMouseEvent *event){
	if (event->buttons() & Qt::LeftButton) {		
		pos_klick = event->scenePos();
		SpNode *neu = new SpNode(pos_klick,QPointF(0,0),QPointF(0,0));
		this->addItem(neu);
		points.insert(points.size(),neu);
		numpoints += 1;
		
    	}
    	this->update();	
}

void scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    	
	points.last()->getLef()->SetPosition(QPointF(0,0)-pos_klick+event->scenePos());
	points.last()->getLef()->setPos(points.last()->getLef()->GetPosition());	
	points.last()->getRig()->SetPosition(pos_klick-event->scenePos());
	points.last()->getRig()->setPos(points.last()->getRig()->GetPosition());
	this->update();
	
}


