//Radix Sort Algorithm - Sort based on digits. Comparisonless sorting algorithm
//Author: Yuvaraja Subramaniam

#include <iostream>
#include <unistd.h>
#include <vector>
#include <algorithm>

using namespace std;

int display(int dt[], int sz) {
	for (int i=0; i <sz-1; i++) {
		cout << dt[i] << " -> ";
	}
	cout << dt[sz-1] << endl;
}



void radix_sort(int dt[], int size);



int main()
{
	cout << "        Radix Sort Algorithm (Sort Based On Values At Digit Positions)" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	
	int data[]     = {99, 5, 77, 5888, 50, 23, 3, 11};
	int data_size  = 8;
	
	cout << "Unsorted Array : " << endl;
	display(data, data_size);
	
	cout << "Sorting Array : " << endl;
	radix_sort(data, data_size);
	
	cout << "Sorted Array : " << endl;
	display(data, data_size);
}



//Radix sort 
//Best case 	- 
//Average case 	- 
//Worst case	- 
//Space complexity -

//
//


void radix_sort(int dt[], int size) {	

	int maxnum = dt[0];

	//find largest  number
	for (int i = 0; i < size; i++) {
		if (dt[i] > maxnum) {
			maxnum = dt[i];
		}
	}

	cout << "largest num = " << maxnum << endl; 
	
	//count the number of digits in the largest number
	int t = maxnum;
	int numdigits = 0;

	do {
		numdigits++;
		t = t / 10;
	} while ( t > 0);

	cout << "number of digits in largest number = " << numdigits << endl;
	vector< vector<int> > buckets = {
										{},
										{},
										{},
										{},
										{},
										{},
										{},
										{},
										{},
										{}
											};

	for(int i = 0, divisor = 1; i < numdigits; i++, divisor=divisor * 10) {

		cout << "digit = " << i + 1 << ", divisor = " << divisor << endl;
		//put the number as per the current digit bucket		
		for (int j = 0; j < size; j++) {
			//cout << "analysing number " << dt[j] << endl;
			int digitvalue = (dt[j] / divisor) % 10;
			//cout << "digitvalue = " << digitvalue << endl;
			buckets[digitvalue].push_back(dt[j]);
		}

		//pull the numbers out and reconstruct the array
		int n = 0;
		for (int k = 0; k <= 9; k++) {
			cout << "Bucket " << k << " : ";
			for( int m = 0; m < buckets[k].size(); m++) {
				dt[n] = buckets[k][m];
				cout << buckets[k][m] << " ";
				n++;
			}
			cout << endl;
			buckets[k].clear();
		}
	display(dt, size);
	}
}
