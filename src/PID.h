#ifndef PID_H
#define PID_H

class PID {
public:
	bool is_initialized;
	int n;
	double err;

	/*
	* Errors
	*/
	double p_error;
	double i_error;
	double d_error;
  
	double cte_old;
  

	/*
	* Coefficients
	*/ 
	double Kp;
	double Ki;
	double Kd;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte, double speed);

  /*
  * Calculate the total PID error.
  */
  double TotalError(double speed);
  
  // get the steering angle/output of the PID controller
  double Output();
  
  
};

#endif /* PID_H */
