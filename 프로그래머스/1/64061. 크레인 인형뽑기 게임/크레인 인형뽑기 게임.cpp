#include <string>
#include <vector>
#include <stack>

using namespace std;


int select_doll(vector<vector<int>> &board, int x)
{
    for(int i = 0; i < board.size(); i++)
    {
        if(board[i][x] != 0)
        {
            int tmp = board[i][x];
            board[i][x] = 0;
            return tmp;
        }
    }
    return 0;
}

bool push_doll_stack(stack<int> & doll_stack, int doll)
{
    //doll이 위에 값이랑 같은 경우
    if(!doll_stack.empty() && doll_stack.top() == doll)
    {
        doll_stack.pop();
        return true;
    }
    doll_stack.push(doll);
    
    return false;
    //boom
}

//moves는 1부터 시작된다. board는 y x
int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    stack<int> doll_stack;
    
    //바구니는 stack
    for(int i = 0; i < moves.size(); i++)
    {
        //board[y][moves[i] - 1]; => 이게 x임
        int doll = select_doll(board, moves[i] - 1);
        
        //인형을 뽑았다면
        if(doll != 0)
        {
            //터진다면
            if(push_doll_stack(doll_stack, doll))
            {
                answer += 2;
            }
        }
    }
    
    return answer;
}