#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//bfs

//93 => 8번 => 9 + 3 => 11 흐음
//100과 90? 어차피 

//44
//100과 40 50

//1404
//ㄴ 2000과 1400 1500

//3421
//당연히 10000과 그냥 그대로 시작.
//그대로 시작하면 바로 421과 그거의 역 음수 => 근데 어차피 음수여도 버튼도 음양수라 절대값으로 변환

class Stone{
public:
    int count = 0;
    int value = 0;
    Stone() {}
    Stone(int count, int value)
    {
        this->count = count;
        this->value = value;
    }
    bool operator <(const Stone & stone) const &
    {
        if(this->count > stone.count)
            return true;
        else
            return false;
    }
};

//3543을 넣으면 3000을 반환
int getNumber(int value, int & j)
{
    int i;
    for(i = 1; i < value; i *= 10) { }
    i/= 10;
    if(i == 0)
        return 0;
    j = value / i; //앞자리
    return j * i;
    //return i;
}

//3543을 넣으면 10000을 반환
int getOverNumber(int value)
{
    int i;
    for(i = 1; i < value; i *= 10) { }
    return i;
}


//1404, 2000
int bfs(int dst)
{
    //queue는 count와 value
    priority_queue<Stone> stone_queue;
    Stone a(0, dst);
    stone_queue.push(a); 
    
    while( !(stone_queue.empty()) )
    {
        Stone stone = stone_queue.top();
        stone_queue.pop();
        
        //만약 도달했다면
        if(stone.value == 0)
        {
            return stone.count;
        }
        int value = stone.value;
        int j;
        
        //하나는 딱뎀 9800 => 800
        value = stone.value - getNumber(stone.value, j);
        //cout << "value : "<< value << ", j : " << j << '\n';
        stone_queue.push(Stone(stone.count + j, value));
        
        //하나는 거기서 오버슛 => 200
        value = getOverNumber(stone.value) - stone.value;
        stone_queue.push(Stone(stone.count + 1, value));
    }
}

int solution(int storey) 
{
    //최소의 마법의 돌
    int answer = 0;
    answer = bfs(storey);
    return answer;
}