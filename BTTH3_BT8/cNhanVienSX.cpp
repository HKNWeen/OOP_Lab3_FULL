#include "cNhanVienSX.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <climits>
using namespace std;

cNhanVienSX::cNhanVienSX() {
    ma = "";
    ten = "";
    ngaysinh = "";
    sosp = 0;
    giasp = 0;
}

//Getter de lay ma tu private cua cNhanVienSX;
string cNhanVienSX::getma() const{ return ma; }
//Getter de lay ten tu private cua cNhanVienX;
string cNhanVienSX::getten() const{ return ten; }
//Getter de lay ngaysinh tu private cua cNhanVienSX;
string cNhanVienSX::getngaysinh() const{ return ngaysinh; }
//Getter de lay sosp tu private cua cNhanVienSX;
int cNhanVienSX::getsosp() const{ return sosp; }
//Getter de lay giasp tu private cua cNhanVienSX;
long long cNhanVienSX::getgiasp() const{ return giasp; }

//Setter de thay doi gia tri ma cua cNhanVienSX;
void cNhanVienSX::setma(string m) { ma = m; }
//Setter de thay doi gia tri ten cua cNhanVienSX;
void cNhanVienSX::setten(string t) { ten = t; }
//Setter de thay doi gia tri ngaysinh cua cNhanVienSX;
void cNhanVienSX::setngaysinh(string ns) { ngaysinh = ns; }
//Setter de thay doi gia tri sosp cua cNhanVienSX;
void cNhanVienSX::setsosp(int sp) { sosp = sp; }
//Setter de thay doi gia tri giasp cua cNhanVienSX;
void cNhanVienSX::setgiasp(long long g) { giasp = g; }
//Ham tinh luong cua tung nhan vien;
long long cNhanVienSX::TinhLuong() const{
    return giasp * sosp;
}
//Ham tinh tuoi cua tung nhan vien;
int cNhanVienSX::TinhTuoi() const{
    int namsinh = stoi(ngaysinh.substr(6, 4));
    return 2026 - namsinh;
}
//Ham nhap cua tung nhan vien san xuat;
void cNhanVienSX::Nhap() {
    cout << "Nhap ma nhan vien: "; cin >> ma; cin.ignore();
    cout << "Nhap ten nhan vien: "; getline(cin, ten);
    cout << "Nhap ngay sinh (dd/mm/yyyy): "; cin >> ngaysinh;
    cout << "Nhap so san pham da gia cong: "; cin >> sosp;
    cout << "Nhap don gia mot san pham: "; cin >> giasp;
}
//Ham xuat gia tri cua tung nhan vien san xuat;
void cNhanVienSX::Xuat() const{
    cout << left << setw(10) << ma
                << setw(25) << ten
                << setw(15) << ngaysinh
                << setw(8) << TinhTuoi()
                << setw(8) << sosp
                << setw(10) << giasp
                << setw(15) << TinhLuong();
    cout << '\n';
}

//Constructor khoi tao gia tri cua danh sach nhan vien san xuat;
cListNhanVienSX::cListNhanVienSX() {
    n = 0;
    ds = nullptr;
}
//Destructor giai phong bo nho;
cListNhanVienSX::~cListNhanVienSX() {
    delete []ds;
}
//Ham nhap cua danh sach nhan vien san xuat;
void cListNhanVienSX::Nhap() {
    do {
        cout << "Nhap so luong nhan vien (n > 0): ";
        cin >> n;
    } while (n <= 0);
    ds = new cNhanVienSX[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhan vien thu " << i + 1 << ": \n";
        ds[i].Nhap();
    }
}
//Ham in tieu de cho bang;
void cListNhanVienSX::intieude() const{
    cout << left << setw(10) << "Ma NV"
                << setw(25) << "Ten NV"
                << setw(15) << "Ngay sinh"
                << setw(8) << "Tuoi"
                << setw(8) << "So SP"
                << setw(10) << "Don gia"
                << setw(15) << "Luong";
    cout << '\n';
}
//Ham xuat danh sach nhan vien san xuat theo dang bang;
void cListNhanVienSX::Xuat() const{
    intieude();
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }
}
//Ham tim nhan vien san xuat co luong thap nhat va xuat danh sach;
void cListNhanVienSX::TimLuongThapNhat() const {
    intieude();
    long long best = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        best = min(best, ds[i].TinhLuong());
    }
    //Xuat ra tat ca nhan vien san xuat co cung luong cao nhat;
    for (int i = 0; i < n; i++) {
        if (ds[i].TinhLuong() == best) {
            ds[i].Xuat();
        }
    }
}
//Ham tim nhan vien san xuat co tuoi cao nhat va xuat danh sach;
void cListNhanVienSX::TimTuoiCaoNhat() const {
    intieude();
    int best = 0;
    for (int i = 0; i < n; i++) {
        best = max(best, ds[i].TinhTuoi());
    }
    //Xuat ra tat ca nhan vien san xuat co cung tuoi cao nhat;
    for (int i = 0; i < n; i++) {
        if (ds[i].TinhTuoi() == best) {
            ds[i].Xuat();
        }
    }
}
//Ham merge trong merge sort de thuc hien sort theo chieu tang dan cua luong;
void cListNhanVienSX::merge(int l, int m, int r) {
    vector<cNhanVienSX> left (ds + l, ds + m + 1);
    vector<cNhanVienSX> right (ds + m + 1, ds + r + 1);
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        if (left[i].TinhLuong() <= right[j].TinhLuong()) ds[k++] = left[i++];
        else ds[k++] = right[j++];
    }
    while (i < left.size()) ds[k++] = left[i++];
    while (j < right.size()) ds[k++] = right[j++];
}
//Ham mergesort de sort theo chieu tang dan cua luong;
void cListNhanVienSX::mergesort(int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergesort(l, m);
    mergesort(m + 1, r);
    merge(l, m, r);
}
//Ham sap xep su dung mergesort de sap xep theo chieu tang dan cua luong va xuat danh sach duoi dang bang;
void cListNhanVienSX::SapXepTangDanTheoLuong() {
    mergesort(0, n - 1);
    intieude();
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }
}
//Ham tinh tuong luong cua tat ca nhan vien trong danh sach;
long long cListNhanVienSX::TinhTongLuong() const{
    long long tong = 0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].TinhLuong();
    }
    return tong;
}
