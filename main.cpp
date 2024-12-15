#include <iostream>
#include <string>

using namespace std;

struct Pegawai {
    string NIK;
    string Nama;
    string Alamat;
    string Jabatan;
    int Gaji;
};

void tampil(Pegawai data[], int n) {
    cout << "NIK\tNama\tAlamat\t\tJabatan\tGaji" << endl;
    for (int i = 0; i < n; i++) {
        cout << data[i].NIK << "\t" << data[i].Nama << "\t" << data[i].Alamat << "\t"
             << data[i].Jabatan << "\t" << data[i].Gaji << endl;
    }
    cout << endl;
}

// Fungsi untuk mengurutkan data pegawai menggunakan bubble sort berdasarkan NIK
void bubbleSortNIK(Pegawai data[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j].NIK > data[j + 1].NIK) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

// Fungsi untuk mengurutkan data pegawai menggunakan selection sort berdasarkan Gaji
void selectionSortGaji(Pegawai data[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j].Gaji < data[min_idx].Gaji) {
                min_idx = j;
            }
        }
        swap(data[min_idx], data[i]);
    }
}

int main() {
    Pegawai dataPegawai[] = {
        {"12345", "Andi", "Jl. Mawar No. 1", "Manager", 10000000},
        {"67890", "Budi", "Jl. Melati No. 2", "Staff", 5000000},
        {"13579", "Cici", "Jl. Anggrek No. 3", "Supervisor", 7500000}
    };
    int n = sizeof(dataPegawai) / sizeof(dataPegawai[0]);

    cout << "Data Pegawai Sebelum Diurutkan:" << endl;
    tampil(dataPegawai, n);

    bubbleSortNIK(dataPegawai, n);
    cout << "Data Pegawai Setelah Diurutkan Berdasarkan NIK:" << endl;
    tampil(dataPegawai, n);

    selectionSortGaji(dataPegawai, n);
    cout << "Data Pegawai Setelah Diurutkan Berdasarkan Gaji:" << endl;
    tampil(dataPegawai, n);

    return 0;
}
