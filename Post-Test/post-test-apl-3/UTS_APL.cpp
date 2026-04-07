#include <iostream>
#include <cmath>
using namespace std;

struct Buku {
    string kode, judul, penulis;
};

Buku buku[100];
int jumlah = 0;

void tampil() {
    if (jumlah == 0) {
        cout << "Data kosong\n";
        return;
    }
    for (int i = 0; i < jumlah; i++) {
        cout << i << ". " << buku[i].kode << " - " << buku[i].judul << " - " << buku[i].penulis << endl;
    }
}

void tambah() {
    if (jumlah >= 100) {
        cout << "Data penuh!\n";
        return;
    }

    cout << "Kode: "; cin >> buku[jumlah].kode;
    cin.ignore();
    cout << "Judul: "; getline(cin, buku[jumlah].judul);
    cout << "Penulis: "; getline(cin, buku[jumlah].penulis);
    jumlah++;
}

void bubble() {
    for (int i = 0; i < jumlah; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (buku[j].judul > buku[j + 1].judul) {
                swap(buku[j], buku[j + 1]);
            }
        }
    }
}

void selection() {
    for (int i = 0; i < jumlah; i++) {
        int idx = i;
        for (int j = i + 1; j < jumlah; j++) {
            if (buku[j].judul < buku[idx].judul) {
                idx = j;
            }
        }
        swap(buku[i], buku[idx]);
    }
}

void insertion() {
    for (int i = 1; i < jumlah; i++) {
        Buku temp = buku[i];
        int j = i - 1;
        while (j >= 0 && temp.judul < buku[j].judul) {
            buku[j + 1] = buku[j];
            j--;
        }
        buku[j + 1] = temp;
    }
}

int sequential(string key) {
    for (int i = 0; i < jumlah; i++) {
        if (buku[i].judul == key) return i;
    }
    return -1;
}

int binary(string key) {
    int kiri = 0, kanan = jumlah - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (buku[tengah].judul == key) return tengah;
        else if (buku[tengah].judul < key) kiri = tengah + 1;
        else kanan = tengah - 1;
    }
    return -1;
}

int jump(string key) {
    int langkah = sqrt(jumlah);
    int prev = 0;

    while (buku[min(langkah, jumlah) - 1].judul < key) {
        prev = langkah;
        langkah += sqrt(jumlah);
        if (prev >= jumlah) return -1;
    }

    for (int i = prev; i < min(langkah, jumlah); i++) {
        if (buku[i].judul == key) return i;
    }
    return -1;
}

int fibonacci(string key) {
    int fib2 = 0, fib1 = 1, fib = fib1 + fib2;

    while (fib < jumlah) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    while (fib > 1) {
        int i = min(offset + fib2, jumlah - 1);

        if (buku[i].judul < key) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if (buku[i].judul > key) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else return i;
    }

    if (fib1 && offset + 1 < jumlah && buku[offset + 1].judul == key)
        return offset + 1;

    return -1;
}

int main() {
    int pilih;
    string cari;

    do {
        cout << "\n=== SISTEM DATA BUKU ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampil Data\n";
        cout << "3. Bubble Sort\n";
        cout << "4. Selection Sort\n";
        cout << "5. Insertion Sort\n";
        cout << "6. Sequential Search\n";
        cout << "7. Binary Search\n";
        cout << "8. Jump Search\n";
        cout << "9. Fibonacci Search\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) tambah();
        else if (pilih == 2) tampil();
        else if (pilih == 3) {
            bubble();
            cout << "Data sudah diurutkan (Bubble)\n";
        }
        else if (pilih == 4) {
            selection();
            cout << "Data sudah diurutkan (Selection)\n";
        }
        else if (pilih == 5) {
            insertion();
            cout << "Data sudah diurutkan (Insertion)\n";
        }
        else if (pilih >= 6 && pilih <= 9) {
            cout << "Cari Judul: ";
            getline(cin, cari);

            int hasil = -1;

            if (pilih == 6) hasil = sequential(cari);
            else if (pilih == 7) hasil = binary(cari);
            else if (pilih == 8) hasil = jump(cari);
            else if (pilih == 9) hasil = fibonacci(cari);

            if (hasil != -1)
                cout << "Ditemukan di index: " << hasil << endl;
            else
                cout << "Tidak ditemukan\n";
        }

    } while (pilih != 0);

    return 0;
}