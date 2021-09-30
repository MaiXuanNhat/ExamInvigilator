#include "phongthi.h"

phongthi::phongthi(int stt, string ten, string diadiem) : stt(stt), ten(ten), diadiem(diadiem){};
int phongthi::so()
{
    return stt;
}
void phongthi::set1(int stt)
{
    giamthi1 = stt;
}

void phongthi::set2(int stt)
{
    giamthi2 = stt;
}

int phongthi::gv1()
{
    return giamthi1;
}

int phongthi::gv2()
{
    return giamthi2;
}

ostream &operator<<(ostream &out, const phongthi &x)
{
    out << x.ten ;
    return out;
}
