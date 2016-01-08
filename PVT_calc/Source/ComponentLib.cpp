
#include "ComponentLib.h"

/* 
	All arrays containing default data are below, followed 
	by the methods of ComponentLib. The library is compiled 
	Perry's Chemical Engineers Handbook. To add components 
	to this library, first increase the maximum number of 
	library components in the global.h header. Then simply 
	add their properties to the arrays below. 
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
	"H2O", // Water
	"CO2", // Carbon dioxide
	"He", // Helium
	"Ne", // Neon
	"Ar", // Argon
	"CH4", // Methane
	"nC2", // Ethane
	"nC3", // Propane
	"nC4", // n-Butane
	"nC5", // n-Pentane
	"nC6", // n-Hexane
	"nC7", // n-Heptane
	"nC8", // n-Octane
	"nC9", // n-Nonane
	"nC10", // n-Decane
	"nC11", // n-Undecane
	"nC12", // n-Dodecane
	"nC13", // n-Tridecane
	"nC14", // n-Tetradecane
	"nC15", // n-Pentadecane
	"nC16", // n-Hexadecane
	"nC17", // n-Heptadecane
	"nC18", // n-Octadecane
	"nC19", // n-Nonadecane
	"nC20", //n-Eicosane
	"cC5", // Cyclopentane
	"cC6", // Cyclohexane
	"Ben", // Benzene
	"Tol", // Toluene
	"oXy", // o-Xylene
	"mXy", // m-Xylene
	"pXy", // p-Xylene
	"Nap", // Naphthalene
	"MeOH", // Methanol
	"EtOH", // Ethanol
	"1-nC3OH", // 1-Propanol
	"1-nC4OH", // 1-Butanol
	"1-nC5OH", // 1-Pentanol
	"1-nC6OH", // 1-Hexanol
	"1-nC7OH", // 1-Heptanol
	"cC6OH", // Cyclohexanol
	"Phe", // Phenol
	"Ace", // Acetone
	"Ani", // Aniline
	"Fur", // Furan
	"Pyr", // Pyridine
	"MeF", // Fluoromethane
	"MeCl", // Chloromethane
	"MeBr", // Bromomethane
	"F2", // Fluorine
	"Cl2", //Chlorine
	"Br2", // Bromine
	"O2", // Oxygen
	"N2", // Nitrogen
	"NH3", // Ammonia
	"N2O", // Nitrous oxide
	"NO", // Nitric oxide
	"CO", // Carbon monoxide
	"HF", // Hydrogen Fluoride
	"HCl", // Hydrogen Chloride
	"HBr", // Hydrogen Bromide
	"H2S", // Hydrogen Sulfide
	"SO2" // Sulfur Dioxide
};
/*
	Default critical temps in K
*/ 
double lib_tc[GLOBAL::MAX_LIB_COMPS] = 
{ 
	647.13,	// Water
	304.21,	// Carbon dioxide
	5.2,	// Helium
	44.4,	// Neon
	150.86,	// Argon
	190.56,	// Methane
	305.32,	// Ethane
	369.83,	// Propane
	425.12,	// n-Butane
	469.70,	// n-Pentane
	507.60,	// n-Hexane
	540.20,	// n-Heptane
	568.70,	// n-Octane
	594.60,	// n-Nonane
	617.70,	// n-Decane
	639.00,	// n-Undecane
	658.00,	// n-Dodecane
	675.00,	// n-Tridecane
	693.00,	// n-Tetradecane
	708.00,	// n-Pentadecane
	723.00,	// n-Hexadecane
	736.00,	// n-Heptadecane
	747.00,	// n-Octadecane
	758.00,	// n-Nonadecane
	768.00,	// n-Eicosane
	511.76,	// Cyclopentane
	560.40,	// Cyclohexane
	562.16,	// Benzene
	591.80,	// Toluene
	630.33,	// o-Xylene
	617.05,	// m-Xylene
	616.23,	// p-Xylene
	748.35,	// Naphthalene
	512.64,	// Methanol
	513.92,	// Ethanol
	536.78,	// 1-Propanol
	563.05,	// 1-Butanol
	586.15,	// 1-Pentanol
	611.35,	// 1-Hexanol
	631.90,	// 1-Heptanol
	650.00,	// Cyclohexanol
	694.25,	// Phenol
	508.20,	// Acetone
	699.00,	// Aniline
	490.15,	// Furan
	619.95,	// Pyridine
	317.42,	// Fluoromethane
	416.25,	// Chloromethane
	467.00,	// Bromomethane
	144.12,	// Fluorine
	417.15,	// Chlorine
	584.15,	// Bromine
	154.58,	// Oxygen
	126.20,	// Nitrogen
	405.65,	// Ammonia
	309.57,	// Nitrous oxide
	180.15,	// Nitric oxide
	132.92,	// Carbon monoxide
	461.15,	// Hydrogen Fluoride
	324.65,	// Hydrogen Chloride
	363.15,	// Hydrogen Bromide
	373.53,	// Hydrogen Sulfide
	430.75	// Sulfur Dioxide
};

/*
	Default critical pressures in bar
*/ 
double lib_pc[GLOBAL::MAX_LIB_COMPS] = 
{ 
	219.40,	// Water
	73.90,	// Carbon dioxide
	2.3,	// Helium
	26.7,	// Neon
	49.0,	// Argon
	45.90,	// Methane
	48.5,	// Ethane
	42.1,	// Propane
	37.7,	// n-Butane
	33.60,	// n-Pentane
	30.40,	// n-Hexane
	27.20,	// n-Heptane
	24.70,	// n-Octane
	23.10,	// n-Nonane
	20.90,	// n-Decane
	19.50,	// n-Undecane
	18.20,	// n-Dodecane
	16.80,	// n-Tridecane
	15.70,	// n-Tetradecane
	14.70,	// n-Pentadecane
	14.10,	// n-Hexadecane
	13.40,	// n-Heptadecane
	12.60,	// n-Octadecane
	12.10,	// n-Nonadecane
	11.70,	// n-Eicosane
	45.00,	// Cyclopentane
	43.90,	// Cyclohexane
	48.80,	// Benzene
	41.00,	// Toluene
	37.40,	// o-Xylene
	35.30,	// m-Xylene
	35.00,	// p-Xylene
	39.90,	// Naphthalene
	81.40,	// Methanol
	61.20,	// Ethanol
	51.20,	// 1-Propanol
	43.40,	// 1-Butanol
	38.70,	// 1-Pentanol
	34.60,	// 1-Hexanol
	31.80,	// 1-Heptanol
	42.50,	// Cyclohexanol
	60.60,	// Phenol
	47.10,	// Acetone
	53.50,	// Aniline
	55.50,	// Furan
	56.40,	// Pyridine
	58.80,	// Fluoromethane
	66.90,	// Chloromethane
	80.00,	// Bromomethane
	51.70,	// Fluorine
	77.90,	// Chlorine
	102.80,	// Bromine
	50.20,	// Oxygen
	33.90,	// Nitrogen
	113.00,	// Ammonia
	72.80,	// Nitrous oxide
	65.20,	// Nitric oxide
	34.90,	// Carbon monoxide
	64.90,	// Hydrogen Fluoride
	83.60,	// Hydrogen Chloride
	84.60,	// Hydrogen Bromide
	90.00,	// Hydrogen Sulfide
	78.60	// Sulfur Dioxide
};

/* 
	Default acentric factor
*/ 
double lib_acentric[GLOBAL::MAX_LIB_COMPS] =
{
	0.343,	// Water
	0.224,	// Carbon dioxide
	-0.388,	// Helium
	-0.038,	// Neon
	0.000,	// Argon
	0.011,	// Methane
	0.098,	// Ethane
	0.149,	// Propane
	0.197,	// n-Butane
	0.251,	// n-Pentane
	0.304,	// n-Hexane
	0.346,	// n-Heptane
	0.396,	// n-Octane
	0.446,	// n-Nonane
	0.488,	// n-Decane
	0.530,	// n-Undecane
	0.577,	// n-Dodecane
	0.617,	// n-Tridecane
	0.643,	// n-Tetradecane
	0.685,	// n-Pentadecane
	0.721,	// n-Hexadecane
	0.771,	// n-Heptadecane
	0.806,	// n-Octadecane
	0.851,	// n-Nonadecane
	0.912,	// n-Eicosane
	0.196,	// Cyclopentane
	0.216,	// Cyclohexane
	0.209,	// Benzene
	0.262,	// Toluene
	0.311,	// o-Xylene
	0.325,	// m-Xylene
	0.320,	// p-Xylene
	0.296,	// Naphthalene
	0.566,	// Methanol
	0.643,	// Ethanol
	0.617,	// 1-Propanol
	0.585,	// 1-Butanol
	0.592,	// 1-Pentanol
	0.572,	// 1-Hexanol
	0.592,	// 1-Heptanol
	0.371,	// Cyclohexanol
	0.438,	// Phenol
	0.307,	// Acetone
	0.381,	// Aniline
	0.205,	// Furan
	0.239,	// Pyridine
	0.198,	// Fluoromethane
	0.154,	// Chloromethane
	0.192,	// Bromomethane
	0.053,	// Fluorine
	0.073,	// Chlorine
	0.128,	// Bromine
	0.020,	// Oxygen
	0.037,	// Nitrogen
	0.253,	// Ammonia
	0.143,	// Nitrous oxide
	0.585,	// Nitric oxide
	0.048,	// Carbon monoxide
	0.383,	// Hydrogen Fluoride
	0.134,	// Hydrogen Chloride
	0.069,	// Hydrogen Bromide
	0.096,	// Hydrogen Sulfide
	0.244	// Sulfur Dioxide	
};

/* 
	Default critical compressibiliy factors
*/ 
double lib_zc[GLOBAL::MAX_LIB_COMPS] =
{
	0.228,	// Water
	0.277,	// Carbon dioxide
	0.305,	// Helium
	0.300,	// Neon
	0.292,	// Argon
	0.286,	// Methane
	0.279,	// Ethane
	0.273,	// Propane
	0.272,	// n-Butane
	0.271,	// n-Pentane
	0.269,	// n-Hexane
	0.259,	// n-Heptane
	0.254,	// n-Octane
	0.252,	// n-Nonane
	0.245,	// n-Decane
	0.242,	// n-Undecane
	0.239,	// n-Dodecane
	0.233,	// n-Tridecane
	0.226,	// n-Tetradecane
	0.222,	// n-Pentadecane
	0.221,	// n-Hexadecane
	0.219,	// n-Heptadecane
	0.214,	// n-Octadecane
	0.215,	// n-Nonadecane
	0.215,	// n-Eicosane
	0.272,	// Cyclopentane
	0.274,	// Cyclohexane
	0.273,	// Benzene
	0.262,	// Toluene
	0.267,	// o-Xylene
	0.259,	// m-Xylene
	0.260,	// p-Xylene
	0.265,	// Naphthalene
	0.224,	// Methanol
	0.240,	// Ethanol
	0.252,	// 1-Propanol
	0.256,	// 1-Butanol
	0.260,	// 1-Pentanol
	0.259,	// 1-Hexanol
	0.263,	// 1-Heptanol
	0.253,	// Cyclohexanol
	0.240,	// Phenol
	0.234,	// Acetone
	0.248,	// Aniline
	0.297,	// Furan
	0.278,	// Pyridine
	0.252,	// Fluoromethane
	0.275,	// Chloromethane
	0.321,	// Bromomethane
	0.287,	// Fluorine
	0.279,	// Chlorine
	0.286,	// Bromine
	0.287,	// Oxygen
	0.288,	// Nitrogen
	0.241,	// Ammonia
	0.277,	// Nitrous oxide
	0.252,	// Nitric oxide
	0.300,	// Carbon monoxide
	0.117,	// Hydrogen Fluoride
	0.253,	// Hydrogen Chloride
	0.280,	// Hydrogen Bromide
	0.287,	// Hydrogen Sulfide
	0.269	// Sulfur Dioxide
};

/* 
	Default critical volumes in cm3/mol
*/ 
double lib_vc[GLOBAL::MAX_LIB_COMPS] =
{
	56.00,	// Water
	95.00,	// Carbon dioxide
	58.00,	// Helium
	42.00,	// Neon
	75.00,	// Argon
	99.00,	// Methane
	146.00,	// Ethane
	200.00,	// Propane
	255.00,	// n-Butane
	315.00,	// n-Pentane
	373.00,	// n-Hexane
	428.00,	// n-Heptane
	486.00,	// n-Octane
	540.00,	// n-Nonane
	601.00,	// n-Decane
	658.00,	// n-Undecane
	718.00,	// n-Dodecane
	779.00,	// n-Tridecane
	830.00,	// n-Tetradecane
	888.00,	// n-Pentadecane
	943.00,	// n-Hexadecane
	998.00,	// n-Heptadecane
	1059.00, // n-Octadecane
	1119.00, // n-Nonadecane
	1169.00, // n-Eicosane
	257.00, // Cyclopentane
	291.00,	// Cyclohexane
	261.00,	// Benzene
	314.00,	// Toluene
	374.00,	// o-Xylene
	377.00,	// m-Xylene
	381.00,	// p-Xylene
	413.00,	// Naphthalene
	117.00,	// Methanol
	168.00,	// Ethanol
	220.00,	// 1-Propanol
	276.00,	// 1-Butanol
	327.00,	// 1-Pentanol
	381.00,	// 1-Hexanol
	435.00,	// 1-Heptanol
	322.00,	// Cyclohexanol
	229.00,	// Phenol
	210.00,	// Acetone
	270.00,	// Aniline
	218.00,	// Furan
	254.00,	// Pyridine
	113.00,	// Fluoromethane
	142.00,	// Chloromethane
	156.00,	// Bromomethane
	67.00,	// Fluorine
	124.00,	// Chlorine
	135.00,	// Bromine
	74.00,	// Oxygen
	89.00,	// Nitrogen
	72.00,	// Ammonia
	98.00,	// Nitrous oxide
	58.00,	// Nitric oxide
	95.00,	// Carbon monoxide
	69.00,	// Hydrogen Fluoride
	82.00,	// Hydrogen Chloride
	100.00,	// Hydrogen Bromide
	99.00,	// Hydrogen Sulfide
	123.00	// Sulfur Dioxide
};

/*
	Default mw in g/mol
*/ 
double lib_mw[GLOBAL::MAX_LIB_COMPS] = 
{
	18.015,	// Water
	44.010,	// Carbon dioxide
	4.003,	// Helium
	20.180,	// Neon
	39.948,	// Argon
	16.040,	// Methane
	30.070,	// Ethane
	44.100,	// Propane
	58.120,	// n-Butane
	72.150,	// n-Pentane
	86.180,	// n-Hexane
	100.210, // n-Heptane
	114.230, // n-Octane
	128.200, // n-Nonane
	142.290, // n-Decane
	156.312, // n-Undecane
	170.338, // n-Dodecane
	184.365, // n-Tridecane
	198.392, // n-Tetradecane
	212.419, // n-Pentadecane
	226.446, // n-Hexadecane
	240.473, // n-Heptadecane
	254.500, // n-Octadecane
	268.527, // n-Nonadecane
	282.553, // n-Eicosane
	70.134,	// Cyclopentane
	82.145,	// Cyclohexane
	78.114,	// Benzene
	92.141,	// Toluene
	106.167, // o-Xylene
	106.167, // m-Xylene
	106.167, // p-Xylene
	128.174, // Naphthalene
	32.042,	// Methanol
	46.069,	// Ethanol
	60.096,	// 1-Propanol
	74.123,	// 1-Butanol
	88.150,	// 1-Pentanol
	102.177, // 1-Hexanol
	116.203, // 1-Heptanol
	110.161, // Cyclohexanol
	94.113,	// Phenol
	58.080,	// Acetone
	93.128,	// Aniline
	68.075,	// Furan
	79.101,	// Pyridine
	34.033,	// Fluoromethane
	50.488,	// Chloromethane
	94.939,	// Bromomethane
	37.997,	// Fluorine
	70.905,	// Chlorine
	159.808, // Bromine
	31.999,	// Oxygen
	28.014,	// Nitrogen
	17.031,	// Ammonia
	44.013,	// Nitrous oxide
	30.006,	// Nitric oxide
	28.010,	// Carbon monoxide
	20.006,	// Hydrogen Fluoride
	36.461,	// Hydrogen Chloride
	80.912,	// Hydrogen Bromide
	34.082,	// Hydrogen Sulfide
	64.065	// Sulfur Dioxide
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
