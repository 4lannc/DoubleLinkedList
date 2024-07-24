#include <iostream>
using namespace std;

// deklarasi 
struct DataUser{
  string nama, username, email, password;
  DataUser *prev;
  DataUser *next;
};

DataUser *kepala, *buntut, *cur, *newNode, *del, *afterNode;


// Create Double Linked List
void buatdoublelinklist( string data[4] ){
  kepala = new DataUser();
  kepala->nama = data[0];
  kepala->username = data[1];
  kepala->email = data[2];
  kepala->password = data[3];
  kepala->prev = NULL;
  kepala->next = NULL;
  buntut = kepala;
}


// hitung Double Linked List
int hitungDoubleLinkedList()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    cur = kepala;
    int jumlah = 0;
    while( cur != NULL ){
      jumlah++;      
      //step
      cur = cur->next;
    }
    return jumlah;
  }
}


// Add First
void addFirst( string data[4] ){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    newNode = new DataUser();
    newNode->nama = data[0];
    newNode->username = data[1];
    newNode->email = data[2];
    newNode->password = data[3];
    newNode->prev = NULL;
    newNode->next = kepala;
    kepala->prev = newNode;
    kepala = newNode;
  }
}

// Add Last
void addLast( string data[4] ){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat";
  }else{
    newNode = new DataUser();
    newNode->nama = data[0];
    newNode->username = data[1];
    newNode->email = data[2];
    newNode->password = data[3];
    newNode->prev = buntut;
    newNode->next = NULL;
    buntut->next = newNode;
    buntut = newNode;
  }
}

// Add Middle
void addmidle( string data[4], int posisi ){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{

    if( posisi == 1 ){
      cout << "Posisi 1 itu bukan posisi tengah!!!" << endl;
    }else if( posisi < 1 || posisi > hitungDoubleLinkedList() ){
      cout << "Posisi diluar jangkauan!" << endl;
    }else{
      newNode = new DataUser();
      newNode->nama = data[0];
      newNode->username = data[1];
      newNode->email = data[2];
      newNode->password = data[3];

      // tranversing
      cur = kepala;
      int nomor = 1;
      while( nomor <  posisi - 1){
        cur = cur->next;
        nomor++;
      }

      afterNode = cur->next;
      newNode->prev = cur;
      newNode->next = afterNode;
      cur->next = newNode;
      afterNode->prev = newNode;
    }

  }
}

// remove First
void removeFirst()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat";
  }else{
    del = kepala;
    kepala = kepala->next;
    kepala->prev = NULL;
    delete del;
  }
}



// remove Last
void removeLast()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat";
  }else{
    del = buntut;
    buntut = buntut->prev;
    buntut->next = NULL;
    delete del;
  }
}

// remove Middle
void removeMiddle(int posisi){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat";
  }else{
    if( posisi == 1 || posisi == hitungDoubleLinkedList() ){
      cout << "Posisi bukan posisi tegah!!" << endl;
    }else if( posisi < 1 || posisi > hitungDoubleLinkedList() ){
      cout << "Posisi diluar jangkauan!!" << endl;
    }else{
      int nomor = 1;
      cur = kepala;
      while( nomor < posisi - 1 ){
        cur = cur->next;
        nomor++;
      }
      del = cur->next;
      afterNode = del->next;
      cur->next = afterNode;
      afterNode->prev = cur;
      delete del;
    }
  }
}

// cetak Double Linked List
void cetakDoubleLinkedList()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    cout << "Jumlah Data : " << hitungDoubleLinkedList() << endl;
    cout << "Isi Data : " << endl;
    cur = kepala;
    while( cur != NULL ){
      // cetak
      cout << "Nama User : " << cur->nama << endl;
      cout << "Username User : " << cur->username << endl;
      cout << "Email User : " << cur->email << endl;
      cout << "Password User : " << cur->password << "\n" << endl;

      cur = cur->next;
    }
  }
}

int main(){

  string newData[4] = {"Aci Kreweng", "Ciweng", "ack123@gmail.com", "admin123"};
  buatdoublelinklist(newData);
  cetakDoubleLinkedList();
  string data2[4] = {"Ferdyansah Saputra", "Paidi", "BakoelGedang@gmail.com", "098098098"};

  addFirst( data2 );
  cetakDoubleLinkedList();

  string data3[4] = {"Bkent Cemek", "Cemek", "yooikuu@gmail.com", "takokdewe"};
  addLast( data3 );
  cetakDoubleLinkedList();

  string data4[4] = {"Huda Ban Dalam", "HBD", "maskulin@yahoo.com", "adambledek"};
  addmidle(data4, 3);
  cetakDoubleLinkedList();
  removeMiddle(2);
  cetakDoubleLinkedList();


}