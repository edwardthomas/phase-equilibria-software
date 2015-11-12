#include "stdafx.h"
#include "PVT_calc.h"





PVT_calc::PVT_calc(string file)
{
	inputFile = file;
	parseInputFile();
}

void PVT_calc::parseInputFile()
{
	vector<string> file;
	
	ifstream fin(inputFile, ios::in );
	
	// check that file is open 
	if ( !fin.is_open() ) 
	{
		cout << "file not open" << endl;
		exit(0); 
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
		i++;
	}
}

void PVT_calc::runPVTsim()
{


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
	Comps.resize(nc); 
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
		Comps[i].name = comps[i]; 
	
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