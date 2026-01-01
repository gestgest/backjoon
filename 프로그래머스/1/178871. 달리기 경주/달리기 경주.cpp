#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) 
{
    map <string, int> runners;
    
    //init
    for(int i = 0; i < players.size(); i++)
    {
        runners.insert(make_pair(players[i], i));
    }
    
    //swap
    for(int i = 0; i < callings.size(); i++)
    {
        int index = runners[callings[i]];
        
        //map도 스왑
        runners[callings[i]] = index - 1;
        runners[players[index - 1]] = index;
        
        //players[index]의 앞사람과 스왑
        swap(players[index], players[index - 1]);
    }
    
    //그리고 players
    
    return players;
}