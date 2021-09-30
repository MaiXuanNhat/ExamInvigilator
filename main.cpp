#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include<iomanip>
#include "GV.h"
#include "GV.cpp"
#include "phongthi.h"
#include "phongthi.cpp"
using namespace std;

int main()
{
    ifstream in;
    ofstream out;

    in.open("CANBOCOITHI.txt");
    out.open("DANHSACH PHANCONG.txt");
    string s;
    getline(in, s);
    int i = 1;
    vector<GV> giamthi;
    while (getline(in, s))
    {
        regex r_sinh("\\d{2}/\\d{2}/\\d{4}"), r_ten("([a-zA-Z]+\\s)+"),
            r_ma("\\d{9}"), r_dv("([a-zA-Z\\-]+\\s?)*([a-zA-Z]*)$");
        smatch m;
        regex_search(s, m, r_sinh);
        string sinh = m.str();
        regex_search(s, m, r_ten);
        string ten = m.str();
        regex_search(s, m, r_ma);
        string ma = m.str();
        regex_search(s, m, r_dv);
        string dv = m.str();
        giamthi.push_back(GV(i++, ten, sinh, ma, dv));
    }
    in.close();
    in.open("PHONGTHI.txt");
    getline(in, s);
    i = 1;
    vector<phongthi> phong;
    string place;
    int cnt_place = 0;
    int cnt_room = 0;
    vector <int> room;
    while (getline(in, s))
    {
        regex r_diadiem("([a-zA-Z]+\\s)*([a-zA-Z]*)$"), r_ten("([a-zA-Z]\\d{3})");
        smatch m;
        regex_search(s, m, r_ten);
        string ten = m.str();
        regex_search(s, m, r_diadiem);
        string diadiem = m.str();
        if (diadiem != place) 
        	{
        		room.push_back(cnt_room);
				cnt_place++;        	
        		cnt_room = 1;
			}
		else cnt_room++;
        place = diadiem;
        phong.push_back(phongthi(++i, ten, diadiem));
    }
    room.push_back(cnt_room);
    room.erase(room.begin());
    vector <GV> ranh = giamthi;
    vector <phongthi> phong1 = phong;
    srand(time(NULL));
    for (int i = 0; i < phong1.size(); ++i)
    {
        int j = rand() % ranh.size();
        phong1[i].set1(giamthi[ranh[j].so() - 1].so());
        ranh.erase(ranh.begin() + j);
        j = rand() % ranh.size();
        phong1[i].set2(giamthi[ranh[j].so() - 1].so());
        ranh.erase(ranh.begin() + j);
    }
    out <<"\t\t\t\t\tDANH SACH GIAM THI COI THI\n";
    out <<"--------------------------------------------------------------------------------------------------------------------\n";
	out <<"STT\tMa GV\t\t\tHo va ten\t\t\t\t  GIAM THI\t\t\tPhong thi\n";
	out <<"--------------------------------------------------------------------------------------------------------------------\n";
    out <<"   \t     \t\t         \t\t\t\tGiam thi 1\tGiam thi 2\n";
    out <<"--------------------------------------------------------------------------------------------------------------------\n";
    int k = 1, q = 1;
	for (auto it: phong1) 
	{
		out << setw(3) << right << setfill('0') << k << "\t" << giamthi[it.gv1() - 1] << "      \t     X\t\t\t\t\t  " << phong[q-1] << "\n";
		out <<"--------------------------------------------------------------------------------------------------------------------\n";
		out << setw(3) << right << setfill('0') <<  k+1 << "\t" << giamthi[it.gv2() - 1] << "\t\t      \t     X\t\t\t  "<< phong[q-1] << "\n";
		out <<"--------------------------------------------------------------------------------------------------------------------\n";
		k+=2;
		q++;
	}
    out.close();
    int num = ranh.size() / cnt_place;
	int num0 = ranh.size() % cnt_place;
	vector <int> giamsat;
	for (int i = 0; i< cnt_place; i++) 
		if (num0!=0) { giamsat.push_back(num+1); num0--;}
		else giamsat.push_back(num);
	int id = 0;
	int m = 0;
	for (int i = 0; i < cnt_place; i++) 
	{
		int r = room[i] / giamsat[i];
		int r0 = room[i] % giamsat[i];
		for (int j = 0; j < room[i]; j+=r)
		{
			ranh[m].setfirst(phong1[id].so()-1);
			if (r0!=0) {
				ranh[m].setfinal(phong1[id+r].so()-1);
				r0--;
				j++;
				id += r+1;
			}
			else {
				ranh[m].setfinal(phong1[id+r+-1].so()-1);
				id += r;
			}
			m++;
		}
	}
    out.open("DANHSACH GIAMSAT.txt"); 
	out <<"\t\t\t\tDANH SACH GIAM SAT HANH LANG\n";
	out <<"------------------------------------------------------------------------------------------\n";
	out <<"STT\tMa GV\t\t       Ho va ten\t\t\t  Phong thi duoc giam sat\n";
	out <<"------------------------------------------------------------------------------------------\n";

	int h = 1;
	for (auto it: ranh) 
	{
		out << setw(3) << setfill('0') << h << "\t" << it << "\t      " << phong1[it.firstroom()-1] << " - " << phong1[it.finalroom()-1] << "\n";
		out <<"------------------------------------------------------------------------------------------\n";
		h++;
	}
    out.close();
    cout <<"\n\nKet qua chuong trinh da duoc luu vao 2 file DANHSACH PHANCONG.txt va DANHSACH GIAMSAT.txt\n\n";
    return 0;
}



