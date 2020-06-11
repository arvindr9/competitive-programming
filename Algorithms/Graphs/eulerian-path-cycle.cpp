// taken from https://cp-algorithms.com/graph/euler_path.html

/*
Recursive procedure:

procedure FindEulerPath(V)
  1. iterate through all the edges outgoing from vertex V;
       remove this edge from the graph,
       and call FindEulerPath from the second end of this edge;
  2. add vertex V to the answer.
  
Non-recursive procedure (below):

stack St;
put start vertex in St;
until St is empty
  let V be the value at the top of St;
  if degree(V) = 0, then
    add V to the answer;
    remove V from the top of St;
  otherwise
    find any edge coming out of V;
    remove it from the graph;
    put the second end of this edge in St;
*/

/*
Domino problem: There are N dominoes, as it is known, on both ends of the Domino one number
is written(usually from 1 to 6, but in our case it is not important). You want to put all
the dominoes in a row so that the numbers on any two adjacent dominoes, written on their
common side, coincide. Dominoes are allowed to turn.
*/


/*

Algo description:

The program below searches for and outputs a Eulerian loop or path in a graph, or outputs −1 if it does not exist.

First, the program checks the degree of vertices: if there are no vertices with an odd degree,
then the graph has an Euler cycle, if there are 2 vertices with an odd degree, then in the graph
there is only an Euler path (but no Euler cycle), if there are more than 2 such vertices, then
in the graph there is no Euler cycle or Euler path. To find the Euler path (not a cycle),
let's do this: if V1 and V2 are two vertices of odd degree,then just add an edge (V1,V2), in
the resulting graph we find the Euler cycle (it will obviously exist), and then remove the "fictitious"
edge (V1,V2) from the answer. We will look for the Euler cycle exactly as described above (non-recursive version),
and at the same time at the end of this algorithm we will check whether the graph was connected or not
(if the graph was not connected, then at the end of the algorithm some edges will remain in the graph,
and in this case we need to print −1). Finally, the program takes into account that there can be isolated
vertices in the graph.

Notice that we use an adjacency matrix in this problem. Also this implementation handles finding the next
with brute-force, which requires to iterate over the complete row in the matrix over and over. A better
way would be to store the graph as an adjacency list, and remove edges in O(1) and mark the reversed edges
in separate list. This way we can archive a O(N) algorithm.
*/

int main() {
    int n;
    vector<vector<int>> g(n, vector<int>(n));
    // reading the graph in the adjacency matrix

    vector<int> deg(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            deg[i] += g[i][j];
    }

    int first = 0;
    while (!deg[first])
        ++first;

    int v1 = -1, v2 = -1;
    bool bad = false;
    for (int i = 0; i < n; ++i) {
        if (deg[i] & 1) {
            if (v1 == -1)
                v1 = i;
            else if (v2 == -1)
                v2 = i;
            else
                bad = true;
        }
    }

    if (v1 != -1)
        ++g[v1][v2], ++g[v2][v1];

    stack<int> st;
    st.push(first);
    vector<int> res;
    while (!st.empty()) {
        int v = st.top();
        int i;
        for (i = 0; i < n; ++i)
            if (g[v][i])
                break;
        if (i == n) {
            res.push_back(v);
            st.pop();
        } else {
            --g[v][i];
            --g[i][v];
            st.push(i);
        }
    }

    if (v1 != -1) {
        for (size_t i = 0; i + 1 < res.size(); ++i) {
            if ((res[i] == v1 && res[i + 1] == v2) ||
                (res[i] == v2 && res[i + 1] == v1)) {
                vector<int> res2;
                for (size_t j = i + 1; j < res.size(); ++j)
                    res2.push_back(res[j]);
                for (size_t j = 1; j <= i; ++j)
                    res2.push_back(res[j]);
                res = res2;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j])
                bad = true;
        }
    }

    if (bad) {
        cout << -1;
    } else {
        for (int x : res)
            cout << x << " ";
    }
}
