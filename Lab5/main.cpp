#include <iostream>
#include <limits>

using namespace std;

void PrintNum(const string& msg);

int main() {
    PrintNum("First Number:");
    PrintNum("Second Number:");
    return 0;
}


void PrintNum(const string& msg)
{
    int num;
    while (true)
    {
        //Writing input to Buffer
        cout << msg;
        cin >> num;

        //If User Entered Any Data type other than mentioned one will fail
        if(cin.fail())
        {
            cout << "Not Valid Input" << endl;
            //To Remove Fail state
            cin.clear();
            //Flush everthing at Buffer
            //Use Numeric Limit to determinate the max size of stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cout << "Value of "<< msg << num << endl;
            break;
        }
    }
}


