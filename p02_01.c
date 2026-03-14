#include <stdio.h>
#include <string.h>

int main() {
    char kodeKota[10];
    char namaKota[20];
    int tarif;
    float beratButet, beratUcok, totalBerat;
    float totalOngkir, diskon;
    int asuransi;

    printf("===== SISTEM PENGIRIMAN DEL EXPRESS =====\n\n");

    while (1) {
        printf("Masukkan kode kota (MDN/BLG/JKT/SBY atau END): ");
        scanf("%s", kodeKota);

        if (strcmp(kodeKota, "END") == 0) {
            printf("\nProgram dihentikan.\n");
            break;
        }

        printf("Masukkan berat paket Butet (kg): ");
        scanf("%f", &beratButet);

        /* Menentukan kota dan tarif */
        if (strcmp(kodeKota, "MDN") == 0) {
            strcpy(namaKota, "Medan");
            tarif = 8000;
            asuransi = 0;
        } else if (strcmp(kodeKota, "BLG") == 0) {
            strcpy(namaKota, "Balige");
            tarif = 5000;
            asuransi = 0;
        } else if (strcmp(kodeKota, "JKT") == 0) {
            strcpy(namaKota, "Jakarta");
            tarif = 12000;
            asuransi = 1;
        } else if (strcmp(kodeKota, "SBY") == 0) {
            strcpy(namaKota, "Surabaya");
            tarif = 13000;
            asuransi = 1;
        } else {
            printf("Kode kota tidak valid!\n\n");
            continue;
        }

        /* Perhitungan berat */
        beratUcok = 1.5 * beratButet;
        totalBerat = beratButet + beratUcok;

        /* Perhitungan ongkir */
        totalOngkir = totalBerat * tarif;

        /* Diskon */
        if (totalBerat > 10) {
            diskon = 0.10 * totalOngkir;
            totalOngkir -= diskon;
        } else {
            diskon = 0;
        }

        /* Output Struk */
        printf("\n===== STRUK PEMBAYARAN =====\n");
        printf("Kota Tujuan        : %s\n", namaKota);
        printf("Berat Butet        : %.2f kg\n", beratButet);
        printf("Berat Ucok         : %.2f kg\n", beratUcok);
        printf("Total Berat        : %.2f kg\n", totalBerat);
        printf("Total Ongkos Kirim : Rp %.2f\n", totalOngkir);

        if (diskon > 0)
            printf("Promo              : Diskon 10%%\n");
        else
            printf("Promo              : Tidak ada\n");

        if (asuransi)
            printf("Asuransi           : Gratis\n");
        else
            printf("Asuransi           : Tidak ada\n");

        printf("===========================\n\n");
    }

    return 0;
}