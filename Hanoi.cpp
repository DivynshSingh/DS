#include <bits/stdc++.h> 
using namespace std; 

void hanoi(int n, char pick, char place, char rod3) 
{ 
	if (n == 0) { 
		return; 
	} 
	hanoi(n - 1, pick, rod3, place); 
	cout << "Move disk " << n << " from rod " << pick 
		<< " to rod " << place << endl; 
	hanoi(n - 1, rod3, place, pick); 
} 

int main() 
{ 
	int N = 3; 
	hanoi(N, 'A', 'C', 'B'); 
	return 0; 
}