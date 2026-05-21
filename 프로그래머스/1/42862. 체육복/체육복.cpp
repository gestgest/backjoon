#include <string>
#include <vector>

using namespace std;

int getStudentSize(vector<bool> & students)
{
    int sum = 0;

    for(int i = 0; i < students.size(); i++)
    {
        if(students[i])
        {
            sum++;
        }
    }
    return sum;
}

int bf(vector<bool> students, vector<int> & reserve, int reserve_index, bool isLeft)
{
    //꽉차면
    if(reserve_index == reserve.size())
    {
        return getStudentSize(students);
    }
    
    if(isLeft) //좌측
    {
        if(reserve[reserve_index] <= 0)
        {
            return getStudentSize(students);
        }
        students[reserve[reserve_index] - 1] = true;
    }
    else //우측
    {
        //우측
        if(students.size() - 1 <= reserve[reserve_index])
        {
            return getStudentSize(students);
        }
        students[reserve[reserve_index] + 1] = true;
    }
    
    reserve_index++;
    
    return max(bf(students, reserve, reserve_index, true),
        bf(students, reserve, reserve_index, false));
    //오른쪽
}

int solution(int n, vector<int> lost, vector<int> old_reserve) 
{
    int answer = 0;
    vector<bool> students = vector<bool>(n, true);
    vector<int> new_reserve;
    
    for(int i = 0; i < lost.size(); i++)
    {
        students[lost[i] - 1] = false;
    }
    
    //reserve와 lost가 만약 겹치면 
    for(int i = 0; i < old_reserve.size(); i++)
    {
        //잃어버린 학생이 여분의 옷을 가짐
        if(!students[old_reserve[i] - 1])
        {
            students[old_reserve[i] - 1] = true;
        }
        else
        {
            new_reserve.push_back(old_reserve[i] - 1);
        }
    }
    //return getStudentSize(students);
    //1 2 3 => 2 1 0에서 1번이 2번 빌려주고 2번이 3번 빌려주는 케이스는 안되는 거 같다.
    
    return max(bf(students, new_reserve, 0, true), bf(students, new_reserve, 0, false));
}