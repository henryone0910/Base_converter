#include "RealTobin.h"
#include <cmath>
#include <math.h>

typedef long long ull;

bool FloatToBin::isValidFormat(string s) {
    const string pat = "-?\\b\\d+.\\d+\\b";
    regex match(pat);
    bool valid = regex_match(s, match);
    return valid;
}
bool FloatToBin::isBinFormat(string s) {
    const string pat = "\\b[0-1]*\\b";
    regex match(pat);
    bool res = regex_match(s, match);
    return res;
}

vector<int> FloatToBin::convert_bin_x32bit(string s) {
    bool isValid = isValidFormat(s);
    vector<int> res;
    vector<int> binn;
    if(isValid) {
        //split float number.
        double r = stod(s);
        int a = abs(r);
        double b = abs(r) - a;
        //sign solving
        if (r < 0) res.push_back(1);
        else res.push_back(0);
        //bit chain of a solving
        while(a > 0) {
            if(a % 2 == 0) binn.push_back(0);
            else binn.push_back(1);
            a = a / 2;
        }
        reverse(binn.begin(),binn.end());
        //exponent solving
        int ex = binn.size() - 1 + 127;
        while(ex > 0) {
            if(ex % 2 == 0) res.push_back(0);
            else res.push_back(1);
            ex/=2;
        }
        reverse(res.begin()+1, res.end());
        //mantissa solving
        for (int i = 1; i < binn.size(); i++)
        {
            res.push_back(binn[i]);
        }
        int msz = 32 - res.size();
        //bit chain of b solving, equivalent to the ramining mantissa
        while(b != 1 && --msz >= 0 ) {
            b *= 2;
            if(b>1) {
                res.push_back(1);
                b = b - 1;
            }
            else res.push_back(0);
        }
        return res;
    }
    else
        throw runtime_error("Invalid format of floating point");
}
vector<int> FloatToBin::convert_bin_x64bit(string s) {
    bool isValid = isValidFormat(s);
    vector<int> res;
    if(isValid) {
        double a = stod(s);
        ull* bit = (ull*)&a;
        bitset<64>bits(*bit);
        for (int i = 0; i < bits.size(); i++) {
            res.push_back(bits[i]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
    else {
        throw runtime_error("Invalid Format of Floating Point.\n");
    }
}

float FloatToBin::sp_floating_point_convert(string s) {
    bool valid = isBinFormat(s);
    if(valid) {
        while(s.size() < 8 * sizeof(float)) {
            s.append("0");
        }
        bitset<32> bit_pat(s);
        unsigned long bit = bit_pat.to_ulong();
        float* r = (float*)&bit;
        return *r;
    }
    else
        throw runtime_error("Invalid bin pattern. Pattern must only contain 0 or 1 elements.\n");
}
double FloatToBin::dp_floating_point_convert(string s) {
    bool isValid = isBinFormat(s);
    if(isValid) {
        while(s.size() < sizeof(double)*8) {
            s.append("0");
        }
        bitset<64> bit_convert(s);
        ull bit_ull = bit_convert.to_ullong();
        double *r = (double*)&bit_ull;
        return *r;
    }
    else
        throw runtime_error("Invalid bin format. The bit pattern must only contain 0 or 1 element.\n");
}