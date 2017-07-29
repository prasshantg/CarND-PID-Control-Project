#include <math.h>
#include <iostream>

#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	Kp_ = Kp;
	Ki_ = Ki;
	Kd_ = Kd;

	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;
}

void PID::UpdateError(double cte) {

	d_error = cte - p_error;

	p_error = cte;

	if (cte < 1)
		i_error = 0;
	else
		i_error += cte;

	if (fabs(i_error) > 300)
		i_error = 0;
}

double PID::TotalError() {
	cout << " total: " << (Kp_ * p_error + Kd_ * d_error + Ki_ * i_error) << " p_e: " << p_error << " d_e: " << d_error << " i_e: " << i_error << endl;
	return (Kp_ * p_error + Kd_ * d_error + Ki_ * i_error);
}

