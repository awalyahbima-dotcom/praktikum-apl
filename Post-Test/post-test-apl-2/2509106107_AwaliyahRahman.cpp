#include <iostream>
using namespace std;

struct DetailMobil{
    string brand;
    string model;
};

struct DataKendaraan{
    string plat;
    int tahun;
    DetailMobil info;
};

struct AkunUser{
    string namaUser;
    string sandiUser;
};

AkunUser daftarUser[50];
DataKendaraan daftarMobil[50];

int totalUser=0;
int totalMobil=0;

bool cekLogin(string nama,string nim){

    for(int i=0;i<totalUser;i++){
        if(nama==daftarUser[i].namaUser && nim==daftarUser[i].sandiUser){
            return true;
        }
    }

    return false;
}

int main(){

    int menuLogin;

    do{

        cout<<"\n=== SISTEM LOGIN ===\n";
        cout<<"1 Register\n";
        cout<<"2 Login\n";
        cout<<"3 Keluar\n";
        cout<<"Pilih : ";
        cin>>menuLogin;

        if(menuLogin==1){

            cout<<"Nama : ";
            cin>>daftarUser[totalUser].namaUser;

            cout<<"NIM  : ";
            cin>>daftarUser[totalUser].sandiUser;

            totalUser++;

            cout<<"Akun berhasil dibuat\n";
        }

        else if(menuLogin==2){

            string nama,nim;
            int kesempatan=0;

            while(kesempatan<3){

                cout<<"Nama : ";
                cin>>nama;

                cout<<"NIM  : ";
                cin>>nim;

                if(cekLogin(nama,nim)){

                    cout<<"Login berhasil\n";

                    int menu;

                    do{

                        cout<<"\n=== MENU DATA KENDARAAN ===\n";
                        cout<<"1 Tambah\n";
                        cout<<"2 Lihat\n";
                        cout<<"3 Update\n";
                        cout<<"4 Hapus\n";
                        cout<<"5 Keluar\n";
                        cout<<"Pilih : ";
                        cin>>menu;

                        if(menu==1){

                            cout<<"Plat : ";
                            cin>>daftarMobil[totalMobil].plat;

                            cout<<"Merk : ";
                            cin>>daftarMobil[totalMobil].info.brand;

                            cout<<"Tipe : ";
                            cin>>daftarMobil[totalMobil].info.model;

                            cout<<"Tahun: ";
                            cin>>daftarMobil[totalMobil].tahun;

                            totalMobil++;

                        }

                        else if(menu==2){

                            if(totalMobil==0){
                                cout<<"Data belum ada\n";
                            }

                            else{

                                cout<<"\nNo Plat Merk Tipe Tahun\n";

                                for(int i=0;i<totalMobil;i++){

                                    cout<<i+1<<" "
                                        <<daftarMobil[i].plat<<" "
                                        <<daftarMobil[i].info.brand<<" "
                                        <<daftarMobil[i].info.model<<" "
                                        <<daftarMobil[i].tahun<<endl;
                                }
                            }
                        }

                        else if(menu==3){

                            int nomor;

                            cout<<"Nomor data : ";
                            cin>>nomor;

                            nomor--;

                            cout<<"Plat baru : ";
                            cin>>daftarMobil[nomor].plat;

                            cout<<"Merk baru : ";
                            cin>>daftarMobil[nomor].info.brand;

                            cout<<"Tipe baru : ";
                            cin>>daftarMobil[nomor].info.model;

                            cout<<"Tahun baru: ";
                            cin>>daftarMobil[nomor].tahun;

                        }

                        else if(menu==4){

                            int nomor;

                            cout<<"Nomor data : ";
                            cin>>nomor;

                            nomor--;

                            for(int i=nomor;i<totalMobil-1;i++){
                                daftarMobil[i]=daftarMobil[i+1];
                            }

                            totalMobil--;
                        }

                    }while(menu!=5);

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

    }while(menuLogin!=3);

}