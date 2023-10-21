#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;


void backtrack(string& currTopoSort, 
               vector<string>& allTopoSorts,
               map<char, unordered_set<char>> adjList,
               int indegrees[]){
    //
    // If we are at the end of a run
    // add this path to the possible sortings.
    if (currTopoSort.size() == adjList.size()){
        allTopoSorts.push_back(currTopoSort);
        return;
    }

    //
    // Backtrack from all other possible paths.
    for (const auto &pair : adjList ) {
        char curr = pair.first;
        //
        // If this element has indegrees, it cannot be removed
        if (indegrees[curr - 'A'] != 0) continue;
        
        //
        // If we've already went down this element in the path,
        // skip...
        if (currTopoSort.find(curr) != string::npos){
            continue;
        }
        
        //
        // Add this element to our current path.
        currTopoSort += curr;

        //
        // Remove this element as an indegree from its neighbors.
        unordered_set<char> neighbors = pair.second;
        for (auto& neighbor : neighbors){
            indegrees[neighbor - 'A']--;
        }

        //
        // Backtrack! 
        backtrack(currTopoSort, allTopoSorts, adjList, indegrees);

        //
        // Put the indegrees back since the element is put back.
        for (auto& neighbor : neighbors){
            indegrees[neighbor - 'A']++;
        }

        //
        // Take the element off of our path.
        currTopoSort.pop_back();
    }

}




int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //
    
    //
    // Get the case number.
    int n;
    cin >> n;
    string line;
    //
    // ignore \n
    getline(cin, line); 
    while (n--){
        //
        // ignore first line with \n
        getline(cin, line); 
        //
        // Names of the vertecies (A B C).
        getline(cin, line);
        string vertexNames = line;
        //
        // The edge list (A<B, and so on)
        getline(cin, line);
        string edges = line;

        //
        // Create an adj list.
        map<char, unordered_set<char>> adjList;

        //
        // Keep track of indegrees for Kahn's
        // using ascii representation of chars to index
        int indegrees[100] = { 0 };
        
        //
        // Iterate over each vertex, create a list for it.
        istringstream iss(vertexNames);
        string currElement;
        while (iss >> currElement){
            adjList[currElement[0]] = unordered_set<char>();
        }

        //
        // Populate the lists in the adjList
        iss.clear();
        iss.str(edges);
        while (iss >> currElement){
            char a = currElement[0];
            char b = currElement[2];
            adjList[a].insert(b); // could there be duplicates???
            indegrees[b - 'A']++; // could there be duplicates???
        }

        //
        // Create the answ array, and 
        // a curr element to backtrack onto.
        vector<string> allTopoSorts;
        string currTopoSort = "";

        //
        // Backtrack...
        backtrack(currTopoSort, allTopoSorts, adjList, indegrees);

        //
        // Alpha-sort the toposortings since the question
        // wants it ordered like that...
        sort(allTopoSorts.begin(),allTopoSorts.end());

        //
        // Print out all sortings.
        // If there was a cycle, don't print.
        if (allTopoSorts.size() == 0){
            cout << "NO" << "\n";
        }
        else {
            for (string curr : allTopoSorts){
                iss.clear();
                iss.str(curr);
                bool first = true;
                char currChar;
                while (iss >> currChar){
                    if (first){
                        first = false;
                        cout << currChar;
                    }
                    else {
                        cout << " " << currChar;
                    }
                }
                cout << "\n";
            }
        }
        
        //
        // If we are not at the last element, print new line.
        if (n) cout << "\n";
    }


    
    return 0;
}

