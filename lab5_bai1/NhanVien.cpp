#include "NhanVien.h"

// --- NhanVien ---
NhanVien::NhanVien() { luong = 0; }

void NhanVien::Nhap() {
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap ngay sinh (ngay thang nam): ";
    cin >> ngaySinh.ngay >> ngaySinh.thang >> ngaySinh.nam;
}

void NhanVien::Xuat() {
    cout << "Ho ten: " << hoTen << " | Ngay sinh: "
        << ngaySinh.ngay << "/" << ngaySinh.thang << "/" << ngaySinh.nam
        << " | Luong: " << luong;
}

double NhanVien::GetLuong() { return luong; }

int NhanVien::GetTuoi() { return 2026 - ngaySinh.nam; }

// --- NhanVienSanXuat ---
NhanVienSanXuat::NhanVienSanXuat() : NhanVien(), luongCanBan(0), soSanPham(0) {}

void NhanVienSanXuat::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap luong can ban: ";
    cin >> luongCanBan;
    cout << "Nhap so san pham: ";
    cin >> soSanPham;
}

void NhanVienSanXuat::Xuat() {
    NhanVien::Xuat();
    cout << " | Loai: San Xuat" << endl;
}

void NhanVienSanXuat::TinhLuong() {
    luong = luongCanBan + soSanPham * 5000;
}

int NhanVienSanXuat::LoaiNhanVien() { return 1; }

// --- NhanVienVanPhong ---
NhanVienVanPhong::NhanVienVanPhong() : NhanVien(), soNgayLamViec(0) {}

void NhanVienVanPhong::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap so ngay lam viec: ";
    cin >> soNgayLamViec;
}

void NhanVienVanPhong::Xuat() {
    NhanVien::Xuat();
    cout << " | Loai: Van Phong" << endl;
}

void NhanVienVanPhong::TinhLuong() {
    luong = soNgayLamViec * 100000;
}

int NhanVienVanPhong::LoaiNhanVien() { return 2; }