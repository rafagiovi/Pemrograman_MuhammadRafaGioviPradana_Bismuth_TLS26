#include <iostream>

int hitungPanjang(int n) {
    return n;
}

int main() {
    int n, k;
    std::cout << "Masukkan jumlah astronot (N): ";
    std::cin >> n;
    std::cout << "Masukkan nilai hitungan awal (K): ";
    std::cin >> k;

    if (n <= 0 || k <= 0) {
        std::cout << "Input tidak valid." << std::endl;
        return 0;
    }

    int astronot[1000];
    for (int i = 0; i < n; i++) {
        astronot[i] = i + 1;
    }

    int jumlahAktif = n;
    int indeksSekarang = 0;

    std::cout << "\nUrutan astronot yang tereliminasi:" << std::endl;

    while (jumlahAktif > 1) {
        indeksSekarang = (indeksSekarang + k - 1) % jumlahAktif;
        int tereliminasi = astronot[indeksSekarang];

        std::cout << "Astronot " << tereliminasi << " dieliminasi." << std::endl;

        for (int i = indeksSekarang; i < jumlahAktif - 1; i++) {
            astronot[i] = astronot[i + 1];
        }
        jumlahAktif--;

        if (tereliminasi % 2 == 0) {
            k += 2;
        } else {
            k -= 1;
        }

        if (k < 2) {
            k = 2;
        }
    }

    std::cout << "\nAstronot terakhir yang bertahan adalah: " << astronot[0] << std::endl;

    return 0;
}