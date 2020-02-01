/* Self Replicating Program
 * Program's only purpose is to print out itself
 * Written by Nischal Shankar
 */

// Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Creates a duplicate file of the given file name
void printMyself(string file_name) {
    // Open given file_name
    ifstream original_file(file_name);
    if (!original_file.is_open()) {
        cerr << "ERROR: Unable to open " << file_name << endl;
        exit(1);
    }
    // Create duplicate file
    ofstream duplicate_file("duplicate_" + file_name);
    if (!duplicate_file.is_open()) {
        cerr << "ERROR: Unable to open " << file_name << endl;
        exit(1);
    }

    bool more_lines = true;
    unsigned int num_lines = 0;
    vector<string> lines(50, "");
    string line = "";
    // Read in 50 lines at a time from original and add them to duplicate file
    while (more_lines) {
        num_lines = 0;
        // Retrieve 50 lines from original
        while (num_lines < 50 && getline(original_file, line)) {
            lines[num_lines] = line;
            ++num_lines;
        }
        // Output lines collected to duplicate
        for (unsigned int i = 0; i < num_lines; ++i) {
            duplicate_file << lines[i] << endl;
        }
        // Entire file has been read
        if (num_lines < 50) {
            more_lines = false;
        }
    }
    original_file.close();
    duplicate_file.close();
}

int main() {
    string fname = "";
    cout << "Welcome to Duplicate File Generator" << endl << 
            "Enter the file name that should be duplicated: ";
    cin >> fname;
    cout << "Starting duplication" << endl;
    printMyself(fname);
    cout << "Successfuly duplicated file" << endl <<
            fname << " -> duplicate_" << fname << endl;
}
