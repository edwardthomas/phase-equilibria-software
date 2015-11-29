
#include "ComponentLib.h"

/* 
	All arrays containing default data are below, followed 
	by the methods of ComponentLib. To add components to this 
	library, first increase the maximum number of library
	components in the global.h header. Then simply add their 
	properties to the arrays below. 
	ex. If I were to add CO2 next, the name array would look
	like: 

	string lib_name[GLOBAL::MAX_LIB_COMPS] =
	{
		"H2O",  // Water
		"CO2"   // Carbon dioxide
	};

	And this pattern will be repeated for all lib array properties.
*/ 

/* 
	Default names 
*/ 
string lib_name[GLOBAL::MAX_LIB_COMPS] =
{
	"H2O",	// Water 
	"CO2", 	// Carbon dioxide
	"He",  	// Helium
	"Ne",   // Neon
	"Ar",   // Argon
	"Kr",   // Krypton
	"Xe",   // Xenon
	"CH4",  // Methane
	"nC2",  // Ethane
	"nC3",  // Propane
	"nC4",  // Butane
	"nC5",  // Pentane
	"nC6",  // Hexane
	"nC7",  // Heptane
	"nC8",  // Octane
	"nC9",  // Nonane
	"nC10"  // Decane
};
/*
	Default critical temps in K
*/ 
double lib_tc[GLOBAL::MAX_LIB_COMPS] = 
{ 
	647.37, // Water  
	304.20, // Carbon dioxide
	5.20,	// Helium
	44.49,	// Neon
	150.69,	// Argon
	209.48,	// Krypton
	289.73,	// Xenon
	190.56,	// Methane
	305.33,	// Ethane
	369.83,	// Propane
	425.13,	// Butane
	469.70,	// Pentane
	507.82,	// Hexane
	540.13,	// Heptane
	569.32,	// Octane
	594.55,	// Nonane
	617.70	// Decane
};

/*
	Default critical pressures in bar
*/ 
double lib_pc[GLOBAL::MAX_LIB_COMPS] = 
{ 
	221.20, // Water 
	 73.80, // Carbon dioxide
	  2.27,	// Helium
	 26.79,	// Neon
	 48.63,	// Argon
	 55.25,	// Krypton
	 58.42,	// Xenon
	 45.92,	// Methane
	 48.72,	// Ethane
	 42.48,	// Propane
	 37.96,	// Butane
	 33.70,	// Pentane
	 30.34,	// Hexane
	 27.36,	// Heptane
	 24.97,	// Octane
	 22.81,	// Nonane
	 21.03	// Decane
};

/* 
	Default acentric factor
*/ 
double lib_acentric[GLOBAL::MAX_LIB_COMPS] =
{
	0.345,  // Water 
	0.244,  // Carbon dioxide
	-0.382, // Helium
	-0.039,	// Neon
	-0.002,	// Argon
	-0.001,	// Krypton
	0.004,	// Xenon
	0.011,	// Methane
	0.099,	// Ethane
	0.152,	// Propane
	0.201,	// Butane
	0.251,	// Pentane
	0.299,	// Hexane
	0.349,	// Heptane
	0.393,	// Octane
	0.443,	// Nonane
	0.488,	// Decane
};

/* 
	Default critical compressibiliy factors
*/ 
double lib_zc[GLOBAL::MAX_LIB_COMPS] =
{
	0.230, // Water 
	0.275, // Carbon dioxide
	0.303, // Helium
	0.303, // Neon
	0.290, // Argon
	0.292, // Krypton
	0.289, // Xenon
	0.286, // Methane
	0.279, // Ethane
	0.276, // Propane
	0.274, // Butane
	0.268, // Pentane
	0.266, // Hexane
	0.263, // Heptane
	0.257, // Octane
	0.255, // Nonane
	0.250  // Decane
};

/* 
	Default critical volumes in cm3/mol
*/ 
double lib_vc[GLOBAL::MAX_LIB_COMPS] =
{
	55.948,  // Water 
	94.119,  // Carbon dioxide
	57.475,	 // Helium
	41.873,	 // Neon
	74.586,	 // Argon
	92.166,	 // Krypton
	119.048, // Xenon
	98.629,  // Methane
	145.560, // Ethane
	200.000, // Propane
	254.922, // Butane
	310.984, // Pentane
	369.563, // Hexane
	431.909, // Heptane
	486.287, // Octane
	552.486, // Nonane
	609.756	 // Decane
};

/*
	Default mw in g/mol
*/ 
double lib_mw[GLOBAL::MAX_LIB_COMPS] = 
{
	18.015,  // Water
	44.010,  // Carbon dioxide
	4.003,	 // Helium
	20.180,	 // Neon
	39.948,	 // Argon
	83.798,	 // Krypton
	131.293, // Xenon
	16.040,	 // Methane
	30.070,	 // Ethane
	44.100,	 // Propane
	58.120,	 // Butane
	72.150,	 // Pentane
	86.180,	 // Hexane
	100.210, // Heptane
	114.230, // Octane
	128.200, // Nonane
	142.290, // Decane
	
};

/* 
	Default constructor for ComponentLib
*/ 
ComponentLib::ComponentLib(void)
{
}


ComponentLib::~ComponentLib(void)
{
}



/*
	This method initializes the data members for the 
	component class to zero, if value is given this 
	will be updated with user data, if no user data
	is given in the input file the default values 
	will be used. 
*/ 
void ComponentLib::initialize_datamembers(int nc)
{
	 // resize all vectors to the number of components
	 // currently in the system
	 name.resize(nc); 
	 tc.resize(nc, 0.0);
	 pc.resize(nc, 0.0); 
	 ac.resize(nc, 0.0);
	 zc.resize(nc, 0.0); 
	 vc.resize(nc, 0.0);
	 mw.resize(nc, 0.0);
	 aPure.resize(nc, 0.0);
	 bPure.resize(nc, 0.0);
	
}

/*
	This method supplies any data the user did not supply 
	using the default library 
*/ 
void ComponentLib::updateDataWithDefaults()
{	
	int nc = GLOBAL::NC; 
	int n_lib = GLOBAL::MAX_LIB_COMPS; 

	for ( int i = 0; i < nc; i++ )// comps 
	{
		for ( int j = 0;  j < n_lib; j++ ) // n in library 
		{
			if ( name[i].compare(lib_name[j]) == 0 )// compare name
			{
				// if no value was given, use defaults 
				if (tc[i] == 0.0) tc[i] = lib_tc[j];
				if (pc[i] == 0.0) pc[i] = lib_pc[j];
				if (zc[i] == 0.0) zc[i] = lib_zc[j];
				if (ac[i] == 0.0) ac[i] = lib_acentric[j];
				// using default mw for now 
				mw[i] = lib_mw[j];
			}
		}
		 
	}
}