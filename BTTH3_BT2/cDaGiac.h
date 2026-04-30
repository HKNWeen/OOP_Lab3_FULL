#ifndef CDAGIAC_H_INCLUDED
#define CDAGIAC_H_INCLUDED

class Diem {
private:
    double x, y;
public:
    void Nhap();
    void Xuat();
    void TinhTien(double dx, double dy);
    void Quay(double goc);
    void PhongToThuNho(double k);
    double TinhKhoangCach (const Diem& khac);
    //Getter de lay du lieu tu private cho cDaGiac su dung de tinh dien tich
    double getx ();
    double gety ();
};

class cDaGiac {
private:
    int Dinh;
    //pointer tro vao tung Dinh (mang dong);
    Diem* dsDinh;
public:
    cDaGiac ();
    ~cDaGiac ();
    void Nhap();
    void Xuat();
    void TinhTien(double dx, double dy);
    void PhongToThuNho(double k);
    void Quay(double goc);
    double TinhChuVi();
    double TinhDienTich();
};


#endif // CDAGIAC_H_INCLUDED
