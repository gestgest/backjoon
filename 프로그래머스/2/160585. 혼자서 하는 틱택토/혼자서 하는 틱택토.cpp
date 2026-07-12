#include <string>
#include <vector>
#include <iostream>

using namespace std;

int tic(vector<string> &board, char c)
{
    int result = 0;
    vector<int> rows = vector<int>(board.size(), 0); //i
    vector<int> cols = vector<int>(board[0].size(), 0); //j
    vector<int> dia = vector<int>(2, 0);
    
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[i].size(); j++)
        {
            if(board[i][j] == c)
            {
                rows[i]++;
                cols[j]++;
                if(i == j)
                {
                    dia[0]++;
                }
                //0 1 2    (2,0)
                if(board.size() - 1 - i == j)
                {
                    dia[1]++;
                }
            }
        }
    }
    for(int i = 0; i < rows.size(); i++)
    {
        if(rows[i] == cols.size())
        {
            result++;
        }
    }
    for(int i = 0; i < cols.size(); i++)
    {
        if(cols[i] == rows.size())
        {
            result++;
        }
    }
    for(int i = 0; i < dia.size(); i++) //대각선
    {
        if(dia[i] == rows.size())
        {
            result++;
        }
    }
    return result;
}

int solution(vector<string> board) 
{
    int answer = 1; //가능하면 1, 가능하지 않다면 0
    int sumA = 0;
    int sumB = 0;
    
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[i].size(); j++)
        {
            if(board[i][j] == 'O')
            {
                sumA++;
            }
            else if(board[i][j] == 'X')
            {
                sumB++;
            }
        }
    }
    if(sumA != sumB && sumA != sumB + 1)
    {
        return 0;
    }
    int a = tic(board, 'O');
    int b = tic(board, 'X');
    cout << a << ' ' << b << '\n';
    //무려 두 명이 틱택토 완성했다면? 0
    if(a >= 1 && b >= 1)
    {
        return 0;
    }
    
    //한 명이 완성했는데 갯수가 같다면?
    // O O .
    // O O .
    // X X X
    if(b >= 1 && sumA != sumB)
    {
        return 0;
    }
    //O O O
    //X X . 
    //X . .
    if(a >= 1 && sumA == sumB)
    {
        return 0;
    }
    
    return answer;
}