/*
 * Bezier.cpp
 *
 *  Created on: 2023/03/10
 *      Author: takuto
 */

#include "Bezier.h"

void Bezier(F3rcLibrary*);

float Bezier::bezier(float start,float goal,float t){
	return start*t+goal*(1-t);
}

float Bezier::beziertwo(float a,float b,float c,float d,float t){
	return bezier(bezier(bezier(a,b,t),bezier(b,c,t),t),bezier(bezier(b,c,t),bezier(c,d,t),t),t);
}

float Bezier::bezierthree(float a,float b,float c,float d,float e,float f,float t){
	return bezier(bezier(bezier(bezier(a,b,t),bezier(b,c,t),t),bezier(bezier(b,c,t),bezier(c,d,t),t),t),bezier(bezier(bezier(c,d,t),bezier(d,e,t),t),bezier(bezier(d,e,t),bezier(e,f,t),t),t),t);
}
