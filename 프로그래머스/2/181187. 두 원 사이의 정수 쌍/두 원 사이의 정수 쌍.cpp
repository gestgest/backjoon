#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long R1 = r1, R2 = r2;

    for (long long x = 1; x <= R2; x++) {
        // 큰 원: y <= sqrt(R2^2 - x^2)  => floor
        long long yMax = (long long)sqrt((double)(R2*R2 - x*x));
        while (yMax*yMax + x*x > R2*R2) yMax--;       // 오차 보정
        while ((yMax+1)*(yMax+1) + x*x <= R2*R2) yMax++;

        long long yMin;
        if (x > R1) {
            yMin = 0; // 작은 원 범위 밖이면 y=0부터
        } else {
            // 작은 원: y >= sqrt(R1^2 - x^2) => ceil
            yMin = (long long)ceil(sqrt((double)(R1*R1 - x*x)));
            while (yMin*yMin + x*x < R1*R1) yMin++;     // 오차 보정
            while (yMin > 0 && (yMin-1)*(yMin-1) + x*x >= R1*R1) yMin--;
        }

        answer += (yMax - yMin + 1); // x>=0인 한 사분면(축 포함)
    }

    return answer * 4; // 4개 사분면 대칭
}