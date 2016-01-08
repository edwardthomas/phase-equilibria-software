#pragma once
namespace GLOBAL
{
	const int MAX_LIB_COMPS = 63; //< number of components in build in component database
	const double R = 83.144598; //< gas constant 
	extern int NC; //< number of components in the system
	extern int NP; //< max number of equilibrium phases
	
	/*
		offsets for allData vector
	*/
	extern int nPres; //< number of pressures 
	extern int nTemp; //< number of temps
	extern int TEMP;  //< location of first temp in data array
	extern int PRES;  //< location of first pres in data array 
	extern int ZC;    //< location of first set of feed comps
	extern int NU;    //< location of first set of phase fractions
	extern int XCP;   //< location of first set of phase compositions
	extern int DEN;   //< location of first set of density
	extern int LEN;   //< total length of data vector

}
