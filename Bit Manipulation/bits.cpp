#include<bits/stdc++.h>
using namespace std;


//********************************************BASICS****************************************************

int getbit(int n, int k) {					//to get the kth bit in the number n
	return ((n & (1 << k)) != 0);
}

int setbit(int n, int k) {					//to make kth bit equal to 1
	return (n | (1 << k));
}

int clearbit(int n, int k) {				//to make kth bit equal to 0
	return (n & ~(1 << k));
}

int updatebit(int n, int k, int val) {							//update bit of a given position(given that we have to make that bit 0 or 1)
	/*	update = clearbit + setbit
		Steps:
		1. clear the bit at position k
		2. set the bit at position k according to value
	*/
	n = n & (~(1 << k));
	return (n | (val << k));
}

//*********************************************MEDIUM****************************************************

bool isPowerOfTwo(int n) {				//Brute force: keep on dividing by 2, if we get 1 in the end then it is power of 2
	if (n == 0)
		return 0;
	return ((n & (n - 1)) == 0);
	//OR       return (n & !(n & n-1));
}

int numberOfOnes(int n) {				//to count the number of ones in the number (Logic: all the bits from rightmost 1 are flipped by applying the operation n & (n-1) )
	int count = 0;
	while (n != 0) {
		n = n & (n - 1);
		count++;
	}
	return count;
}

void subsets(int arr[], int n) {				// to find all the subsets of the given array
	for (int i = 0; i < (1 << n); i++) {
		cout << "{";
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				cout << arr[j] << " ";
			}
		}
		cout << "}, ";
	}
	cout << endl;
}
//******************************************HARD**********************************************************

int unique(int arr[], int n) {						//to find a unique number in the array when all others are present two times each
	int ans = arr[0];
	for (int i = 1; i < n; i++)
		ans = ans ^ arr[i];
	return ans;
}

void unique2(int arr[], int n) {						//to find two unique elements in the array when all others are present two times each
	int xorsum = 0;
	for (int i = 0; i < n; i++)
		xorsum = xorsum ^ arr[i];
	int sbit = 0, tempxor = xorsum, pos = 0;
	while (sbit != 1) {			//to find rightmost set bit
		sbit = xorsum & 1;
		pos++;
		xorsum = xorsum >> 1;
	}
	int newxor = 0;
	for (int i = 0; i < n; i++) {		//to find xor of all elements with bit at pos=1
		if (getbit(arr[i], pos - 1) == 1)
			newxor = newxor ^ arr[i];
	}
	cout << newxor << " and " << (tempxor ^ newxor) << endl;	//gives both the numbers
}

int unique3(int arr[], int n) {						//to find a unique number in array when all others are present 3 times each
	int res = 0;
	for (int i = 0; i < 64; i++) {		//to check for all 64 bits in the numbers
		int sum = 0;
		for (int j = 0; j < n; j++) {	//to check every no's ith bit
			if (getbit(arr[j], i)) {
				sum++;
			}
		}
		if (sum % 3 != 0) {				//if number of 1 bits at ith position is not a multiple of 3, then it belongs to unique no
			res = setbit(res, i);
		}
	}
	return res;
}


int main() {
	cout << getbit(16, 2) << endl;
	cout << setbit(16, 2) << endl;
	cout << clearbit(17, 4) << endl;
	cout << updatebit(17, 4, 0) << endl;
	cout << updatebit(17, 4, 1) << endl;
	cout << isPowerOfTwo(32) << endl;
	cout << numberOfOnes(19) << endl;
	int arr[] = {1, 2, 3};
	subsets(arr, sizeof(arr) / sizeof(int));

	int un[] = {1, 2, 3, 5, 3, 1, 2};
	cout << unique(un, sizeof(un) / sizeof(int)) << endl;

	int un2[] = {1, 2, 3, 4, 5, 3, 2, 1};
	unique2(un2, sizeof(un2) / sizeof(int));

	int un3[] = {1, 2, 3, 1, 2, 3, 4, 5, 4, 4, 1, 2, 3};
	cout << unique3(un3, sizeof(un3) / sizeof(int)) << endl;

	return 0;
}







