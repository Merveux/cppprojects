
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream backup("backup.txt");
    string line;

    ofstream file("student.txt");

    if(backup.is_open() && file.is_open()) {

        while(getline(backup,line)) {
            file << line << endl;
        } 

        cout << "File restored successfully!" << endl;

    }
    else {
        cout << "Backup file not found!" << endl;
    }

    backup.close();
    file.close();

    return 0;
}
