
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
		"CO2"   // CO2
	};

	And this pattern will be repeated for all lib array properties.
*/ 

/* 
   Default names 
*/ 
string lib_name[GLOBAL::MAX_LIB_COMPS] =
{
	"H2O" // Water 
};
/*
	Default critical temps in K
*/ 
double lib_tc[GLOBAL::MAX_LIB_COMPS] = 
{ 
	647.37 // Water  
};

/*
	Default critical pressures in bar
*/ 
double lib_pc[GLOBAL::MAX_LIB_COMPS] = 
{ 
	221.20 // Water  
};

/* 
	Default acentric factor
*/ 
double lib_acentric [ GLOBAL::MAX_LIB_COMPS] =
{
	0.345 // Water 
};

/*
	Default mw (g/mol)
*/ 
double lib_mw [ GLOBAL::MAX_LIB_COMPS] = 
{
	18.145 // Water
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




void ComponentLib::initialize_datamembers(int nc)
{
	 // resize all vectors to the number of components
	 // currently in the system
	 name.resize(nc); 
	 tc.resize(nc);
	 pc.resize(nc); 
	 ac.resize(nc);
	 zc.resize(nc); 
	 vc.resize(nc);
	 mw.resize(nc);
	
}

