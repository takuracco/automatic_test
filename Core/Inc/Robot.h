/*
 * Robot.h
 *
 *  Created on: 2023/03/10
 *      Author: takuto
 */

#ifndef INC_ROBOT_H_
#define INC_ROBOT_H_
#include "F3rcLibrary/F3rcLibrary.h"
#include "PID.h"
#include "Bezier.h"

#define r 0.23f //半径

class Robot{
private:
	F3rcLibrary* f3rc;
	float backmotor;
	float rightmotor;
	float leftmotor;
	float nowx;
	float nowy;
	float nowyaw;
public:
	PID pidx;
	PID pidy;
	PID pidyaw;
	Bezier bezier;
	Robot(F3rcLibrary* _f3rc,float t):f3rc(_f3rc),backmotor(0),rightmotor(0),leftmotor(0),nowx(0),nowy(0),nowyaw(0),pidx(t),pidy(t),pidyaw(t),bezier(f3rc){}
	void IK(float x,float y,float yaw,float omega);
	void move1(float x1,float x2,float y1,float y2,float t);
	void move2(float x1,float x2,float x3,float x4,float x5,float x6,float y1,float y2,float y3,float y4,float y5,float y6,float t);
	void stop(float x,float y,float yaw);
};



#endif /* INC_ROBOT_H_ */
