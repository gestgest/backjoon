#include <string>
#include <vector>

using namespace std;

class Point{
public:  
    int x;
    int y;
    Point(){}
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void setPoint(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    Point operator + (Point & point)
    {
        Point result;
        result.x = this->x + point.x;
        result.y = this->y + point.y;
        return result;
    }
};

string getBoard(vector<vector<string>> & b, Point & p)
{
    string s = "";
    if(p.x < 0 || p.y < 0)
    {
        return s;
    }
    if(p.x >= b[0].size() || p.y >= b.size())
    {
        return s;
    }
    return b[p.y][p.x];
}

int solution(vector<vector<string>> board, int h, int w) 
{
    int answer = 0;
    Point myPoint(w,h);
    Point points[4];
    points[0].setPoint(0,1);
    points[1].setPoint(0,-1);
    points[2].setPoint(1,0);
    points[3].setPoint(-1,0);
    
    for(int i = 0; i < 4; i++)
    {
        Point p = myPoint + points[i];
        //string s1 = "";
        //string s2 = "";
        string s1 = getBoard(board, myPoint);
        string s2 = getBoard(board, p);
        if(s1 == s2)
        {
            answer++;
        }
    }
    
    return answer;
}