#include "cDathuc.h"
#include <iostream>
#include <cmath>
using namespace std;
//Constructor khoi tao 1 da thuc voi bac = 0 (mac dinh);
cDaThuc::cDaThuc() {
    bac = 0;
    heso = new double[1];
    heso[0] = 0;
}
//Constructor khoi tao 1 da thuc voi bac = n;
cDaThuc::cDaThuc(int n) {
    bac = n;
    //Khoi tao mang voi n + 1 phan tu va moi phan tu co gia tri = 0;
    heso = new double[bac + 1]{0};
    /*
    for (int i = 0; i <= bac; i++) {
        heso[i] = 0;
    }
    */
}
//Destructor giai phong bo nho;
cDaThuc::~cDaThuc() {
    delete []heso;
}
//Copy constructor;
/*Vi du: "kq" trong method Cong va Tru se bi xoa khi ket thuc method vi la bien cuc bo
nen ham copy constructor se giup tao ra 1 ban sao tam thoi de dua ra ngoai cho Tong & Hieu lay;
*/
cDaThuc::cDaThuc(const cDaThuc& other) {
    bac = other.bac;
    heso = new double[bac + 1];
    for (int i = 0; i <= bac; i++) {
        heso[i] = other.heso[i];
    }
}
//Toan tu gan (operator)
//Vi du: Tong = A + B (A + B (cDaThuc) se duoc gan cho Tong);
cDaThuc& cDaThuc::operator=(const cDaThuc& other) {
    if (this != &other) {
        delete []heso;
        bac = other.bac;
        heso = new double[bac + 1];
        for (int i = 0; i <= bac; i++) {
            heso[i] = other.heso[i];
        }
    }
    return *this;
}
//Ham nhap da thuc;
void cDaThuc::Nhap() {
    do {
        cout << "Nhap bac cua da thuc (n >= 0): ";
        cin >> bac;
    } while (bac < 0);
    delete []heso;
    heso = new double[bac + 1];
    for (int i = bac; i >= 0; i--){
        cout << "Nhap he so cua x^" << i << ": ";
        cin >> heso[i];
    }
}
//Ham xuat da thuc;
void cDaThuc::Xuat () const {
    if (bac == 0 && heso[0] == 0) {
        cout << "0" << '\n';
        return;
    }
    bool first = true;
    for (int i = bac; i >= 0; i--) {
        if (heso[i] == 0) continue;
        if (!first && heso[i] > 0) cout << " + ";
        else if (heso[i] < 0) {
            if (first) cout << "-";
            else cout << " - ";
        }
        double val = abs(heso[i]);
        //In gia tri ra neu no khac 1 hoac bac cua no la 0;
        if (val != 1 || i == 0) cout << val;
        if (i > 0) cout << "x";
        if (i > 1) cout << "^" << i;
        first = false;
    }
    if (first) cout << "0";
    cout << '\n';
}
//Ham tinh gia tri cua da thuc khi biet x;
//Vi du: A(x) = 2x³ - 3x² + x - 5, x = 2; Output: 1;
double cDaThuc::TinhGiaTri(double x) const{
    double kq = 0;
    for (int i = bac; i >=0; i--) {
        kq = kq + (heso[i] * pow(x, i));
    }
    return kq;
}
//Ham tinh tong cua 2 da thuc;
cDaThuc cDaThuc::Cong(const cDaThuc& other) const {
    int maxBac = max(bac, other.bac);
    cDaThuc kq(maxBac);
    for (int i = 0; i <= maxBac; i++) {
        double heso1 = (i <= bac) ? heso[i] : 0;
        double heso2 = (i <= other.bac) ? other.heso[i] : 0;
        kq.heso[i] = heso1 + heso2;
    }
    return kq;
}
//Overload operator +;
cDaThuc cDaThuc::operator+(const cDaThuc& other) const {
    return Cong(other);
}
//Ham tinh hieu cua 2 da thuc;
cDaThuc cDaThuc::Tru(const cDaThuc& other) const {
    int maxBac = max(bac, other.bac);
    cDaThuc kq(maxBac);
    for (int i = 0; i <= maxBac; i++) {
        double heso1 = (i <= bac) ? heso[i] : 0;
        double heso2 = (i <= other.bac) ? other.heso[i] : 0;
        kq.heso[i] = heso1 - heso2;
    }
    return kq;
}
//Overload operator -;
cDaThuc cDaThuc::operator-(const cDaThuc& other) const {
    return Tru(other);
}
