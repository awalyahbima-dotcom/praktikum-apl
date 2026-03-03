#include <iostream>
using namespace std;

int main() {
    string Nama;
    string Password;
    int kesempatan = 0;
    bool loginBerhasil = false;

    while (kesempatan < 3) {
        cout << "Masukkan Nama: ";
        cin >> Nama;

        cout << "Masukkan Password (3 digit NIM terakhir): ";
        cin >> Password;

        if (Nama == "Awaliyah" && Password == "107") {
            cout << "Login Berhasil!" << endl;
            loginBerhasil = true;
            break; 
        } else {
            cout << "Nama dan Password salah!" << endl;
            kesempatan++;
        }
    }

    if (!loginBerhasil) {
        cout << "Anda sudah salah 3 kali. Program berhenti." << endl;
        return 0;
    }

    int pilih;

    do {
        cout << "\n Menu \n";
        cout << "1. Jam -> Menit dan Detik\n";
        cout << "2. Menit -> Jam dan Detik\n";
        cout << "3. Detik -> Jam dan Menit\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (menu == 1) {
            int jam;
            cout << "Masukkan Jam: ";
            cin >> jam;

            cout << "Hasil: "
                 << jam * 60 << " Menit dan "
                 << jam * 3600 << " Detik\n";
        }
        else if (pilih == 2) {
            int menit;
            cout << "Masukkan Menit: ";
            cin >> menit;

            cout << "Hasil: "
                 << menit / 60 << " Jam dan "
                 << menit * 60 << " Detik\n";
        }
        else if (pilih == 3) {
            int detik;
            cout << "Masukkan Detik: ";
            cin >> detik;

            cout << "Hasil: "
                 << detik / 3600 << " Jam dan "
                 << detik / 60 << " Menit\n";
        }
        else if (pilih == 4) {
            cout << "Program selesai.\n";
        }
        else {
            cout << "Pilihan tidak tersedia.\n";
        }

    } while (pilih != 4);

    return 0;
}
