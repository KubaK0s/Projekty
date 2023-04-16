#include<iostream>
#include<stdio.h>
#include <vector>
#include <stack>
#include <fstream>

#include "InputHandler.h"

using namespace std;

struct Dijkstra
{
    vector<vector<int>> G;
    int cityCount;

    void showGraph();

    void createGraph(vector<Connection> connections, int nodeCount);

    void dijkstra(int startnode, CityTable cityTable, string output);
};