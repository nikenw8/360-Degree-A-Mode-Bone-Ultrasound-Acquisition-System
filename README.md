# 360-Degree-A-Mode-Bone-Ultrasound-Acquisition-System
Sistem berbasis Arduino untuk mengendalikan tiga motor stepper pada perangkat akuisisi ultrasonik A-Mode. Motor pertama digunakan untuk gerakan rotasi pemindaian, sedangkan motor kedua dan ketiga digunakan untuk menggerakkan dudukan transduser secara vertikal.
Fitur
Mengendalikan tiga motor stepper melalui sinyal STEP dan DIR.
Menggerakkan motor rotasi secara bertahap dengan jeda pengambilan data.
Menggerakkan dua motor vertikal secara bersamaan.
Menjalankan proses pemindaian otomatis dalam beberapa siklus.
Menampilkan status pergerakan motor melalui Serial Monitor.
Menghentikan sistem secara otomatis setelah seluruh proses selesai.
Konfigurasi Pin
Motor	Direction Pin	Step Pin	Fungsi
Motor 1	2	3	Rotasi pemindaian
Motor 2	4	5	Gerakan vertikal
Motor 3	6	7	Gerakan vertikal
Alur Sistem
Motor pertama melakukan gerakan rotasi secara bertahap.
Sistem menunggu selama 60 detik sebelum setiap pergerakan rotasi.
Motor pertama kembali menuju posisi awal.
Motor kedua dan ketiga bergerak secara bersamaan untuk menaikkan dudukan transduser.
Proses dijalankan sebanyak dua siklus.
Motor kedua dan ketiga diturunkan setelah seluruh siklus selesai.
Program berhenti secara otomatis.
Parameter Utama
#define stepPerRevolution 6400
#define stepDelay 1500
#define stepFor2cm 6400
#define step10Deg 640
#define stepFor6cm 12800
Nilai jumlah langkah perlu dikalibrasi kembali sesuai motor stepper, microstepping driver, mekanisme transmisi, dan jarak gerak aktual perangkat.

Cara Menjalankan
Buka file bg4kali.ino menggunakan Arduino IDE.
Pilih board dan port yang sesuai.
Hubungkan Arduino dengan driver motor stepper.
Upload program ke board.
Buka Serial Monitor dengan baud rate 9600.
Sistem akan menjalankan proses pemindaian secara otomatis.
Catatan
Pastikan driver motor menggunakan catu daya eksternal yang sesuai.
Satukan ground Arduino dengan ground driver motor.
Periksa arah motor sebelum menjalankan perangkat secara penuh.
Gunakan limit switch untuk mencegah pergerakan melewati batas mekanis.
Nilai step10Deg, jarak vertikal, dan posisi awal perlu divalidasi melalui kalibrasi perangkat.
