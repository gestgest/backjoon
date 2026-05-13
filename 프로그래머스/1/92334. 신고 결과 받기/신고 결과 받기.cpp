#include <string>
#include <vector>
#include <map>

using namespace std;

void div(string & a, string & b, string s)
{
    int i = 0;
    while(true)
    {
        //구분자
        if(s[i] == ' ')
        {
            i++;
            break;
        }
        a += s[i];
        i++;
    }
    for(; i < s.size(); i++)
    {
        b += s[i];
    }
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) 
{
    vector<int> answer = vector<int>(id_list.size(), 0);;
    
    map<string, int> my_map;
    
    //
    vector<vector<bool>> isCheck = vector<vector<bool>>(id_list.size());
    vector<int> count_list = vector<int>(id_list.size(), 0); //신고 받은 량
    
    //id_list를 string에 넣는다
    for(int i = 0; i < id_list.size(); i++)
    {
        isCheck[i] = vector<bool>(id_list.size(), false);
        my_map.insert(make_pair(id_list[i], i));
    }
    
    //bool로 체크?
    for(int i = 0; i < report.size(); i++)
    {
        string a, b;
        div(a, b, report[i]);
        if(!isCheck[my_map[a]][my_map[b]])
        {
            isCheck[my_map[a]][my_map[b]] = true;
            count_list[my_map[b]]++;
        }
    }
    
    
    //여기까지는 잘됨
    //k를 넘어선 애 비교
    //a => b
    for(int i = 0; i < id_list.size(); i++)
    {
        //b
        for(int j = 0; j < id_list.size(); j++)
        {
            if(k <= count_list[j] && isCheck[i][j])
            {
                answer[i]++;
            }
        }
    }
    
    //만약 bool 체크한 값에 그 애가 포함되면 sum[i]++;
    
    //마지막 출력
    
    return answer;
}