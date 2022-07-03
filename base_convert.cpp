#include <iostream>
#include <math.h>
#include <bitset>
#include <vector>
#include <string>
#include "RealToBin.h"
#include "IntTobin.h"
#include <iomanip>
using namespace std;

// typedef long long ll;
// typedef unsigned long long ull;

// typedef union {
//     float value; // 4
//     struct {
//         ull man: 23; //8
//         ull ex: 8; //8
//         ull sign: 1; //8
//     };
// } myfloat;

int main() {
    string s, s1;
    FloatToBin ftb;
    IntToBin itb;
    bool back = false;
    int choice = -1;
    while(true) {
menu:
        if(back) break;
        cout << "-----------------------NUMBER CONVERTER------------------------";
        cout << "\nSelect type of number:\n";
        cout << "1. Real number.\n";
        cout << "2. Integer number.\n";
        cout << "3. End.\n";
        cin >> choice;
        switch(choice) {
        case 1:
doub:
            cout << "1. Convert real number to bin.\n";
            cout << "2. Convert bin to real number.\n";
            cout << "3. Back.\n";
            cout << "3. Back.\n";
            cin >> choice;
            switch(choice) {
            case 1:
                cout << "Select bit chain.\n";
                cout << "1. 32 bit.\n";
                cout << "2. 64 bit.\n";
                cout << "3. Back.\n";
                cin >> choice;
                switch(choice) {
                case 1: {
                    cout << "Input a floating number: ";
                    cin.ignore(99,'\n');
                    getline(cin, s);
                    cout << "The binary chain is: \n";
                    try {
                        vector<int> binn = ftb.convert_bin_x32bit(s);
                        for (int i = 0; i < binn.size(); i++)
                        {
                            if(i == 1 || i == 9) cout << ' ';
                            cout << binn[i];
                        }
                    }
                    catch(runtime_error ex) {
                        cout << ex.what();
                    }
                    cout << endl;
                    cin.get();
                    goto menu;
                }
                case 2: {
                    cout << "Input a floating number: ";
                    cin.ignore(99,'\n');
                    getline(cin, s);
                    cout << "The binary chain is: \n";
                    try {
                        vector<int> binn = ftb.convert_bin_x64bit(s);
                        for (int i = 0; i < binn.size(); i++)
                        {
                            if(i==1 || i== 12) cout << ' ';
                            cout << binn[i];
                        }
                    }
                    catch(runtime_error ex) {
                        cout << ex.what();
                    }
                    cout << endl;
                    cin.get();
                    goto menu;
                }
                case 3:
                    goto doub;
                }
            case 2:
                cout << "Select bit chain.\n";
                cout << "1. 32 bit.\n";
                cout << "2. 64 bit.\n";
                cout << "3. Back.\n";
                cin >> choice;
                switch(choice) {
                case 1: {
                    cout << "input your binary pattern: ";
                    cin.ignore(99, '\n');
                    getline(cin, s);
                    cout << "The floating point with single precision is: " << ftb.sp_floating_point_convert(s) << endl;
                    cin.get();
                    goto menu;
                }
                case 2: {
                    cout << "input your binary pattern: ";
                    cin.ignore(99, '\n');
                    getline(cin, s);
                    cout << fixed << setprecision(6);
                    cout << "The floating point with double precision is: " << ftb.dp_floating_point_convert(s) << endl;
                    cin.get();
                    goto menu;
                }
                case 3:
                    goto doub;
                }
            case 3:
                goto menu;
            }
        case 2:
inte:
            cout << "1.Convert int to bin.\n";
            cout << "2.Convert bin to int.\n";
            cout << "3.Back.\n";
            cin >> choice;
            switch(choice) {
            case 1:
                cout << "Select bit chain.\n";
                cout << "1. 8 bit.\n";
                cout << "2. 16 bit.\n";
                cout << "3. 32 bit.\n";
                cout << "4. Back.\n";
                cin >> choice;
                switch(choice) {
                case 1:
                    cout << "The binary chain:\n"; cin.get(); goto menu;
                case 2:
                {
                    cout << "Intput an integer number: ";
                    cin.ignore(99,'\n');
                    getline(cin, s1);
                    vector<int> binn = itb.x16_bit(s1);
                    cout << binn;
                    cin.get(); goto menu;
                }
                case 3:
                    cout << "The binary chain:\n"; cin.get(); goto menu;
                case 4:
                    goto inte;
                }
            case 2:
                cout << "Select bit chain.\n";
                cout << "1. 8 bit.\n";
                cout << "2. 16 bit.\n";
                cout << "3. 32 bit.\n";
                cout << "4. Back.\n";
                cin >> choice;
                switch(choice) {
                case 1:
                    cout << "The integer number is:\n"; cin.get();
                    goto menu;
                case 2: {
                    cout << "Input a bit pattern: ";
                    cin.ignore(99,'\n');
                    getline(cin, s);
                    int a = itb.x16bit_convertback(s);
                    cout << "The decimal number is: " << a << endl;
                    goto menu;
                }
                case 3:
                    cout << "The integer number is:\n"; cin.get();
                    goto menu;
                case 4:
                    goto inte;
                }
            case 3:
                goto menu;
            }
        case 3:
            back = true;
            break;
        }
    }
}