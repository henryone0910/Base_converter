#include "IntTobin.h"

bool IntToBin::isFormat(string s) {
    const string pat = "-?\\b\\d+\\b";
    regex match(pat);
    bool res = regex_match(s, match);
    return res;
}

ostream& operator<<(ostream& outDev, vector<int> v){
    for (int i = 0; i < v.size(); i++)
    {
        outDev << v[i];
    }
    return outDev;
}

vector<int> IntToBin::x16_bit(string s) {
    bool isValid = isFormat(s);
    vector<int> res;
    if(isValid) {
        short a = stoi(s);
        cout << a << endl;
        bitset<16> b = bitset<16>(a);
        for (int i = 0; i < b.size(); i++)
        {
            res.push_back(b[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
}
int IntToBin::x16bit_convertback(string s) {
    bool isValid = isBinFormat(s);
    if(isValid) {
        int a = 0;
        vector<int> temp;
        while(s.size() < 16) {
            s.insert(0, "0");
        }
        for (int i = 0; i < s.size(); i++)
        {
            temp.push_back(s[i] - 48);
        }
        if(s[0] == '1') {
            int sz = temp.size();
            //bit - 1
            temp[sz-1] -= 1;
            while(temp[--sz] < 0) {
                temp[sz] = 1;
                temp[sz - 1] -= 1;
            }
            //converse bit
            for (int i = 0; i < temp.size(); i++) {
                temp[i] = 1 - temp[i];
            }
        }
        //convert to dec
        for (int i = 0; i < temp.size() - 1; i++) {
                a = (a + temp[i])*2;
        }
        if(s[0] == '1') a = -a;
        return a;
    }
}