#include "GV.h"

GV::GV(int stt, string ho_ten, string sinh, string ma, string dv) : stt(stt), ho_ten(ho_ten), sinh(sinh), ma(ma), dv(dv) {}
int GV::so()
{
    return stt;
}
void GV::setfirst(int stt)
{
	phongdau =  stt; 
} 
void GV::setfinal(int stt)
{
	phongcuoi =  stt; 
} 
int GV::firstroom()
{
	return phongdau;
}
int GV::finalroom()
{
	return phongcuoi;
}
ostream &operator<<(ostream &out, const GV &x)
{
    out << x.ma << "\t" << setw(30) <<  setfill(' ') << x.ho_ten ;
    return out;
}
