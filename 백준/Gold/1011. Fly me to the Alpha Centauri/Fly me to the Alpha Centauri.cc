#include <iostream>
#include <cmath>

using namespace std;

int main() {
	cin.tie(0);
	int temp;
	cin >> temp;

	long long x, y;

	for (int i = 0; i < temp; i++) {
		cin >> x >> y;
        // 두 x, y의 거리
		double distance = y - x; 
        
        // 거리의 제곱근
		double distance_pow = sqrt(distance); 
        
        // 거리의 제곱근을 반올림
		int pow = round(sqrt(distance)); 

		if (distance_pow <= pow) cout << pow * 2 - 1 << "\n";
		else cout << pow * 2 << "\n";
	}

	return 0;
}