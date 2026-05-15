#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Point{
public:
    int x;
    int y = 3;
    
    int isSmaller(Point &a, Point & b)
    {
        int a_dis = abs(this->x - a.x) + abs(this->y - a.y);
        int b_dis = abs(this->x - b.x) + abs(this->y - b.y);
        
        
        if(a_dis < b_dis)
        {
            return -1;
        }
        if(a_dis == b_dis)
        {
            return 0;
        }
        return 1;
    }
    
    void setPoint(Point & point)
    {
        this->x = point.x;
        this->y = point.y;
    }
};

//left 1, 4, 7 [0,1,2]
void setLeftPoint(Point & point, int number)
{
    point.x = 0;
    point.y = number / 3; //0, 1, 2
}

//irhgt 3, 6, 9 [0,1,2]
bool setMiddlePoint(Point & a, Point & b, int number, bool isRight)
{
    Point point;
    point.x = 1;
    
    if(number == 0)
    {
        point.y = 3;
    }
    else
    {
        point.y = number / 3; //0, 1, 2
    }
    
    int p = point.isSmaller(a,b);
    
    if(p == 0)
    {
        if(!isRight)
        {
            a.setPoint(point);
            return false;
        }
        else
        {
            b.setPoint(point);
            
            return true;
        }
    }
    else if(p == -1)
    {
        a.setPoint(point);
        
        return false;
    }
    else
    {
        b.setPoint(point);
        return true;
    }
}

//irhgt 3, 6, 9 [0,1,2]
void setRightPoint(Point & point, int number)
{
    point.x = 2;
    point.y = (number - 1) / 3; //0, 1, 2
}

string solution(vector<int> numbers, string hand) 
{
    string answer = "";
    bool isRight = true;
    Point hands[2]; //left, right
    
    //초기 위치 설정
    hands[0].x = 0; 
    hands[1].x = 2;
    
    if(hand == "left")
    {
        isRight = false;
    }
    
    for(int i = 0; i < numbers.size(); i++)
    {
        //middle
        if(numbers[i] % 3 == 2 || numbers[i] == 0)
        {
            //false면 left, true면 right
            if(setMiddlePoint(hands[0], hands[1], numbers[i], isRight))
            {
                answer += 'R';
            }
            else
            {
                answer += 'L';
            }
        }
        else if(numbers[i] % 3 == 1) //left
        {
            setLeftPoint(hands[0], numbers[i]);
            answer += 'L';
        }
        else //right
        {
            setRightPoint(hands[1], numbers[i]);
            answer += 'R';
        }
    }
    
    return answer;
}