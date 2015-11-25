
#include "PVT_calc.h"




/*
	The PVT_calc constructer is responsible for setting 
	up everything that the program will need to run. The 
	method to parse the input file is parsed, the data is
	stored in a ComponentLib object, and the type of EOS 
	and simulation is determined. 
*/ 
PVT_calc::PVT_calc(string file)
{
	// open and parse input file  
	inputFile = file;
	if ( !parseInputFile() ) 
	{
		cout << "Problem parsing input file, quitting!" << endl; 
		exit(0); 
	}

	//set up pure component data, must use defaults or 
	//user defined data, or a mixture of both 
	pComps->updateDataWithDefaults();

	// Create EOS object 
	if ( !makeEOSobject() ) 
	{
		cout << "Could not create EOS object" << endl; 
		exit(0); 
	} 

	// Create Simulation object 
	if ( !makeSIMobject() ) 
	{
		cout << "Could not create sim object" << endl; 
		exit(0); 
	} 

	setOffsets();

}

/*
	Once this method is called, the data has been read, the appropriate
	objects have been created, and the simulation is ready to run. This 
	is the main method of PVT_calc. 
*/ 
void PVT_calc::runPVTsim()
{
	//

}


/*
	Creates indexes for the data vector to store 
	all simulation data, temperature, pressure, density, 
	composition, phase fraction, phase composition, etc. 
*/
void PVT_calc::setOffsets()
{
	int npres = pres.size();
	int ntemp = temp.size();
	int nc = GLOBAL::NC;
	int np = GLOBAL::NP;
	//TODO: finish this method 

}




bool PVT_calc::makeEOSobject()
{
	if ( eosModel == SRK)
	{
		pEOS = new SRK_EquationOfState();
		if ( pEOS ) return true; 
		return false;
	}
	else
		return false; 
}
bool PVT_calc::makeSIMobject()
{
	if ( this->eosModel == LIQDENSITY)
	{
		pSimulation = new LiquidDensity(pComps, pEOS);
		if ( pEOS ) return true; 
		return false;
	}
	else
		return false; 
}

bool PVT_calc::parseInputFile()
{
	vector<string> file;
	
	ifstream fin(inputFile, ios::in );
	
	// check that file is open 
	if ( !fin.is_open() ) 
	{
		cout << "file not open" << endl;
		return false; 
	}
	else 
	{
		// read file and store in vector
		string line;
		while (getline(fin, line) )
		{
			if ( line.size() > 0 && line.find("#") == -1 ) 
				file.push_back(line); 
		}

		fin.close();
	}
	
	int i = 0; 
	while ( i < file.size() ) 
	{
		file[i] = trim(file[i]); 
		if ( file[i] == "NC_NP" ) 
		{
			parseNC_NP(file[i+1]);
		}
		else if (file[i] == "COMPS") 
		{
			parseCOMPS(file[i+1]);
		}
		else if ( file[i] == "EOS")
		{
			parseEOS(file[i+1]); 
		}
		else if ( file[i] == "TC")
		{
			parseTC(file[i+1]); 
		}
		else if ( file[i] == "PC")
		{
			parsePC(file[i+1]); 
		}
		else if ( file[i] == "ZC")
		{
			parseZC(file[i+1]); 
		}
		else if ( file[i] == "ACF")
		{
			parseACF(file[i+1]); 
		}
		else if ( file[i] == "SIMULATION")
		{
			parseSIMULATION(file[i+1]); 
		}
		else if ( file[i] == "TEMP")
		{
			parseTEMP(file[i+1]); 
		}
		else if ( file[i] == "PRES")
		{
			parsePRES(file[i+1]); 
		}
		i++;
	}
	return true; 
}



PVT_calc::~PVT_calc(void)
{
}


void PVT_calc::parseNC_NP (string f) 
{
	int nc, np; 
	istringstream s(f);
	s >> nc >> np; 
	GLOBAL::NC = nc; 
	GLOBAL::NP = np; 
	pComps = new ComponentLib();
	pComps->initialize_datamembers(nc); 
}

void PVT_calc::parseCOMPS (string f) 
{ 
	vector<string> comps;
	string comp; 
	istringstream s(f);
	while (s >> comp ) 
	{
		comps.push_back(comp); 
	}
	for ( int i = 0; i < GLOBAL::NC; i++ ) 
		pComps->name[i]=comps[i]; 
	
}

void PVT_calc::parseEOS (string f) 
{ 
	string eos;
	istringstream s(f); 
	s >> eos; 	

	if ( eos == "SRK") 
		eosModel = SRK;
	else if ( eos == "PR") 
		eosModel = PR; 
	else
	{
		cout << "EOS model: " <<eos << " not found" << endl;
	}
}

void PVT_calc::parseTC (string f) 
{ 
	istringstream s(f);
	int nc = GLOBAL::NC; 

	for ( int i = 0; i < nc; i++ )
	{
		s >> pComps->tc[i]; 
	} 
}
void PVT_calc::parsePC (string f) 
{ 
	istringstream s(f);
	int nc = GLOBAL::NC; 

	for ( int i = 0; i < nc; i++ )
	{
		s >> pComps->pc[i]; 
	} 
}

void PVT_calc::parseZC (string f) 
{ 
	istringstream s(f);
	int nc = GLOBAL::NC; 

	for ( int i = 0; i < nc; i++ )
	{
		s >> pComps->zc[i]; 
	} 
}
void PVT_calc::parseACF (string f) 
{ 
	istringstream s(f);
	int nc = GLOBAL::NC; 
	for ( int i = 0; i < nc; i++ )
	{
		s >> pComps->ac[i]; 
	} 
}

void PVT_calc::parseSIMULATION (string f) 
{ 
	string sim;
	istringstream s(f); 
	s >> sim; 	

	if ( sim == "TPFLASH") 
		simToRun = TPFLASH;
	else if ( sim == "LIQDENSITY")
		simToRun = LIQDENSITY; 
	else
	{
		cout << "Simulation type: " << sim << " not found" << endl;
	}
}

void PVT_calc::parseTEMP( string f)
{
	istringstream s(f);
	double t; 

	while ( s.good() ) 
	{
		s >> t; 
		temp.push_back(t);
	}

}

void PVT_calc::parsePRES( string f)
{
	istringstream s(f);
	double p; 

	while ( s.good() ) 
	{
		s >> p; 
		pres.push_back(p);
	}

}