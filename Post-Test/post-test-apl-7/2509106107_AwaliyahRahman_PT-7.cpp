#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>

using namespace std;

struct Info {
    string merkMobil;
    string tipeMobil;
};

struct Kendaraan {
    string noPlat;
    int tahunMobil;
    Info dataMobil;
};

struct Akun {
    string namaUser;
    string nimUser;
};

Akun akunData[50];
Kendaraan mobilData[50];
int jumlahUser = 0;
int jumlahData = 0;

void bersihkanInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool cekUser(string x, string y, Akun *a, int n) {
    for (int i = 0; i < n; i++) {
        if (x == a[i].namaUser && y == a[i].nimUser) return true;
    }
    return false;
}

void sortTahunAsc(Kendaraan *k, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (k[i].tahunMobil > k[j].tahunMobil) swap(k[i], k[j]);
        }
    }
}

void inputMobil(Kendaraan *k, int *n) {
    if (*n >= 50) throw runtime_error("Kapasitas penuh!");

    cout << "Plat : "; cin >> k[*n].noPlat;
    cout << "Merk : "; cin >> k[*n].dataMobil.merkMobil;
    cout << "Tipe : "; cin >> k[*n].dataMobil.tipeMobil;
    cout << "Tahun: "; 
    if (!(cin >> k[*n].tahunMobil)) {
        bersihkanInput();
        throw runtime_error("Input tahun harus angka!");
    }
    
    if (k[*n].tahunMobil < 1886 || k[*n].tahunMobil > 2026) {
        throw runtime_error("Tahun tidak valid!");
    }

    (*n)++;
    sortTahunAsc(k, *n);
}

void tampilMobil(Kendaraan *k, int i, int n) {
    if (i == n) return;
    cout << i + 1 << ". [" << k[i].noPlat << "] " << k[i].dataMobil.merkMobil 
         << " " << k[i].dataMobil.tipeMobil << " (" << k[i].tahunMobil << ")" << endl;
    tampilMobil(k, i + 1, n);
}

void ubahMobil(Kendaraan *k, int n) {
    int pilih;
    cout << "\nNomor yang ingin diubah: ";
    if (!(cin >> pilih)) {
        bersihkanInput();
        throw runtime_error("Input harus angka!");
    }
    
    if (pilih < 1 || pilih > n) throw runtime_error("Nomor salah!");
    pilih--;

    cout << "Plat Baru : "; cin >> k[pilih].noPlat;
    cout << "Merk Baru : "; cin >> k[pilih].dataMobil.merkMobil;
    cout << "Tipe Baru : "; cin >> k[pilih].dataMobil.tipeMobil;
    cout << "Tahun Baru: "; cin >> k[pilih].tahunMobil;
    
    sortTahunAsc(k, n);
}

void hapusMobil(Kendaraan *k, int *n) {
    int pilih;
    cout << "\nNomor yang ingin dihapus: ";
    if (!(cin >> pilih)) {
        bersihkanInput();
        throw runtime_error("Input harus angka!");
    }
    
    if (pilih < 1 || pilih > *n) throw runtime_error("Nomor salah!");
    pilih--;

    for (int i = pilih; i < (*n) - 1; i++) {
        k[i] = k[i + 1];
    }
    (*n)--;
}

int cariMobil(Kendaraan *k, int n, string plat) {
    for (int i = 0; i < n; i++) {
        if (k[i].noPlat == plat) return i;
    }
    return -1;
}

int cariMobilTahun(Kendaraan *k, int n, int tahun) {
    int kiri = 0, kanan = n - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (k[tengah].tahunMobil == tahun) return tengah;
        else if (k[tengah].tahunMobil < tahun) kiri = tengah + 1;
        else kanan = tengah - 1;
    }
    return -1;
}

int main() {
    int menuAwal;

    do {
        cout << "\n=== MENU UTAMA ===\n1. Daftar\n2. Login\n3. Keluar\nPilih: ";
        if (!(cin >> menuAwal)) {
            bersihkanInput();
            continue;
        }

        try {
            if (menuAwal == 1) {
                cout << "Nama: "; cin >> akunData[jumlahUser].namaUser;
                cout << "NIM : "; cin >> akunData[jumlahUser].nimUser;
                jumlahUser++;
                cout << "Berhasil dibuat!\n";
            } 
            else if (menuAwal == 2) {
                string nm, ni;
                int coba = 0;
                while (coba < 3) {
                    cout << "Nama: "; cin >> nm;
                    cout << "NIM : "; cin >> ni;

                    if (cekUser(nm, ni, akunData, jumlahUser)) {
                        int menu;
                        do {
                            cout << "\n=== MENU KENDARAAN ===\n1. Tambah\n2. Lihat\n3. Ubah\n4. Hapus\n5. Cari Plat\n6. Cari Tahun\n7. Keluar\nPilih: ";
                            if (!(cin >> menu)) {
                                bersihkanInput();
                                cout << "Pilih angka 1-7!\n";
                                continue;
                            }

                            try {
                                if (menu == 1) inputMobil(mobilData, &jumlahData);
                                else if (menu >= 2 && menu <= 6) {
                                    if (jumlahData == 0) throw runtime_error("Data masih kosong!");
                                    if (menu == 2) tampilMobil(mobilData, 0, jumlahData);
                                    else if (menu == 3) {
                                        tampilMobil(mobilData, 0, jumlahData);
                                        ubahMobil(mobilData, jumlahData);
                                    }
                                    else if (menu == 4) {
                                        tampilMobil(mobilData, 0, jumlahData);
                                        hapusMobil(mobilData, &jumlahData);
                                    }
                                    else if (menu == 5) {
                                        string p; cout << "Cari Plat: "; cin >> p;
                                        int h = cariMobil(mobilData, jumlahData, p);
                                        if (h != -1) cout << "Ketemu di nomor " << h + 1 << endl;
                                        else cout << "Tidak ada.\n";
                                    }
                                    else if (menu == 6) {
                                        int t; cout << "Cari Tahun: "; cin >> t;
                                        int h = cariMobilTahun(mobilData, jumlahData, t);
                                        if (h != -1) cout << "Ketemu di nomor " << h + 1 << endl;
                                        else cout << "Tidak ada.\n";
                                    }
                                }
                            } catch (const exception& e) {
                                cout << "Pesan: " << e.what() << endl;
                            }
                        } while (menu != 7);
                        break;
                    } else {
                        cout << "Gagal login.\n";
                        coba++;
                    }
                }
                if (coba == 3) return 0;
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    } while (menuAwal != 3);

    return 0;
}