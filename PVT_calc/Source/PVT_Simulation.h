
#include "EquationOfState.h"
#include "ComponentLib.h"
/*
	This is the PVT simlulation base class. All of the types of simulations
	will derived classes of PVT_Simulation, and MUST implement the virtual 
	methods of this class. 
*/ 
#pragma once
class PVT_Simulation
{
public:
	PVT_Simulation(ComponentLib *pComps, EquationOfState *pEOS);
	~PVT_Simulation(void);

	virtual int run_simulation(vector<double> &data)=0;
	virtual void output_results(vector<double> &data)=0;
	ComponentLib *pComps; //< Holds all comp data 
	EquationOfState *pEOS; //< Equation of state object
};

