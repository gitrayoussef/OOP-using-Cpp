#include <iostream>
#include "utils/sort.h"
using namespace std;



int main() {
    int isSorted = 0;
    int numbers[] = {2 , 1, 8 , 5 , 4};
    isSorted=sorting::BubbleSort(numbers , size(numbers));
    for(int number:numbers)
    {
        cout << number << endl;
    }
    cout << "Sorted Value = " << isSorted << endl;
    return 0;
}



