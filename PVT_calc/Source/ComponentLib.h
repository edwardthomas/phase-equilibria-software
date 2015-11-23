#pragma once
#include<string> 
#include<vector>
#include "global.h"
using namespace std; 

/*
	The ComponentLib class is a class to hold all component information. The is a private
	data base of pure component properties, from which we can look up data that is not 
	supplied by the user. The public data members for this class are vectors containing 
	the pure components names and properties of all of the components in the system, thus 
	they are all of size NC with NC = the number of components in the system. 
*/
class ComponentLib
{
/*
 Public data members here hold the data for each pure component in the system.
*/
public:
	ComponentLib(void);
	~ComponentLib(void);
	void initialize_datamembers(int nc); //< size arrays properly 
	void updateDataWithDefaults(); //< add data not supplied by user to comps
	vector<string> name; //< vector of the names of the current components
	vector<double> tc; //< vector of critical temperatures in K 
	vector<double> pc; //< vector of critical pressures in bar
	vector<double> ac; //< vector of acentric factors
	vector<double> zc; //< vector of critical compressiblity
	vector<double> vc; //< vector of critical molar volumes (cm^3/mol)
	vector<double> mw; //< vector of mw (g/mol) 
};

