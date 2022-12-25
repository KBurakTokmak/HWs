#include "the7.h"

// Implement your solution after this line
using namespace std;

// IMPORTANT NOTES: Couldnt understand how to keep a different stack for path to printing or add them to a path vector
// so I made my own printing system
// I decided to return dijkstra function one time for distances so I can decide if I can make it or not
//Dijkstra returns another time this time with path parents
//parents prints
vector<int> dijkstra(int adj[500][500], int src,int size){//returns for minimum path so I can check decide which routes to take in time given
 
    vector<int> shortest_paths(size);
    vector<bool> found_list(size);
    for (int i = 0; i< size; i++) {
        shortest_paths[i] = INT_MAX;
        found_list[i] = false;
    }
    vector<int> parents(size);
    shortest_paths[src] = 0;
    parents[src] = -1;//source no need parent used as flag
 
    for (int i = 1; i < size; i++) {//find shortest path to all items no need to get 0 to 0 path no loops
        int neighbour = -1;
        int current_shortest = INT_MAX;
        for (int j = 0; j < size;j++) {
            if (!found_list[j]&& shortest_paths[j]< current_shortest) {// get the next element that is not calculated as neighbour
                neighbour = j;
                current_shortest= shortest_paths[j];
            }
        }
        found_list[neighbour] = true;
        
        for (int j = 0; j < size;j++) {
            int edge= adj[neighbour][j];
 
            if (edge > 0 && ((current_shortest + edge)< shortest_paths[j])) {//if shorter path exists
                parents[j] = neighbour;//add or change the element as a parent to current
                shortest_paths[j]= current_shortest + edge;//set as new short
            }
        }
    }
    return shortest_paths;
}

vector<int> dijkstra_path(int adj[500][500], int src,int size){// returns the path as parents so path can be printed copy paste from dijkstra function
 
    vector<int> shortest_paths(size);
    vector<bool> found_list(size);
    for (int i = 0; i< size; i++) {
        shortest_paths[i] = INT_MAX;
        found_list[i] = false;
    }
    vector<int> parents(size);
    shortest_paths[src] = 0;
    parents[src] = -1;
 
    for (int i = 1; i < size; i++) {
        int neighbour = -1;
        int current_shortest = INT_MAX;
        for (int j = 0; j < size;j++) {
            if (!found_list[j]&& shortest_paths[j]< current_shortest) {
                neighbour = j;
                current_shortest= shortest_paths[j];
            }
        }
        found_list[neighbour] = true;
        
        for (int j = 0; j < size;j++) {
            int edge= adj[neighbour][j];
 
            if (edge > 0 && ((current_shortest + edge)< shortest_paths[j])) {
                parents[j] = neighbour;
                shortest_paths[j]= current_shortest + edge;
            }
        }
    }
    return parents;
}

void get_stack(int src,vector<int> parents, stack<int>*parent_stack){
    if(parents[src]==-1){
        return;
    }
    else{
        parent_stack->push(src);
        get_stack(parents[src],parents,parent_stack);
    }
}

void pathtoend_print(int s,vector<int>parents,int d){
    if(parents[s]==-1){
        return;
    }
    else{
        pathtoend_print(parents[s],parents,d);
        if(s==d){
            cout<<s;
        }
        else{
            cout<<s<<"->";
        }
    }
}
void path_print(int s,vector<int>parents){
    if(parents[s]==-1){
        return;
    }
    else{
        path_print(parents[s],parents);
            cout<<s<<"->";
    }
}


void CanCatch(int n, std::vector<Road> roads, int s, int d, int x, int y, int l, int printPath) {
    // You can change these variables. These are here for demo only.
    std::vector<int> path;
    int adj[500][500];
    int size=n;
    bool printed=false;
    for(auto& i : roads){
       adj[i.buildings.first][i.buildings.second]=i.time;
       adj[i.buildings.second][i.buildings.first]=i.time;
    }
    
    
    
    std::vector<int> s_vector=dijkstra(adj,s,size);
    std::vector<int> x_vector=dijkstra(adj,x,size);
    std::vector<int> y_vector=dijkstra(adj,y,size);
    
    vector<int> s_parents=dijkstra_path(adj,s,size);
    vector<int> x_parents=dijkstra_path(adj,x,size);
    vector<int> y_parents=dijkstra_path(adj,y,size);


    /*
    std::cout<<"s_vector is: ";
    for(int i=0; i<s_vector.size();i++){
        std::cout<<s_vector[i]<<',';
    }
    std::cout<<std::endl;
    std::cout<<"x_vector is: ";
    for(int i=0; i<x_vector.size();i++){
        std::cout<<x_vector[i]<<',';
    }
    std::cout<<std::endl;
    
    
    std::cout<<"y_vector is: ";
    for(int i=0; i<y_vector.size();i++){
        std::cout<<y_vector[i]<<',';
    }
    std::cout<<std::endl;
    */
    if ((s_vector[y]+x_vector[d]+y_vector[x])<(s_vector[x]+x_vector[y]+y_vector[d])){
        if(s_vector[y]+x_vector[d]+y_vector[x]<=l){
           
            std::cout<<"YES"<<" "<<"BOTH"<<" "<<s_vector[y]+y_vector[x]+x_vector[d]<<"MINUTES"<<endl;
            if(printPath){
                cout<<s<<"->";
                path_print(y,s_parents);
                path_print(x,y_parents);
                pathtoend_print(d,x_parents,d);
            }
            printed=true;
        }
    }
    else{
        if(s_vector[x]+x_vector[y]+y_vector[d]<=l){
            std::cout<<"YES"<<" "<<"BOTH"<<" "<<s_vector[x]+x_vector[y]+y_vector[d]<<"MINUTES"<<endl;
            if(printPath){
                cout<<s<<"->";
                path_print(x,s_parents);
                path_print(y,x_parents);
                pathtoend_print(d,y_parents,d);
            }
            printed=true;
        }
    }
    
    if(!printed){
        if(s_vector[x]+x_vector[d]<=s_vector[y]+y_vector[d]){
            if(s_vector[x]+x_vector[d]<=l){
                std::cout<<"YES"<<" "<<"PRINTER"<<" "<<s_vector[x]+x_vector[d]<<"MINUTES"<<endl;
                if(printPath){
                    cout<<s<<"->";
                    path_print(x,s_parents);
                    pathtoend_print(d,x_parents,d);
                }
                printed=true;
            }
        }
        else{
             if(s_vector[y]+y_vector[d]<=l){
                std::cout<<"YES"<<" "<<"DORM"<<" "<<s_vector[y]+y_vector[d]<<"MINUTES"<<endl;
                if(printPath){
                    cout<<s<<"->";
                    path_print(y,s_parents);
                    pathtoend_print(d,y_parents,d);
                }
                printed=true;
            }
        }
    }
    
    if(!printed){
        if(s_vector[d]<=l){
            std::cout<<"YES"<<" "<<"DIRECTLY"<<" "<<s_vector[d]<<"MINUTES"<<endl;
            if(printPath){
                cout<<s<<"->";
                pathtoend_print(d,s_parents,d);
            }
            printed=true;
        }
        else{
            std::cout<<"IMPOSSIBLE";
            printed=true;
        }
    }
        
    
    /*for(int i=0;i<size;i++){
        
        for(int j=0;j<size;j++){
            std::cout<<adj[i][j]<<',';
        }
        std::cout<<std::endl;
    }*/
    
    



    
    // You can use the PrintRange function to print the path.
    // It helps you print elements of containers with iterators (e.g., std::vector).
    // Usage: PrintRange(path.begin(), path.end());
    
}