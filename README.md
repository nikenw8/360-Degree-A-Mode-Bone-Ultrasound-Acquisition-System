# 360-Degree-A-Mode-Bone-Ultrasound-Acquisition-System
Sistem berbasis Arduino untuk mengoperasikan tiga motor stepper pada perangkat akuisisi ultrasonik A-Mode. Motor pertama berfungsi mengatur rotasi pemindaian, sedangkan motor kedua dan ketiga bekerja secara simultan untuk mengontrol pergerakan vertikal dudukan transduser.

## Dokumentasi Kegiatan

Video dokumentasi proses perancangan dan pengujian sistem dapat dilihat melalui tautan berikut:

Video: [Dokumentasi Kegiatan dan Pengujian Sistem](https://www.youtube.com/watch?v=g-s9wTPwNNM)

# Fitur

1. Mengontrol tiga motor stepper menggunakan sinyal STEP dan DIR.
2. Mengatur rotasi pemindaian secara bertahap dengan interval akuisisi data.
3. Menggerakkan dua motor vertikal secara simultan.
4. Mengotomatisasi proses pemindaian dalam beberapa siklus.
5. Menampilkan status sistem melalui Serial Monitor.
6. Menghentikan sistem secara otomatis setelah proses pemindaian selesai.

# Konfigurasi Pin

| Motor | Direction Pin | Step Pin | Fungsi |
|:------|--------------:|---------:|:-------|
| Motor 1 | 2 | 3 | Rotasi pemindaian |
| Motor 2 | 4 | 5 | Gerakan vertikal |
| Motor 3 | 6 | 7 | Gerakan vertikal |

### Alur Sistem

Sistem menjalankan proses pemindaian secara otomatis melalui koordinasi tiga motor stepper. Motor 1 digunakan untuk mengatur gerakan rotasi pemindaian, sedangkan Motor 2 dan Motor 3 digunakan untuk mengatur pergerakan vertikal dudukan transduser.

Urutan kerja sistem:

1. **Inisialisasi sistem**  
   Arduino menginisialisasi seluruh motor stepper dan parameter pemindaian.
2. **Rotasi pemindaian**  
   Motor 1 bergerak secara bertahap untuk melakukan rotasi pemindaian.
3. **Jeda pengambilan data**  
   Sistem memberikan jeda selama 60 detik sebelum setiap pergerakan rotasi untuk memungkinkan proses pengambilan data.
4. **Kembali ke posisi awal**  
   Setelah rotasi selesai, Motor 1 kembali bergerak menuju posisi awal.
5. **Pergerakan vertikal**  
   Motor 2 dan Motor 3 bergerak secara bersamaan untuk menaikkan dudukan transduser.
6. **Pengulangan siklus**  
   Proses pemindaian dilakukan sebanyak dua siklus.
7. **Pengembalian posisi**  
   Setelah seluruh siklus selesai, Motor 2 dan Motor 3 bergerak turun untuk mengembalikan dudukan transduser.
8. **Sistem berhenti**  
   Program menghentikan seluruh pergerakan motor secara otomatis setelah proses selesai.


## Parameter Utama

Parameter utama yang digunakan dalam sistem meliputi:

```cpp
#define stepPerRevolution 6400
#define stepDelay 1500
#define stepFor2cm 6400
#define step10Deg 640
#define stepFor6cm 12800
