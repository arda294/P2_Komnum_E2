# Integrasi Romberg **(Don't Copy Without Permission)**
## Kelompok 2
- 5025211235 Ketut Arda Putra Mahotama Sadha
- 5025211009 Muhammad Rafif Tri Risqullah
- 5025211241 Anggara Saputra

## Penjelasan Singkat
Integrasi Romberg merupakan salah satu metode ekstrapolasi yang didasarkan pada perluasan ekstrapolasi Richardson, dimana pada setiap penerapan ekstrapolasi Richadson akan menaikkan orde galat pada hasil solusinya sebesar dua. (Google)

Metode Romberg merupakan metode integrasi yang dilandaskan pada perluasan Ekstrapolasi Richardson yang dihasilkan dari aturan Metode Trapesium yang dilakukan secara terus menerus (Rekursif). Kelemahan dari metode ini adalah harus menggunakan jumlah interval yang besar guna mencapai akurasi yang diharapkan. Karena interval yang besar tersebut, diperlukan rekursi secara terus menerus agar lebih akurat.

Pada dasarnya, seperti halnya algoritma integrasi adaptif, Integrasi Romberg adalah perluasan yang relatif mudah dari keluarga algoritma Newton-Cotes. Keduanya bekerja dengan menggunakan iterasi yang disempurnakan dari beberapa metode Newton-Cotes yang mendasarinya untuk memberikan perkiraan nilai integral yang cenderung lebih akurat.

Integrasi Romberg bukanlah pendekatan adaptif terhadap intergrasi. Hal tersebut berarti metode Romberg tiddak mengubah perilakunya sendiri berdasarkan perilaku fungsi yang akan diintegrasikan. Sebaliknya, kita juga dapat mengeksploitasi perilaku fungsi trapesiumm pada batas untuk menghasilkan estimasi integral.

## Penjelasan Program  
**Perhitungan Integrasi Romberg**  
![image](https://user-images.githubusercontent.com/65074635/209343946-7b263b4f-a4f1-4ea0-8a8b-37b235a16bea.png)  
Pada romberg.cpp kita memiliki dua fungsi yakni, fungsi romberg dan fungsi trapezoid. Fungsi romberg digunakan untuk melakukan Integrasi  dengan cara pencarian interval, kemudian dilanjutkan dengan pemanggilan fungsi trapezoid, lalu menggunakan konsep perluasan Ekstrapolasi Richardson. Untuk fungsi yang trapezoid sendiri melakukan perhitungan trapezoid sebagaimana mestinya, tetapi dia memiliki reference terhadap data yang akan dieksekusi di fungsi Romberg.

**Perhitungan Error Relatif**  
![WhatsApp Image 2022-12-23 at 21 18 50](https://user-images.githubusercontent.com/65074635/209351361-036d1664-3545-44f7-8f29-010185fe1e7e.jpg)  
Untuk perhitungan error relatif sendiri, kita menggunakan rumus diatas dimana nantinya kita akan menghitung Er untuk setiap iterasi atau setiap ada perubahan.

## Testing Program
Data Set : (1, 0.88889, 0.8, 0.72727, 0.66667, 0.61538, 0.57143, 0.53333, 0.50000) a = 0, b = 1

**Input**  
![WhatsApp Image 2022-12-23 at 21 27 51](https://user-images.githubusercontent.com/65074635/209352841-4eeddf64-134c-4176-be7a-fdc5204a4fdc.jpg)  
Memasukkan data-data melalui UI yang telah dibuat.

**Result**  
![WhatsApp Image 2022-12-23 at 21 27 05](https://user-images.githubusercontent.com/65074635/209352899-3d9b92e4-d6a7-4eca-9fcd-f82b94d21fc8.jpg)  
Berupa output tabel Romberg.

## Referensi
Integrasi Romberg - https://informatika.stei.itb.ac.id/~rinaldi.munir/MetNum/2010-2011/Integrasi%20Numerik%20(Bagian%202).pdf  
Perhitungan Error Relatif - https://engcourses-uofa.ca/books/numericalanalysis/numerical-integration/rombergs-method/
