#include "the5.h"

// do not add extra libraries here
bool findInVector(const std::vector<int>& vec, int element) {
    for (int v : vec) {
        if (v == element) {
            return true;
        }
    }
    return false;
}

void dfs(int node, const std::vector<std::vector<int>>& dependencyMatrix, std::vector<int>& visited, std::vector<int>& stack, bool& isCyclic, std::vector<int>& localOrder);
void findCycles(int node, const std::vector<std::vector<int>>& dependencyMatrix, std::vector<int>& visited, std::vector<int>& recStack, std::vector<std::vector<int>>& cycles, std::vector<int>& path);

void run(const std::vector<std::vector<int>>& dependencyMatrix, 
     bool& isCompilable,
     std::vector<int>& compileOrder, 
     std::vector<std::vector<int>>& cyclicDependencies){

    int n = dependencyMatrix.size();
    std::vector<int> visited(n, 0), stack;
    isCompilable = true;

    // Detect cycles and get compilation order
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            std::vector<int> localOrder;
            dfs(i, dependencyMatrix, visited, stack, isCompilable, localOrder);
            compileOrder.insert(compileOrder.end(), localOrder.rbegin(), localOrder.rend());
        }
    }

    // If a cycle is detected, find all cyclic dependencies
    if (!isCompilable) {
        compileOrder.clear();
        visited.assign(n, 0);
        std::vector<int> recStack(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                std::vector<int> path;
                findCycles(i, dependencyMatrix, visited, recStack, cyclicDependencies, path);
            }
        }
    }
}

void dfs(int node, const std::vector<std::vector<int>>& dependencyMatrix, std::vector<int>& visited, std::vector<int>& stack, bool& isCyclic, std::vector<int>& localOrder) {
    visited[node] = 1;
    stack.push_back(node);
    for (int j = 0; j < dependencyMatrix[node].size(); ++j) {
        if (dependencyMatrix[node][j]) {
            if (!visited[j]) {
                dfs(j, dependencyMatrix, visited, stack, isCyclic, localOrder);
            } else if (findInVector(stack, j)) {
                isCyclic = false;
            }
        }
    }
    stack.pop_back();
    localOrder.push_back(node);
}

void findCycles(int node, const std::vector<std::vector<int>>& dependencyMatrix, std::vector<int>& visited, std::vector<int>& recStack, std::vector<std::vector<int>>& cycles, std::vector<int>& path) {
    visited[node] = 1;
    recStack[node] = 1;
    path.push_back(node);
    for (int j = 0; j < dependencyMatrix[node].size(); ++j) {
        if (dependencyMatrix[node][j]) {
            if (!visited[j]) {
                findCycles(j, dependencyMatrix, visited, recStack, cycles, path);
            } else if (recStack[j]) {
                // Check if j is in the current path to detect a cycle
                bool found = false;
                int startIndex = 0;
                for (int k = 0; k < path.size(); ++k) {
                    if (path[k] == j) {
                        found = true;
                        startIndex = k;
                        break;
                    }
                }

                if (found) {
                    // Cycle detected
                    std::vector<int> cycle;
                    cycle.assign(path.begin() + startIndex, path.end());
                    cycles.push_back(cycle);
                }
            }
        }
    }
    recStack[node] = 0;
    path.pop_back();
}