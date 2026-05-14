#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int h1, h2, v1, v2;
}Batu;

int V, H, N;

Batu *batu;
int catatan[30][30];

int readInput();
int cek_tabrakan(int v, int h, Batu *batu);
int hitung_total_tabrakan(int v, int h, int V_max, int H_max, Batu *daftar_batu)
