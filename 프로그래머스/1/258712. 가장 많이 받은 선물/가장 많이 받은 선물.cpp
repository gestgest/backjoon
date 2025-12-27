#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int solution(vector<string> friends_str, vector<string> gifts) 
{
    int answer = 0;
    map<string, int> friends_index; 
    int gift_mat[50][50] = {0};
    int gift_const_array[50] = {0};
    int gift_array[50] = {0};
    
    queue<char> string_queue;
    
    for(int i = 0; i < friends_str.size(); i++)
    {
        friends_index.insert(make_pair(friends_str[i], i));
    }
    
    for(int i = 0; i < gifts.size(); i++)
    {
        string send_name = "";
        string get_name = "";
        for(int j = 0; j < gifts[i].size(); j++)
        {
            //띄어쓰기
            if(gifts[i][j] == ' ')
            {
                //큐 넣기
                while(!string_queue.empty())
                {
                    char c = string_queue.front();
                    send_name += c;
                    string_queue.pop();
                }
                
                continue;
            }
            string_queue.push(gifts[i][j]);
        }
        //큐 넣기
        while(!string_queue.empty())
        {
            char c = string_queue.front();
            get_name += c;
            string_queue.pop();
        }
        
        int get_index = friends_index[get_name];
        int send_index = friends_index[send_name];
        
        gift_mat[send_index][get_index]++;
        gift_const_array[send_index]++;
        gift_const_array[get_index]--;
    }
    
    for(int i = 0; i < friends_str.size(); i++)
    {
        for(int j = i + 1; j <friends_str.size(); j++)
        {
            //왼쪽이 더 크다면 => i가 ++
            if(gift_mat[j][i] < gift_mat[i][j])
            {
                gift_array[i]++;
            }
            else if(gift_mat[j][i] > gift_mat[i][j])
            {
                gift_array[j]++;
            }
            else
            {
                if(gift_const_array[i] > gift_const_array[j])
                {
                    gift_array[i]++;
                }
                if(gift_const_array[i] < gift_const_array[j])
                {
                    gift_array[j]++;
                }
            }
        }
    }
    for(int i = 0; i < friends_str.size(); i++)
    {
        if(answer < gift_array[i])
        {
            answer = gift_array[i];
        }
    }
    //친구c2 / 2만큼  경우의 수
    //ryan x2  muzi neox2 frodo 
    //왼쪽이 값이 많으면 오른쪽
    //이후 선물지수 비교
    
    return answer;
}