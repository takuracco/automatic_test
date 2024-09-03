/*
 * Robot.cpp
 *
 *  Created on: 2023/03/10
 *      Author: takuto
 */

#include <math.h>
#include "Robot.h"
#include "Bezier.h"


void Robot(F3rcLibrary*,float);

void Robot::IK(float x,float y,float yaw,float omega){
	Robot::backmotor = x * cos(0) + y * sin(0) + omega * r;
	Robot::rightmotor = x * cos(2 * M_PI/3) + y * sin(2 * M_PI / 3) + omega * r;
	Robot::leftmotor = x * cos(4 * M_PI / 3) + y * sin(4 * M_PI / 3) + omega * r;

	f3rc->M3.SetDuty(backmotor);
	f3rc->M4.SetDuty((-1)* leftmotor);
	f3rc->M1.SetDuty((-1)* rightmotor);
}

void Robot::move1(float x1,float x2,float y1,float y2,float t){
	float vx = bezier.bezier(x1, x2, t);
	float vy = bezier.bezier(y1, y2, t);
	Robot::nowx = f3rc->Loca.GetX();
	Robot::nowy = f3rc->Loca.GetY();
	Robot::nowyaw = f3rc->Loca.GetYaw();
	float target_yaw = 0;
	float vomega = pidyaw.caluculate(0, -1*F3RCLibrary::GetYawError(nowyaw, target_yaw));
	IK(pidx.caluculate(vx,nowx),pidy.caluculate(vy, nowy),nowyaw,vomega);
}

void Robot::move2(float x1,float x2,float x3,float x4,float x5,float x6,float y1,float y2,float y3,float y4,float y5,float y6,float t){
	float vx = bezier.bezierthree(x1, x2, x3, x4, x5, y6, t);
	float vy = bezier.bezierthree(y1, y2, y3, y4, y5, y6, t);
	Robot::nowx = f3rc->Loca.GetX();
	Robot::nowy = f3rc->Loca.GetY();
	Robot::nowyaw = f3rc->Loca.GetYaw();
	float target_yaw = 0;
	float vomega = pidyaw.caluculate(0.0f, -1*F3RCLibrary::GetYawError(nowyaw, target_yaw));
	IK(pidx.caluculate(vx,nowx),pidy.caluculate(vy, nowy),nowyaw,vomega);
}

void Robot::stop(float x,float y,float yaw){
	float nowx = f3rc->Loca.GetX();
	float nowy = f3rc->Loca.GetY();
	float nowyaw = f3rc->Loca.GetYaw();
	float vomega = pidyaw.caluculate(0.0f, -1*F3RCLibrary::GetYawError(nowyaw,yaw));

	nowx = -1*nowx;
//	nowy = -1*nowy;
	IK(pidx.caluculate(x,nowx),pidy.caluculate(y, nowy),nowyaw,vomega);
}
