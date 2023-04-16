#include "Dijkstra.h"

#define INFINITY 99999
#define max 10

void Dijkstra::showGraph()
{
    for (int y = 0; y < G.size(); y++)
    {
        for (int x = 0; x < G[y].size(); x++)
        {
            cout << G[y][x] << ' ';
        }
        cout << '\n';
    }
}

void Dijkstra::createGraph(vector<Connection> connections, int cityCount)
{
    this->cityCount = cityCount;
    G = vector<vector<int>>(cityCount, vector<int>(cityCount));

    int c1, c2, d;
    for (int i = 0; i < connections.size(); i++)
    {
        c1 = connections[i].city1;
        c2 = connections[i].city2;
        d = connections[i].distance;
        G[c1][c2] = d;
        G[c2][c1] = d;
    }
}

void Dijkstra::dijkstra(int startnode, CityTable cityTable, string output) {
    int cost[max][max], distance[max], pred[max];
    int visited[max], count, mindistance, nextnode, i, j;

    for (i = 0; i < cityCount; i++)
        for (j = 0; j < cityCount; j++)
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];

    for (i = 0; i < cityCount; i++) {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }

    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;

    while (count < cityCount - 1) {
        mindistance = INFINITY;
        for (i = 0; i < cityCount; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        visited[nextnode] = 1;

        for (i = 0; i < cityCount; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    ofstream file;
    file.open(output, ios::out);

    stack<int> wholeConnection;
    for (i = 0; i < cityCount; i++)
    {

        if (i != startnode)
        {
            wholeConnection.push(i);
            j = i;
            do {
                j = pred[j];
                wholeConnection.push(j);
            } while (j != startnode);

            int size = wholeConnection.size();

            for (int x = 0; x < size; x++)
            {
                file << cityTable.cities[wholeConnection.top()];
                if (x < size - 1)
                    file << "->";
                wholeConnection.pop();
            }

            file << ": " << distance[i] << '\n';
        }
    }
    file.close();
}