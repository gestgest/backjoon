#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Item
{
    int count = 0;
    int money = 0;
};

//살짝 시간 복잡도 위험한데
Item bf(vector<vector<int>> &users, vector<int> & emoticons, vector<double> & sales, int index)
{
    Item item;
    
    //다 되면 한번 계산
    if(index == sales.size())
    {
        //유저
        for(int i = 0; i < users.size(); i++) //1000
        {
            double sum = 0; //이모티콘 합
            
            //이모티콘 구매비용
            for(int j = 0; j < sales.size(); j++) 
            {
                //cout << j << " : " << sales[j] << '\n';
                
                //비율 비교, 세일값이 더 커야함
                if(sales[j] < users[i][0])
                {
                    continue;
                }
                sum += (100 - sales[j]) * emoticons[j] / 100;
            }
            //cout << "sum : "<<  sum << '\n';
            
            //이모티콘 플러스 삼
            if(users[i][1] <= sum)
            {
                item.count++;
            }
            else //자체를 구매함.
            {
                item.money += sum;
            }
            //아예 안 사는 경우 
        }
        //cout << "item : "<< item.count << ", " << item.money <<'\n';
        
        return item;
    }
    //세팅
    for(int i = 1; i <= 4; i++)
    {
        sales[index] = i * 10;
        Item tmp = bf(users, emoticons, sales, index + 1);
        
        if(item.count < tmp.count)
        {
            item.count = tmp.count;
            item.money = tmp.money;
        }
        else if(item.count == tmp.count)
        {
            if(item.money < tmp.money)
            {
                item.money = tmp.money;
            }
        }
    }
    return item;
}


//n m
vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    //가입자수를 최대한 늘려야함. 이후 이모티콘 판매액
    //이모티콘 플러스 서비스 가입자 수, 이모티콘 판매액
    vector<int> answer;
    
    //비율 : 비율보다 할인하는 이모티콘은 무조건 구매해
    //일단 이모티콘 비용이 커야함. 근데 퍼센트가 딸리면 못삼.
    
    //10^5 => 이모티콘
    vector<double> sales = vector<double>(emoticons.size(), 0);
    
    //todo
    Item item = bf(users, emoticons, sales, 0);
    answer.push_back(item.count);
    answer.push_back(item.money);
    return answer;
}