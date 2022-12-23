# Integrasi Romberg

## Penjelasan Singkat
Integrasi Romberg merupakan salah satu metode ekstrapolasi yang didasarkan pada perluasan ekstrapolasi Richardson, dimana pada setiap penerapan ekstrapolasi Richadson akan menaikkan orde galat pada hasil solusinya sebesar dua. (Google)

Metode Romberg merupakan metode integrasi yang didasarka pada perluasan Ekstrapolasi  Richardson yang dihasilkan dari aturan Metode Trapesium yang dilakukan secara terus menerus (Rekursif). Kelemahan dari metode ini adalah harus menggunakan jumlah interval yang besar guna mencapai akurasi yang diharapkan. Untuk meningkatkan akurasi kita harus melakukan rekursi terus menerus sampai nilai integral yang dihitung mendekati nilai 2^k yang konvergen pada suatu nilai

Pada dasarnya, seperti halnya algoritma integrasi adaptif, Integrasi Romberg adalah perluasan yang relatif mudah dari keluarga algoritma Newton-Cotes. Keduanya bekerja dengan menggunakan iterasi yang disempurnakan dari beberapa metode Newton-Cotes yang mendasarinya untuk memberikan perkiraan nilai integral yang cenderung lebih akurat. Tidak seperti Metode Rieman yang masih terbilang kurang akurat.

Integrasi Romberg bukanlah pendekatan adaptif terhadap intergrasi. Gal tersebut berarti metode Romberg tiddak mengubah perilakunya sendiri berdasarkan perilaku fungsi yang akan diintegrasikan. Sebaliknya, kita juga dapat mengeksploitasi perilaku fungsi trapesiumm pada batas untuk menghasilkan estimasi integral.

## Penjelasan Program
![image](https://user-images.githubusercontent.com/65074635/209343946-7b263b4f-a4f1-4ea0-8a8b-37b235a16bea.png)
Pada romberg.cpp kita memiliki dua fungsi yakni, fungsi romberg dan fungsi trapezoid.
