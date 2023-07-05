#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 50;

class Barang
{
private:
    struct Produk
    {
        char kode[10];
        char nama[30];
        int harga;
    } prod[MAX];

    int sum;

    void hapusData(int index)
    {
        for (int i = index; i < sum - 1; i++)
        {
            prod[i] = prod[i + 1];
        }
    }

public:
    Barang()
    {
        sum = 0;
    }

    void tambah()
    {
        cout << "Masukkan kode barang: ";
        cin >> prod[sum].kode;
        cout << "Masukkan nama barang: ";
        cin.ignore();
        cin.getline(prod[sum].nama, 30);
        cout << "Masukkan harga barang: ";
        cin >> prod[sum].harga;
        sum++;
    }

    void ubah(char *kode)
    {
        for (int i = 0; i < sum; i++)
        {
            if (strcmp(kode, prod[i].kode) == 0)
            {
                cout << "Masukkan kode barang baru: ";
                cin >> prod[i].kode;
                cout << "Masukkan nama barang baru: ";
                cin.ignore();
                cin.getline(prod[i].nama, 30);
                cout << "Masukkan harga barang baru: ";
                cin >> prod[i].harga;
                break;
            }
        }
    }

    void hapus(char *kode)
    {
        for (int i = 0; i < sum; i++)
        {
            if (strcmp(kode, prod[i].kode) == 0)
            {
                hapusData(i);
                sum--;
                cout << "Barang dengan kode " << kode << " telah dihapus." << endl;
                break;
            }
        }
    }

    void tampil()
    {
        if (sum == 0)
        {
            cout << "Tidak ada data barang." << endl;
        }
        else
        {
            cout << "Daftar Barang:" << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "No.  Kode Barang    Nama Barang         Harga" << endl;
            cout << "--------------------------------------------------" << endl;
            for (int i = 0; i < sum; i++)
            {
                cout << i + 1 << "    " << prod[i].kode << "         " << prod[i].nama << "     " << prod[i].harga << endl;
            }
            cout << "--------------------------------------------------" << endl;
        }
    }

    void tambahBarangKeAntrian(queue<int> &antrian, int index)
    {
        antrian.push(index);
    }

    void hapusBarangDariAntrian(queue<int> &antrian)
    {
        if (!antrian.empty())
        {
            int index = antrian.front();
            antrian.pop();
            hapusData(index);
            sum--;
            cout << "Barang dengan index " << index << " telah dihapus dari antrian." << endl;
        }
        else
        {
            cout << "Antrian kosong!" << endl;
        }
    }
};

int main()
{
    Barang item;
    int pilih;
    queue<int> antrian;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Ubah Barang\n";
        cout << "3. Hapus Barang\n";
        cout << "4. Tampil Barang\n";
        cout << "5. Tambah Barang ke Antrian\n";
        cout << "6. Hapus Barang dari Antrian\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            item.tambah();
            break;
        case 2:
            char kode[10];
            cout << "Masukkan kode barang yang ingin diubah: ";
            cin >> kode;
            item.ubah(kode);
            break;
        case 3:
            char kode_hapus[10];
            cout << "Masukkan kode barang yang ingin dihapus: ";
            cin >> kode_hapus;
            item.hapus(kode_hapus);
            break;
        case 4:
            item.tampil();
            break;
        case 5:
            int index_tambah;
            cout << "Masukkan index barang yang ingin ditambahkan ke antrian: ";
            cin >> index_tambah;
            item.tambahBarangKeAntrian(antrian, index_tambah - 1);
            break;
        case 6:
            item.hapusBarangDariAntrian(antrian);
            break;
        case 0:
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }
    } while (pilih != 0);

    return 0;
}
