#Fluidity
##An open source fluid phase equilibria project. 

###Notes on compiling and running 

The code in source has been compiled using visual C++, it assumes the input file, "pvt.in", is in the same working directory where where the executable is run. The project can be built on linux using the g++ compiler and the included makefile. Simply change to the source directory and type: 
```
  make 
```
This requires a version of the g++ compiler and GNU make. The resulting executable "fluidity" should be run in the same directory as your input file. 

A decription of the input file can be found [HERE](https://github.com/edwardthomas/phase-equilibria-software/wiki/Input-File-Description).

###Implementation notes
* Adding equations of state will be straight forward, just create a class using the SRK class as template. Implement the methods in the class differently depending on the EOS, but make sure you write the methods that are defined in the base class EquationOfState. 
* Adding simulation types will be similar, they will all be derived classes of PVT_Simulation. LiquidDensity is the first example simulation we have.
* More implementation info [HERE] (https://github.com/edwardthomas/phase-equilibria-software/wiki/Implementing-New-Features)

### Simulation modes implemented
* Liquid density calculation
* Pure component saturation pressure 

### Equations of state
* VDW  - classic van der Waals
* SRK - Soave modification of Redlich-Kwong
 
###List of Contributors
####2016 
* Edward Thomas 
* Heath Henley
* Robert Kelly 
####2015 
* Edward Thomas 
* Heath Henley
* Robert Kelly 
