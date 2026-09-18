#include <iostream>

int hitungPanjangString(const char teks[]) {
    int panjang = 0;
    while (teks[panjang] != '\0') {
        panjang++;
    }
    return panjang;
}

int main() {
    char pesan[1000];
    std::cout << "Masukkan pesan (huruf kapital tanpa spasi): ";
    std::cin >> pesan;

    int panjang = hitungPanjangString(pesan);
    if (panjang == 0) {
        return 0;
    }

    char hasil[1000];
    hasil[0] = pesan[0];

    for (int i = 1; i < panjang; i++) {
        int nilaiSekarang = pesan[i] - 'A' + 1;
        int nilaiSebelumnya = pesan[i - 1] - 'A' + 1;

        int nilaiBaru = nilaiSekarang + nilaiSebelumnya;
        if (nilaiBaru > 26) {
            nilaiBaru -= 26;
        }

        hasil[i] = (char)('A' + nilaiBaru - 1);
    }
    hasil[panjang] = '\0';

    std::cout << "Pesan terenkripsi: " << hasil << std::endl;

    return 0;
}