#pragma once
// Common, utilities, and components 
#include "commonDefs.hpp"
#include "global.h"
#include "ComponentLib.h"
#include "utils.hpp"
// Equations of state
#include "EquationOfState.h"
#include "SRK_EquationOfState.h"
#include "VDW_EquationOfState.h"
// simulation types
#include "PVT_Simulation.h"
#include "LiquidDensity.h"
#include "Psat_Simulation.h"
// C++ libraries 
#include<string>
#include<fstream>
#include<iostream>
#include<sstream>
#include<vector>
using namespace GLOBAL;
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

	
	
	// equation of state 
	EOS_TYPE eosModel; 
	
	// flash method
	FLASH_TYPE flashModel;
	
	// simulation to run
	SIM_TYPE simToRun;
	
	// pressure and temperature ( bar and K ) 
	vector<double> temp; //< vector of temps to run given simulation
	vector<double> pres; //< vector of pres to run given simulation
	vector<double> zc; //< vector of compositions for each data point

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
	void parseFEED( string f);

	/*
		pointers to objects used by PVT_calc
	*/
	// pointer to component objects
	ComponentLib *pComps; //< Holds all comp data 
	EquationOfState *pEOS; //< Equation of state object
	PVT_Simulation *pSimulation; //< Object defining simulation

	/*
		Methods to create simulation and eos objects 
	*/ 
	bool makeEOSobject(); 
	bool makeSIMobject(); 

	/*
		Method to set up offsets and resize data vector
	*/ 
	void setOffsets(); 
	void setUpData(); 

	vector<double> allData;//< holds all data to pass to/from a simulation

	


};

