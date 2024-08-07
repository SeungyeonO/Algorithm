#include <iostream>
#include <cmath>
using namespace std;


class point {
public:
	int x;
	int y;

	point() {}
	void setX() { cin >> x; }
	void setY() { cin >> y; }
	int squaredDistance(point otherPoint) {
		int result = pow(this->x - otherPoint.x, 2) + pow(this->y - otherPoint.y, 2);
		return result;
	}
};

class planetarySystem {
public:
	point center;
	int radius;

	planetarySystem() {}
	void setCenter() { center.setX(); center.setY(); }
	void setRadius() { cin >> radius; }

};

int main() {

	int tryNum;
	cin >> tryNum;

	int* arrPointer = new int[tryNum];

	for (int i = 0; i < tryNum; i++)
	{
		point departure, arrival;
		departure.setX(); departure.setY();
		arrival.setX(); arrival.setY();

		int systemNum, count = 0;
		cin >> systemNum;
		
		for (int j = 0; j < systemNum; j++)
		{
			planetarySystem system;
			system.setCenter(); system.setRadius();
			int dDistance = departure.squaredDistance(system.center);
			int aDistance = arrival.squaredDistance(system.center);
			int squaredDistance = pow(system.radius, 2);

			if (dDistance < squaredDistance && aDistance > squaredDistance)
				count++;
			else if (dDistance > squaredDistance && aDistance < squaredDistance)
				count++;
		}

		arrPointer[i] = count;
	}

	for (int i = 0; i < tryNum; i++)
	{
		cout << arrPointer[i] << endl;
	}

	delete[] arrPointer;

	return 0;
}
