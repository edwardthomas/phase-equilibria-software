#include "EquationOfState.h"


EquationOfState::EquationOfState(void)
{
}

double F( double c0, double c1, double c2, double c3, double Z) { return c0*Z*Z*Z +c1*Z*Z + c2*Z + c3; }
double DF( double c0, double c1, double c2, double Z) { return 3*c0*Z*Z +2*c1*Z + c2; }
/*
This method solves cubic eos with the coefficients c0, c1, c2, c3 
using Newton iteration. The form of the eos is assumed to be 
c0*Z^3 + c1*Z^2 + c2*Z + C3 = 0 
*/ 
void EquationOfState::solveCubicEOS(double c0, double c1, double c2, double c3, int findMinRoot, double* Zroot )
{
	double Z_old = 1.0;// guess 
	double Z_new;
	int count = 0; 
	//double h = 0.5;// step size
	
	// use Newton iteration to find a root 
	double eps = 1.0; 
	while ( eps > 1e-12 ) 
	{
		Z_new = Z_old - (F(c0, c1, c2, c3, Z_old)/DF(c0, c1, c2, Z_old));//*h;
		eps = pow(abs(Z_new-Z_old),2);
		Z_old = Z_new;

		count++;
	}
	// found one root 
	//cout << count << "\t" << Z_new <<"\t" << eps << endl;
	
	// coefficients of defalted quatratic equation
	double a = c0; 
	double b = c1+Z_new*a;
	double c = c2+b*Z_new;
	//determinant 
	double delta = b*b - 4*a*c;

	// roots 
	double z1=0, z2=0, z3=0; 

	if ( delta >= 0 ) // two real roots remaining (or real duplicate roots) 
	{
		z1 = Z_new;
		z2 = (-b+sqrt(delta)) / 2*a;
		z3 = (-b-sqrt(delta)) / 2*a;

		if (findMinRoot)
		{
			*Zroot = min( min(z1,z2) , z3 );
		}
		else 
		{
			*Zroot = max( max(z1,z2) ,z3); 
		}
	}
	else // already found only real root 
	{
		
		*Zroot = Z_new;
	}
	 

	
}

EquationOfState::~EquationOfState(void)
{
}
