#include "lattice.h"
#include <eigen3/Eigen/Dense>
#include <cmath>
#include <iostream>

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;

lattice::lattice(double lattice_const, int size)
        :lattice_const(lattice_const), size(size){}

void lattice::generate(){

    //basis functions
    VectorXd v1(2); //vector v is created to contain 2 coefficients 
    v1 << 1, 0;
    v1*= lattice_const;
    VectorXd v2(2);
    v2 << 0.5, 0.5*sqrt(3);
    v2*= lattice_const;

    lattice_points.resize((2*size+1)*(2*size+1),2); //note the size of lattice
    int lattice_num = 0; //count index of lattice_points
    //note: lattice_points needs to be appended row-wise according to its size
    for (int i = -size; i <= size; ++i) {
        for (int j = -size; j <= size; ++j) {

            lattice_points.row(lattice_num) = v1 * i + v2 * j;
            lattice_num += 1;
        }
    }
}

void lattice::rotate(float theta){ //theta in unit of degrees

    MatrixXd Rmatrix(2,2); //rotation matrix

    theta *= M_PI/180; 
    Rmatrix <<cos(theta) , -1*sin(theta),
        sin(theta), cos(theta);

    lattice_points = (Rmatrix * lattice_points.transpose()).transpose();
}

Eigen::MatrixXd lattice::get_lattice(){
    return lattice_points;
}

std::vector<double> lattice::get_vectorX(){

    int nrows = lattice_points.rows();

    for(int i=0; i<nrows; ++i) {
        latticeX.push_back(lattice_points(i,0)); //X vector
    }

    return latticeX;
}

std::vector<double> lattice::get_vectorY(){

    int nrows = lattice_points.rows();

    for(int i=0; i<nrows; ++i) {
        latticeY.push_back(lattice_points(i,1));//Y vector
    }

    return latticeY;
}

void lattice::print(){
    std::cout << "lattice =" <<std::endl;
    for(int i=0; i<lattice_points.rows(); ++i) {
        std::cout<<lattice_points.row(i)<< " ";
    }
}


lattice::~lattice(){
    //std::cout << "Destructor: Deallocated memory." << std::endl;
}
