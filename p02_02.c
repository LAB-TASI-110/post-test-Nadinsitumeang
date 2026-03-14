#include <stdio.h>

int main() {
    int N;
    int i;
    int stok[100];
    char barang[100][50];

    printf("Masukkan jumlah data: ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        printf("Masukkan nama barang ke-%d: ", i + 1);
        scanf(" %49s", barang[i]);   // spasi sebelum %s penting

        printf("Masukkan jumlah stok: ");
        scanf("%d", &stok[i]);
    }

    int naik = 1, turun = 1;

    for (i = 0; i < N - 1; i++) {
        if (stok[i] > stok[i + 1]) naik = 0;
        if (stok[i] < stok[i + 1]) turun = 0;
    }

    if (naik && !turun)
        printf("\nPola deret: MENINGKAT\n");
    else if (turun && !naik)
        printf("\nPola deret: MENURUN\n");
    else
        printf("\nPola deret: TIDAK BERATURAN\n");

    printf("\nData Barang:\n");
    for (i = 0; i < N; i++) {
        printf("%s : %d pcs\n", barang[i], stok[i]);
    }

    return 0;
}