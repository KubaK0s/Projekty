#pragma once
#include <vector>
#include <iostream>

using namespace std;

struct Connection {
	int city1;
	int city2;
	int distance;
	Connection(int city1, int city2, int distance)
	{
		this->city1 = city1;
		this->city2 = city2;
		this->distance = distance;
	}
};

struct CityTable {
	vector <string> cities;

	int getIdx(string name) {

		for (int i = 0; i < cities.size(); i++)
		{
			if (cities[i] == name)
				return i;

		}
		return -1;
	}

	void addCity(string city)
	{
		for (int i = 0; i < cities.size(); i++)
		{
			if (cities[i] == city)
				return;
		}
		cities.push_back(city);
	}
};

