#include "ejemplo1.h"

ejemplo1::ejemplo1(): Ui_Counter()
{
	setupUi(this);
	show();
	connect(button, SIGNAL(clicked()), this, SLOT(doButton()) );
	connect(&cont, SIGNAL(timeout()), this, SLOT(senial()) );
	connect(verticalSlider, SIGNAL(valueChanged(int)), this, SLOT(frecuencia()) );
	
	cont.start(1000);
	
	
}

ejemplo1::~ejemplo1()
{}

void ejemplo1::doButton()
{
  int y;
	qDebug() << "click on button";
	if(cont.isActive()){
	  cont.stop();
	 }else{
	 y=verticalSlider->value();
	    cont.start(y);
	 }
	 
	
}

void ejemplo1::senial()
{
	qDebug() << "Timeout";
	lcdNumber->display(lcdNumber->intValue()+1);
}

void ejemplo1::frecuencia()
{
  int  y;

  y=verticalSlider->value();


}
