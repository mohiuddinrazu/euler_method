// Euler's method

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

//Declaring initial condition variables
double x = 0, z = 1;
double h = 0.01;

//Declaring the euler function
void euler(double w){
    //Declaring file name as an automated process.
    //You can do this manually if this seems difficult to understand.
    //You have to run the program more than once if you do so.
	std::string filename = "euler_for_w_" + std::to_string(int(w)) + ".dat";
	
	ofstream fout(filename);
	fout << "t \t x \t z" << endl;
	//Initiating limit
	 double lim = 20;
	
	cout << "Writing to file \"" << filename << "\" for w = " << w << endl;
	double x1, z1;
	for(double t=0; t <= lim; t += h){
		fout << t << "\t" << x << "\t" << z << endl;
		x1 = x + z*h;
		z1 = z -1*w*w*x*h;
		
		//Swapping variable values
		x = x1;
		z = z1;
	}
	cout << "Done for w = "<< w << endl << endl;
	fout.close();
}

int main(){
	euler(1);
	
	euler(4);
	
	euler(9);
	
	euler(16);
	
	cout << "Process Completed! \n \nCheck the above files.";
	return 0;
}
