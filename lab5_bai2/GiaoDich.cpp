#include "GiaoDich.h"

// --- GiaoDich ---
GiaoDich::GiaoDich() : donGia(0), dienTich(0) {}

void GiaoDich::Nhap() {
    cin.ignore();
    cout << "Nhap ma GD: ";
    getline(cin, maGD);
    cout << "Nhap ngay GD (ngay thang nam): ";
    cin >> ngayGD.ngay >> ngayGD.thang >> ngayGD.nam;
    cout << "Nhap don gia: ";
    cin >> donGia;
    cout << "Nhap dien tich: ";
    cin >> dienTich;
}

void GiaoDich::Xuat() {
    cout << "Ma GD: " << maGD << " | Ngay: " << ngayGD.ngay << "/" << ngayGD.thang << "/" << ngayGD.nam
        << " | Gia: " << donGia << " | DT: " << dienTich;
}

Ngay GiaoDich::GetNgayGD() { return ngayGD; }

// --- GiaoDichDat ---
GiaoDichDat::GiaoDichDat() : GiaoDich() {}

void GiaoDichDat::Nhap() {
    GiaoDich::Nhap();
    cin.ignore();
    cout << "Nhap loai dat (A, B, C): ";
    getline(cin, loaiDat);
}

void GiaoDichDat::Xuat() {
    GiaoDich::Xuat();
    cout << " | Loai dat: " << loaiDat << " | Thanh tien: " << TinhTien() << endl;
}

double GiaoDichDat::TinhTien() {
    if (loaiDat == "A" || loaiDat == "a") return dienTich * donGia * 1.5;
    return dienTich * donGia;
}

int GiaoDichDat::LoaiGD() { return 1; }

// --- GiaoDichNhaPho ---
GiaoDichNhaPho::GiaoDichNhaPho() : GiaoDich() {}

void GiaoDichNhaPho::Nhap() {
    GiaoDich::Nhap();
    cin.ignore();
    cout << "Nhap loai nha (cao cap / thuong): ";
    getline(cin, loaiNha);
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);
}

void GiaoDichNhaPho::Xuat() {
    GiaoDich::Xuat();
    cout << " | Loai nha: " << loaiNha << " | Dia chi: " << diaChi << " | Thanh tien: " << TinhTien() << endl;
}

double GiaoDichNhaPho::TinhTien() {
    if (loaiNha == "cao cap") return dienTich * donGia;
    return dienTich * donGia * 0.9;
}

int GiaoDichNhaPho::LoaiGD() { return 2; }

// --- GiaoDichChungCu ---
GiaoDichChungCu::GiaoDichChungCu() : GiaoDich(), viTriTang(0) {}

void GiaoDichChungCu::Nhap() {
    GiaoDich::Nhap();
    cin.ignore();
    cout << "Nhap ma can: ";
    getline(cin, maCan);
    cout << "Nhap vi tri tang: ";
    cin >> viTriTang;
}

void GiaoDichChungCu::Xuat() {
    GiaoDich::Xuat();
    cout << " | Ma can: " << maCan << " | Tang: " << viTriTang << " | Thanh tien: " << TinhTien() << endl;
}

double GiaoDichChungCu::TinhTien() {
    if (viTriTang == 1) return dienTich * donGia * 2;
    if (viTriTang >= 15) return dienTich * donGia * 1.2;
    return dienTich * donGia;
}

int GiaoDichChungCu::LoaiGD() { return 3; }