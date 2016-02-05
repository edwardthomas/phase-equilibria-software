
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

	//set up data array 
	setOffsets();

	//add all data to array 
	setUpData();	

	cout << "All data read in and ready to run:" << endl;
	cout << "\t" << *(pSimulation->simName) << " using " << *(pEOS->eosName) << endl; 
}

/*
	Once this method is called, the data has been read, the appropriate
	objects have been created, and the simulation is ready to run. This 
	is the main method of PVT_calc. 
*/ 
void PVT_calc::runPVTsim()
{
	// run the simulation
	pSimulation->run_simulation(allData);

	// output the results
	pSimulation->output_results(allData);
}

/*
	Copy all input data into large data array to 
	prepare to run a simulation
*/ 
void PVT_calc::setUpData()
{
	int nc = NC;

	// copy t and p 
	for ( int i = 0; i < temp.size(); i++ ) 
		allData[TEMP+i] = temp[i]; 
	for ( int i = 0; i < pres.size(); i++ ) 
		allData[PRES+i] = pres[i];

	// copy feed 
	for ( int i = 0; i < temp.size()*pres.size()*nc; i++ ) 
		allData[ZC +  i] = zc[i];
	

}

/*
	Creates indexes for the data vector to store 
	all simulation data, temperature, pressure, density, 
	composition, phase fraction, phase composition, etc. 
*/
void PVT_calc::setOffsets()
{
	
	nPres = pres.size();
	nTemp = temp.size();
	int ndata = nPres*nTemp; 
	int nc = GLOBAL::NC;
	int np = GLOBAL::NP;

	PRES = 0; 
	TEMP = PRES + nPres;
	ZC = TEMP + nTemp; 
	NU = ZC + nc*ndata;  
	XCP = NU+np*ndata;   
	DEN = XCP+ nc*np*ndata; 
	LEN = DEN + np*ndata;

	// allocate space in data array
	allData.resize(LEN); 

	// feed not entered, use default of 1/nc 
	if ( zc.size() == 0 ) 
	{
		zc.assign( ndata*nc, 1.0/nc);
	}
}




bool PVT_calc::makeEOSobject()
{
	if ( eosModel == SRK)
	{
		pEOS = new SRK_EquationOfState();
		if ( pEOS ) return true; 
		return false;
	}
	else if ( eosModel == VDW)
	{
		pEOS = new VDW_EquationOfState();
		if ( pEOS ) return true;
		return false;
	}
	else
		return false; 
}
bool PVT_calc::makeSIMobject()
{
	if ( this->simToRun == LIQDENSITY)
	{
		pSimulation = new LiquidDensity(pComps, pEOS);
		if ( pSimulation ) return true; 
		return false;
	}
	else if ( this->simToRun == PUREPSAT)
	{
		pSimulation = new Psat_Simulation(pComps, pEOS);
		if ( pSimulation ) return true; 
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
		else if ( file[i] == "FEED")
		{
			parseFEED(file[i+1]);
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
	else if ( eos == "VDW")
		eosModel = VDW;
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
	else if ( sim == "PSAT") 
		simToRun = PUREPSAT;
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

void PVT_calc::parseFEED( string f)
{
	istringstream s(f);
	double tmp; 

	
	while ( s.good() ) 
	{
		s >> tmp; 
		zc.push_back(tmp);
	}

}
