#include <iostream>
#include <fstream>

using namespace std;
struct Movie
{
    int id{};
    string title;
    int year{};
};

int main() {

   //Write to file
    ofstream file;
    file.open("movies.txt");
    if(file.is_open())
    {
        //Don't <endl> each line instead use <\n>
        //Because each <endl> will flush the buffer each time
        //CSV
        file << "id,name,year\n"
             << "1,Barbie,2023\n"
             << "2,Run Rabbit Run,2022\n";
        file.close();
    }

    //Read from file
    ifstream file2;
    file2.open("movies.txt");
    if(file2.is_open())
    {
        string str;
        getline(file2,str);
        while(!file2.eof())
        {
            getline(file2,str,',');
            if(str.empty()) continue;

            Movie movie;
            movie.id=stoi(str);

            getline(file2,str,',');
            movie.title=str;

            getline(file2,str);
            movie.year=stoi(str);

            cout << movie.title << endl;
        }

        file2.close();
    }
    return 0;
}
