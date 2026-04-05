#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    bool isCyclicBFS(int start, vector<bool> visited)
    {
        queue<pair<int, int>> Q;

        Q.push({start, -1});
        visited[start] = true;

        while (Q.size() > 0)
        {
            int u = Q.front().first;
            int parent = Q.front().second;
            Q.pop();

            list<int> neighbours = l[u];
            for (int v : neighbours)
            {
                if (!visited[v])
                {
                    Q.push({v, u});
                    visited[v] = true;
                }
                else if (v != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle()
    {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (isCyclicBFS(i, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    if (g.isCycle())
    {
        cout << "Cycle present\n";
    }
    else
    {
        cout << "No cycle\n";
    }
}