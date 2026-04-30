#ifndef CNHANVIENSX_H_INCLUDED
#define CNHANVIENSX_H_INCLUDED
#include <string>

class cNhanVienSX {
private:
    std::string ma;
    std::string ten;
    std::string ngaysinh;
    int sosp;
    long long giasp;
public:
    cNhanVienSX();

    std::string getma() const;
    std::string getten() const;
    std::string getngaysinh() const;
    int getsosp() const;
    long long getgiasp() const;

    void setma(std::string m);
    void setten(std::string t);
    void setngaysinh(std::string ns);
    void setsosp(int sp);
    void setgiasp(long long g);

    void Nhap();
    void Xuat() const;
    long long TinhLuong() const;
    int TinhTuoi() const;
};

class cListNhanVienSX {
private:
    int n;
    cNhanVienSX* ds;
    void intieude() const;
    void merge(int l, int m, int r);
    void mergesort(int l, int r);
public:
    cListNhanVienSX();
    ~cListNhanVienSX();
    void Nhap();
    void Xuat()const;

    void TimLuongThapNhat() const;
    void TimTuoiCaoNhat () const;
    long long TinhTongLuong() const;
    void SapXepTangDanTheoLuong();

};

#endif // CNHANVIENSX_H_INCLUDED
