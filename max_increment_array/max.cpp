#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define N 100000

int a[N];

void genRandom (int a[], int n) {
	int r = 0;
	srand (time(NULL));
	for (int i = 0; i < n; i++) {
		r = rand() %100;
		if (r > 70) a[i] = -r;    // 30% là số âm  
		else a[i] = r;            // 70% là số dương  
	}
}

int max (int x, int y) {
	if (x > y) 
		return x;
	else return y;
}

int maxSub1 (int a[], int n) {
	int maxsum = INT32_MIN;  //âm vô cùng
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			sum = 0;
			for (int k = i; k <= j; k++) {
				sum = sum + a[k];
			}
			maxsum = max (sum, maxsum);          
		}   
	}
	return maxsum;
}




int maxleft (int a[], int i, int j) {
	int maxsum = INT32_MIN;
	int sum = 0;
	for (int k = j; k >= i; k--) {
		sum = sum + a[k];
		maxsum = max(sum, maxsum);
	}
	return maxsum;
}

int maxright (int a[], int i, int j) {
	int maxsum = INT32_MIN;
	int sum = 0;
	for (int k = i; k <= j; k++) {
		sum = sum + a[k];
		maxsum = max(sum, maxsum);
	}
	return maxsum;
}

int maxsub(int a[], int i, int j) {
	if (i == j) 
		return a[i];
	
	int m = (i + j) / 2;
	int wL = maxsub(a, i, m);
	int wR = maxsub(a, m + 1, j);
	int wM = maxleft(a, i, m) + maxright(a, m + 1, j);
	return max (max(wL, wR), wM);
}

int maxsub3 (int a[], int n) {
	return maxsub (a, 0, N-1);
}

int main(int argc, char const* argv[]) {
	genRandom(a, N);
	cout << maxsub3(a, N) << endl;
	return 0;
}