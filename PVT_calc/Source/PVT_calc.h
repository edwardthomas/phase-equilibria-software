#pragma once
#include "commonDefs.hpp"
#include "global.h"
#include "ComponentLib.h"
#include "utils.hpp"
#include "EquationOfState.h"
#include "SRK_EquationOfState.h"
#include "PVT_Simulation.h"
#include "LiquidDensity.h"
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

	vector<double> allData;//< holds all data to pass to/from a simulation

	/*
		offsets for allData vector
	*/
	int nPres; //< number of pressures 
	int nTemp; //< number of temps
	int TEMP;  //< location of first temp in data array
	int PRES;  //< location of first pres in data array 
	int ZC;    //< location of first set of feed comps
	int NU;    //< location of first set of phase fractions
	int XCP;   //< location of first set of phase compositions
	int DEN;   //< location of first set of density
	int LEN;   //< total length of data vector


};

