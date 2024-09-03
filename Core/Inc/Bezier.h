/*
 * Bezier.h
 *
 *  Created on: 2023/03/10
 *      Author: takuto
 */

#ifndef INC_BEZIER_H_
#define INC_BEZIER_H_

#include "F3rcLibrary/F3rcLibrary.h"

class Bezier{
private:
	F3rcLibrary* f3rc;
public:
	Bezier(F3rcLibrary* _f3rc):f3rc(_f3rc){};
	float bezier(float start,float goal,float t);
	float beziertwo(float a,float b,float c,float d,float t);
	float bezierthree(float a,float b,float c,float d,float e,float f,float t);
};




#endif /* INC_BEZIER_H_ */
