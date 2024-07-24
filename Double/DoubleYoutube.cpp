#include <iostream>

using namespace std;

struct Datauser{
    string nama,  username, email, password;
    Datauser *prev;//sebelumnya
    Datauser *next;//selanjutnya
};

Datauser *kepala, *buntut, *cur, *newnode, *del;


void doublelinkedlist( string data [4]){

    kepala = new Datauser();
    kepala -> nama = data[0];
    kepala -> username = data[1];
    kepala -> email = data[2];
    kepala -> password = data[3];
    kepala->prev = NULL;
    kepala->next = NULL;
    buntut = kepala;
}

//Penambah awalan
void addfirst( string data[4]){
if(kepala == NULL){
    cout << "double-link list belum dibuat";
}else{
        newnode = new Datauser();
        newnode -> nama = data[0];
        newnode -> username = data[1];
        newnode -> email = data[2];
        newnode -> password = data[3];
        newnode->prev = NULL;
        newnode->next = buntut; 
        kepala ->prev = newnode;
        kepala = newnode;
     }
}

//Penambahan node diakhir
void addlast( string data[4]){
if(kepala == NULL){
    cout << "double-link list belum dibuat";
}else{
        newnode = new Datauser();
        newnode -> nama = data[0];
        newnode -> username = data[1];
        newnode -> email = data[2];
        newnode -> password = data[3];
        newnode->prev = buntut;
        newnode->next = NULL; 
        buntut ->prev = newnode;
        buntut = newnode;
     }
}

//Hapusawal
void removefirst(){
    if(kepala == NULL){
    cout << "double-link list belum dibuat";
    }else{
        del = kepala;
        kepala = kepala->next;
        kepala->prev = NULL;
        delete del;
    }
}
//Hapusakhir
void removelast(){
    if(kepala == NULL){
    cout << "double-link list belum dibuat";
}else{
    del = buntut;
    buntut = buntut ->prev;
    buntut -> next = NULL;
    delete del;
    }
}


//Mencetak double linked list
void cetakdouble(){
if(kepala == NULL){
    cout << "double-link list belum dibuat";
}else{
    cout << "isi data : " << endl;
cur = kepala;
while (cur != NULL){
//print
            cout << "nama user : " << cur->nama << endl;
            cout << "username : " << cur->username <<endl;
            cout << "email user : " << cur->email << endl;
            cout << "password : " << cur->password << " \n"<< endl; 
            cur=cur->next;
        }
    }
}


int main(){
    string newData[4]= {"Muhammad Hafid Luthfi Maulana", "Luthfi", 
    "muhammadhafidluthfi@gmail.com","090909"};
    doublelinkedlist(newData);
    cetakdouble();

    string data2[4] = {"Alan", "4lannc",
    "Alannc@gmail.com", "0987654321"};
    addfirst( data2);
    cetakdouble();

    string data3[4] = {"Muhammad Ali Hasanudin", "Hasan",
    "Hasilkosan@gmail.com", "01010101"};
    addlast( data3);
    cetakdouble();


    removefirst();
    cetakdouble();

    removelast();
    cetakdouble();


}