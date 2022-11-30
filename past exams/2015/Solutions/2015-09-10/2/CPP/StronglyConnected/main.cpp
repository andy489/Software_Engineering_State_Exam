/**
 * Kosaraju's DFS based algorithm that does two DFS traversals of graph:
 * 1    Initialize all vertices as not visited.
 * 2    Do a DFS traversal of graph starting from any arbitrary vertex v.
 *      If DFS traversal doesn't visit all vertices, then return false.
 * 3    Reverse all arcs (or find transpose or reverse of graph).
 * 4    Mark all vertices as not-visited in reversed graph.
 * 5    Do a DFS traversal of reversed graph starting from same vertex v (Same as step 2).
 *      If DFS traversal doesn't visit all vertices, then return false. Otherwise return true.
 *
 *      The idea is, if every node can be reached from a vertex v, and every node can reach v,
 *      then the graph is strongly connected. In step 2, we check if all vertices are reachable from v.
 *      In step 5, we check if all vertices can reach v (In reversed graph, if all vertices are reachable
 *      from v, then all vertices can reach v in original graph).
 */

#include <iostream>

using namespace std;

class AdjList {
    static const int MXN = 1e3 + 3;
    int *adj;
    int currIndex;

public:

    AdjList() {
        adj = new int[MXN];
        currIndex = 1;
    }

    ~AdjList() {
        delete[] adj;
    }

    int getSize() const {
        return currIndex;
    }

    void add(int u) {
        adj[currIndex++] = u;
    }

    int get(int index) {
        return adj[index];
    }
};

class DirectedGraph {
    static const int MXN = 1e3 + 3;
    int additions;

    AdjList *adjacencyList;
    bool *visited;
    bool *isNode;

public:
    DirectedGraph() {
        adjacencyList = new AdjList[MXN]();
        visited = new bool[MXN]();
        isNode = new bool[MXN]();
        additions = 0;
    }

    void add(int from, int to) {
        adjacencyList[from].add(to);
        isNode[from] = true;
        isNode[to] = true;
        additions++;
    }

    void transpose() {
        AdjList *reversedAdjacencyList = new AdjList[MXN]();

        for (int i = 1; i < MXN; ++i) {
            AdjList currList = adjacencyList[i];
            const int SIZE = currList.getSize();

            for (int j = 1; j < SIZE; j++) {
                reversedAdjacencyList[currList.get(j)].add(i);
            }
        }

        adjacencyList = reversedAdjacencyList;
    }

    void dfs(int u) {
        if (visited[u]) {
            return;
        }

        visited[u] = true;

        const int SIZE = adjacencyList[u].getSize();

        for (int i = 1; i < SIZE; i++) {
            dfs(adjacencyList[u].get(i));
        }
    }

    bool checkAllVisited() {
        for (int i = 1; i < MXN; ++i) { if (isNode[i] && !visited[i]) { return false; }}
        return true;
    }

    void reset() {
        for (int i = 0; i < MXN; i++) {
            visited[i] = false;
        }
    }

    bool isStronglyConnected() {
        if (!additions) { return true; }

        dfs(1);

        if (!checkAllVisited()) { return false; }

        reset();
        transpose();
        dfs(1);

        if (!checkAllVisited()) { return false; }

        transpose();
        reset();

        return true;
    }
};


int main() {
    DirectedGraph *dg = new DirectedGraph();

    dg->add(1, 2);
    dg->add(2, 3);
    dg->add(3, 4);
    dg->add(4, 1);
    dg->add(3, 5);
    dg->add(5, 3);
//    dg->add(4, 6);
    dg->add(6, 4);

    dg->dfs(1);

    cout << "The graph is " << (dg->isStronglyConnected() ? "" : "NOT") << " strongly connected" << endl;
    return 0;
}
