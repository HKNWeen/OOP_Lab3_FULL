#include "cNhanVienVP.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

cNhanVienVP::cNhanVienVP() {
    ma = "";
    ten = "";
    ngaysinh = "";
    luong = 0;
}
//Getter de lay ma tu private cua cNhanVienVP;
string cNhanVienVP::getma() const{ return ma; }
//Getter de lay ten tu private cua cNhanVienVP;
string cNhanVienVP::getten() const{ return ten; }
//Getter de lay ngaysinh tu private cua cNhanVienVP;
string cNhanVienVP::getngaysinh() const{ return ngaysinh; }
//Getter de lay luong tu private cua cNhanVienVP;
long long cNhanVienVP::getluong() const{ return luong; }

//Setter de thay doi gia tri ma cua cNhanVienVP;
void cNhanVienVP::setma(string m) { ma = m; }
//Setter de thay doi gia tri ten cua cNhanVienVP;
void cNhanVienVP::setten(string t) { ten = t; }
//Setter de thay doi gia tri ngaysinh cua cNhanVienVP;
void cNhanVienVP::setngaysinh(string ns) { ngaysinh = ns; }
//Setter de thay doi gia tri luong cua cNhanVienVP;
void cNhanVienVP::setluong(long long l) { luong = l; }
//Ham tinh tuoi cua tung nhan vien;
int cNhanVienVP::TinhTuoi() const{
    int namsinh = stoi(ngaysinh.substr(6, 4));
    return 2026 - namsinh;
}
//Ham nhap cua tung nhan vien van phong;
void cNhanVienVP::Nhap() {
    cout << "Nhap ma nhan vien: "; cin >> ma; cin.ignore();
    cout << "Nhap ten nhan vien: "; getline(cin, ten);
    cout << "Nhap ngay sinh (dd/mm/yyyy): "; cin >> ngaysinh;
    cout << "Nhap luong nhan vien: "; cin >> luong;
}
//Ham xuat gia tri cua tung nhan vien van phong
void cNhanVienVP::Xuat() const{
    cout << left << setw(10) << ma
                << setw(25) << ten
                << setw(15) << ngaysinh
                << setw(8) << TinhTuoi()
                << setw(15) << luong;
    cout << '\n';
}
//Constructor khoi tao gia tri cua danh sach nhan vien van phong;
cListNhanVienVP::cListNhanVienVP() {
    n = 0;
    ds = nullptr;
}
//Destructor giai phong bo nho;
cListNhanVienVP::~cListNhanVienVP() {
    delete []ds;
}
//Ham nhap cua danh sach nhan vien van phong;
void cListNhanVienVP::Nhap() {
    do {
        cout << "Nhap so luong nhan vien (n > 0): ";
        cin >> n;
    } while (n <= 0);
    ds = new cNhanVienVP[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhan vien thu " << i + 1 << ": \n";
        ds[i].Nhap();
    }
}
//Ham in tieu de cho bang;
void cListNhanVienVP::intieude() const{
    cout << left << setw(10) << "Ma NV"
                << setw(25) << "Ten NV"
                << setw(15) << "Ngay sinh"
                << setw(8) << "Tuoi"
                << setw(15) << "Luong";
    cout << '\n';
}
//Ham xuat danh sach nhan vien van phong theo dang bang;
void cListNhanVienVP::Xuat() const{
    intieude();
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }
}
//Ham tim nhan vien van phong co luong cao nhat va xuat danh sach;
void cListNhanVienVP::TimLuongCaoNhat() const {
    intieude();
    long long best = 0;
    for (int i = 0; i < n; i++) {
        best = max(best, ds[i].getluong());
    }
    //Xuat ra tat ca nhan vien van phong co cung luong cao nhat;
    for (int i = 0; i < n; i++) {
        if (ds[i].getluong() == best) {
            ds[i].Xuat();
        }
    }
}
//Ham tim nhan vien van phong co tuoi cao nhat va xuat danh sach;
void cListNhanVienVP::TimTuoiCaoNhat() const {
    intieude();
    int best = 0;
    for (int i = 0; i < n; i++) {
        best = max(best, ds[i].TinhTuoi());
    }
    //Xuat ra tat ca nhan vien van phong co cung tuoi cao nhat;
    for (int i = 0; i < n; i++) {
        if (ds[i].TinhTuoi() == best) {
            ds[i].Xuat();
        }
    }
}
//Ham merge trong merge sort de thuc hien sort theo chieu tang dan cua luong;
void cListNhanVienVP::merge(int l, int m, int r) {
    vector<cNhanVienVP> left (ds + l, ds + m + 1);
    vector<cNhanVienVP> right (ds + m + 1, ds + r + 1);
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        if (left[i].getluong() <= right[j].getluong()) ds[k++] = left[i++];
        else ds[k++] = right[j++];
    }
    while (i < left.size()) ds[k++] = left[i++];
    while (j < right.size()) ds[k++] = right[j++];
}
//Ham mergesort de sort theo chieu tang dan cua luong;
void cListNhanVienVP::mergesort(int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergesort(l, m);
    mergesort(m + 1, r);
    merge(l, m, r);
}
//Ham sap xep su dung mergesort de sap xep theo chieu tang dan cua luong va xuat danh sach duoi dang bang;
void cListNhanVienVP::SapXepTangDanTheoLuong() {
    mergesort(0, n - 1);
    intieude();
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }
}
//Ham tinh tuong luong cua tat ca nhan vien trong danh sach;
long long cListNhanVienVP::TinhTongLuong() const{
    long long tong = 0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].getluong();
    }
    return tong;
}






