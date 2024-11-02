#include <iostream>
#include <fstream>
using namespace std;

void from_input_to_output(istream& is, ostream& os)
{
    string line;
    int count = 0;
    while (getline(is, line)) {
        count++;
        os << "Line " << count << ": " << line << endl;
    }
}


int main()
{
    string infilename, outfilename;
    cout << "Enter the input file: ";
    cin >> infilename;
    cout << "Enter the output file: ";
    cin >> outfilename;

    ifstream infile;
    infile.open(infilename.c_str());
    if (!infile) {
        cout << "Failed to open the input file" << endl;
        return -1;
    }

    ofstream outfile;
    outfile.open(outfilename.c_str());
    if (!outfile) {
        cout << "Failed to open the output file" << endl;
        return -1;
    }

    from_input_to_output(infile, outfile);
    infile.close();
    outfile.close();
    return 0;
}
