#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

#define SPEED_MIN 3.0

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_in, double Ki_in, double Kd_in) {
	Kp = Kp_in;
	Ki = Ki_in;
	Kd = Kd_in;
	
	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;
	
	is_initialized = false;
	
	n = 1;
	err = 0.0;
}

void PID::UpdateError(double cte, double speed) {
	if (is_initialized == false) {
		cte_old = cte;
		is_initialized = true;
	}
	
	p_error = cte;
	if (speed > SPEED_MIN) {
		i_error += cte;
	}
	d_error = cte - cte_old;
	cte_old = cte;
	
}

double PID::TotalError(double speed) {
	
	if (speed > SPEED_MIN){
		n += 1;
		err += p_error*p_error;
	}
	
	return err / n;
	
}

double PID::Output() {
	double out;
	
	out = -Kp*p_error - Ki*i_error - Kd*d_error;
	
	return out;
}

