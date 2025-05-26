/**
 * Project Class-Diagram-Progdas
 */


#ifndef _ITEM_H
#define _ITEM_H

class Item {
public: 
    
/**
 * @param kode
 * @param nama
 * @param jumlah
 */
void Item(string kode, string nama, int jumlah);
    
string getKode();
    
string getNama();
    
int getJumlah();
    
/**
 * @param namaBaru
 */
void setNama(string namaBaru);
    
/**
 * @param jumlahBaru
 */
void setJumlah(int jumlahBaru);
    
/**
 * @param kodeBaru
 */
void setKode(string kodeBaru);
    
void display();
private: 
    string kode;
    string nama;
    int jumlah;
};

#endif //_ITEM_H