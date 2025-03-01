Problem:
In this exam, you are given a maze consisting of various rooms connected to each other via a direct door. In one of those rooms, there is a secret treasure and your purpose is to find that treasure. You do not know in which room the treasure is placed. Therefore starting from the entrance, you search for the treasure walking through room-by-room. During the search, you print the path that you follow until you reach the treasure.

     maze

Here are the details of the problem structure:
The maze is actually a connected undirected graph. Each room is a node of the graph. If a room is connected to an other room, there is an edge between those two rooms. 
Each room is defined in the type of Struct Room. This structure has 3 components:
int id: Each room has a unique id.
char content: Shows the content of the room. All rooms have the content of '-' character except the room containing the treasure. That room has the content of '*' character representing the treasure.
vector<Room*> neighbors: Holds a pointer for the rooms which are connected to the current room via a door.
If a Room Y is defined as a neighbor to Room X, then you can be sure that Room X is also defined as a neighbor to Room Y in its neighborhood vector.
The rooms of the maze will be given to the function as in the type of vector<Room*>. 
You are expected to return the path as vector of ids of rooms which are visited.
Here are the details of how to search/traverse the maze:
You will actually do a kind of DFS. You will start from the first room (first means the firstly defined room, not the room with the first id) to traverse. You will pass to one of its neighbor rooms, and then to one of the neighbors of it, and to one of the neighbors of it, and so on. As you pass through a new room each time, you will add the id of that room to the output path. Upto here, it is exactly DFS.
 When you come to an end, that is a room with no unvisited neighbor, then you should turn back. While going back, you should also add the ids of the rooms  that you need to visit one more time into the output path. For instance, assume that Room 5 is neighbor to Room 12 and assume that you come to Room 5 at some point and have not visited Room 12, yet. Also assume Room 12 is not neighbor to any other nonvisited room. Then, in your output path a pattern like the following have to exist: 5, 12, 5 . That means "you pass through Room 5, then Room 12, then you turn back to Room 5 again since there is not left any nonvisited room neighbor to Room 12. In short, in addition to usual DFS output, you are expected to print the nodes at each time you visit.
When you find the treasure (The Room whose content is '*'), you should turn back totally. That is, you need to go back over the route that you follow. You should not go into any new room. During the going back, you again add the ids of the rooms that you visit.
For the neighbor selection, you need to follow the order in which the rooms are defined as a neighbor for that Room. For instance, if the neighbors of Room 5  are ordered as <Room 12, Room 7, Room 9> inside the neighbor vector, then you should select Room 12 first. After completing Room 12, you should continue from Room 7 and next from Room 9. Assume that Room 7 was visited before. Then you should follow Room 9 after completing the Room 12 and its neighbors. In other words, you should skip Room 7.
There will always be exactly one room including the treasure.
Example IO:
Please pay attention to the ordering of the neighbors for each node. It affects the resulting path!

EXAMPLE-1
dfs_example1
EXAMPLE-2
dfs_example2
EXAMPLE-3
dfs_example3
EXAMPLE-4
dfs_example4

Constraints:
Maximum number of nodes in a maze graph will be 10000. 
Evaluation:
After your exam, black box evaluation will be carried out. You will get full points if your function returns the correct result without exceeding time limit.
Specifications:
There are only 1 task to be solved in 12 hours in this take home exam.
You will implement your solutions in the5.cpp file.
Do not change the first line of the5.cpp, which is #include "the5.h"
<iostream>,  <climits>, <vector>, <string>, <stack>, <queue>  are included in "the5.h" for your convenience.
Do not change the arguments and return types of the function maze_trace(). (You should change return value, on the other hand.)
Do not include any other library or write include anywhere in your the5.cpp file (not even in comments)
Compilation:
You are given test.cpp file to test your work on ODTÜClass or your locale. You can and you are encouraged to modify this file to add different test cases.
If you want to test your work and see your outputs you can compile and run your work on your locale as:
>g++ test.cpp the5.cpp -Wall -std=c++11 -o test

> ./test


You can test your the5.cpp on virtual lab environment. If you click run, your function will be compiled and executed with test.cpp. If you click evaluate, you will get a feedback for your current work and your work will be temporarily graded for limited number of inputs.
The grade you see in lab is not your final grade, your code will be re-evaluated with completely different inputs after the exam.
The system has the following limits:

a maximum execution time of 32 seconds
a 192 MB maximum memory limit
an execution file size of 1M.
Solutions with longer running times will not be graded.
If you are sure that your solution works in the expected complexity constrains but your evaluation fails due to limits in the lab environment, the constant factors may be the problem.

vector<int> maze_trace(vector<Room*> maze);