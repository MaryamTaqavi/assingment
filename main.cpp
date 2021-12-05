#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

class user{
    public:
        void submit(){
            string username, temp;
            ofstream file("userinfo.dat", ios::app);
            if (!file){
                cout << "error";
                exit(0);
            }
            ifstream file1("userinfo.dat");
                if (!file1){
                    cout << "error";
                    exit(0);
                }

                while (!file1.eof()){
                    file1 >> temp;
                    while (true){
                    cout << "enter a username: ";
                    cin >> username;
                    if (temp == username){
                        cout << "username is duplicate!" << endl;
                    }
                    else {
                        ofstream file("userinfo.dat", ios::app);
                        file << username;
                        break;
                    }

                    }
                }
                file.close();
                file1.close();

        }
        void login (){
            string username, temp;
            cout << "enter a username: ";
            cin >> username;
            ofstream file("userinfo.dat", ios::app);
            ifstream file1("userinfo.dat");
            while (file1.eof()){
                file1 >> temp;
                if (temp == username){
                    cout << "welcome";
                }
                else {
                    cout << "wrong username!";
                }
            }
            file.close();
            file1.close();

        }
};

int main()
{
    string s;
    cout << "enter a string: ";
    cin >> s;

    user user_1;

    if (s == "submit"){
        user_1.submit();
    }
    else if (s == "login"){
        user_1.login();
    }
    else {
        cout << "error!";
    }

    return 0;
}
