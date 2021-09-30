#ifndef PHONGTHI_H
#define PHONGTHI_H

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include<iomanip>
using namespace std;

class phongthi
{
private:
    int stt;
    string ten, diadiem;
    int giamthi1, giamthi2;

public:
    phongthi(int stt = -1, string ten = "", string diadiem = "");
    friend ostream &operator<<(ostream &out, const phongthi &x);
    int so();
    void set1(int stt);
    void set2(int stt);
    int gv1();
    int gv2();
};

#endif
