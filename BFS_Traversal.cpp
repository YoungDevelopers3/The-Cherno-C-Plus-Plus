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
        l[v].push_back(u);
        l[u].push_back(v);
    }

    void BFS()
    {
        queue<int> Q;
        vector<int> Visited(V, false);
        Q.push(0);
        Visited[0] = true;
        while (Q.size() > 0)
        {
            int u = Q.front();
            Q.pop();
            cout << u << " ";

            for (int v : l[u])
            {
                if (!Visited[v])
                {
                    Visited[v] = true;
                    Q.push(v);
                }
            }
        }
    }
};

int main()
{

    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.BFS();
    return 0;
}