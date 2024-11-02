#include <iostream>
#include <fstream>
using namespace std;

void read_input(istream& is)
{
    string line;
    int count = 0;
    while (getline(is, line)) {
        count++;
        cout << "Line " << count << ": " << line << endl;
    }
}

int main()
{
    string filename;
    cin >> filename;

    ifstream infile;
    infile.open(filename.c_str());
    if (!infile) {
        cout << "Failed to open the file" << endl;
        return -1;
    }
    read_input(infile);
    infile.close();
    return 0;
}
