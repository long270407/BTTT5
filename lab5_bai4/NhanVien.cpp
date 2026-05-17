#include "NhanVien.h"

// --- NhanVien ---
NhanVien::NhanVien() : tuoi(0), luongCoBan(0), luong(0) {}

void NhanVien::Nhap() {
    cin.ignore();
    cout << "Nhap ma NV: ";
    getline(cin, maNV);
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap tuoi: ";
    cin >> tuoi;
    cin.ignore();
    cout << "Nhap so dien thoai: ";
    getline(cin, sdt);
    cout << "Nhap email: ";
    getline(cin, email);
    cout << "Nhap luong co ban: ";
    cin >> luongCoBan;
}

void NhanVien::Xuat() {
    cout << "Ma NV: " << maNV << " | Ten: " << hoTen
        << " | Tuoi: " << tuoi << " | Luong CB: " << luongCoBan
        << " | Luong thuc lanh: " << luong;
}

double NhanVien::GetLuong() { return luong; }

// --- LapTrinhVien ---
LapTrinhVien::LapTrinhVien() : NhanVien(), soGioOvertime(0) {}

void LapTrinhVien::Nhap() {
    cout << "--- Nhap Thong Tin Lap Trinh Vien ---" << endl;
    NhanVien::Nhap();
    cout << "Nhap so gio overtime: ";
    cin >> soGioOvertime;
}

void LapTrinhVien::Xuat() {
    NhanVien::Xuat();
    cout << " | Overtime: " << soGioOvertime << "h | Vi tri: LTV" << endl;
}

void LapTrinhVien::TinhLuong() {
    luong = luongCoBan + soGioOvertime * 200000;
}

int LapTrinhVien::LoaiNV() { return 1; }

// --- KiemChungVien ---
KiemChungVien::KiemChungVien() : NhanVien(), soLoi(0) {}

void KiemChungVien::Nhap() {
    cout << "--- Nhap Thong Tin Kiem Chung Vien ---" << endl;
    NhanVien::Nhap();
    cout << "Nhap so loi phat hien duoc: ";
    cin >> soLoi;
}

void KiemChungVien::Xuat() {
    NhanVien::Xuat();
    cout << " | So loi: " << soLoi << " | Vi tri: KCV" << endl;
}

void KiemChungVien::TinhLuong() {
    luong = luongCoBan + soLoi * 50000;
}

int KiemChungVien::LoaiNV() { return 2; }