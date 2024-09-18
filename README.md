# Twisted Moire Supperlattice 


Simulating twisted MoS2 biayer with varied twisted angles. 

## Dependency

`matplotlibcpp` - to visualize moire superlattice 
`eigen3` - to do matrix multiplation

## To Use

Just do 
```bash
mkdir build
cd build
cmake ..
make -j4
./twisted_moire
```
then it will ask
`Twisted Angle:? (float)`
Once you input the angle, the program will eat the input as twisted angle then generate lattice with twisted angle. Then overlay them together.

## More with shell script

the shell script `more.sh`

can run the c binary repeatedly with odd number angle 



