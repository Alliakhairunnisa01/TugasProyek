#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;


struct Barang {
    string kode;
    string nama;
    string satuan;
    double hargaBeli;
    double hargaJual;
    int stokAwal;
    int terjual;
    int stokAkhir;
};

vector<Barang> daftarBarang;

int hitungStokAkhir(int stokAwal, int terjual) {
    return stokAwal - terjual;
}


void tambahBarang() {
    Barang barang;
    cout << "\nMasukkan Data Barang:\n";
    cout << "Kode Barang: ";
    cin >> barang.kode;
    cin.ignore(); 
    cout << "Nama Barang: ";
    getline(cin, barang.nama);
    cout << "Satuan: ";
    cin >> barang.satuan;
    
    cout << "Harga Beli: ";
    while (!(cin >> barang.hargaBeli)) {
        cout << "Input tidak valid! Masukkan angka: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Harga Jual: ";
    while (!(cin >> barang.hargaJual)) {
        cout << "Input tidak valid! Masukkan angka: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Stok Awal: ";
    while (!(cin >> barang.stokAwal)) {
        cout << "Input tidak valid! Masukkan angka: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Terjual: ";
    while (!(cin >> barang.terjual)) {
        cout << "Input tidak valid! Masukkan angka: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    barang.stokAkhir = hitungStokAkhir(barang.stokAwal, barang.terjual);
    daftarBarang.push_back(barang);
    cout << "\nBarang berhasil ditambahkan!\n";
}


void editBarang() {
    string kode;
    cout << "\nMasukkan Kode Barang yang akan diedit: ";
    cin >> kode;
    for (size_t i = 0; i < daftarBarang.size(); ++i) {
        if (daftarBarang[i].kode == kode) {
            Barang &barang = daftarBarang[i];
            cout << "\nData Barang Lama:\n";
            cout << "Nama Barang: " << barang.nama << "\n";
            cout << "Satuan: " << barang.satuan << "\n";
            cout << "Harga Beli: " << barang.hargaBeli << "\n";
            cout << "Harga Jual: " << barang.hargaJual << "\n";
            cout << "Stok Awal: " << barang.stokAwal << "\n";
            cout << "Terjual: " << barang.terjual << "\n";

            cout << "\nMasukkan Data Baru:\n";
            cin.ignore(); 
            cout << "Nama Barang: ";
            getline(cin, barang.nama);
            cout << "Satuan: ";
            cin >> barang.satuan;
            cout << "Harga Beli: ";
            while (!(cin >> barang.hargaBeli)) {
                cout << "Input tidak valid! Masukkan angka: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Harga Jual: ";
            while (!(cin >> barang.hargaJual)) {
                cout << "Input tidak valid! Masukkan angka: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Stok Awal: ";
            while (!(cin >> barang.stokAwal)) {
                cout << "Input tidak valid! Masukkan angka: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Terjual: ";
            while (!(cin >> barang.terjual)) {
                cout << "Input tidak valid! Masukkan angka: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            barang.stokAkhir = hitungStokAkhir(barang.stokAwal, barang.terjual);
            cout << "\nBarang berhasil diedit!\n";
            return;
        }
    }
    cout << "\nBarang dengan kode " << kode << " tidak ditemukan!\n";
}

void hapusBarang() {
    string kode;
    cout << "\nMasukkan Kode Barang yang akan dihapus: ";
    cin >> kode;
    for (size_t i = 0; i < daftarBarang.size(); ++i) {
        if (daftarBarang[i].kode == kode) {
            daftarBarang.erase(daftarBarang.begin() + i);
            cout << "\nBarang berhasil dihapus!\n";
            return;
        }
    }
    cout << "\nBarang dengan kode " << kode << " tidak ditemukan!\n";
}

void lihatBarang() {
    if (daftarBarang.empty()) {
        cout << "\nDaftar barang kosong!\n";
        return;
    }
    cout << "\nDaftar Barang:\n";
    cout << left << setw(10) << "Kode" << setw(20) << "Nama" << setw(10) << "Satuan" << setw(15) << "Harga Beli" << setw(15) << "Harga Jual" << setw(10) << "Stok Awal" << setw(10) << "Terjual" << setw(10) << "Stok Akhir" << "\n";
    cout << string(100, '-') << "\n";
    for (size_t i = 0; i < daftarBarang.size(); ++i) {
        const Barang &barang = daftarBarang[i];
        cout << left << setw(10) << barang.kode << setw(20) << barang.nama << setw(10) << barang.satuan << setw(15) << barang.hargaBeli << setw(15) << barang.hargaJual << setw(10) << barang.stokAwal << setw(10) << barang.terjual << setw(10) << barang.stokAkhir << "\n";
    }
}


void cetakBarang() {
    cout << "\nMencetak Daftar Barang:\n";
    lihatBarang();
    cout << "\nData berhasil dicetak ke layar!\n";
}

int main() {
    int pilihan;
    do {
        cout << "\nMenu CRUD Data Barang:\n";
        cout << "1. Tambah Data Barang\n";
        cout << "2. Edit Data Barang\n";
        cout << "3. Hapus Data Barang\n";
        cout << "4. Lihat Data Barang\n";
        cout << "5. Cetak Data Barang\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        while (!(cin >> pilihan)) {
            cout << "Input tidak valid! Masukkan angka: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (pilihan) {
            case 1:
                tambahBarang();
                break;
            case 2:
                editBarang();
                break;
            case 3:
                hapusBarang();
                break;
            case 4:
                lihatBarang();
                break;
            case 5:
                cetakBarang();
                break;
           case 6:
                cout << "\nKeluar dari program. Terima kasih!\n";
                break;
            default:
                cout << "\nPilihan tidak valid!\n";
        }
    } while (pilihan != 6);

    return 0; 
}
