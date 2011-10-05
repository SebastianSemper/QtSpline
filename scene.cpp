#include "scene.h"

using namespace std;

void scene::mousePressEvent(QGraphicsSceneMouseEvent *event){	
	SpNode *neu = new SpNode(event->scenePos()-QPointF(5,5),QPointF(-30,-30),QPointF(30,30));
	this->addItem(neu);
	points.insert(0,neu);
	numpoints += 1;
}
