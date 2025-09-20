#include <iostream>
#include <cmath>

using namespace std;

#define INF 2147483647
#define PRIM_SIZE 12


//a
//double?
long long s[19];
double a[19];
double ap[19];
double b[19];
double bp[19];

//nC2
long long pac(int n, int c)
{
	long long result = 1;
	if (n / 2 < c)
	{
		c = n - c;
	}
	for (int i = n; i > n - c; i--)
	{
		result *= i;
	}
	for (int i = 2; i <= c; i++)
	{
		result /= i;
	}
	return result;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.setf(ios::fixed);
	cout.precision(16);

	long long tmp = 1;
	int prim[PRIM_SIZE] = { 0, 1,4,6,8,9,10,12,14,15,16,18 };
	for (int i = 1; i <= 18; i++)
	{
		tmp *= i;
		s[i] = tmp;
	}
	
	double double_a, double_ap, double_b, double_bp;
	double suma = 0;
	double sumb = 0;

	cin >> double_a >> double_b;
	double_ap = 100 - double_a;
	double_bp = 100 - double_b;

	double_a /= 100;
	double_ap /= 100;
	double_b /= 100;
	double_bp /= 100;

	a[0] = 1;
	for (int i = 1; i <= 18; i++)
	{
		a[i] = a[i - 1] * double_a;
	}
	ap[0] = 1;
	for (int i = 1; i <= 18; i++)
	{
		ap[i] = ap[i - 1]* double_ap;
	}

	b[0] = 1;
	for (int i = 1; i <= 18; i++)
	{
		b[i] = b[i - 1] * double_b;
	}

	bp[0] = 1;
	for (int i = 1; i <= 18; i++)
	{
		bp[i] = bp[i - 1] * double_bp;
	}

	//교집합
	//18c2
	for (int ii = 0; ii < PRIM_SIZE; ii++)
	{
		int i = prim[ii];
		long long pp = pac(18, i);
		suma +=  a[i] *ap[18 - i] * pp;
		sumb += b[i] * bp[18 - i] * pp;
	}
	double sum = 1;
	cout <<  sum - suma * sumb << '\n';

}