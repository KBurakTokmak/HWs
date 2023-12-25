#include "the6.h"

// do not add extra libraries here

//smallest key value that is not  in  minimum spanning tree
int minKey(const std::vector<int>& key, const std::vector<bool>& min_span_tree) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < key.size(); v++)
        if (!min_span_tree[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

// part1 prim's algorithm 
int find_structure(std::vector< std::vector<std::pair<int, int> > >& bond_energies, std::vector< std::vector<std::pair<int, int> > >& lowest_energy_structure) {
    int n = bond_energies.size();
    std::vector<int> parent(n);
    std::vector<int> key(n, INT_MAX);
    std::vector<bool> min_span_tree(n, false);
    //empty initial
    key[0] = 0;
    parent[0] = 0;

    for (int count = 0; count < n-1; count++) {
        int min_index = minKey(key, min_span_tree);
        min_span_tree[min_index] = true;

        for (auto x : bond_energies[min_index]) {
            int v = x.first;
            int weight = x.second;
            if (!min_span_tree[v] && weight < key[v]) {
                parent[v] = min_index, key[v] = weight;
            }
        }
    }

    int lowest_total_energy = 0;
    lowest_energy_structure = std::vector<std::vector<std::pair<int, int>>>(n);
    for (int i = 1; i < n; i++) {//add edges 
        lowest_energy_structure[i].push_back({parent[i], key[i]});
        lowest_energy_structure[parent[i]].push_back({i, key[i]});
        lowest_total_energy += key[i];
    }

    return lowest_total_energy;
}

// part2
//dfs
void dfs(const std::vector< std::vector<std::pair<int, int> > >& graph, int v, std::vector<bool>& visited, std::vector<int>& parent, int& max_distance, int dist, int& farthest_node) {
    visited[v] = true;
    if (dist > max_distance) {
        max_distance = dist;
        farthest_node = v;
    }
    //recur for all adjacent vertices
    for (auto x : graph[v]) {
        if (!visited[x.first]) {
            parent[x.first] = v;  
            dfs(graph, x.first, visited, parent, max_distance, dist + 1, farthest_node);
        }
    }
}


int find_longest_chain(std::vector< std::vector<std::pair<int, int> > >& molecule_structure, std::vector<int>& chain) {
    int n = molecule_structure.size();
    std::vector<bool> visited(n, false);
    std::vector<int> parent(n, -1);
    int farthest_node = 0, max_distance = 0;

    //find farthest from node 0
    dfs(molecule_structure, 0, visited, parent, max_distance, 0, farthest_node);

    
    //reset visited and parent and max_distance
    visited = std::vector<bool>(n, false);
    parent = std::vector<int>(n, -1);
    max_distance = 0;

    //longest chain from farthest
    dfs(molecule_structure, farthest_node, visited, parent, max_distance, 0, farthest_node);

    //backtack from farthest
    int current = farthest_node;
    while (current != -1) {
        chain.push_back(current);
        current = parent[current];
    }


    return chain.size();
}