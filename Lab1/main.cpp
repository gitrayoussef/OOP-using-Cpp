#include <iostream>
#include "utils/search.h"

using namespace std;

int main() {
    int target;
    int numbers[] = {1,5,8,4,2,13};
    cout << "Enter Number to search: ";
    cin >>  target;
    int result = searching::findNumber(numbers, size(numbers) , target);

    cout << result << endl;

    return 0;
}

