
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream file("student.txt");
    string line;

    // Automatically create the backup file
    ofstream backup("backup.txt");

    if(file.is_open() && backup.is_open()) {

        while(getline(file,line)) {
            backup << line << endl;
        }

        file.close();
        backup.close();

        // Clear the original file
        ofstream clearFile("student.txt");
        clearFile.close();

        cout << "Backup created automatically!" << endl;
        cout << "File contents cleared!" << endl;

    }
    else {
        cout << "Error opening files!" << endl;
    }

    return 0;
}
