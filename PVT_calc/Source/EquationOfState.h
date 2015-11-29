/*
 This is a general equation of state base class, 
 all of the equations of state that are available will implement 
 the required methods slightly differently. 
*/ 
#include "ComponentLib.h"
#include "global.h"
#include <vector> 
#include <iostream> 
using namespace std; 


#pragma once
 class EquationOfState
{
public:
	EquationOfState(void);
	~EquationOfState(void);

	/*
	All derived classes MUST implement these methods
	*/ 
	virtual void computeMixParameters(vector<double> zc, ComponentLib *p,double Pres, double Temp)=0;
	virtual void computeDensity(vector<double> zc, ComponentLib *p, double Pres, double Temp, int phase_id, vector<double> &den)=0;
	virtual void computeFugacity(vector<double> zc, ComponentLib *p, double Pres, double Temp, int phase_id, vector<double> &fug)=0;

	/*
		Computes average molecular weight of mixture 
	*/ 
	double computeAverageMW(vector<double> zc, ComponentLib *p)
	{
			double AMW = 0.0; 
			for ( int i = 0; i < GLOBAL::NC; i++) AMW+=zc[i]*(p->mw[i]); 
			return AMW; 
	}; 

	double EOS_A_mix; //< mixture eos paraemter A, dimensionless
	double EOS_B_mix; //< mixture eos parameter B, dimensionless 
	 
	
	vector<double> EOS_A_Pure; //< eos parameter A, dimensionless
	vector<double> EOS_B_Pure; //< eos parameter B, dimensionless

	double c0, c1, c2, c3; //< cubic eos coefficients
	
	void solveCubicEOS(double c0, double c1, double c2, double c3, int findMinRoot, double* Zroot );

	ComponentLib *pComps; //< holds pointer to props object

	string *eosName; //< name of eos 



	
};

