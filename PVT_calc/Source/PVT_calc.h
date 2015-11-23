#pragma once
#include "commonDefs.hpp"
#include "global.h"
#include "ComponentLib.h"
#include "utils.hpp"
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
	bool parseInputFile(); 

private:
	// main input file 
	string inputFile; 

	// pointer to component objects
	ComponentLib *pComps;
	
	// equation of state 
	EOS_TYPE eosModel; 
	
	// flash method
	FLASH_TYPE flashModel;
	
	// simulation to run
	SIM_TYPE simToRun;
	
	// pressure and temperature ( bar and K ) 
	vector<double> temp; //< vector of temps to run given simulation
	vector<double> pres; //< vector of pres to run given simulation

	// methods to handle keywords
	void parseNC_NP(string f);
	void parseCOMPS(string f); 
	void parseEOS(string f);
	void parseTC( string f);
	void parsePC( string f);
    void parseZC( string f);
	void parseACF( string f);
	void parseSIMULATION( string f); 
	void parseTEMP( string f);
	void parsePRES( string f);


};

