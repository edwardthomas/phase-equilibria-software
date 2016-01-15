#include "VDW_EquationOfState.h"


VDW_EquationOfState::VDW_EquationOfState(void)
{
	eosName = new string("VDW Equation of State"); 
}


void VDW_EquationOfState::computeMixParameters(vector<double> zc, ComponentLib *pComp, double Pres, double Temp)
{
	/*
	The van der Waals equation of state is implemented with the energy parameter and molecular covolume as 
	as constants using original combining rules. 
	*/ 
	int nc = GLOBAL::NC;
	const double R = GLOBAL::R;

	double tc, pc; 

// compute A and B for mixture
	// first get a, and b for pure components
	vector <double> a(nc), b(nc); 
	double am=0, bm=0, Am=0, Bm=0;
	for ( int i = 0; i < nc; i++ ) 
	{
		// temp variables to make calculation simpler to read
		tc = pComp->tc[i]; // crit temp
		pc = pComp->pc[i]; // crit pres
		ac = pComp->ac[i]; // acentric factor

		// pure component b 
		b[i] = R*tc/(8*pc);

		//linear mixing rule for bm
		bm += zc[i]*b[i]; 

		// pure component a
		a[i] = 27*R*R*tc*tc/(64*pc);

		//mixing rule for am -- calculation finished outside of loop
		am += zc[i]*sqrt( a[i] );

		// pure a
		pComp->aPure[i] = a[i];
		// pure b
		pComp->bPure[i] = b[i]; 
	}

	//am*am to fnish calculation
	am = am*am;

	// Reduced Am and Bm
	Am = am*Pres / ( R*R*Temp*Temp);
	Bm = bm*Pres / (R*Temp); 
	EOS_A_mix = Am; 
	EOS_B_mix = Bm;
	

	// Compute EOS coefficients for cubic eos 
	c0 =  1.0;
	c1 = -Bm-1.0;
	c2 = Am; 
	c3 = -Am*Bm; 
}

void VDW_EquationOfState::computeDensity(vector<double> zc, ComponentLib *pComp, double Pres, double Temp, int phase_id, vector<double> &den)
{
	const double R = GLOBAL::R;
	double Zreturn = 0.0; 

	// update mix parameters 
	computeMixParameters(zc, pComp, Pres, Temp);

	// compute average mw 
	double AMW = computeAverageMW(zc, pComp); 

	// solve cubic
	solveCubicEOS(c0,c1,c2,c3, phase_id, &Zreturn);

	double density  = Pres/(Zreturn*R*Temp);

	den[phase_id] = density*AMW;


}


void VDW_EquationOfState::computeFugacity(vector<double> zc, ComponentLib *pComp, double Pres, double Temp, int phase_id, vector<double> &fug)
{
	const double R = GLOBAL::R;
	int NC = GLOBAL::NC; 
	double Zreturn = 0.0; 

	// update mix parameters 
	computeMixParameters(zc, pComp, Pres, Temp);

	// compute average mw 
	double AMW = computeAverageMW(zc, pComp); 
	
	// solve cubic
	solveCubicEOS(c0,c1,c2,c3, phase_id, &Zreturn);

	// get dimensioned mix parameters 
	double bm = EOS_B_mix*R*Temp/Pres;
	double am = EOS_A_mix*R*R*Temp*Temp/Pres;

	// temporary storage
	double term1=0; double term2=0; 
	vector<double> lnphi(NC), A(NC), B(NC);
	
	// compute mixture fugacity coefficients
	for ( int i = 0; i <NC; i++)
	{
		//compute dimensions Ai and Bi
		A[i] = a[i]*Pres / (R*R*Temp*Temp);
		B[i] = b[i]*Pres / (R*Temp);
	
		lnphi[i] = B[i]/(Zreturn-EOS_B_mix)-log(Zreturn*(1-EOS_B_mix/Zreturn))-2*sqrt(EOS_A_mix*A[i])/Zreturn;

		// compute fugacity 
		fug[i] = exp(lnphi[i])*zc[i]*Pres;
	} 

};


VDW_EquationOfState::~VDW_EquationOfState(void)
{
}

