
#include "lattice.h"
#include <iostream>
#include <string>
#include <iomanip>  // For std::setprecision
#include <sstream>  // For std::ostringstream
#include <eigen3/Eigen/Dense>
#include <matplotlibcpp/matplotlibcpp.h>

namespace plt = matplotlibcpp;

using Eigen::MatrixXd;
using Eigen::VectorXd;

int main(){

    double a = 3.18; //angstrom
    int size = 20;

    lattice mos2(a, size);
    lattice twist_mos2(a, size);

    mos2.generate();
    twist_mos2.generate();

    float twisted_angle;
    std::cout<<"Twisted Angle:? (float)"<<std::endl;
    std::cin >> twisted_angle;    

    twist_mos2.rotate(twisted_angle);

    std::vector<double> mos2X = mos2.get_vectorX();
    std::vector<double> mos2Y = mos2.get_vectorY();

    std::vector<double> tmos2X = twist_mos2.get_vectorX();
    std::vector<double> tmos2Y = twist_mos2.get_vectorY();
    
    plt::figure();

    plt::rcparams({
        {"font.family", "Arial"},          // Set font family
        {"font.size", "22"},               // Set general font size
        {"axes.titlesize", "38"},          // Set title font size
        {"axes.labelsize", "38"},          // Set axis label font size
        {"xtick.labelsize", "30"},         // Set x-axis tick label font size
        {"ytick.labelsize", "30"},         // Set y-axis tick label font size
        {"xtick.major.size", "5"},         // Set length of major ticks on x-axis
        {"ytick.major.size", "5"}          // Set length of major ticks on y-axis
    });

    plt::figure_size(2000, 1250);

    plt::plot(mos2X, mos2Y,"bo");  //scatter
    plt::plot(tmos2X, tmos2Y,"ro"); 
    plt::axis("equal");
    plt::xlim(-100,100); //the order of calling will make this xlim/ylim take effect or not
    plt::ylim(-90, 90); 

    plt::xlabel("x (Angstrom)");
    plt::ylabel("y (Angstrom)");   
       
      
    // save figure
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(1) << twisted_angle;

    // First concatenate as a std::string
    std::string filename_str = "moire_" + stream.str()+ ".png";
    
    // Then convert the std::string to const char* using c_str()
    const char* filename = filename_str.c_str();
    std::cout << "Saving result to " << filename << std::endl;;
    plt::save(filename);
    //plt::show();
    
    //plt::clf();
    plt::close();
   
    
    return 0;

}
