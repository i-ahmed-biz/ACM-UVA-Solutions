#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <queue>
#include <cstdio>

#define MAX_NODE 30
using namespace std;

enum VisitStatus
{
    NOT_VISITED,
    VISITED
};

class Graph
{
   public:
        unsigned int nVertices;
        std::vector<int>adj[MAX_NODE];
        std::map<string,int>vertixToInt;

        void add_edge(int src, int dest)
        {
           adj[src].push_back(dest);
        }

        int BFS(string srcStr,string destStr)
        {
           int src;
           int dest;
           int tempVertix;
           unsigned int i;

           std::vector<bool>visited;
           std::vector<int>vCost;
           std::queue<int>vQueue;

           for(i = 0; i < nVertices;i++)
           {
                visited.push_back(NOT_VISITED);
                vCost.push_back(0);
           }

           std::map<string,int>::iterator vIntIterator;
           vIntIterator = vertixToInt.find(srcStr);
           src = vIntIterator->second;

           vIntIterator = vertixToInt.find(destStr);
           dest = vIntIterator->second;

           vQueue.push(src);
           vCost[src] = 0;
           visited[src] = VISITED;

           while(!vQueue.empty())
           {
               tempVertix = vQueue.front();
               vQueue.pop();

               for(i = 0; i < adj[tempVertix].size();i++)
               {
                   if(visited[adj[tempVertix][i]] == NOT_VISITED)
                   {
                       vQueue.push(adj[tempVertix][i]);
                       visited[adj[tempVertix][i]] = VISITED;
                       vCost[adj[tempVertix][i]] = vCost[tempVertix] + 1;
                   }
                   if(adj[tempVertix][i] == dest)
                   {
                        return vCost[dest];
                   }
               }
           }
           return 0;
        }
};
int main()
{

    int i;
    int j;
    int noDataSet;
    int noWirehouse;
    int noLegs;
    int noShoppingReq;
    string vertexChar;
    Graph *graph;

    cin>>noDataSet;
    cout<<"SHIPPING ROUTES OUTPUT"<<endl;

    for(j = 1; j <= noDataSet; j++)
    {
       cout<<"\nDATA SET  "<<j;
       cout<<"\n\n";

       cin>>noWirehouse;
       cin>>noLegs;
       cin>>noShoppingReq;

       graph = new Graph();
       graph->nVertices = noWirehouse;

       for(i = 0; i < noWirehouse; i++)
       {
           cin>>vertexChar;
           graph->vertixToInt[vertexChar] = i;
       }
       while(noLegs--)
       {
           int src;
           int dest;
           std::map<string,int>::iterator vIntIterator;

           cin>>vertexChar;
           vIntIterator = graph->vertixToInt.find(vertexChar);
           src = vIntIterator->second;

           cin>>vertexChar;
           vIntIterator = graph->vertixToInt.find(vertexChar);
           dest = vIntIterator->second;

           graph->add_edge(src,dest);
           graph->add_edge(dest,src);
       }
       while(noShoppingReq--)
       {
           int costPerNode;
           int finalCost;
           string srcStr;
           string destStr;
           cin>>costPerNode;
           cin>>srcStr;
           cin>>destStr;
           finalCost = graph->BFS(srcStr,destStr) * costPerNode * 100;
           if(finalCost == 0)
                cout<<"NO SHIPMENT POSSIBLE"<<endl;
           else
                cout<<"$"<<finalCost<<endl;
       }
    delete graph;
    }

    cout<<"\nEND OF OUTPUT\n";

    return 0;
}

