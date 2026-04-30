#ifndef CNHANVIENVP_H_INCLUDED
#define CNHANVIENVP_H_INCLUDED
#include <string>

class cNhanVienVP {
private:
    std::string ma;
    std::string ten;
    std::string ngaysinh;
    long long luong;
public:
    cNhanVienVP ();

    std::string getma() const;
    std::string getten() const;
    std::string getngaysinh() const;
    long long getluong() const;

    void setma(std::string m);
    void setten(std::string t);
    void setngaysinh(std::string ns);
    void setluong(long long l);

    void Nhap();
    void Xuat() const;
    int TinhTuoi() const;
};

class cListNhanVienVP {
private:
    int n;
    cNhanVienVP* ds;
    void intieude() const;
    void merge(int l, int m, int r);
    void mergesort(int l, int r);
public:
    cListNhanVienVP();
    ~cListNhanVienVP();
    void Nhap();
    void Xuat()const;

    void TimLuongCaoNhat() const;
    void TimTuoiCaoNhat () const;
    long long TinhTongLuong() const;
    void SapXepTangDanTheoLuong();

};
#endif // CNHANVIENVP_H_INCLUDED
