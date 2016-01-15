#include "EquationOfState.h"


#pragma once
class VDW_EquationOfState : public EquationOfState
{
public:
	VDW_EquationOfState(void);
	~VDW_EquationOfState(void);
	void computeMixParameters(vector<double> zc, ComponentLib *p, double Pres, double Temp);
	void computeDensity(vector<double> zc, ComponentLib *p,double Pres, double Temp, int phase_id, vector<double> &den);
	void computeFugacity(vector<double> zc, ComponentLib *p,double Pres, double Temp, int phase_id, vector<double> &fug);
};

