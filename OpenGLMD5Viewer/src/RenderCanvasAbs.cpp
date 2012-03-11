/*
 * RenderCanvasAbs.cpp
 *
 *  Created on: 11 mars 2012
 *      Author: Ikspay
 */

#include "RenderCanvasAbs.h"

#include <qapplication.h>
#include <qtimer.h>

RenderCanvasAbs::RenderCanvasAbs(int framesPerSecond, QWidget *parent) :
	QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
	int timerInterval = 0;
	if(framesPerSecond == 0) {
		timerInterval = 1000 / 60;
	}
	else
	{
		timerInterval = 1000 / framesPerSecond;
	}

	t_Timer = new QTimer(this);
	t_Timer->setSingleShot(false);
	connect(t_Timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()));
	t_Timer->start(timerInterval);
}


void RenderCanvasAbs::timeOut()
{
}

void RenderCanvasAbs::timeOutSlot()
{
	timeOut();
}




