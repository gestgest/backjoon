#include <string>
#include <vector>

using namespace std;


//시전 시간, 초당 회복량, 추가 회복량  ()
int solution(vector<int> bandage, int max_health, vector<vector<int>> attacks) 
{
    int hp = max_health;
    int bandage_stack = 0;
    int count = 0;
    //최대 1000 => i가 시간, 
    for(int i = 1; i <= attacks[attacks.size() - 1][0]; i++)
    {
        //공격
        if(attacks[count][0] == i)
        {
            hp -= attacks[count][1];
            if(hp <= 0)
            {
                return -1;
            }
            bandage_stack = 0;
            count++;
        }
        //회복
        else if(hp < max_health)
        {
            bandage_stack++;
            hp += bandage[1];
            
            //추가 회복
            if(bandage_stack >= bandage[0])
            {
                hp += bandage[2];
                bandage_stack = 0;
            }
            if(hp >= max_health) //맥스
            {
                hp = max_health;
            }
        }
        else //hp가 full
        {
            bandage_stack = 0;
        }
    }
    if(hp <= 0)
    {
        return -1;
    }
    //2 : 20, 7 : 30, 8 : max
    return hp;
}