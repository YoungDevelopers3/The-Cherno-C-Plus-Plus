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

    bool DFS_Detection(int u, int parent, vector<bool> visited)
    {
        visited[u] = true;

        for (int v : l[u])
        {
            if (!visited[v])
            {
                if (DFS_Detection(v, u, visited))
                {
                    return true;
                }
            }
            else if (v != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool containsCycle()
    {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (DFS_Detection(i, -1, visited))
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

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    if (g.containsCycle())
    {
        cout << "Cycle present\n";
    }
    else
    {
        cout << "No cycle\n";
    }
}