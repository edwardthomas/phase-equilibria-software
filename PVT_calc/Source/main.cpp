#include "global.h"
#include "PVT_calc.h"

#include<string>
#include<iostream>
#include<fstream>
using namespace std; 

int main(void)
{
	string filename = "pvt.in";

	PVT_calc * myPVTsim = new PVT_calc(filename); 

	myPVTsim->runPVTsim();

	return 0;
}
