#include "PVT_Simulation.h"


PVT_Simulation::PVT_Simulation(ComponentLib *pc, EquationOfState *pe)
{
	pComps = pc; 
	pEOS = pe; 
}


PVT_Simulation::~PVT_Simulation(void)
{
}
