#include "scene.h"

using namespace std;

void scene::mousePressEvent(QGraphicsSceneMouseEvent *event){	
	SpNode *neu = new SpNode(event->scenePos()-QPointF(5,5),event->scenePos()-QPointF(30,30),event->scenePos()+QPointF(30,30));
	this->addItem(neu);
	points.insert(0,neu);
	numpoints += 1;
}
