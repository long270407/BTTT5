#include "NhanVien.h"

const int MAX = 100;

int main() {
    NhanVien* danhSach[MAX];
    int soLuong = 0;
    int slLTV, slKCV;

    // a. Nhập danh sách nhân viên
    cout << "So luong Lap trinh vien: "; cin >> slLTV;
    for (int i = 0; i < slLTV; i++) {
        if (soLuong >= MAX) break;
        danhSach[soLuong] = new LapTrinhVien();
        danhSach[soLuong]->Nhap();
        soLuong++;
    }

    cout << "\nSo luong Kiem chung vien: "; cin >> slKCV;
    for (int i = 0; i < slKCV; i++) {
        if (soLuong >= MAX) break;
        danhSach[soLuong] = new KiemChungVien();
        danhSach[soLuong]->Nhap();
        soLuong++;
    }

    // Tính lương cho tất cả nhân viên
    double tongLuong = 0;
    for (int i = 0; i < soLuong; i++) {
        danhSach[i]->TinhLuong();
        tongLuong += danhSach[i]->GetLuong();
    }

    // b. Xuất danh sách nhân viên
    cout << "\n================ DANH SACH NHAN VIEN ================" << endl;
    for (int i = 0; i < soLuong; i++) {
        danhSach[i]->Xuat();
    }

    // c. Xuất danh sách các nhân viên có lương thấp hơn mức lương trung bình
    double luongTB = soLuong > 0 ? tongLuong / soLuong : 0;
    cout << "\n===== NHAN VIEN CO LUONG THAP HON TRUNG BINH (" << luongTB << ") =====" << endl;
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i]->GetLuong() < luongTB) {
            danhSach[i]->Xuat();
        }
    }

    // Khởi tạo các biến tìm max, min
    NhanVien* nvMaxLuong = nullptr;
    NhanVien* nvMinLuong = nullptr;
    NhanVien* ltvMaxLuong = nullptr;
    NhanVien* kcvMinLuong = nullptr;

    for (int i = 0; i < soLuong; i++) {
        // d. Nhân viên có lương cao nhất
        if (nvMaxLuong == nullptr || danhSach[i]->GetLuong() > nvMaxLuong->GetLuong()) {
            nvMaxLuong = danhSach[i];
        }

        // e. Nhân viên có lương thấp nhất
        if (nvMinLuong == nullptr || danhSach[i]->GetLuong() < nvMinLuong->GetLuong()) {
            nvMinLuong = danhSach[i];
        }

        // f. Lập trình viên có lương cao nhất
        if (danhSach[i]->LoaiNV() == 1) {
            if (ltvMaxLuong == nullptr || danhSach[i]->GetLuong() > ltvMaxLuong->GetLuong()) {
                ltvMaxLuong = danhSach[i];
            }
        }

        // g. Kiểm chứng viên có lương thấp nhất
        if (danhSach[i]->LoaiNV() == 2) {
            if (kcvMinLuong == nullptr || danhSach[i]->GetLuong() < kcvMinLuong->GetLuong()) {
                kcvMinLuong = danhSach[i];
            }
        }
    }

    cout << "\n================ THONG KE LUONG ================" << endl;
    if (nvMaxLuong) {
        cout << "Nhan vien co luong cao nhat:" << endl;
        nvMaxLuong->Xuat();
    }
    if (nvMinLuong) {
        cout << "\nNhan vien co luong thap nhat:" << endl;
        nvMinLuong->Xuat();
    }
    if (ltvMaxLuong) {
        cout << "\nLap trinh vien co luong cao nhat:" << endl;
        ltvMaxLuong->Xuat();
    }
    else {
        cout << "\nKhong co Lap trinh vien." << endl;
    }
    if (kcvMinLuong) {
        cout << "\nKiem chung vien co luong thap nhat:" << endl;
        kcvMinLuong->Xuat();
    }
    else {
        cout << "\nKhong co Kiem chung vien." << endl;
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < soLuong; i++) {
        delete danhSach[i];
    }

    return 0;
}