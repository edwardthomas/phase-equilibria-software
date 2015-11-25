#include "PVT_Simulation.h"

#pragma once
class LiquidDensity: public PVT_Simulation 
{
public:
	//This classes constructor calls base class constructor with same args
	LiquidDensity(ComponentLib *pc, EquationOfState *pe ): PVT_Simulation( pc, pe){}
	
	// method to actually run the simulation
	int run_simulation(vector<double> &allData);
	// method to print results, either to screen or file or both
	void output_results(vector<double> &allData); 

};