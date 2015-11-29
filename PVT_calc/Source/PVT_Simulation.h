
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

	/*
		All derived classes MUST implement run_simulation: the method that 
		actually performs the required calculations
	*/
	virtual int run_simulation(vector<double> &data)=0;

	/*
		All derived classes MUST implement output_results: the method
		that will print out all of the results in a readable way. 
	*/ 
	virtual void output_results(vector<double> &data)=0;


	ComponentLib *pComps; //< Holds all comp data 
	EquationOfState *pEOS; //< Equation of state object
	string *simName; //< name for the simulation being run
};

