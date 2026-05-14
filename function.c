#include "header.h"

int readInput() {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("ERROR: File data.txt tidak ditemukan!\n");
        return 0;
    }

    fscanf(fp, "%d %d %d", &V, &H, &N);

    // alokasi memori sesuai N yang dibaca
    batu = (Batu *)malloc(N * sizeof(Batu));
    if (batu == NULL) {
        printf("ERROR: Gagal alokasi memori!\n");
        fclose(fp);
        return 0;
    }

    for (int i = 0; i < N; i++) {
        fscanf(fp, "%d %d %d %d",
               &batu[i].v1, &batu[i].h1,
               &batu[i].v2, &batu[i].h2);
    }

    fclose(fp);
    return 1;
}

int cek_tabrakan(int v, int h, Batu *batu){
    for(int i = 0; i < N; i++){
        if(v >= batu[i].v1 && v <= batu[i].v2 && h >= batu[i].h1 && h <= batu[i].h2){
            return i;
        }
    }
    return -1;
}

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

void reset_catatan(){
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 30; j++){
            catatan[i][j] = 1;
        }
    }
}