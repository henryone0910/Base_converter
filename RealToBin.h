#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <bitset>
using namespace std;

class FloatToBin {
public:
    bool isValidFormat(string);
    bool isBinFormat(string);
    vector<int> convert_bin_x32bit(string);
    vector<int> convert_bin_x64bit(string);
    float sp_floating_point_convert(string);
    double dp_floating_point_convert(string);
};