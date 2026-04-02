#include <string>
#include <vector>

using namespace std;
#define MAX_SIZE 1000000

class Edge{
public:
    int src_count = 0; //받는 쪽
    int dst_count = 0; //주는 쪽
};
vector<Edge> graph;

//graph 사이즈가 되려나
vector<int> solution(vector<vector<int>> edges)
{
    vector<int> answer;
    answer = vector<int>(4, 0);
    
    graph = vector<Edge>(MAX_SIZE);
    
    //아니면 역으로 자신을 참조 안하는 노드가 정점중 에서
    //외부에 많이 나가는게 정점을 찾아보자
    
    
    for(int i = 0; i < edges.size(); i++)
    {
        //출발 증가
        graph[edges[i][0] - 1].dst_count++; //주는 쪽
        graph[edges[i][1] - 1].src_count++; //받는 쪽
    }
    
    
    //8자 : 정점의 보내는 놈 - 막대 - 도넛 => 즉 나머지 도형
    for(int i = 0; i < MAX_SIZE; i++)
    {
        //정점 : 참조 보내기만 하는 애가 여럿, 참조 받기는 0
        if(graph[i].src_count == 0 && graph[i].dst_count >= 2)
        {
            answer[0] = i;
        }
        //막대 : 참조 받기만 하는 애가 하나 이상 (꼭대기 기준으로 하자)
        else if(graph[i].src_count >= 1 && graph[i].dst_count == 0)
        {
            answer[2]++;
        }
        //도넛 : 여럿 여럿
        else if(graph[i].src_count >= 2 && graph[i].dst_count >= 2)
        {
            answer[3]++;
        }
        //나머지는 어딘가에 소속된 노드들
        
    }
    answer[1] = graph[answer[0]].dst_count - answer[2] - answer[3];
    answer[0]++;
    return answer;
}