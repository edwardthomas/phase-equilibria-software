#Fluidity
##An open source fluid phase equilibria project. 

###Notes on compiling and running 

The code in source has been compiled using visual C++, it assumes the input file, "pvt.in", is in the same working directory where where the executable is run. It will also compile with g++ on linux or mac using the following command: 
```
  g++ -std=c++11  *.cpp -o fluidity 
```
A make file will be provided in the future.  

###Implementation notes
* Adding equations of state will be straight forward, just create a class using the SRK class as template. Implement the methods in the class differently depending on the EOS, but make sure you write the methods that are defined in the base class EquationOfState. 
* Adding simulation types will be similar, they will all be derived classes of PVT_Simulation. LiquidDensity is the first example simulation we will have, however it is currently unfinished. 

###List of Contributors
####2015 
* Edward Thomas 
* Heath Henley
* Robert Kelly 
