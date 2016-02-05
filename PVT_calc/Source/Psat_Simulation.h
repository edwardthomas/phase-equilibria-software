#include "PVT_Simulation.h"
#include <iomanip>
using namespace std; 

#pragma once
class Psat_Simulation: public PVT_Simulation 
{
public:
	//This classes constructor calls base class constructor with same args
	Psat_Simulation(ComponentLib *pc, EquationOfState *pe ): PVT_Simulation( pc, pe){ simName = new string("Pure Saturation Pressure Calculation");}
	
	// method to actually run the simulation
	int run_simulation(vector<double> &allData);
	// method to print results, either to screen or file or both
	void output_results(vector<double> &allData); 

private:
	double getSaturationPressure(double temperature,double p0, int max_iter, double tol); 
	double getObjective(double temperature,double pressure);

};