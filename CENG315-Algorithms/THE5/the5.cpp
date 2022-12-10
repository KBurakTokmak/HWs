#include "the5.h"
/* 
    in the5.h "struct Room" is defined as below:
    
    struct Room {
        int id;
        char content;
        vector<Room*> neighbors;
    };

*/


vector<int> maze_trace(vector<Room*> maze) { 

    vector<int> path;
    bool visited[10000]={false};
    stack<int> DFS;
    bool treasure_found=false;
    Room *current_room=maze[0];
    //std::cout<<"room id is: "<< current_room->id<<std::endl;
    DFS.push(current_room->id);
    
    while(!DFS.empty()){
        int t=DFS.top();
    
        for (auto& i : maze){//find the room that has the stack id
            if (i->id==t){
                current_room=i;
            }
        }

        
        if(visited[current_room->id]==false){
            visited[current_room->id]=true;//first time visiting mark it
            path.push_back(current_room->id);//on the path
            //std::cout<<"pushed "<<current_room->id<<" to stack"<<std::endl;
        }
        else{
            path.push_back(current_room->id);//on the path when backtracking
        }
        
        if(current_room->content=='*'){//treasure found
            DFS.pop();//latest room already got pushed to path just pop it
            treasure_found=true;
            while(!DFS.empty()){//pop all the stack while adding to backtrack
                path.push_back(DFS.top());
                DFS.pop();
            }
        }
        
        bool all_neig_visited=true;
        bool pushed=false;
        for (auto& i : current_room->neighbors) {//traverse the neigbours vector
            if(!pushed && !treasure_found){
                if(!visited[i->id]){//if its not a visited room push it to stack set flags so that we dont push any other room before exploring this one
                     DFS.push(i->id);
                     all_neig_visited=false;
                     pushed=true;
                }
            }
            else{
                break;//if a neighbor found and pushed go explore that neigbor first, if treasure is found stack already emptied
            }
        }
        
        
        if(all_neig_visited&&!treasure_found){
            DFS.pop();//only pop if there is no more neighbors to explore, not popping helps us write this node on backtrack
        }
        
    }
    

    return path; 
}


