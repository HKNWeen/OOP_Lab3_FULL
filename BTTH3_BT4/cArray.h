#ifndef CARRAY_H_INCLUDED
#define CARRAY_H_INCLUDED

class cArray {
private:
    int n;
    int *arr;
    bool KiemTraSoNguyenTo(int x);
    void Merge(int l, int m, int r);
    void MergeSort(int l, int r);
    void Merge2(int l, int m, int r);
    void MergeSort2(int l, int r);

public:
    cArray(int size);
    ~cArray();
    void TaoMangNgauNhien();
    void XuatMang();
    int DemSoLanXuatHien (int x);
    bool KiemTraTangDan();
    int TimPhanLeNhoNhat();
    int TimSoNguyenToLonNhat();
    void SapXepTangDan();
    void SapXepGiamDan();
};

#endif // CARRAY_H_INCLUDED
