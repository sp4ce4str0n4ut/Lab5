#include <CustomIter.h>
#include <mergesort.h>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main() {
	
    int ind = 2;
	
	vector<int> myvec;
    CustomIter<int> iterator(cout, " ", ind);
	
    

    cout << "myvector: ";
    for(int i = 10; i >= 0; i--) {
        cout << i << " ";
        myvec.push_back(i);
    }

    cout << endl << "myvector through iterator with N = " << ind << ":" << endl;

	
	
    auto pointer = myvec.begin();

    while(pointer != myvec.end()) {
        *iterator = *pointer;
        iterator++;
        pointer++;
    }


    mergesort(myvec.begin(), myvec.end());
    cout << endl << "myvector after sorting:" << endl;
    for(int x: myvec)
        cout << x << " ";
    return 0;
}
