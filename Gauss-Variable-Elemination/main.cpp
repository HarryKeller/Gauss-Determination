#include <vector>
#include <iostream>
#include <string>
#include "Gaus.h"
int main()
{
	
	//Hier werden die einzelnen lines reingepusht
	std::vector<std::pair<std::vector<std::pair<double, std::string>>, double>> *matrix = new std::vector<std::pair<std::vector<std::pair<double, std::string>>, double>>;

	//Gesamte Line
	std::pair<std::vector<std::pair<double, std::string>>, double> line1;
	std::pair<std::vector<std::pair<double, std::string>>, double> line2;

	//Gesamte seite vorm =
	std::vector<std::pair<double, std::string>> pm_l1;
	std::vector<std::pair<double, std::string>> pm_l2;

	//Einzelne parameter
	std::pair<double, std::string> pm1_l1;
	std::pair<double, std::string> pm2_l1;
	std::pair<double, std::string> pm1_l2;
	std::pair<double, std::string> pm2_l2;
	//Soviel zur Grundstrucktur zum Befüllen der Matrix

	//Befüllen der einzelnen Parameter
	//Erste Zeile
	pm1_l1.first = 3;
	pm1_l1.second = "x";
	pm2_l1.first = -4;
	pm2_l1.second = "y";

	//Zweite Zeile
	pm1_l2.first = 2;
	pm1_l2.second = "x";

	pm2_l2.first = 3;
	pm2_l2.second = "y";
	//Befüllen der Einzelnen Parameter abgeschlossen
	//Befüllen des Teils vorm =

	pm_l1.push_back(pm1_l1);
	pm_l1.push_back(pm2_l1);
	pm_l2.push_back(pm1_l2);
	pm_l2.push_back(pm2_l2);
	//Befüllen abgeschlossen des Teils vorm =
	//Befüllen der gesamten Zeile
	line1.first = pm_l1;
	line1.second = -26;
	line2.first = pm_l2;
	line2.second = 28;
	//Befülle der Gesamten Zeile abgeschlossen
	//Befüllen der Matrix
	matrix->push_back(line1);
	matrix->push_back(line2);
	//Befüllen abgeschlossen

	//Ausgabe der Matrix sieht in etwas so aus(jede Zeile ist eine Linie):
	// 1x 2y 5
	// 3x 4x 6

	//Ausgabe der Matrix:
	for (std::vector<std::pair<std::vector<std::pair<double, std::string>>, double>>::iterator it1 = matrix->begin(); it1 != matrix->end(); it1++)
	{
		for (std::vector<std::pair<double, std::string>>::iterator it2 = it1->first.begin(); it2 != it1->first.end(); it2++)		//einzelne Zeile der Matrix ausgeben
		{
			//Sind hier in dem Teil vor dem =
			std::cout << it2->first;
			std::cout << it2->second;
		}
		std::cout << it1->second << std::endl;
	}
	//Also befüllen funktioniert
	std::cout << "-------------------------------------------------------------------------------" << std::endl;

	//Im a Bad boy
	system("pause >nul");

	Gaus *g = new Gaus(matrix);
	std::cout<< std::endl << g->destroyVar(0);

	system("pause>nul");
	return 0;
}