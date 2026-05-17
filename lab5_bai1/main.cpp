#include "NhanVien.h"

const int MAX = 100; // Giới hạn số lượng nhân viên tối đa của mảng tĩnh

int main() {
    NhanVien* danhSach[MAX];
    int soLuong = 0; // Số lượng nhân viên thực tế đang có trong mảng
    int soLuongSX, soLuongVP;

    // 1. Nhập danh sách nhân viên
    cout << "--- NHAP DANH SACH NHAN VIEN SAN XUAT ---" << endl;
    cout << "So luong NVSX: "; cin >> soLuongSX;
    for (int i = 0; i < soLuongSX; i++) {
        if (soLuong >= MAX) {
            cout << "Mang da day, khong the them!" << endl;
            break;
        }
        cout << "\nNhan vien san xuat thu " << i + 1 << ":" << endl;
        danhSach[soLuong] = new NhanVienSanXuat();
        danhSach[soLuong]->Nhap();
        soLuong++;
    }

    cout << "\n--- NHAP DANH SACH NHAN VIEN VAN PHONG ---" << endl;
    cout << "So luong NVVP: "; cin >> soLuongVP;
    for (int i = 0; i < soLuongVP; i++) {
        if (soLuong >= MAX) {
            cout << "Mang da day, khong the them!" << endl;
            break;
        }
        cout << "\nNhan vien van phong thu " << i + 1 << ":" << endl;
        danhSach[soLuong] = new NhanVienVanPhong();
        danhSach[soLuong]->Nhap();
        soLuong++;
    }

    // 2. Tính lương cho từng nhân viên
    for (int i = 0; i < soLuong; i++) {
        danhSach[i]->TinhLuong();
    }

    // 3. Xuất thông tin danh sách
    cout << "\n--- DANH SACH NHAN VIEN ---" << endl;
    double tongLuong = 0;
    for (int i = 0; i < soLuong; i++) {
        danhSach[i]->Xuat();
        tongLuong += danhSach[i]->GetLuong();
    }

    // 4. Tính tổng lương
    cout << "\nTong luong cong ty phai tra: " << tongLuong << " VND" << endl;

    // 5. Tìm NV Sản Xuất lương thấp nhất
    double minLuongSX = -1;
    NhanVien* nvSXMin = nullptr;
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i]->LoaiNhanVien() == 1) { // Là NVSX
            if (minLuongSX == -1 || danhSach[i]->GetLuong() < minLuongSX) {
                minLuongSX = danhSach[i]->GetLuong();
                nvSXMin = danhSach[i];
            }
        }
    }

    if (nvSXMin != nullptr) {
        cout << "\nNhan vien san xuat co luong thap nhat: " << endl;
        nvSXMin->Xuat();
    }

    // 6. Tìm NV Văn Phòng lớn tuổi nhất
    int maxTuoiVP = -1;
    NhanVien* nvVPMaxTuoi = nullptr;
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i]->LoaiNhanVien() == 2) { // Là NVVP
            if (maxTuoiVP == -1 || danhSach[i]->GetTuoi() > maxTuoiVP) {
                maxTuoiVP = danhSach[i]->GetTuoi();
                nvVPMaxTuoi = danhSach[i];
            }
        }
    }

    if (nvVPMaxTuoi != nullptr) {
        cout << "\nNhan vien van phong co tuoi cao nhat (" << maxTuoiVP << " tuoi): " << endl;
        nvVPMaxTuoi->Xuat();
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < soLuong; i++) {
        delete danhSach[i];
    }

    return 0;
}