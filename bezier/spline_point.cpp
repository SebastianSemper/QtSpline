#include "spline_point.h"

using namespace std;

spline_point::spline_point(){
	radius = 10;
	setAcceptHoverEvents(true);
}

spline_point::spline_point(int x, int y){
	position.setX(x);
	position.setY(y);
	setPos(position);
	radius = 10;
	setAcceptHoverEvents(true);
}

spline_point::~spline_point(){

}

int spline_point::getX(){
	return position.x();
}
int spline_point::getY(){
	return position.y();
}

void spline_point::setpos(int x, int y){
	position.setX(x);
	position.setY(y);
	setPos(position);
}

void spline_point::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
	painter->setRenderHint(QPainter::Antialiasing);
        painter->setBrush(Qt::blue);
        painter->drawEllipse(0, 0, radius, radius);
}

QRectF spline_point::boundingRect() const{
	return QRectF(0,0, 2*radius, 2*radius);
}

void spline_point::mousePressEvent(QGraphicsSceneMouseEvent * event){
	event->setAccepted(true);
	drag_start = event->pos();
}

void spline_point::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
	QPointF maus_pos = event->pos();
	position += maus_pos-drag_start;
	setPos(position);
}

void spline_point::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
	radius = 20;
	update();
}
void spline_point::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
	radius = 10;
	update();
}
