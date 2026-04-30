#include "cDaGiac.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//Constructor
cDaGiac::cDaGiac() {
    Dinh = 0;
    dsDinh = nullptr;
}
//Destructor de giai phong bo nho
cDaGiac::~cDaGiac() {
    if (dsDinh != nullptr) {
        delete[] dsDinh;
        dsDinh = nullptr;
    }
}

void Diem::Nhap() {
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
}

void Diem::Xuat() {
    cout << fixed << setprecision(2) << "(" << x << ", " << y << ")";
}

void cDaGiac::Nhap() {
    do {
        cout <<"Nhap so dinh cua da giac (n >= 3): ";
        cin >> Dinh;
    } while (Dinh < 3);
    if (dsDinh != nullptr) {
        delete[] dsDinh;
    }
    //Cap phat mang dong cho danh sach cac dinh;
    dsDinh = new Diem[Dinh];
    for (int i = 0; i < Dinh; i++) {
        cout << "Nhap toa do dinh thu " << i + 1 << ": \n";
        //ham nhap cua class Diem vi day la pointer cua Diem;
        dsDinh[i].Nhap();
    }
}

void cDaGiac::Xuat() {
    for (int i = 0; i < Dinh; i++) {
        cout << "Dinh " << i + 1 << ": "; dsDinh[i].Xuat();
        if (i != Dinh - 1) cout << ", ";
    }
}
//Ham tinh tien cua tung diem trong da giac;
void Diem::TinhTien(double dx, double dy) {
    x += dx, y += dy;
}
//Ham tinh tien cua ca da giac;
void cDaGiac::TinhTien(double dx, double dy) {
    for (int i = 0; i < Dinh; i++) {
        //method TinhTien cua class Diem;
        dsDinh[i].TinhTien(dx, dy);
    }
}
//Ham phong to/ thu nho cua tung diem trong da giac;
void Diem::PhongToThuNho(double k) {
    x *= k;
    y *= k;
}
//Ham phong to/ thu nho cua ca da giac;
void cDaGiac::PhongToThuNho(double k) {
    for (int i = 0; i < Dinh; i++) {
        //method PhongToThuNho cua class Diem;
        dsDinh[i].PhongToThuNho(k);
    }
}
//Ham quay cua tung diem trong da giac;
void Diem::Quay(double goc) {
    double rad = goc * M_PI / 180;
    double dx = x * cos(rad) - y * sin (rad);
    double dy = y * cos(rad) + x * sin (rad);
    x = dx;
    y = dy;
}
//Ham quay cua ca da giac;
void cDaGiac::Quay(double goc) {
    for (int i = 0; i < Dinh; i++) {
        //method Quay cua class Diem;
        dsDinh[i].Quay(goc);
    }
}
//Ham tinh do dai tung canh cua da giac;
double Diem::TinhKhoangCach(const Diem& khac) {
    return sqrt(pow(x - khac.x, 2) + pow(y - khac.y, 2));
}
//Ham tinh chu vi cua da giac;
double cDaGiac::TinhChuVi() {
    double cv = 0;
    for (int i = 0; i < Dinh; i++) {
        int next = (i + 1) % Dinh;
        cv += dsDinh[i].TinhKhoangCach(dsDinh[next]);
    }
    return cv;
}
//Getter de lay gia tri x trong private cua class Diem;
double Diem::getx () {
    return x;
}
//Getter de lay gia tri y trong private cua class Diem;
double Diem::gety () {
    return y;
}
//Ham tinh dien tich da giac(su dung cong thuc Shoelace);
//Cong thuc shoelace: S = 1/2 * [(x1y2 + x2y3 + ... + xny1) - (y1x2 + y2x3 + ... + ynx1)];
double cDaGiac::TinhDienTich() {
    double dt = 0;
    for (int i = 0; i < Dinh; i++) {
        int next = (i + 1) % Dinh;
        dt += (dsDinh[i].getx() * dsDinh[next].gety() - dsDinh[i].gety() * dsDinh[next].getx());
    }
    return abs(dt) * 0.5;
}
