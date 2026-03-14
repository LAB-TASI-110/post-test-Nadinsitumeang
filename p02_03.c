#include <stdio.h>
#include <string.h>

int main() {
    // Daftar menu
    char menu[6][30] = {
        "Nasi Goreng",
        "Mie Goreng",
        "Ayam Geprek",
        "Es Teh",
        "Jus Jeruk",
        "Air Mineral"
    };

    int harga[6] = {20000, 18000, 25000, 5000, 10000, 5000};

    char namaPembeli[50];
    int jumlahPesanan, pilihan, qty;
    int total = 0;
    int subtotal[50];
    int indexMenu[50];
    int jumlah[50];
    int bayar, diskon = 0;

    printf("===== KAFETARIA IT DEL =====\n");
    printf("Masukkan nama pembeli : ");
    fgets(namaPembeli, sizeof(namaPembeli), stdin);
    namaPembeli[strcspn(namaPembeli, "\n")] = 0;

    printf("\n--- DAFTAR MENU ---\n");
    for(int i = 0; i < 6; i++) {
        printf("%d. %-15s : Rp %d\n", i+1, menu[i], harga[i]);
    }

    printf("\nJumlah jenis menu yang dipesan : ");
    scanf("%d", &jumlahPesanan);

    for(int i = 0; i < jumlahPesanan; i++) {
        printf("\nPesanan ke-%d\n", i+1);
        printf("Pilih menu (1-6) : ");
        scanf("%d", &pilihan);
        printf("Jumlah           : ");
        scanf("%d", &qty);

        indexMenu[i] = pilihan - 1;
        jumlah[i] = qty;
        subtotal[i] = harga[indexMenu[i]] * qty;
        total += subtotal[i];
    }

    // Diskon
    if(total > 80000) {
        diskon = total * 0.10;
    }

    int totalAkhir = total - diskon;

    printf("\nMasukkan uang bayar : Rp ");
    scanf("%d", &bayar);

    int kembalian = bayar - totalAkhir;

    // STRUK BELANJA
    printf("\n\n========= STRUK BELANJA =========\n");
    printf("Nama Pembeli : %s\n", namaPembeli);
    printf("--------------------------------\n");

    for(int i = 0; i < jumlahPesanan; i++) {
        printf("%-15s x %d = Rp %d\n",
            menu[indexMenu[i]],
            jumlah[i],
            subtotal[i]);
    }

    printf("--------------------------------\n");
    printf("Total        : Rp %d\n", total);
    printf("Diskon       : Rp %d\n", diskon);
    printf("Total Akhir  : Rp %d\n", totalAkhir);
    printf("Bayar        : Rp %d\n", bayar);
    printf("Kembalian    : Rp %d\n", kembalian);
    printf("================================\n");
    printf("Terima kasih telah berbelanja!\n");

    return 0;
}