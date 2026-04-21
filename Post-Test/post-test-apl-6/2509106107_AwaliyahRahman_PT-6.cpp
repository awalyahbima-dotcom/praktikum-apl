#include <iostream>
using namespace std;

struct Info{
    string merkMobil;
    string tipeMobil;
};

struct Kendaraan{
    string noPlat;
    int tahunMobil;
    Info dataMobil;
};

struct Akun{
    string namaUser;
    string nimUser;
};

Akun akunData[50];
Kendaraan mobilData[50];

int jumlahUser=0;
int jumlahData=0;

bool cekUser(string x,string y,Akun *a,int n){
    for(int i=0;i<n;i++){
        if(x==a[i].namaUser && y==a[i].nimUser){
            return true;
        }
    }
    return false;
}

void inputMobil(Kendaraan *k,int *n){
    cout<<"Plat : ";
    cin>>k[*n].noPlat;

    cout<<"Merk : ";
    cin>>k[*n].dataMobil.merkMobil;

    cout<<"Tipe : ";
    cin>>k[*n].dataMobil.tipeMobil;

    cout<<"Tahun: ";
    cin>>k[*n].tahunMobil;

    (*n)++;
}

void tampilMobil(Kendaraan *k,int i,int n){
    if(i==n) return;

    cout<<i+1<<" "
        <<k[i].noPlat<<" "
        <<k[i].dataMobil.merkMobil<<" "
        <<k[i].dataMobil.tipeMobil<<" "
        <<k[i].tahunMobil<<endl;

    tampilMobil(k,i+1,n);
}

void ubahMobil(Kendaraan *k,int n){
    int pilih;

    cout<<"\nNomor yang ingin diubah: ";
    cin>>pilih;
    pilih--;

    cout<<"Plat : ";
    cin>>k[pilih].noPlat;

    cout<<"Merk : ";
    cin>>k[pilih].dataMobil.merkMobil;

    cout<<"Tipe : ";
    cin>>k[pilih].dataMobil.tipeMobil;

    cout<<"Tahun: ";
    cin>>k[pilih].tahunMobil;
}

void hapusMobil(Kendaraan *k,int *n){
    int pilih;

    cout<<"\nNomor yang ingin dihapus: ";
    cin>>pilih;
    pilih--;

    for(int i=pilih;i<(*n)-1;i++){
        k[i]=k[i+1];
    }

    (*n)--;
    cout << "Data berhasil dihapus.\n";
}

int cariMobil(Kendaraan *k,int n,string plat){
    for(int i=0;i<n;i++){
        if(k[i].noPlat==plat){
            return i;
        }
    }
    return -1;
}

void sortTahunAsc(Kendaraan *k, int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(k[i].tahunMobil > k[j].tahunMobil){
                swap(k[i], k[j]);
            }
        }
    }
}

int cariMobilTahun(Kendaraan *k, int n, int tahun){
    int kiri = 0, kanan = n - 1;

    while(kiri <= kanan){
        int tengah = (kiri + kanan) / 2;

        if(k[tengah].tahunMobil == tahun){
            return tengah;
        }
        else if(k[tengah].tahunMobil < tahun){
            kiri = tengah + 1;
        }
        else{
            kanan = tengah - 1;
        }
    }
    return -1;
}

int main(){

    int menuAwal;

    do{
        cout<<"\n=== Menu Akun ===\n";
        cout<<"1 Daftar\n";
        cout<<"2 Login\n";
        cout<<"3 Keluar\n";
        cout<<"Pilih : ";
        cin>>menuAwal;

        if(menuAwal==1){
            cout<<"Nama : ";
            cin>>akunData[jumlahUser].namaUser;

            cout<<"NIM  : ";
            cin>>akunData[jumlahUser].nimUser;

            jumlahUser++;
            cout<<"Akun berhasil dibuat\n";
        }

        else if(menuAwal==2){

            string nama,nim;
            int kesempatan=0;

            while(kesempatan<3){

                cout<<"Nama : ";
                cin>>nama;

                cout<<"NIM  : ";
                cin>>nim;

                if(cekUser(nama,nim,akunData,jumlahUser)){

                    int menu;

                    do{
                        cout<<"\n=== Menu Kendaraan ===\n";
                        cout<<"1 Tambah\n";
                        cout<<"2 Lihat\n";
                        cout<<"3 Ubah\n";
                        cout<<"4 Hapus\n";
                        cout<<"5 Cari Plat (Linear)\n";
                        cout<<"6 Cari Tahun (Binary)\n";
                        cout<<"7 Keluar\n";
                        cout<<"Pilih : ";
                        cin>>menu;

                        if(menu==1){
                            inputMobil(mobilData,&jumlahData);
                        }

                        else if(menu==2){
                            if(jumlahData==0){
                                cout<<"\nTidak ada data yang tersedia\n";
                            }
                            else{
                                cout<<"\n--- Daftar Kendaraan ---\n";
                                cout<<"No Plat Merk Tipe Tahun\n";
                                tampilMobil(mobilData,0,jumlahData);
                            }
                        }

                        else if(menu==3){
                            if(jumlahData==0){
                                cout<<"\nTidak ada data yang tersedia\n";
                            }
                            else{
                                cout<<"\n--- Daftar Kendaraan ---\n";
                                cout<<"No Plat Merk Tipe Tahun\n";
                                tampilMobil(mobilData,0,jumlahData);
                                ubahMobil(mobilData,jumlahData);
                            }
                        }

                        else if(menu==4){
                            if(jumlahData==0){
                                cout<<"\nTidak ada data yang tersedia\n";
                            }
                            else{
                                cout<<"\n--- Daftar Kendaraan ---\n";
                                cout<<"No Plat Merk Tipe Tahun\n";
                                tampilMobil(mobilData,0,jumlahData);
                                hapusMobil(mobilData,&jumlahData);
                            }
                        }

                        else if(menu==5){
                            if(jumlahData==0){
                                cout<<"\nTidak ada data yang tersedia\n";
                            }
                            else{
                                cout<<"\n--- Daftar Kendaraan ---\n";
                                cout<<"No Plat Merk Tipe Tahun\n";
                                tampilMobil(mobilData,0,jumlahData);
                                
                                string cari;
                                cout<<"\nMasukkan Plat yang dicari: ";
                                cin>>cari;

                                int hasil=cariMobil(mobilData,jumlahData,cari);

                                if(hasil!=-1)
                                    cout<<"Data ditemukan di nomor ("<< hasil + 1 <<")\n";
                                else
                                    cout<<"Data tidak ada\n";
                            }
                        }

                        else if(menu==6){
                            if(jumlahData==0){
                                cout<<"\nTidak ada data yang tersedia\n";
                            }
                            else{
                                // Melakukan sorting sebelum menampilkan data agar nomor urut layar sesuai dengan memori
                                sortTahunAsc(mobilData, jumlahData);

                                cout<<"\n--- Daftar Kendaraan ---\n";
                                cout<<"No Plat Merk Tipe Tahun\n";
                                tampilMobil(mobilData,0,jumlahData);

                                int tahun;
                                cout<<"\nMasukkan Tahun yang dicari: ";
                                cin>>tahun;

                                int hasil=cariMobilTahun(mobilData,jumlahData,tahun);

                                if(hasil!=-1)
                                    cout<<"Data ditemukan di nomor (" << hasil + 1 <<")\n";
                                else
                                    cout<<"Data tidak ada\n";
                            }
                        }

                    }while(menu!=7);

                    break; 
                }

                else{
                    cout<<"Login gagal\n";
                    kesempatan++;
                }
            }

            if(kesempatan==3){
                cout<<"Kesempatan login habis\n";
                return 0;
            }
        }

    }while(menuAwal!=3);

    return 0;
}