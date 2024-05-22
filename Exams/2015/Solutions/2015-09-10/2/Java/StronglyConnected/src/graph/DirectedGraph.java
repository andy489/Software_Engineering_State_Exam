/*
 * Kosaraju's DFS based algorithm that does two DFS traversals of graph:
 * 1    Initialize all vertices as not visited.
 * 2    Do a DFS traversal of graph starting from any arbitrary vertex v.
 *      If DFS traversal doesn't visit all vertices, then return false.
 * 3    Reverse all arcs (or find transpose or reverse of graph).
 * 4    Mark all vertices as not-visited in reversed graph.
 * 5    Do a DFS traversal of reversed graph starting from same vertex v (Same as step 2).

 *      If DFS traversal doesn't visit all vertices, then return false. Otherwise return true.
 *      The idea is, if every node can be reached from a vertex v, and every node can reach v,
 *      then the graph is strongly connected. In step 2, we check if all vertices are reachable from v.
 *      In step 5, we check if all vertices can reach v (In reversed graph, if all vertices are reachable
 *      from v, then all vertices can reach v in original graph).
 */

package graph;

class AdjList {
    private static final int MXN = (int) 1e3 + 3;

    private final int[] adj;
    private int currIndex;

    public AdjList() {
        adj = new int[MXN];
        currIndex = 1;
    }

    public int getSize() {
        return currIndex;
    }

    public void add(int u) {
        adj[currIndex++] = u;
    }

    public int get(int index) {
        return adj[index];
    }
}

public class DirectedGraph {
    private static final Integer MXN = 10;
    private static int additions = 0;

    private AdjList[] adjacencyList;
    private final boolean[] visited;
    private final boolean[] isNode;

    public DirectedGraph() {
        adjacencyList = new AdjList[MXN];
        init(adjacencyList);
        visited = new boolean[MXN];
        isNode = new boolean[MXN];
    }

    public void add(int from, int to) {
        adjacencyList[from].add(to);
        isNode[from] = true;
        isNode[to] = true;
        additions++;
    }

    public boolean isStronglyConnected() {
        if (additions == 0) {
            return true;
        }

        dfs(1);
        if (!checkAllVisited()) {
            return false;
        }

        reset();
        transpose();
        dfs(1);

        if (!checkAllVisited()) {
            return false;
        }

        transpose();
        reset();

        return true;
    }

    private void reset() {
        for (int i = 0; i < MXN; i++) {
            visited[i] = false;
        }
    }

    private void transpose() {
        AdjList[] reversedAdjacencyList = new AdjList[MXN];
        init(reversedAdjacencyList);

        for (int i = 1; i < MXN; ++i) {
            AdjList currList = adjacencyList[i];
            final int SIZE = currList.getSize();

            for (int j = 1; j < SIZE; j++) {
                reversedAdjacencyList[currList.get(j)].add(i);
            }
        }

        adjacencyList = reversedAdjacencyList;
    }

    private boolean checkAllVisited() {
        for (int i = 1; i < MXN; i++) {
            if (isNode[i] && !visited[i]) {
                return false;
            }
        }

        return true;
    }

    private void dfs(int u) {
        if (visited[u]) {
            return;
        }

        visited[u] = true;

        final int SIZE = adjacencyList[u].getSize();
        for (int i = 1; i < SIZE; i++) {
            dfs(adjacencyList[u].get(i));
        }
    }

    private void init(AdjList[] list) {
        for (int i = 1; i < MXN; i++) {
            list[i] = new AdjList();
        }
    }

    public static void main(String... args) {
        DirectedGraph dg = new DirectedGraph();

        dg.add(1, 2);
        dg.add(2, 3);
        dg.add(3, 4);
        dg.add(4, 1);
        dg.add(3, 5);
        dg.add(5, 3);
        // dg.add(4, 6);
        dg.add(6, 4);

        System.out.printf("The graph is %s strongly connected%n", dg.isStronglyConnected() ? "" : "NOT");
    }
}
