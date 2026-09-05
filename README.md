# 360-Degree-A-Mode-Bone-Ultrasound-Acquisition-System
Sistem berbasis Arduino untuk mengendalikan tiga motor stepper pada perangkat akuisisi ultrasonik A-Mode. Motor pertama digunakan untuk gerakan rotasi pemindaian, sedangkan motor kedua dan ketiga digunakan untuk menggerakkan dudukan transduser secara vertikal.

# Fitur

- Mengendalikan tiga motor stepper melalui sinyal `STEP` dan `DIR`.
- Menggerakkan motor rotasi secara bertahap dengan jeda pengambilan data.
- Menggerakkan dua motor vertikal secara bersamaan.
- Menjalankan proses pemindaian otomatis dalam beberapa siklus.
- Menampilkan status pergerakan motor melalui Serial Monitor.
- Menghentikan sistem secara otomatis setelah seluruh proses selesai.

# Konfigurasi Pin

| Motor | Direction Pin | Step Pin | Fungsi |
|:------|--------------:|---------:|:-------|
| Motor 1 | 2 | 3 | Rotasi pemindaian |
| Motor 2 | 4 | 5 | Gerakan vertikal |
| Motor 3 | 6 | 7 | Gerakan vertikal |

### Alur Sistem

1. Motor pertama melakukan gerakan rotasi secara bertahap untuk proses pemindaian.
2. Sistem menunggu selama 60 detik sebelum setiap pergerakan rotasi untuk memberikan waktu pengambilan data.
3. Motor pertama kembali menuju posisi awal setelah proses rotasi selesai.
4. Motor kedua dan ketiga bergerak secara bersamaan untuk menaikkan dudukan transduser.
5. Proses pemindaian dijalankan sebanyak dua siklus.
6. Setelah seluruh siklus selesai, motor kedua dan ketiga bergerak turun untuk mengembalikan dudukan transduser ke posisi awal.
7. Program berhenti secara otomatis setelah seluruh proses selesai.

## Parameter Utama

Parameter utama yang digunakan dalam sistem meliputi:

```cpp
#define stepPerRevolution 6400
#define stepDelay 1500
#define stepFor2cm 6400
#define step10Deg 640
#define stepFor6cm 12800

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
   Setelah rotasi selesai, Motor 1 bergerak kembali menuju posisi awal.
5. **Pergerakan vertikal**  
   Motor 2 dan Motor 3 bergerak secara bersamaan untuk menaikkan dudukan transduser.
6. **Pengulangan siklus**  
   Proses pemindaian dilakukan sebanyak dua siklus.
7. **Pengembalian posisi**  
   Setelah seluruh siklus selesai, Motor 2 dan Motor 3 bergerak turun untuk mengembalikan dudukan transduser.
8. **Sistem berhenti**  
   Program menghentikan seluruh pergerakan motor secara otomatis setelah proses selesai.

## Dokumentasi Kegiatan

Video dokumentasi proses perancangan dan pengujian sistem dapat dilihat melalui tautan berikut:

**Video:** [Dokumentasi Kegiatan dan Pengujian Sistem](https://www.youtube.com/watch?v=g-s9wTPwNNM)
