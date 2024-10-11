#include <iostream>
#include <cstring>
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
            ifstream passes("passdb.txt");
            while (getline (passes, filetext)) {
                linecount++;
            }
            for (int i = 0; i < linecount; i++) {
                getline(passes, filetext);
                if (filetext == to_string(hashpass)) {
                    cout << "login succesful\n";
                    passes.close();
                    return 0;
                }
            }
        } else if (!strcmp(argv[1],"signup")) {
            cout << "Username: ";
            cin >> inpusername;
            cout << "Password: ";
            cin >> inppass;
            size_t hashpass = hasher(inppass);
            ofstream passes("passdb.txt");
            fout
            passes << to_string(hashpass) + "\n";
            passes.close();
            return 0;


        }
    }
    return 0;
}