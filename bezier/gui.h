#ifndef GUI_H
#define GUI_H

#include "ui_gui.h"

using namespace std; 
 
struct point{
	double x;
	double y;

}; 

class gui : public QMainWindow, public Ui::MainWindow { 
	Q_OBJECT
	 
	public slots:
		
		
	public:
	    	gui(QMainWindow *parent = 0);
	    	~gui();
	private slots:
		//void make_spline();
		//void add_point();
	private :
		QGraphicsScene scene;		
};

#endif //WR_H
