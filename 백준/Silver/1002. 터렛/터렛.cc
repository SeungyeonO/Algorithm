#include <iostream>
#include <cmath>
using namespace std;

class circle {
private:
	int centerX;
	int centerY;
	int radius;

public:
	circle() {}
	void setX() { cin >> centerX; }
	void setY() { cin >> centerY; }
	void setRadius() { cin >> radius; }
	int getX() { return centerX; }
	int getY() { return centerY; }
	int getRadius() { return radius; }
	int distanceBetweenCenter(circle _circle) { return pow(centerX - _circle.getX(), 2) + pow(centerY - _circle.getY(), 2); }
};

int main() {
	int tryNum;
	cin >> tryNum;

	for (int i = 0; i < tryNum; i++)
	{
		//조규현 백승환 위치와 류재명과의 거리 받기
		circle officer1, officer2;
		officer1.setX(); officer1.setY(); officer1.setRadius();
		officer2.setX(); officer2.setY(); officer2.setRadius();

		int distance = officer1.distanceBetweenCenter(officer2);
		int officer1Radius = officer1.getRadius();
		int officer2Radius = officer2.getRadius();
		int differnceRaidus = pow(officer1Radius - officer2Radius, 2);

		//조규현 백승환의 위치가 같을 때 
		if (distance == 0)
		{
			if (officer1Radius == officer2Radius)
				cout << -1 << endl;
			else
				cout << 0 << endl;
		}

		//한 사람의 반경(원)이 다른 사람의 반경(원)에 속해있을 때
		else if (distance == differnceRaidus)
			cout << 1 << endl;

		//한 사람의 반경(원)이 다른 사람의 반경(원)에 안에 있지만 경계가 겹칠 때
		else if (distance < differnceRaidus)
			cout << 0 << endl;

		else
		{
			int totalRadius = officer1Radius + officer2Radius;
			if (distance == totalRadius * totalRadius)
				cout << 1 << endl;

			else if (distance > totalRadius * totalRadius)
				cout << 0 << endl;

			else
				cout << 2 << endl;

		}

	}
}
