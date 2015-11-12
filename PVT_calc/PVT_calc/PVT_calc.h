#pragma once
#include "commonDefs.hpp"
#include "global.h"
#include "ComponentLib.h"
#include<string>
#include<fstream>
#include<iostream>
#include<sstream>
#include<vector>
using namespace std; 



class PVT_calc
{
public:
	~PVT_calc(void);
	PVT_calc( string file); 
	
	// main method - controls flow of program 
	void runPVTsim();

	// read input file and set data members 
	void parseInputFile(); 

private:
	// main input file 
	string inputFile; 
	// vector of component objects
	vector<ComponentLib> Comps;
	// equation of state 
	EOS_TYPE eosModel; 
	// flash method
	FLASH_TYPE flashModel;
	// simulation to run
	SIM_TYPE simToRun;
	
	// methods to handle keywords
	void parseNC_NP(string f);
	void parseCOMPS(string f); 
	void parseEOS(string f); 


};

