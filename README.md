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
