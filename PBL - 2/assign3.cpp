#include <iostream>
#include <queue>
using namespace std;

class gnode
{
    int vertex;
    gnode *next;
    friend class graph;
};

class graph
{
private:
    gnode *head[20];
    int n;
    int visited[20];

public:
    graph();
    void create();
    void display();
    void DFS_start();
    void DFS(int v);
    void BFS(int v);
};



graph::graph()
{
    cout << "Enter number of vertices: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        head[i] = new gnode;
        head[i]->vertex = i;
        head[i]->next = NULL;
    }
}


void graph::create()
{
    int v;
    char ans;

    for (int i = 0; i < n; i++)
    {
        gnode *temp = head[i];

        do
        {
            cout << "Enter adjacent vertex for " << i << ": ";
            cin >> v;

            if (v == i)
            {
                cout << "Self loops are not allowed\n";
            }
            else
            {
                gnode *curr = new gnode;
                curr->vertex = v;
                curr->next = NULL;

                temp->next = curr;
                temp = temp->next;
            }

            cout << "Add more adjacent vertices? (y/n): ";
            cin >> ans;

        } while (ans == 'y' || ans == 'Y');
    }
}
void graph::display()
{
    cout << "\nAdjacency List Representation:\n";

    for (int i = 0; i < n; i++)
    {
        gnode *temp = head[i];
        cout << temp->vertex << " -> ";

        temp = temp->next;
        while (temp != NULL)
        {
            cout << temp->vertex << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
void graph::DFS_start()
{
    int v;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "Enter starting vertex for DFS: ";
    cin >> v;

    cout << "DFS Traversal: ";
    DFS(v);
    cout << endl;
}
void graph::DFS(int v)
{
    cout << v << " ";
    visited[v] = 1;

    gnode *temp = head[v]->next;
    while (temp != NULL)
    {
        int w = temp->vertex;
        if (!visited[w])
            DFS(w);
        temp = temp->next;
    }
}
void graph::BFS(int v)
{
    queue<int> q;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    q.push(v);
    visited[v] = 1;

    cout << "BFS Traversal: ";

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        gnode *temp = head[curr]->next;
        while (temp != NULL)
        {
            int w = temp->vertex;
            if (!visited[w])
            {
                visited[w] = 1;
                q.push(w);
            }
            temp = temp->next;
        }
    }
    cout << endl;
}
int main()
{
    graph g;

    g.create();
    g.display();

    g.DFS_start();

    int start;
    cout << "Enter starting vertex for BFS: ";
    cin >> start;
    g.BFS(start);

    return 0;
}