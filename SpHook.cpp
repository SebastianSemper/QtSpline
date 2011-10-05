#include "SpHook.h"

using namespace std;

SpHook::SpHook(QPointF pos, int typ){
	position = pos;
	this->setPos(pos-QPointF(2,2));
	type = typ;
}

SpHook::~SpHook(){
	
}

QRectF SpHook::boundingRect() const{
	return QRectF(0, 0, 20, 20);
}
void SpHook::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
	painter->setRenderHint(QPainter::Antialiasing);
        painter->setBrush(Qt::blue);
        painter->drawEllipse(-10, -10, 20, 20);
        
        
}

QPointF SpHook::GetPosition(){
	return position;
}

void SpHook::SetPosition(QPointF pos){
	position = pos;
}
