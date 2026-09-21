#include <iostream>
#include <fstream>
#include <random>
#include <vector>


int main() {
	double mu = 1.40; // long term mean
	double sigma = 0.01;  // volatility, typical of commodities
	double theta = 0.15;  // mean-revision speed
        int time = 100; // days 			  
	double initial_val = 1.924;
	int time_scale = 1;
	// random number generator
	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(0,1);
	std::vector<double> v = {initial_val};
	double dSt = 0.0;

	for (int i; i <= time; i++) {
		double St = initial_val;
		double dw = distribution(generator);
		dSt = theta*(mu-St)*time_scale + sigma*dw;
		St = St + dSt;
		v.push_back(St);
	}

	for (auto i : v)
		std::cout << i << " ";

	std::ofstream datafile;
	datafile.open ("datafile.txt");
	for (int i; i <= time; i++) {
		datafile << i << " " << v[i] << "\n";
	}	
	datafile.close();
	return 0;
}




