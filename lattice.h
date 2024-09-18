#ifndef LATTICE_H
#define LATTICE_H

#include <eigen3/Eigen/Dense>
#include <iostream>



using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;

class lattice
{

private:

    double lattice_const;
    int size;
    Eigen::MatrixXd lattice_points; //unknown sizes
    std::vector<double> latticeX;
    std::vector<double> latticeY;

public:

    //constructor
    lattice(double lattice_const, int size);

    // basis functions and repeat unit cell
    void generate();

    Eigen::MatrixXd get_lattice(); //get private lattice_points

    std::vector<double> get_vectorX(); //turn x coords of lattice_points as vector (matplotlib)
    std::vector<double> get_vectorY(); 

    // rotate lattice points
    void rotate(float theta);
    // print lattice_point
    void print();
    
    //destructor
    ~lattice();

};


#endif
