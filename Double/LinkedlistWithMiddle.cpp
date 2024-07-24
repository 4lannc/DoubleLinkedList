#include <iostream>

using namespace std;

struct PlaylistLagu
{
    string judul, pengarang;
    float durasi;

    PlaylistLagu *next;
};

PlaylistLagu *kepala, *buntut, *ini, *nodeBaru, *hapus;

void ngisiLinkedlist (string judul, string pengarang, float durasi) {
    kepala = new PlaylistLagu();
    kepala->judul = judul;
    kepala->pengarang = pengarang;
    kepala->durasi = durasi;
    kepala->next = NULL;
    buntut = kepala;    
}

void tambahAwal (string judul, string pengarang, float durasi) {
    nodeBaru = new PlaylistLagu();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->durasi = durasi;
    nodeBaru->next = kepala;
    kepala = nodeBaru;
}

void tambahahir (string judul, string pengarang, float durasi) {
    nodeBaru = new PlaylistLagu();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->durasi = durasi;
    nodeBaru->next = NULL;
    buntut->next = nodeBaru;
    buntut = nodeBaru;
}
// Tambah tengah single list

void tambahtengah (string judul, string pengarang, float durasi,float posisi) {
    nodeBaru = new PlaylistLagu();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->durasi = durasi;
    
    //transversing
    ini = kepala;
    float nomer = 1;
    while(nomer < posisi - 1){
        ini = ini->next;
        nomer++;
    }
    nodeBaru->next = ini->next;
    ini->next = nodeBaru;
}

void ubahAwal(string judul, string pengarang, float durasi){
    kepala->judul = judul;
    kepala->pengarang = pengarang;
    kepala->durasi = durasi;
}


void ubahLast(string judul, string pengarang, float durasi){
    buntut->judul = judul;
    buntut->pengarang = pengarang;
    buntut->durasi = durasi;
}

void hapusAwal () {
    hapus = kepala;
    kepala = kepala->next;
    delete hapus;
}

void hapusLast () {
    hapus = buntut;
    ini = kepala;
    while (ini->next != buntut)
    {
        ini = ini->next;
    }
    buntut = ini;
    buntut->next = NULL;
    delete hapus;  
}

void cetakLinkedlist(){
    ini = kepala;
    while (ini != NULL)
    {
        cout << "Judul Lagu : " << ini->judul << endl;
        cout << "Artis Lagu : " << ini->pengarang << endl;
        cout << "Durasi Lagu : " << ini->durasi << endl;
        cout << endl;
    ini = ini->next;
    }
    
}

int main () {
 ngisiLinkedlist("Sepinya Malam", "Divarina indra", 04.00);
 tambahAwal("Kerinduan", "Yeni Inka", 05.22);
 tambahahir("Kemesraan", "Adinda Rahel", 06.22);
 tambahtengah("Tresno Waranggono","Jokowi", 03.44, 2);

 hapusAwal();

 hapusLast();


 ubahAwal("Mengejar Badai", "Arneta Julia", 05.21);
 ubahLast("Bahtera Cinta", "Dinda Teratu", 03.45);
 cetakLinkedlist();

 return 0;
}