#include "Gaus.h"


double Gaus::destroyVar(int col)
{
	bool isfirstline = true;
	double zaehlerLetzerVariable;
	double wertErgebnis;

	//Immer die vorherige Zeile, wird benötigt um den multiplikator zu errechnen
	//Im ersten Durchlauf ist es automatisch die erste Zeile
	std::pair<std::vector<std::pair<double, std::string>>, double> *line_before = new std::pair<std::vector<std::pair<double, std::string>>, double>;
	for (std::vector<std::pair<std::vector<std::pair<double, std::string>>, double>>::iterator it1 = p_matrix->begin(); it1 != p_matrix->end(); it1++)
	{
		//Die erste Zeile bleibt immer unberührt
		if (isfirstline)
		{
			//speichert die erste Zeile in line_before
			line_before->first = it1->first;
			line_before->second = it1->second;
			isfirstline = false;
			continue;
		}
		//Multiplikator mit dem die andere Zeile multipliziert wird default 0, um zu sehen ob er bereits belegt wurde
		double multiplikator = 0;
		//Hier wird gezählt wie of durch die Schleife durchgegangen worden ist, dies ist wichtig zu wissen, um die richtige Variable ( x,y,z etc.) ausfinding zu machen, die
		//in dem jeweiligen durchlauf eleminiert wird
		//Es ist zu überlegen, ob i überhaupt noch benötigt wird
		double i = 0;
		//Gesamte Zeile
		for (std::vector<std::pair<double, std::string>>::iterator it2 = it1->first.begin(); it2 != it1->first.end(); it2++)
		{
			//Wenn die Variable bereits eleminiert wurde, also col bereits hochgezählt wurde
			/*if (col > i)
			{
				i++;
				continue;
			}*/
			
			//Zählt durchläufe von line_before, genau wie i eine Zeile weiter oben mit dem selben Grund
			int a = 0;
			double valueLineBefore;
			for (std::vector<std::pair<double, std::string>>::iterator it_lb = line_before->first.begin(); it_lb != line_before->first.end(); it_lb++)
			{
				//Hier wird jetzt aus der vorhergehenden Zeile(it_lb) und der aktuellen(it2) der Multiplikator mit dem die aktuelle durchmultiplizert werden muss
				//gebildet
				if (multiplikator == 0)
				{
					multiplikator = it2->first / it_lb->first;
				}
				if (a == i)
				{
					valueLineBefore = it_lb->first;
				}
				
				a++;
			}
			//durchmultiplizieren mit dem Multiplikator
			//Die Zeilen die aufgrund der Abfrage mit if(col > 0 ) übersprungen wurden müssen nicht behandelt werden, da diese ja bereits 0 sind
			// und eine multiplikation mit 0 wenig Sinvoll ist
			it2->first = it2->first - valueLineBefore * multiplikator;
			zaehlerLetzerVariable = it2->first;
			i++;
		}
		//Das "Ergebnis" wird an dieser Stelle ebenfalls multipliziert
		
		it1->second = it1->second- line_before->second*multiplikator;
		wertErgebnis = it1->second;
	}
	//An dieser Stelle muss später die Rekursion eingebaut werden, falls eine überhaupt notwenidg ist. Zumindest von der Funktion, in der wir gerade drin sind.

	//Gibt den Wert der ersten Variable aus, die ermittelt wurde
	return wertErgebnis / zaehlerLetzerVariable;
}

Gaus::Gaus(std::vector<std::pair<std::vector<std::pair<double, std::string>>, double>>*matrix)
{
	//Pointer to the matrix
	//maybe its better if a copy becomes created 
	//I dont know...
	p_matrix = matrix;

}
