#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  _is_initialized = false;
}

void PID::UpdateError(double cte) {
  if(_is_initialized == false){
    _previous_cte = cte;
    _cte_sum = 0;
    _is_initialized = true;
  }
  double diff_cte = cte - _previous_cte;
  _previous_cte = cte;
  _cte_sum += cte;
    
  p_error = cte;
  d_error = diff_cte;
  i_error = _cte_sum;
  
}

double PID::TotalError() {
  return -Kp * p_error - Kd * d_error - Ki * i_error;
}

