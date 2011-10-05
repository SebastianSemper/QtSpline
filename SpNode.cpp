#include "SpNode.h"

using namespace std;

SpNode::SpNode(QPointF pos, QPointF tan_1, QPointF tan_2){
	position = pos;		
	lef = new SpHook(tan_1,1);
	rig = new SpHook(tan_2,2);	
	this->addToGroup(lef);
	this->addToGroup(rig);
	this->setPos(position);
}

SpNode::~SpNode(){
	
}

QRectF SpNode::boundingRect() const{
	return QRectF(0, 0, 20, 20);
}
void SpNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
	painter->setRenderHint(QPainter::Antialiasing);
	
        painter->setBrush(Qt::black);
        painter->drawLine(QPointF(0,0), lef->GetPosition());
        painter->drawLine(QPointF(0,0), rig->GetPosition());
        
        //painter->setBrush(Qt::red);
        //painter->drawEllipse(-5, -5, 10, 10);
}

QPointF SpNode::GetPosition(){
	return position;
}

void SpNode::SetPosition(QPointF pos){
	position = pos;
}
