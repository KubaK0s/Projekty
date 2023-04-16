#include <iostream>
#include <fstream>
#include <vector>

#include "Dijkstra.h"
#include "InputHandler.h"
#include "ArgumentHandler.h"

using namespace std;


int main(int argc, char* argv[])
{
	ArgumentHandler ah;
	Files f = ah.process(argc, argv);
	if (f.end)
		return 0;


	CityTable cityTable;
	vector <Connection> connections;
	ifstream file;

	file.open(f.input, ios::in);

	string city1, city2;
	int distance;
	while (file >> city1 >> city2 >> distance)
	{
		cityTable.addCity(city1);
		cityTable.addCity(city2);
		connections.push_back(Connection(cityTable.getIdx(city1), cityTable.getIdx(city2), distance));
	}
	file.close();

	Dijkstra dij;
	dij.createGraph(connections, cityTable.cities.size());
	dij.dijkstra(cityTable.getIdx(f.centralOffice), cityTable, f.output);

	return 0;
}
