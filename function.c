#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Wajib banget lu tulis ini buat fungsi memset!
#include "header.h"

int main() {
    // 1. Suruh si Tukang Struktur kerja (baca file data.txt)
    if (readInput() == 0) {
        return 1; 
    }

    // 2. Siapkan tempat buat nyimpen data batu (Biar gak ribet, kita pake array 2D aja)
    memset(catatan, -1, sizeof(catatan));

    int max_tabrakan = 0;

    for (int kolom = 1; kolom <= H; kolom++) {
        
        // Tetesin air dari baris 0 (di atas langit-langit tebing)
        int hasil_sekarang = hitung_total_tabrakan(0, kolom, V, H, batu);

        // Cari tabrakan yang paling banyak dari semua kolom
        if (hasil_sekarang > max_tabrakan) {
            max_tabrakan = hasil_sekarang;
        }
    }

    // 4. Print hasilnya
    printf("%d\n", max_tabrakan);

    // 5. Jangan lupa pungutin sampah memori!
    free(batu);

    return 0;
}
