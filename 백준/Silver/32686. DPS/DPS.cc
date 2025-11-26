
#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.setf(ios::fixed); //정수도 소수점 아래 처리
	cout.precision(12);


	int n, start, end;
	int wait_time, deal_time;
	long long damage;
	long double sum_damage = 0;

	cin >> n >> start >> end;

	for (int i = 0; i < n; i++)
	{
		cin >> wait_time >> deal_time >> damage;

		int delay_time = wait_time + deal_time;

		//전체 딜량 - (0 ~ start까지의 딜량)
		// 딜량은 무난한 딜량 + 나머지 딜량

		//전체 딜량의 무난한 딜량
		int end_other_time = end % delay_time;
		long double entire_damage = damage * (end - end_other_time);
		entire_damage = entire_damage  / delay_time;
		//cout << entire_damage << '\n';
		sum_damage += entire_damage;


		//전체 딜량의 나머지 딜량 => end_other_time가 0이하면 0, 이상이면
		long double end_other_damage = damage * max(end_other_time - wait_time, 0);
		end_other_damage /= deal_time;
		//cout << end_other_damage << '\n';
		sum_damage += end_other_damage;

		//start 딜량의 무난한 딜량
		int start_other_time = start % delay_time;
		long double start_damage = damage * (start - start_other_time);
		start_damage /= delay_time;
		sum_damage -= start_damage;

		//start 딜량의 나머지 딜량 => end_other_time가 0이하면 0, 이상이면
		long double start_other_damage = damage * max(start_other_time - wait_time, 0);
		start_other_damage /= deal_time;
		sum_damage -= start_other_damage;

		//cout << sum_damage  << '\n';
	}
	cout << sum_damage / (end - start) << '\n';
}

