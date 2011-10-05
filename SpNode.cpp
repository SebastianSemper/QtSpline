#include "SpNode.h"

using namespace std;

SpNode::SpNode(QPointF pos, QPointF tan_1, QPointF tan_2){
	position = pos;
	mid = new SpHook(pos,0);	
	lef = new SpHook(tan_1,1);
	rig = new SpHook(tan_2,2);
	this->addToGroup(mid);
	this->addToGroup(lef);
	this->addToGroup(rig);	
}

SpNode::~SpNode(){
	
}

QRectF SpNode::boundingRect() const{
	return QRectF(0, 0, 20, 20);
}
void SpNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
	painter->setRenderHint(QPainter::Antialiasing);
        painter->setBrush(Qt::black);
        painter->drawLine(position, lef->GetPosition());
        painter->drawLine(position, rig->GetPosition());
}

QPointF SpNode::GetPosition(){
	return position;
}

void SpNode::SetPosition(QPointF pos){
	position = pos;
}
