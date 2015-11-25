#include "SRK_EquationOfState.h"


SRK_EquationOfState::SRK_EquationOfState(void)
{
	//cout << "srk set up" << endl;
}


void SRK_EquationOfState::computeMixParameters(vector<double> zc, ComponentLib *pComp, double Pres, double Temp)
{
	int nc = GLOBAL::NC;
	const double R = GLOBAL::R;

// compute A and B for mixture, using srk equation
	// first get a, alpha=f(T) and b for pure components
	vector <double> a(nc), alpha(nc), b(nc); 
	double am=0, bm=0, Am=0, Bm=0;
	for ( int i = 0; i < nc; i++ ) 
	{
		b[i] = 0.08664*R*(pComp->tc[i]) / (pComp->pc[i]);
		//simple linear mixing rule for bm
		bm += zc[i]*b[i]; 

		a[i] = 0.427*R*R*(pComp->tc[i])*(pComp->tc[i]) / (pComp->tc[i]);
		alpha[i] = (1 + ( 0.48508 + 1.55171*(pComp->ac[i])-
			            0.15613*(pComp->ac[i])*(pComp->ac[i]))*
						(1-sqrt(Temp/(pComp->tc[i]))));
		alpha[i] *= alpha[i];

		pComp->aPure[i] = a[i] = alpha[i]*a[i];
		pComp->bPure[i] = b[i]; 
	}

	for ( int i = 0; i < nc; i++)
		for ( int j = 0; j < nc; j++)
		{
			am += zc[i]*zc[j]*sqrt( alpha[i]*a[i]*alpha[j]*a[j] );
		}

	// Reduced Am and Bm
	Am = am*Pres / ( R*R*Temp*Temp);
	Bm = bm*Pres / (R*Temp); 
	EOS_A_mix = Am; 
	EOS_B_mix = Bm;
	

	// Compute EOS coefficients for cubic eos 
	c0 =  1.0;
	c1 = -1.0;
	c2 = (Am-Bm-Bm*Bm); 
	c3 = -Am*Bm; 
}

void SRK_EquationOfState::computeDensity(vector<double> zc, ComponentLib *pComp, double Pres, double Temp, int phase_id, vector<double> &den)
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


};


void SRK_EquationOfState::computeFugacity(vector<double> zc, ComponentLib *pComp, double Pres, double Temp, int phase_id, vector<double> &fug)
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
	double term1=0; double term2 = 0; 
	vector<double> lnphi(NC);
	
	// compute mixture fugacity coefficients
	for ( int i = 0; i <NC; i++)
	{
		// compute "a sum" term 
		double sum_a = 0.0; 
		for ( int j = 0; j < NC; j++ )
			sum_a +=zc[j]*sqrt(pComp->aPure[i] * pComp->aPure[j]); 

		term1 = ((pComp->bPure[i])/bm)*(Zreturn-1)-log(Zreturn-EOS_B_mix);
		term2 = -(EOS_A_mix/EOS_B_mix )*(2*sum_a/am -(pComp->bPure[i])/bm)*log((Zreturn+EOS_B_mix)/Zreturn); 

		lnphi[i] = term1 + term2;

		// compute fugacity 
		fug[i] = exp(lnphi[i])*zc[i]*Pres;
	} 

};


SRK_EquationOfState::~SRK_EquationOfState(void)
{
}
