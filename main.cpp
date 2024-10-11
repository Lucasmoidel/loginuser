#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

void signUp();

void login();

int main(int argc, char *argv[]) {
    
    int linecount = 0;
    string filetext;
    string inpusername;
    hash<string> hasher;
    string inppass;
    
    if (argc == 2) {
        if (!strcmp(argv[1],"login")) {
            cout << "Username: ";
            cin >> inpusername;
            cout << "Password: ";
            cin >> inppass;
            size_t hashpass = hasher(inppass);
            //cout << hashpass;
            ifstream fpass;
            fpass.open("passdb.txt", ios::in);
            while (getline (fpass, filetext)) {
                linecount++;
            }
            for (int i = 0; i < linecount; i++) {
                getline(fpass, filetext);
                //replace( filetext.begin(), filetext.end(), '\n', '\0');
                if (filetext == to_string(hashpass)) {
                    cout << "login succesful\n";
                    fpass.close();
                    return 0;
                }
            }
        } else if (!strcmp(argv[1],"signup")) {
            cout << "Username: ";
            cin >> inpusername;
            cout << "Password: ";
            cin >> inppass;
            size_t hashpass = hasher(inppass);
            ofstream fpass;
            fpass.open("passdb.txt", ios::app);
            fpass << to_string(hashpass);
            fpass.close();
            return 0;


        }
    }
    return 0;
}