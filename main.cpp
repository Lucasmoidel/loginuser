#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    string inpusername;
    hash<string> hasher;
    string inppass;
    
    if (argc == 2) {
        if (!strcmp(argv[1],"login")) {
            string filetext;
            cout << "Username: ";
            cin >> inpusername;
            cout << "Password: ";
            cin >> inppass;
            size_t hashpass = hasher(inppass);
            ifstream fpass("passdb.txt");
            while (getline (fpass, filetext)) {
                if (filetext == (inpusername + ": " +to_string(hashpass))) {
                    cout << "login succesful\n";
                    fpass.close();
                    return 0;
                }
            }
            cout << "login failed \n";
        } else if (!strcmp(argv[1],"signup")) {
            string filetext;
            cout << "Username: ";
            cin >> inpusername;
            cout << "Password: ";
            cin >> inppass;

            size_t hashpass = hasher(inppass);
            
            ifstream inpass("passdb.txt");
            while (getline(inpass, filetext)){
                size_t pos = filetext.find(':');
                if (inpusername == filetext.substr(0, pos)) {
                    cout << "there is already a user with that name.\n";
                    inpass.close();
                    return 0;
                }
            }
            ofstream outpass;
            outpass.open("passdb.txt", ios::app);
            outpass << inpusername << ": " << (hashpass) << "\n";
            outpass.close();
            return 0;


        }
    }
    return 0;
}