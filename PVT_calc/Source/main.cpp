#include "global.h"
#include "PVT_calc.h"

#include<string>
#include<iostream>
#include<fstream>
using namespace std; 

int main(int narg, char** arg)
{
	string filename; 
	if ( narg == 1 )
	{
		cout << "No input file provided as an argument, using default value (pvt.in)" << endl; 
		filename = "pvt.in";
	}
	else
	{
		filename = arg[1];
	}
	PVT_calc * myPVTsim = new PVT_calc(filename); 

	myPVTsim->runPVTsim();

	return 0;
}
