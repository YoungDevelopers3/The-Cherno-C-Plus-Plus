#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int v;
    list<int> *l;

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfs(int u, vector<int> &visited)
    {
        visited[u] = true;
        cout << u << " ";
        for (int v : l[u])
        {
            if (!visited[v])
            {
                dfs(v, visited);
            }
        }
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    vector<int> visited(5, false);
    g.dfs(0, visited);
}