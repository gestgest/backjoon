#include <iostream>
int main() 
{
    int resp;
    for (int a = 1; a <= 9; a++) 
    {
        // A가 a인지 물어보고 flush를 한다.
        // endl은 자동으로 flush도 해준다.
        std::cout << "? A " << a << std::endl;

        // 채점기의 답변을 입력받는다.
        std::cin >> resp;

        if (resp == 1) 
        {
            int b;
            // 답변이 "예"이므로 A의 값은 a이다.
            for (b = 1; b <= 9; b++)
            {
                std::cout << "? B " << b << std::endl;
                std::cin >> resp;
                if (resp == 1) 
                {
                    std::cout << "! " << a + b;
                    // B의 값은 b이다.
                    break;
				}
            }

            break;
        }
    }
}