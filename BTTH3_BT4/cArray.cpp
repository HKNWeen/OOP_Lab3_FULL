#include "cArray.h"
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
//Constructor khoi tao gia tri ban dau cua mang
cArray::cArray(int size) {
    n = size;
    arr = new int[n];
}
//destructor giai phong bo nho
cArray::~cArray() {
    if (arr != nullptr) {
        delete []arr;
        arr = nullptr;
    }
}
//Ham tao mang so nguyen ngau nhien;
void cArray::TaoMangNgauNhien() {
    for (int i = 0; i < n; i++) {
        //Random gia tri tu 0 den 99 (rand() trong <cstdlib>);
        arr[i] = rand() % 100;
    }
}
//Ham xuat mang
void cArray::XuatMang() {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}
//Ham dem so lan ma gia tri x xuat hien trong mang
int cArray::DemSoLanXuatHien(int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) count++;
    }
    return count;
}
//Ham kiem tra xem mang co tang dan hay khong;
bool cArray::KiemTraTangDan() {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true;
}
//Ham tim phan le nho nhat trong mang, neu ko co phan le thi in -1;
int cArray::TimPhanLeNhoNhat() {
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            ans = min(ans, arr[i]);
        }
    }
    return (ans == INT_MAX) ? -1 : ans;
}
//Ham tro giup kiem tra so nguyen to cua gia tri x trong mang;
bool cArray::KiemTraSoNguyenTo(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;

    for (int i = 3; i*i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}
//Ham tim so nguyen to lon nhat;
int cArray::TimSoNguyenToLonNhat() {
    int best = -1;
    for (int i = 0; i < n; i++) {
        if (KiemTraSoNguyenTo(arr[i])) {
            best = max(best, arr[i]);
        }
    }
    return best;
}
//Ham merge cua thuat toan merge sort (Sap xep tang dan);
void cArray::Merge(int l, int m, int r) {
    vector<int> left (arr + l, arr + m + 1);
    vector<int> right (arr + m + 1, arr + r + 1);
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++];
        }
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}
//Ham mergesort giup sap xep phan tu tang dan theo gia tri;
void cArray::MergeSort(int l, int r) {
    if (l >= r) return;
    int m = l + (r - l)/2;
    MergeSort(l, m);
    MergeSort(m + 1, r);
    Merge(l, m, r);
}
//Ham sap xep mang tang dan su dung mergesort;
void cArray::SapXepTangDan() {
    MergeSort(0, n - 1);
}
//Ham merge cua thuat toan merge sort (Sap xep giam dan);
void cArray::Merge2(int l, int m, int r) {
    vector<int> left (arr + l, arr + m + 1);
    vector<int> right (arr + m + 1, arr + r + 1);
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        if (left[i] > right[j]) {
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++];
        }
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}
//Ham mergesort giup sap xep phan tu giam dan theo gia tri;
void cArray::MergeSort2(int l, int r) {
    if (l >= r) return;
    int m = l + (r - l)/2;
    MergeSort2(l, m);
    MergeSort2(m + 1, r);
    Merge2(l, m, r);
}
//Ham sap xep mang giam dan su dung mergesort;
void cArray::SapXepGiamDan() {
    MergeSort2(0, n - 1);
}


