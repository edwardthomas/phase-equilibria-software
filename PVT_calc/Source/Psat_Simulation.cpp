#include "Psat_Simulation.h"


int Psat_Simulation::run_simulation(vector<double> &allData)
{
	 
	//number of temperatures
	int ntemp = GLOBAL::nTemp;
	int npres = GLOBAL::nPres;

	if  ( ntemp != npres ) 
	{
		cout << "ntemp != npres, please provide an initial guess for each temperature,\n"<<
			    "using the PRES keyword."<< endl; 
			 return -1; 
	}

	// guess of pressure 
	double p0 = 1.0;

	// solving parameters 
	int max_iter = 100; 
	double tol = 1e-15; 

	// current temperature 
	double temperature;
	
	for (int i = 0; i < ntemp; i++ )
	{
		// current temperature 
		temperature = allData[GLOBAL::TEMP+i];
	
		// use input pressure as guess, if one pressure is given for each temp
		p0 = allData[GLOBAL::PRES+i];

		// get psat at given temperature 
		allData[GLOBAL::PRES+i] = getSaturationPressure( temperature, p0, max_iter, tol); 
	}

	return 0; 
}

/*
	This method should print the output in a some readable 
	way for the user. Very important to remember that 
	temperature is looped over the fastest. 

		//TODO: add a class or utility that will write to 
		the screen and/or a log depending on some state 
		variable that can be read from the input file
*/ 
void Psat_Simulation::output_results(vector<double> &allData)
{
	//number of temperatures and pressures
	int ntemp = GLOBAL::nTemp;
	
	// header
	cout << endl <<  " ****** Saturation Pressure Calculation Results ****** " << endl; 

	// print # of components in system 
	cout << "Number of components: " << GLOBAL::NC << endl << endl;

	// print component names
	cout << "Components in system:" << endl; 
	for ( int i = 0; i < GLOBAL::NC; i++ ) cout << "\t"<< pComps->name[i] << endl << endl;

	// labels 
	cout <<setw(8)<< "T(K)    " << setw(5*GLOBAL::NC)<< "Feed   " << setw(20)<< "Sat. Pressure (bar) " << endl; 
	
	for ( int i = 0; i < GLOBAL::nTemp; i++ ) 
	{
		cout << setw(8) << allData[GLOBAL::TEMP +i ] << setw(8) << 1.0 << setw(15) << allData[GLOBAL::PRES +i ] << endl;
	}

	return; 
} 

double Psat_Simulation::getSaturationPressure(double temperature,double p0, int max_iter, double tol)
{
	// use Newtons method to find saturation pressure 
	// at the given temperature
	
	// pressure step for derivatives
	const double dp = 1.0e-5;
	
	// residual ( fug_l - fug_v) 
	double residual = 1.0;

	// iteration counter 
	int iteration = 0; 
	
	// temporary variables for objective functions 
	double F1, F2, dF_dP;

	// current pressure, start with guess
	double pressure = p0, pressure_old;

	// step size 
	double h = 1.0; 

	// main loop 
	while ( residual > tol && iteration++ < max_iter ) 
	{
		// get objective function at T, P, and perturb 
		// to get at P + dp
		F1 = getObjective( temperature, pressure ); 
		F2 = getObjective( temperature, pressure + dp);

		// derivative wrt pressure 
		dF_dP = (F2-F1)/dp;

		if ( fabs(dF_dP) < 1e-30   ) 
		{
			cout << "Derivative is zero for Newton update..." << endl; 
			return -1.; 
		}

		// update pressure, chop update if it results negative pressure 
		pressure_old = pressure;
		h = 1.0; 
		do
		{
			pressure = pressure_old - h*(F1/dF_dP);
			h *= 0.75;
		}
		while(pressure < 0. && h > 0.01);

		residual = F1*F1;

		if ( h < 0.01 ) 
		{
			cout << "stalled, update fraction is too small..." << endl; 
			return -1.; 
		}
		

	}

	return pressure; 
}


double Psat_Simulation::getObjective(double temperature,double pressure)
{
	// pure component, so nc = 1, z(1) = 1.0; 
	vector<double> fugl(1), fugv(1),z(1,1.0);
	
	// get liquid and vapor fugacities 
	pEOS->computeFugacity(z, pComps , pressure, temperature, 1, fugl);
	pEOS->computeFugacity(z, pComps , pressure, temperature, 0, fugv);

	return fugl[0]-fugv[0]; 
}