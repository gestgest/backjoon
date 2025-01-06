#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define PI 3.14159265358979f

using namespace std;

class Circle {
public:
	double x;
	double y;
	double r;
	Circle()
	{
	}
	Circle(double x, double y, double r)
	{
		this->x = x;
		this->y = y;
		this->r = r;
	}
	void setCircle(double x, double y, double r)
	{
		this->x = x;
		this->y = y;
		this->r = r;
	}
};

//원이 안 겹치는지 => 0
//원이 한 개만 겹치는지 => r1 + r2 == (x1 - x2)^2 + (y1 - y2)^2 => 1
//원이 두 겹 겹치는지 => 2 또는 원 범주안에 있는지
int isOverlabCircle(Circle c1, Circle c2, double dis)
{
	double r = c1.r + c2.r;

	if (dis > r) {
		return 0;
	}
	//원 범주
	if (c1.r + dis <= c2.r)
	{
		return 1;
	}
	return 2;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout.setf(ios::fixed); //정수도 소수점 아래 처리
	cout.precision(3); //cout의 소수점 범위를 10자리까지 늘린다. 4은 3.1415

	double x, y, r;
	Circle circle[2];

	for (int i = 0; i < 2; i++)
	{
		cin >> x >> y >> r;

		circle[i].setCircle(x, y, r);
	}

	if (circle[0].r > circle[1].r) {
		Circle tmp = circle[0];
		circle[0] = circle[1];
		circle[1] = tmp;
	}

	double dis = sqrt((circle[0].x - circle[1].x) * (circle[0].x - circle[1].x) + (circle[0].y - circle[1].y) * (circle[0].y - circle[1].y));
	int isOverlab = isOverlabCircle(circle[0], circle[1], dis);

	if (isOverlab == 0) {
		//아예 안 만나는 경우
		cout << 0.000 << '\n';
		return 0;
	}
	//원이 겹치는 경우
	if (isOverlab == 1)
	{
		cout << circle[0].r * circle[0].r * PI<< '\n';
		return 0;
	}

	//각도를 구하고
	// dis, r1, r2
	// dis^2 + r1^2 - r2^2 / 2 * dis * r1=> r2를 바라보는 각도 (작은 원의 각도), 0은 circle0의 각도
	double angle0 = acos((dis * dis + circle[0].r * circle[0].r - circle[1].r * circle[1].r) / (2 * dis * circle[0].r));
	double angle1 = acos((dis * dis + circle[1].r * circle[1].r - circle[0].r * circle[0].r) / (2 * dis * circle[1].r));

	//double theta1 = acos((circle[0].r * circle[0].r + dis * dis - circle[1].r * circle[1].r) / (2 * circle[0].r * dis));
	//double theta2 = acos((circle[1].r * circle[1].r + dis * dis - circle[0].r * circle[0].r) / (2 * circle[1].r * dis));

	//cout << angle0 << ' ' << angle1 << '\n';
	//cout << theta1 << ' ' << theta2 << '\n';

	//angle0 *= 2;
	//angle1 *= 2;
	//파이 = 180
	
	//dis * angle0
	double triangle_area0 = circle[0].r * circle[0].r * sin(angle0 * 2) * 0.5;
	double triangle_area1 = circle[1].r * circle[1].r * sin(angle1 * 2) * 0.5;

	double circle_area0 = circle[0].r * circle[0].r * angle0;
	double circle_area1 = circle[1].r * circle[1].r * angle1; //애초에 360도 원의 넓이는 r^2파이*각도. 그렇다면 180도는 "1/2r^2파이" 식이 도출되어야 한다
	
	cout << circle_area1 - triangle_area1 + circle_area0 - triangle_area0 << '\n';
}
