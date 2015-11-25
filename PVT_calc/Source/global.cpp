#include"global.h"

namespace GLOBAL
{
	int NC; 
    int NP; 
	int nPres; //< number of pressures 
	int nTemp; //< number of temps
	int TEMP;  //< location of first temp in data array
	int PRES;  //< location of first pres in data array 
	int ZC;    //< location of first set of feed comps
	int NU;    //< location of first set of phase fractions
	int XCP;   //< location of first set of phase compositions
	int DEN;   //< location of first set of density
	int LEN;   //< total length of data vector
}