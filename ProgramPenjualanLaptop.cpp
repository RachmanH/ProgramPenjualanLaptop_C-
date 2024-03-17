#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib> // Untuk menggunakan system("cls")
                    // system("cls") berfungsi untuk menghapus layar konsole
                    // system ini saya gunakan agar menambah kenyamanan user

using namespace std;

class Laptop {
private:
    int id;
    string merek;
    string model;
    string spesifikasi;
    int harga;

public:
    Laptop(int _id, string _merek, string _model, string _spesifikasi, int _harga)
        : id(_id), merek(_merek), model(_model), spesifikasi(_spesifikasi), harga(_harga) {}

    int getId() const { return id; }
    string getMerek() const { return merek; }
    string getModel() const { return model; }
    string getSpesifikasi() const { return spesifikasi; }
    int getHarga() const { return harga; }


    // Fungsi Hitung Diskon
    // Hitung Diskon Tetap menggunakan If else agar lebih fleksibel
    // berbeda dengan switch case yang hanya bisa untuk nilai konstan
    double hitungDiskon() const {
        double diskon = 0.0;

        if (harga > 10000000) { // Diskon 20% untuk harga di atas 10 juta
            diskon = 0.20;
        } else if (harga > 7000000) { // Diskon 17% untuk harga di atas 7 juta
            diskon = 0.17;
        } else if (harga > 5000000) { // Diskon 13% untuk harga di atas 5 juta
            diskon = 0.13;
        } else if (harga > 4000000) { // Diskon 10% untuk harga di atas 4 juta
            diskon = 0.10;
        }

        return diskon;
    }

    // Fungsi Menghitung Harga Setelah Harga Diskon Ditentukan
    int hitungHargaSetelahDiskon() const {
        double diskon = hitungDiskon();
        int hargaSetelahDiskon = static_cast<int>(harga - (harga * diskon));

        // Memeriksa apakah digit terakhir dari harga adalah 9
        // Ex Error : ketika diskon 20 persen pada 10.000.000 maka akan jadi 8.079.999
        // ini merupakan sebuah kode untuk mengakali error tersebut
        if (hargaSetelahDiskon % 10 == 9) {
            hargaSetelahDiskon++; // Menambahkan 1 ke harga jika digit terakhir adalah 9
        }

        return hargaSetelahDiskon;
    }

    // Fungsi Menampilkan Info
    void tampilkanInfo() const {
        cout << "ID: " << id << endl;
        cout << "Merek      : " << merek << endl;
        cout << "Model      : " << model << endl;
        cout << "Spesifikasi: " << spesifikasi << endl;
        cout << "Harga      : Rp " << harga << endl;

        // Pada Penentuan Bonus dan Output penjelasan diskon saya menggunakan Switch Case
        // Tujuannya Agar tantangan dari agri bisa sedikit dipenuhi
        // Request dari Agriby Diandra Chaniago
        double diskon = hitungDiskon();
        cout << "Diskon     : ";
        switch (static_cast<int>(diskon * 100)) {
            case 20:
                cout << "20% untuk harga di atas 10 juta" << endl;
                cout << "Bonus      : Mouse & Keyboard Mechanical Gaming" << endl;
                break;
            case 17:
                cout << "17% untuk harga di atas 7 juta" << endl;
                cout << "Bonus      : Mouse & Keyboard Logitech Wireless" << endl;
                break;
            case 13:
                cout << "13% untuk harga di atas 5 juta" << endl;
                cout << "Bonus      : Mouse Wireless & Headphone" << endl;
                break;
            case 10:
                cout << "10% untuk harga di atas 4 juta" << endl;
                cout << "Bonus      : Mouse Wireless" << endl;
                break;
            default:
                cout << "Tidak ada diskon yang berlaku" << endl;
                cout << "Bonus      : Mouse Wired" << endl;
                break;
        }

        cout << "Total harga setelah diskon : Rp " << hitungHargaSetelahDiskon() << endl;
        cout << endl;
    }
};

class DaftarLaptop {
private:
    vector<Laptop> daftar;
    map<int, int> historyPembelian; // Menyimpan riwayat pembelian (ID Laptop, Jumlah)

public:
    void tambahLaptop(const Laptop& laptop) {
        daftar.push_back(laptop);
    }

    // Fungsi Login Admin
    // Request dari Agriby Diandra Chaniago
    bool loginAdmin() {
        string username, password;
        cout << "=== Selamat Datang di Program Toko Laptop ===" << endl;
        cout << "Silakan Masukkan Akun Admin Anda Untuk Masuk" << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;


        // Cek apakah username dan password sesuai dengan yang diharapkan untuk admin
        if (username == "admin" && password == "admin123") {
            cout << "Login berhasil! Selamat datang, " << username << "!" << endl;
            return true;
        } else {
            cout << "Username atau password admin salah. Silakan coba lagi." << endl;
            return false;
        }
    }

    // Fungsi Login User
    // Request dari Agriby Diandra Chaniago
    bool loginUser() {
        string username, password;
        cout << "=== Selamat Datang di Program Toko Laptop ===" << endl;
        cout << " Silakan Masukkan Akun User Anda Untuk Masuk" << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;


        // agri meminta di sediakan 3 akun sekaligus untuk login sebagai user
        // Request dari Agriby Diandra Chaniago
        if (username == "agri" && password == "agri123") {
        cout << "Login berhasil! Selamat datang, " << username << "!" << endl;    
        return true;
        } else if (username == "putra" && password == "putra123") {
        cout << "Login berhasil! Selamat datang, " << username << "!" << endl;
        return true;
        } else if (username == "tasya" && password == "tasya123") {
        cout << "Login berhasil! Selamat datang, " << username << "!" << endl;
        return true;
        } else {
        cout << "Username atau password user salah. Silakan coba lagi." << endl;
        return false;
        }
}

    // Fungsi Menampilkan Menu Admin
    // Request dari Agriby Diandra Chaniago
    void tampilkanMenuAdmin() {
        int pilihanAdmin;
        do {
            cout << "\n=== Menu Admin ===" << endl;
            cout << "1. Tampilkan Semua Laptop" << endl;
            cout << "2. Cari Laptop Berdasarkan Model" << endl;
            cout << "3. Tambah Laptop" << endl;
            cout << "4. Hapus Laptop dari List" << endl;
            cout << "5. Logout" << endl;
            cout << "Masukkan pilihan Anda: ";
            cin >> pilihanAdmin;

            switch (pilihanAdmin) {
                case 1: {
                    system("cls");
                    tampilkanSemuaLaptop();
                    break;
                }
                case 2: {
                system("cls");
                string model;
                cout << "Masukkan model laptop yang ingin dicari: ";
                cin >> model;
                try {
                    const Laptop& laptop = cariLaptopDenganModel(model);
                    cout << "Laptop ditemukan:" << endl;
                    laptop.tampilkanInfo();
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
                } 
                case 3: {
                    system("cls");
                    int id, harga;
                    string merek, model, spesifikasi;

                    cout << "Masukkan ID Laptop: ";
                    cin >> id;
                    cout << "Masukkan Merek Laptop: ";
                    cin >> merek;
                    cout << "Masukkan Model Laptop: ";
                    cin >> model;
                    cout << "Masukkan Spesifikasi Laptop: ";
                    cin.ignore(); // Membersihkan buffer
                    getline(cin, spesifikasi);
                    cout << "Masukkan Harga Laptop: ";
                    cin >> harga;

                    Laptop laptop(id, merek, model, spesifikasi, harga);
                    tambahLaptop(laptop);
                    simpanKeFile();
                    break;
                }
                case 4: {
                    int id;
                    cout << "Masukkan ID Laptop yang akan dihapus dari file: ";
                    cin >> id;
                    hapusLaptopDariFile(id);
                    break;
                }
                case 5: {
                    cout << "Logout berhasil!" << endl;
                    break;
                }
                default: {
                    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                    break;
                }
            }
        } while (pilihanAdmin != 5);
    }

    // Menampilkan Menu User setelah Memasukkan Akun User
    // Request dari Agriby Diandra Chaniago
    void tampilkanMenuUser() {
        int pilihanUser;
        do {
            cout << "\n=== Menu User ===" << endl;
            cout << "1. Tampilkan Daftar Laptop" << endl;
            cout << "2. Cari Laptop Berdasarkan Model" << endl;
            cout << "3. Beli Laptop" << endl; // Menambah opsi untuk membeli laptop
            cout << "4. Logout" << endl;
            cout << "Masukkan pilihan Anda: ";
            cin >> pilihanUser;

            switch (pilihanUser) {
                case 1: {
                    system("cls");
                    tampilkanSemuaLaptop();
                    break;
                }
                case 2: {
                system("cls");
                string model;
                cout << "Masukkan model laptop yang ingin dicari: ";
                cin >> model;
                try {
                    const Laptop& laptop = cariLaptopDenganModel(model);
                    cout << "Laptop ditemukan:" << endl;
                    laptop.tampilkanInfo();
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
                }
                case 3: {
                    system("cls");
                    beliLaptop(); // Memanggil fungsi untuk membeli laptop
                    simpanHistoryPembelian();
                    break;
                }
                case 4: {
                    cout << "Logout berhasil!" << endl;
                    break;
                }
                default: {
                    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                    break;
                }
            }
        } while (pilihanUser != 4);
    }

    // Fungsi Menampilkan Semua Laptop dengan menghubungkannya dengan fungsi Baca dari File
    // Maka laptop akan ter generate dari file ber ekstensi ".txt"
    void tampilkanSemuaLaptop() {
    bacaDariFile();    
    if (daftar.empty()) {
        cout << "Daftar laptop kosong." << endl;
    } else {
        cout << "Daftar Laptop:" << endl;
        for (const auto& laptop : daftar) {
            laptop.tampilkanInfo();
        }
    }
}

    // Sebagai Fungsi Pendukung Simpan History Pembelian
    const Laptop& cariLaptopDenganID(int id) const {
        for (const auto& laptop : daftar) {
            if (laptop.getId() == id) {
                return laptop;
            }
        }
        throw runtime_error("Laptop dengan ID tersebut tidak ditemukan.");
    }

    const Laptop& cariLaptopDenganModel(const string& model) const {
        for (const auto& laptop : daftar) {
            if (laptop.getModel() == model) {
                return laptop;
            }
        }
        throw runtime_error("Laptop dengan model tersebut tidak ditemukan.");
    }

    // Fungsi Menyimpan History Pembelian
    // Request dari Anggi Dwi Saputra
    void simpanHistoryPembelian() const {
        ofstream file("history_pembelian.txt", ios::app);
        if (file.is_open()) {
            for (const auto& pembelian : historyPembelian) {
                // Mendapatkan informasi laptop berdasarkan ID
                const Laptop& laptop = cariLaptopDenganID(pembelian.first);
                // Menghitung harga setelah diskon
                int hargaSetelahDiskon = laptop.hitungHargaSetelahDiskon();
                // Menyimpan detail pembelian ke dalam file
                file << "ID Laptop: " << pembelian.first << ", Merek: " << laptop.getMerek() << ", Model: " << laptop.getModel() << ", Diskon: " << laptop.hitungDiskon() * 100 << "%, Harga: " << hargaSetelahDiskon << ", Jumlah: " << pembelian.second << endl;
            }
            file.close();
            cout << "Riwayat pembelian disimpan ke dalam file." << endl;
        } else {
            cout << "Gagal membuka file untuk menyimpan riwayat pembelian." << endl;
        }
    }

    // Fungsi untuk Membeli Laptop
    // Request dari Agriby Diandra Chaniago & Anggi Dwi Saputra
    void beliLaptop() {
        int id, jumlah;
        bool found = false;

        // Memuat data dari file
        bacaDariFile();

        // Menampilkan daftar laptop
        tampilkanSemuaLaptop();

        cout << "Masukkan ID Laptop yang ingin dibeli: ";
        cin >> id;

        // Mencari laptop berdasarkan ID
        for (auto& laptop : daftar) {
            if (laptop.getId() == id) {
                found = true;
                cout << "Masukkan jumlah yang ingin dibeli: ";
                cin >> jumlah;

                // Menampilkan informasi pembelian
                cout << "\n--- Detail Pembelian ---" << endl;
                laptop.tampilkanInfo();
                cout << "Jumlah yang dibeli: " << jumlah << " unit" << endl;
                int totalHarga = laptop.hitungHargaSetelahDiskon() * jumlah;
                cout << "Total Harga: Rp " << totalHarga << endl;
                cout << "------------------------" << endl;

                // Menyimpan riwayat pembelian
                historyPembelian[laptop.getId()] += jumlah;

                break;
            }
        }

        if (!found) {
            cout << "Laptop dengan ID tersebut tidak ditemukan." << endl;
        }
    }

    // Fungsi Simpan Daftar Laptop Ke File
    void simpanKeFile() const {
        ofstream file("daftar_laptop.txt");
        if (file.is_open()) {
            for (const auto& laptop : daftar) {
                file << laptop.getId() << endl;
                file << laptop.getMerek() << endl;
                file << laptop.getModel() << endl;
                file << laptop.getSpesifikasi() << endl;
                file << laptop.getHarga() << endl;
            }
            file.close();
            cout << "Data disimpan ke dalam file." << endl;
        } else {
            cout << "Gagal membuka file untuk disimpan." << endl;
        }
    }

    // Fungsi Membaca Daftar Laptop dari File
    void bacaDariFile() {
    ifstream file("daftar_laptop.txt");
    if (file.is_open()) {
        daftar.clear(); // Menghapus data yang mungkin ada sebelumnya
        int id, harga;
        string merek, model, spesifikasi;

        while (file >> id >> merek >> model) {
            file.ignore(); // Membersihkan buffer
            getline(file, spesifikasi);
            file >> harga;

            Laptop laptop(id, merek, model, spesifikasi, harga);
            tambahLaptop(laptop);
        }

        file.close();
        cout << "Data berhasil dimuat dari file." << endl;
    } else {
        cout << "Gagal membuka file untuk dimuat." << endl;
    }
}

    // Fungsi Menghapus Laptop dari File
    void hapusLaptopDariFile(int id) {
    bool found = false;
    for (auto it = daftar.begin(); it != daftar.end(); ++it) {
        if (it->getId() == id) {
            daftar.erase(it);
            found = true;
            break;
        }
    }

    if (found) {
        simpanKeFile(); // Simpan kembali ke file setelah menghapus
        cout << "Laptop dengan ID " << id << " berhasil dihapus dari file." << endl;
    } else {
        cout << "Laptop dengan ID " << id << " tidak ditemukan dalam file." << endl;
    }
    }


};


// Fungsi Utama Untuk Memilih Sebagai Admin/User untuk masuk ke program
int main() {
    DaftarLaptop daftarLaptop;
    int jenisAkun;

    do {
        cout << "\nSelamat Datang di Program Daftar Laptop" << endl;
        cout << "Silakan pilih jenis akun:" << endl;
        cout << "1. Admin" << endl;
        cout << "2. User" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilihan Anda: ";
        cin >> jenisAkun;

        switch (jenisAkun) {
            case 1: {
                system("cls");
                if (daftarLaptop.loginAdmin()) {
                    daftarLaptop.tampilkanMenuAdmin();
                }
                system("cls");
                break;
            }
            case 2: {
                system("cls");
                if (daftarLaptop.loginUser()) {
                    daftarLaptop.tampilkanMenuUser();
                }
                system("cls");
                break;
            }
            case 3: {
                system("cls");
                cout << "Terima kasih!" << endl;

                break;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
            }
        }
    } while (jenisAkun != 3);

    return 0;
}
