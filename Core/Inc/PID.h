#ifndef INC_LIB_PID_H_
#define INC_LIB_PID_H_


class PID{
	float kp = 5;
	float ki = 2;
	float kd = 1;
	float t,integral,past_e;
	public:
		PID(float _t):t(_t),integral(0),past_e(0){}
		void SetParam(float p,float i,float d){
			kp=p;ki=i;kd=d;
		}

		float caluculate(float target,float measure){
			float e=target-measure;
			float p=kp*e;
			integral+=ki*(e+past_e)/2.f*t;
			float d=kd*(e-past_e)/t;
			float u=p+integral+d;
			past_e=e;
			return u;
		}
};

#endif /* INC_LIB_PID_H_ */
