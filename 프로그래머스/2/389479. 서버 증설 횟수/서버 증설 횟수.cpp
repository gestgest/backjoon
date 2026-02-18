#include <string>
#include <vector>
#include <queue>

using namespace std;

class Server{
public:
    int time;
    int value;
    Server(int time, int value)
    {
        this->time = time;
        this->value = value;
    }
};

int solution(vector<int> players, int m, int k)
{
    int answer = 0;
    queue<Server> server; //예를 들어 시각이 11시에 했다면 16으로 설정하고 나중에 시간되면 반납
    
    int server_value = m;
    //예를 들어 m이 3인 경우 3 ~ 5명이면 서버 1대임.
    for(int i = 0; i < players.size(); i++)
    {
        //서버가 다 됐는지
        while(!server.empty())
        {
            Server ss = server.front();
            if(ss.time == i)
            {
                server_value -= ss.value;
                server.pop();
            }
            else
            {
                break;
            }
        }
        //증설해야함
        if(players[i] >= server_value)
        {
            int n = (players[i] - server_value + m) / m;
            answer += n;
            server_value += n * m;
            server.push(Server(i + k, n * m));
        }
    }
    
    return answer;
}