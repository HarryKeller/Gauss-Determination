#include <vector>
#ifndef _GAUS_H_
#define _GAUS_H_
class Gaus
{
private:

	std::vector<std::pair<std::vector<std::pair<double, std::string>>, double>> *p_matrix;
	//Idee ist diese methode rekursiv aufzurufen, bis alle variablen zerst�rt sind und sich das erste ergebnis ablesen l�sst
	


public:

	double destroyVar(int col);
	Gaus(std::vector<std::pair<std::vector<std::pair<double, std::string>>, double>>* matrix);

};
#endif // !_GAUS_H_
