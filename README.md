#Fluidity
##An open source fluid phase equilibria project. 

###Notes on compiling and running 

The code in source has been compiled using visual C++, it assumes the input file, "pvt.in", is in the same working directory where where the executable is run. It will also compile with g++ on linux or mac using the following command: 
```
  g++ -std=c++11  main.cpp ComponentLib.cpp PVT_calc.cpp global.cpp -o fluidity 
```
A make file will be provided in the future.  

###Implementation notes 
###List of Contributors
####2015 
* Edward Thomas 
* Heath Henley
* Robert Kelly 
