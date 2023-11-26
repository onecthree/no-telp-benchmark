### Benchmark No Telpon

Semua benchmark dilakukan pada info berikut:
- Ubuntu 20.04
- Intel Core i7 8650U | 16 GB Memory
- gcc v9.4.0
- libpcre2 (PCRE2_CODE_UNIT_WIDTH = 8)


| Judul Kode   | Score (terendah lebih baik) | Persentase dari peringkat terbawah | Info                      |
|--------------|-----------------------------|------------------------------------|---------------------------|
| token        | 1,9749                      | 24,99% Lebih cepat dari regex      |                           |
| pp_inline    | 1,9796                      | 24,81% Lebih cepat dari regex      |                           |
| inline       | 1,9847                      | 24,62% Lebih cepat dari regex      |                           |
| array        | 1,9977                      | 24,12% Lebih cepat dari regex      |                           |
| branch       | 2,0044                      | 23,87% Lebih cepat dari regex      |                           |
| regex_simply | 2,5942                      | 1,46% Lebih cepat dari regex       | no-jit, no cached pattern |
| regex        | 2,6326                      |                                    | no-jit, no cached pattern |