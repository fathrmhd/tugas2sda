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
