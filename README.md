# antraUzd
Pazymiu programa
Paleidimo instrukcija:
1. Atidaryti failą su VSCode ar bet kuriuo kitu IDE
2. Terminale nusinaviguoti iki programos direktorijos
3. Į terminalą rašyti "mingw32-make main"
4. Po to rašyti "./main"

V0.1-----

Programa nuskaito ranka įvestus duomenis ir su jais atlieka skaičiavimus.

V0.2-----

Programa nuskaito duomenų faile esančius duomenis ir su jais atlieka skaičiavimus.

V0.3-----

Programa panaudoja struktūras ir header failus, taip pat išimčių valdymą.

V0.4-----

Programa pati sugeneruoja duomenų failus, atlieka skaičiavimus ir suskirsto mokinius į "smegenius" ir "besmegenius"

Atlikta programos spartos analizė:
| Dydis   | Failo Gen | Skaitymas | Rusiavimas | Isvedimas |
|---------|-----------|-----------|------------|-----------|
| 1000    | 2.09816 s | 0.044095 s| 0 s        | 0.028026 s|
| 10000   | 3.18421 s | 0.4383 s  | 0.004004 s | 0.275964 s|
| 100000  | 7.27836 s | 4.34515 s | 0.031028 s | 2.73221 s |
| 1000000 | 41.4902 s | 43.7056 s | 0.271286 s | 27.6124 s |

V0.5-----

Naudojami skirtingi konteineriai:
std::list
std::deque
std::vector

Spartos analizė:
su vector
| Dydis   | Skaitymas | Rusiavimas|
|---------|-----------|-----------|
| 1000    | 0.046042 s| 0 s       |
| 10000   | 0.435396 s| 0.003001 s|
| 100000  | 4.34195 s | 0.031028 s|
| 1000000 | 43.0352 s | 0.281256 s| 

su list
| Dydis   | Skaitymas | Rusiavimas|
|---------|-----------|-----------|
| 1000    | 0.042037 s| 0.001 s   |
| 10000   | 0.403367 s| 0.134121 s|
| 100000  | 4.03867 s | 19.1044 s |
| 1000000 | 40.3247 s | N/A       | 

su deque
| Dydis   | Skaitymas | Rusiavimas|
|---------|-----------|-----------|
| 1000    | 0.043041 s| 0 s       |
| 10000   | 0.409372 s| 0.001001 s|
| 100000  | 4.03067 s | 0.006005 s|
| 1000000 | 40.8527 s | 0.062056 s|


V1.0-----

Naudojamos 2 skirtingos strategijos, pritaikomos konteineriams:

1 strategija - sukuriami du nauji konteineriai "smegeniai" ir "besmegeniai" ir programa juos suskirsto                                         
su vector                                           
| Dydis   | Skaitymas | Rusiavimas|  Total    |         
|---------|-----------|-----------|-----------|
| 1000    | 0.046042 s| 0 s       | 0.046042 s|
| 10000   | 0.435396 s| 0.003001 s| 0.438397 s|                          
| 100000  | 4.34195 s | 0.031028 s| 4.372978 s|
| 1000000 | 43.0352 s | 0.281256 s| 12.10390 s|

su list
| Dydis   | Skaitymas | Rusiavimas|  Total    |
|---------|-----------|-----------|-----------|
| 1000    | 0.042037 s| 0.001 s   | 0.42137 s |
| 10000   | 0.403367 s| 0.134121 s| 0.537488 s|
| 100000  | 4.03867 s | 19.1044 s | 23.14307 s|
| 1000000 | 40.3247 s | N/A       | N/A       | 

su deque
| Dydis   | Skaitymas | Rusiavimas|   Total   |
|---------|-----------|-----------|-----------|
| 1000    | 0.043041 s| 0 s       | 0.043041 s|
| 10000   | 0.409372 s| 0.001001 s| 0.410373 s|
| 100000  | 4.03067 s | 0.006005 s| 4.036675 s|
| 1000000 | 40.8527 s | 0.062056 s| 40.914756s|

2 strategija - naudojamas tik vienas "besmegeniu" konteineris, o "besmegeniai" yra istrinami is "studentu" konteinerio t.y. jame lieka tik "smegeniai".  

su vector                                           
| Dydis   | Skaitymas | Rusiavimas|    Total  |                  
|---------|-----------|-----------|-----------|              
| 1000    | 0.046042 s| 0.019017 s| 0.065059 s|                   
| 10000   | 0.436397 s| 1.95278 s | 2.389177 s|                                     
| 100000  | 4.02412 s | 30.2641 s | 34.28822 s|
| 1000000 | 43.0352 s | N/A       | N/A       | 

su list
| Dydis   | Skaitymas | Rusiavimas|    Total  |
|---------|-----------|-----------|-----------|
| 1000    | 0.043034 s| 0 s       | 0.043034 s|
| 10000   | 0.406379 s| 0.065059 s| 0.471438 s|
| 100000  | 4.00564 s | 10.4835 s | 14.48914 s|
| 1000000 | 41.0978 s | N/A       | N/A       | 

su deque
| Dydis   | Skaitymas | Rusiavimas|    Total  |
|---------|-----------|-----------|-----------|
| 1000    | 0.043039 s| 0.001 s   | 0.43196  s|
| 10000   | 0.403376 s| 0.138126 s| 0.541502 s|
| 100000  | 4.09773 s | 13.9747 s | 18.07243 s|
| 1000000 | 40.9181 s | 0.062056 s| 40.980156s|
