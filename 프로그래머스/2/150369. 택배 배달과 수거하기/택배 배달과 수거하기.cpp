#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void debugArray(vector<int> & array)
{
    for(int i = 0; i < array.size(); i++)
    {
        cout << array[i] << ' ';
    }
    cout << '\n';
}

//true면 다 찼다는 뜻
bool minusValue(vector<int> & array, int index, int cap, int & sum)
{
    //만약 더했는데 꽉 차는 경우 => array[index]의 용량이 큰 경우
    if(cap <= sum + array[index])
    {
        array[index] -= cap - sum;
        return true;
    }
    //여기는 오히려 cap 이 너무 큰 경우. array[i]가 1인 경우 다음에도 더 채웟 
    sum += array[index];
    array[index] = 0;
    //debugArray(array);
    
    return false;
}


//사실 queue가 필요할까?
//이러면 시간초과를 유의해야하는데 => 바구니 한개 꽉찬 픽업과 딜리버리
//start == deliveries.size() - 1
int getIndex(vector<int> & array, int start, int cap)
{
    int index = -1;
    int sum = 0;
    
    if(start == -1)
        return index;
    
    //cout << start << '\n';
    for(int i = start; i >= 0; i--)
    {
        if(array[i] > 0)
        {
            //처음 시작. 
            if(sum == 0)
                index = i; //처음 지정
            
            //만약 더했는데 꽉 차는 경우 => 완료
            if(minusValue(array, i, cap, sum))
            {
                return index;
            }
        }
        //값이 없는 경우
    }
    return index; //-1반환이면 다 돈거.
}



long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) 
{
    long long answer = 0;
    
    int delivery_index = n - 1;
    int pickup_index = n - 1;
    
    
    while(true)
    {
        delivery_index = getIndex(deliveries, delivery_index, cap);
        pickup_index = getIndex(pickups, pickup_index, cap);
        
//         cout << i + 1<< ") \nDelivery : ";
//         debugArray(deliveries);
//         cout << "Pickup : ";
//         debugArray(pickups);
            
        //cout << delivery_index << ' ' << pickup_index << '\n';
        //도달함
        if(delivery_index == -1 && pickup_index == -1)
        {
            break;
        }
        answer += (max(delivery_index, pickup_index) + 1) * 2; //거리 값이라 + 1를 해야함.
    }
    
    return answer;
}

//1) (4, 3) => 4
//1 0 2 0 0
//0 3 0 0 0

//2) 여기서부터 잘못되었구만