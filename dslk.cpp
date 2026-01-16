#include <iostream>
using namespace std;

const int SO_DINH = 11;

struct DanhSachKe {
    int dinhKe;
    DanhSachKe* tiepTheo;
};

DanhSachKe* dsKe[SO_DINH + 1];

void khoiTaoDanhSach() {
    for (int i = 1; i <= SO_DINH; i++) {
        dsKe[i] = NULL;
    }
}

void themDau(int dinh, int dinhKe) {
    DanhSachKe* p = new DanhSachKe;
    p->dinhKe = dinhKe;
    p->tiepTheo = dsKe[dinh];
    dsKe[dinh] = p;
}

void themCanhVoHuong(int u, int v) {
    themDau(u, v);
    themDau(v, u);
}

void inDanhSachKe() {
    cout << "Do thi dung danh sach lien ket" << endl;
    for (int i = 1; i <= SO_DINH; i++) {
        cout << "Dinh " << i << ": ";
        DanhSachKe* p = dsKe[i];
        if (p == NULL) {
            cout << "Khong co ket noi";
        }
        while (p != NULL) {
            cout << "-> " << p->dinhKe << " ";
            p = p->tiepTheo;
        }
        cout << endl;
    }
}

int main() {
    khoiTaoDanhSach();

    themCanhVoHuong(1, 2);
    themCanhVoHuong(1, 10);
    themCanhVoHuong(1, 9);
    themCanhVoHuong(1, 8);
    themCanhVoHuong(1, 7);
    themCanhVoHuong(1, 6);
    themCanhVoHuong(2, 11);
    themCanhVoHuong(11, 10);
    themCanhVoHuong(6, 5);
    themCanhVoHuong(5, 4);
    themCanhVoHuong(6, 4);
    themCanhVoHuong(4, 3);
    themCanhVoHuong(3, 2);

    inDanhSachKe();
    return 0;
}
