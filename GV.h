#ifndef GV_H
#define GV_H

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include<iomanip>
using namespace std;

class GV
{
private:
    int stt;
    string ho_ten, sinh, ma, dv;
	int phongdau, phongcuoi; 
public:
    GV(int stt = -1, string ho_ten = "", string sinh = "", string ma = "", string dv = "");
    friend ostream &operator<<(ostream &out, const GV &x);
    int so();
    void setfirst(int stt); 
    void setfinal(int stt); 
    int firstroom();
    int finalroom();
};

#endif
