#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int vertices;
    vector<int> adj[20];

public:

    void CreateGraph()
    {
        int edges, source, destination;

        cout << "Enter number of users: ";
        cin >> vertices;

        for(int i = 0; i < vertices; i++)
        {
            adj[i].clear();
        }

        cout << "Enter number of friendships: ";
        cin >> edges;

        for(int i = 0; i < edges; i++)
        {
            cout << "Enter two connected users: ";
            cin >> source >> destination;

            if(source < 0 || source >= vertices ||
               destination < 0 || destination >= vertices)
            {
                cout << "Invalid user number!" << endl;
                i--;
                continue;
            }

            adj[source].push_back(destination);
            adj[destination].push_back(source);
        }

        cout << "Social network created successfully!" << endl;
    }

    void DisplayGraph()
    {
        cout << "\nAdjacency List:\n";

        for(int i = 0; i < vertices; i++)
        {
            cout << i << " -> ";

            for(int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << " ";
            }

            cout << endl;
        }
    }

    void BFS(int startUser)
    {
        if(startUser < 0 || startUser >= vertices)
        {
            cout << "Invalid starting user!" << endl;
            return;
        }

        int visited[20] = {0};
        queue<int> q;

        visited[startUser] = 1;
        q.push(startUser);

        cout << "Users connected level by level: ";

        while(!q.empty())
        {
            int currentUser = q.front();
            q.pop();

            cout << currentUser << " ";

            for(int i = 0; i < adj[currentUser].size(); i++)
            {
                int friendUser = adj[currentUser][i];

                if(visited[friendUser] == 0)
                {
                    visited[friendUser] = 1;
                    q.push(friendUser);
                }
            }
        }

        cout << endl;
    }
};

int main()
{
    Graph socialNetwork;
    int choice, startUser;

    do
    {
        cout << "\n===== SOCIAL NETWORK MENU =====";
        cout << "\n1. Create Graph";
        cout << "\n2. Display Adjacency List";
        cout << "\n3. Perform BFS";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                socialNetwork.CreateGraph();
                break;

            case 2:
                socialNetwork.DisplayGraph();
                break;

            case 3:
                cout << "Enter starting user: ";
                cin >> startUser;

                socialNetwork.BFS(startUser);
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
