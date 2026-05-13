#include "header.h"

//Untuk menyimpan hasil biar tidak menghitung ulang koordinat yang sama
int catatan[30][30];

int hitung_total_tabrakan(int v, int h, int V_max, int H_max, Batu *daftar_batu) {
    
    if (v > V_max || h < 1 || h > H_max) {
        return 0;
    }

    if (catatan[v][h] != -1) {
        return catatan[v][h];
    }

    int id_batu = cek_tabrakan(v, h, daftar_batu);

    if (id_batu != -1) {
        //Jika menabrak, air pecah ke sisi kiri (h1-1) dan kanan (h2+1)
        int kiri = hitung_total_tabrakan(v + 1, daftar_batu[id_batu].h1 - 1, V_max, H_max, daftar_batu);
        int kanan = hitung_total_tabrakan(v + 1, daftar_batu[id_batu].h2 + 1, V_max, H_max, daftar_batu);
        return catatan[v][h] = 1 + kiri + kanan;
    } else {
        //Jika tidak menabrak, air lanjut jatuh lurus ke bawah
        return catatan[v][h] = hitung_total_tabrakan(v + 1, h, V_max, H_max, daftar_batu);
    }
}