#include <iostream>
using namespace std;

class Graph
{
    int adj[20][20];
    int visited[20];
    int vertices;

public:

    void CreateGraph()
    {
        int edges, source, destination;

        cout << "Enter number of vertices: ";
        cin >> vertices;

        for(int i = 0; i < vertices; i++)
        {
            for(int j = 0; j < vertices; j++)
            {
                adj[i][j] = 0;
            }
        }

        cout << "Enter number of edges: ";
        cin >> edges;

        for(int i = 0; i < edges; i++)
        {
            cout << "Enter source and destination: ";
            cin >> source >> destination;

            adj[source][destination] = 1;
            adj[destination][source] = 1;
        }

        cout << "Graph created successfully!" << endl;
    }

    void DisplayGraph()
    {
        cout << "\nAdjacency Matrix:\n";

        for(int i = 0; i < vertices; i++)
        {
            for(int j = 0; j < vertices; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS(int vertex)
    {
        visited[vertex] = 1;

        cout << vertex << " ";

        for(int i = 0; i < vertices; i++)
        {
            if(adj[vertex][i] == 1 && visited[i] == 0)
            {
                DFS(i);
            }
        }
    }

    void PerformDFS()
    {
        int start;

        for(int i = 0; i < vertices; i++)
        {
            visited[i] = 0;
        }

        cout << "Enter starting vertex: ";
        cin >> start;

        if(start < 0 || start >= vertices)
        {
            cout << "Invalid starting vertex!" << endl;
            return;
        }

        cout << "DFS Traversal: ";
        DFS(start);
        cout << endl;
    }
};

int main()
{
    Graph g;
    int choice;

    do
    {
        cout << "\n===== GRAPH DFS MENU =====";
        cout << "\n1. Create Graph";
        cout << "\n2. Display Graph";
        cout << "\n3. Perform DFS";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                g.CreateGraph();
                break;

            case 2:
                g.DisplayGraph();
                break;

            case 3:
                g.PerformDFS();
                break;

            case 4:
                cout << "Program terminated.";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while(choice != 4);

    return 0;
}
