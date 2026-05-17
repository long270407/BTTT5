#include "SinhVien.h"

// --- SinhVien ---
SinhVien::SinhVien() : tongTinChi(0), diemTB(0) {}

void SinhVien::Nhap() {
    cin.ignore();
    cout << "Nhap MSSV: ";
    getline(cin, mssv);
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);
    cout << "Nhap tong so tin chi: ";
    cin >> tongTinChi;
    cout << "Nhap diem trung binh: ";
    cin >> diemTB;
}

void SinhVien::Xuat() {
    cout << "MSSV: " << mssv << " | Ho ten: " << hoTen
        << " | Dia chi: " << diaChi << " | Tin chi: " << tongTinChi
        << " | DTB: " << diemTB;
}

double SinhVien::GetDiemTB() { return diemTB; }

// --- SinhVienCaoDang ---
SinhVienCaoDang::SinhVienCaoDang() : SinhVien(), diemThiTotNghiep(0) {}

void SinhVienCaoDang::Nhap() {
    SinhVien::Nhap();
    cout << "Nhap diem thi tot nghiep: ";
    cin >> diemThiTotNghiep;
}

void SinhVienCaoDang::Xuat() {
    SinhVien::Xuat();
    cout << " | Diem thi TN: " << diemThiTotNghiep << " | He: Cao dang" << endl;
}

bool SinhVienCaoDang::KiemTraTotNghiep() {
    return (tongTinChi >= 120 && diemTB >= 5.0 && diemThiTotNghiep >= 5.0);
}

int SinhVienCaoDang::LoaiSV() { return 1; }

// --- SinhVienDaiHoc ---
SinhVienDaiHoc::SinhVienDaiHoc() : SinhVien(), diemLuanVan(0) {}

void SinhVienDaiHoc::Nhap() {
    SinhVien::Nhap();
    cin.ignore();
    cout << "Nhap ten luan van: ";
    getline(cin, tenLuanVan);
    cout << "Nhap diem luan van: ";
    cin >> diemLuanVan;
}

void SinhVienDaiHoc::Xuat() {
    SinhVien::Xuat();
    cout << " | Luan van: " << tenLuanVan << " | Diem LV: " << diemLuanVan << " | He: Dai hoc" << endl;
}

bool SinhVienDaiHoc::KiemTraTotNghiep() {
    return (tongTinChi >= 170 && diemTB >= 5.0 && diemLuanVan >= 5.0);
}

int SinhVienDaiHoc::LoaiSV() { return 2; }