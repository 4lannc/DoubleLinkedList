#include <iostream>

using namespace std;

struct lagu
{
    string judul, pengarang;
    float durasi;

    lagu *next;
};

lagu *kepala, *buntut, *ini, *nodeBaru, *hapus;

void ngisiLinkedlist (string judul, string pengarang, float durasi) {
    kepala = new lagu();
    kepala->judul = judul;
    kepala->pengarang = pengarang;
    kepala->durasi = durasi;
    kepala->next = NULL;
    buntut = kepala;    
}

void tambahAwal (string judul, string pengarang, float durasi) {
    nodeBaru = new lagu();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->durasi  = durasi;
    nodeBaru->next = kepala;
    kepala = nodeBaru;
}

void tambahAhir (string judul, string pengarang, float durasi ) {
    nodeBaru = new lagu();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->durasi = durasi;
    nodeBaru->next = NULL;
    buntut->next = nodeBaru;
    buntut = nodeBaru;
}

void ubahAwal(string judul, string pengarang, float durasi){
    kepala->judul = judul;
    kepala->pengarang = pengarang;
    kepala->durasi = durasi;
}
void ubahLast(string judul, string pengarang, float durasi  ){
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
 ngisiLinkedlist("argumentasi dimensi", "Gerry Mahesa", 04.45);
 tambahAwal("Mancing YUK", "doni salman", 03.55);
 tambahAhir("turu ahh", "yayan supratman", 05.20);
//  hapusAwal();
//  hapusLast();


 ubahAwal("Selendang Biru", "Cantika Devinca", 03.45);
 ubahLast("Hitam putih", "Bobon Santoso", 04.44);
//  hapusLast();
//  hapusAwal();

 cetakLinkedlist();

 return 0;
}