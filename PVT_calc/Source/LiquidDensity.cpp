#include "LiquidDensity.h"

/*
		This routine loops over temperatures fastest and then 
		pressures and calculates the liquid density using 
		whichever eos is set.
*/
int LiquidDensity::run_simulation(vector<double> &allData)
{
	 
	//number of temperatures and pressures
	int ntemp = GLOBAL::nTemp;
	int npres = GLOBAL::nPres;
	
	//temporary vars
	double temp, pres;
	vector<double> den(GLOBAL::NP), feed(GLOBAL::NC);

	//for each temp and pres
	for ( int i = 0; i < npres; i++ ) 
	{
		//get pressure 
		pres = allData[i+ GLOBAL::PRES];

		for ( int j = 0; j < ntemp; j++ ) 
		{
			// get temperature 
			temp = allData[ j + GLOBAL::TEMP];

			// set feed - can be different for any T,P datapoint 
			for ( int k = 0; k<GLOBAL::NC; k++ ) 
			{
				feed[k] = allData[GLOBAL::ZC + i*ntemp*GLOBAL::NC + j*GLOBAL::NC + k];
			}

			// call eos to get density 
			pEOS->computeDensity(feed, pComps, pres, temp, 1, den); 

			// put density result back into allData 
			allData[ GLOBAL::DEN + i*ntemp + j] = den[1]; 
		}
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
void LiquidDensity::output_results(vector<double> &allData)
{
	//number of temperatures and pressures
	int ntemp = GLOBAL::nTemp;
	int npres = GLOBAL::nPres;
	
	//temporary vars
	double temp, pres;
	
	// header
	cout << endl <<  " ****** Liquid Density Calculation Results ****** " << endl; 

	// print # of components in system 
	cout << "Number of components: " << GLOBAL::NC << endl << endl;

	// print component names
	cout << "Components in system:" << endl; 
	for ( int i = 0; i < GLOBAL::NC; i++ ) cout << "\t"<< pComps->name[i] << endl << endl;

	// labels 
	cout <<setw(8)<< "P(bar)"<< setw(8)<<"T(K)" << setw(5*GLOBAL::NC)<< "Feed" << setw(15)<< "Density(g/cm3)" << endl; 

	//for each temp and pres
	for ( int i = 0; i < npres; i++ ) 
	{
		//get pressure 
		pres = allData[i+ GLOBAL::PRES];

		for ( int j = 0; j < ntemp; j++ ) 
		{
			// get temperature 
			temp = allData[ j + GLOBAL::TEMP];

			// print pressure + temperature 
			cout << setw(8) << pres << setw(8) << temp; 

			// print  feed - can be different for any T,P datapoint 
			for ( int k = 0; k<GLOBAL::NC; k++ ) 
			{
				cout<< setw(5) <<  allData[GLOBAL::ZC + i*ntemp*GLOBAL::NC + j*GLOBAL::NC + k];
			}

			cout << setw(15) <<  allData[ GLOBAL::DEN + i*ntemp + j] << endl;  
		}
	}
	
	

	return; 
} 