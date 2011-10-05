#include "gui.h"
#include "spline_point.h"
#include "bezier.h"

using namespace std;


gui::gui(QMainWindow *parent) : QMainWindow(parent){
        //Methode, die die erstellte GUI läd und erstellt.
        setupUi(this);

	connect(button_go, SIGNAL(clicked()), this, SLOT(add_point()));
	
	spline_point *bam = new spline_point(0,0);
	spline_point *bum = new spline_point(80,0);
	spline_point *bim = new spline_point(20,60);
	spline_point *bom = new spline_point(100,60);
	
	scene.addItem(bam);
	scene.addItem(bum);
	scene.addItem(bim);
	scene.addItem(bom);
	
	
	bezier b(bam,bum,bim,bom);
	spline_point *q;
	QList<QPointF> p;
	q = new spline_point[13];
	p = b.getp();
	for(int i = 0; i < 13; i++){
		q[i].setpos(int(p[i].x()),int(p[i].y()));
	}
	
	for(int i = 1; i < 12; i++){
		scene.addItem(&q[i]);
	}
	
	view_canvas->setScene(&scene);
	view_canvas->show();
	
	
}

//Destruktor der Klasse "GUI".
gui::~gui(){
}


