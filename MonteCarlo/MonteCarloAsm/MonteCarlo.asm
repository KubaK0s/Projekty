;Wersja 1.0 Jakub Kos AEI Informatyka rok III sem IV
;G��wnym za�o�eniem projektu jest wykorzystanie algorytmu Monte Carlo do obliczenia ca�ki dla podanej funkcji.
;Warto�� ca�ki jest przybli�on� warto�ci� pola pod krzyw�, kt�re jest obliczane za pomoc� algorytmu.
;Algorytm polega na wygenerowaniu podanej ilo�ci losowych punkt�w w zadanym obszarze, przez kt�ry przechodzi nasza funkcja.
;Nasze pole(ca�ka) jest to jej stosunek do wyznaczonego pola, do stosunku liczby punkt�w pod krzyw� do liczby wszystkich wylosowanych punkt�w.

.DATA
.CODE

MonteCarloAsm PROC EXPORT
   push rbp                   ; Zachowaj warto�� wska�nika bazowego
   push rdi                   ; Zachowaj warto�� rejestru indeksu docelowego
   push rsi                   ; Zachowaj warto�� rejestru indeksu �r�d�owego
   push rdx                   ; Zachowaj warto�� rejestru danych
   push rcx                   ; Zachowaj warto�� rejestru licznika
   push r8                    ; Zachowaj warto�� og�lnego rejestru 8
   push r9                    ; Zachowaj warto�� og�lnego rejestru 9
   push r10                   ; Zachowaj warto�� og�lnego rejestru 10
   push r11                   ; Zachowaj warto�� og�lnego rejestru 11
   push r12                   ; Zachowaj warto�� og�lnego rejestru 12
   push r13                   ; Zachowaj warto�� og�lnego rejestru 13
   push r14                   ; Zachowaj warto�� og�lnego rejestru 14
   push r15                   ; Zachowaj warto�� og�lnego rejestru 15

   mov r11, rcx               ; Skopiuj pierwszy argument (randX) do rejestru r11
   mov r12, rdx               ; Skopiuj drugi argument (randY) do rejestru r12
   mov edi, [r9]              ; Skopiuj trzeci argument (slope) do rejestru EDI
   mov r10d, r8d              ; Skopiuj czwarty argument (n) do rejestru r10d
   mov esi, [r9 + 4]          ; Skopiuj pi�ty argument (intercept) do rejestru ESI
   mov edx, [r9 + 8]          ; Skopiuj sz�sty argument (startX) do rejestru EDX
   mov ecx, [r9 + 12]         ; Skopiuj si�dmy argument (endX) do rejestru ECX
   mov r8d, [r9 + 16]         ; Skopiuj �smy argument (minY) do rejestru r8d
   mov r9d, [r9 + 20]         ; Skopiuj dziewi�ty argument (maxY) do rejestru r9d
   push rdx
   mov rax, 4
   mul r10
   mov r10, rax               ; n *= 4
   mov r13, 0                 ; Inicjalizacja zmiennej pomocniczej c na 0
   pop rdx

   mov r14, 0                 ; Inicjalizacja zmiennej pomocniczej i na 0
   ForLoop:
      cmp r14, r10            ; Por�wnanie i z n
      jge EndLoop             ; Je�li i >= n, zako�cz p�tl�

      mov r15d, [r11 + r14]   ; Wczytaj randX[i] do rejestru r15
      mov rax, rdi            ; fx = slope
      push rdx
      mul r15                 ; fx *= randX[i]
      pop rdx
      add rax, rsi            ; fx += intercept

      mov r15d, [r12 + r14]   ; Wczytaj randY[i] do rejestru r15

      cmp r15, 0              ; Por�wnaj randY[i] z 0
      jle Elif                ; Je�li randY[i] <= 0, przejd� do Elif
      cmp r15, rax            ; Por�wnaj randY[i] z fx
      jg Elif                 ; Je�li randY[i] > fx, przejd� do Elif
      inc r13                 ; Zwi�ksz zmienn� pomocnicz� c
      jmp Continue            ; Przejd� do etykiety Continue

      Elif:
         cmp r15, 0           ; Por�wnaj randY[i] z 0
         jge Continue         ; Je�li randY[i] >= 0, przejd� do Continue
         cmp r15, rax         ; Por�wnaj randY[i] z fx
         jl Continue          ; Je�li randY[i] < fx, przejd� do Continue
         dec r13              ; Zmniejsz zmienn� pomocnicz� c
         jmp Continue         ; Przejd� do etykiety Continue

      Continue:
         add r14, 4           ; Inkrementuj i o 4 (przesuni�cie o 4 bajty, poniewa� dane to liczby 32-bitowe)
         jmp ForLoop          ; Powr�t do pocz�tku p�tli

   EndLoop:
      mov rax, rcx         ; Przenie� warto�� rcx (randX) do rax
      sub rax, rdx         ; Odejmij warto�� rdx (startX) od rax
      sub r9, r8           ; Odejmij warto�� r8 (minY) od r9 (maxY)
      mul r9               ; Pomn� rax przez r9 (maxY - minY)
      mul r13              ; Pomn� wynik przez r13 (liczb� punkt�w spe�niaj�cych warunki)
      mov r8, 4            ; Przenie� warto�� 4 do r8 (dzielnik)
      mul r8               ; Pomn� przez r8 (dzielnik)
      cmp r10, 0           ; Por�wnaj n (ilo�� punkt�w) z 0
      je Zero              ; Je�li n = 0, przejd� do etykiety Zero
      div r10              ; Podziel przez r10 (ilo�� punkt�w)
      jmp Return           ; Przejd� do etykiety Return

   Zero:
      mov rax, 0

   Return:
      pop r15                   ; Przywr�� warto�� rejestru r15
      pop r14                   ; Przywr�� warto�� rejestru r14
      pop r13                   ; Przywr�� warto�� rejestru r13
      pop r12                   ; Przywr�� warto�� rejestru r12
      pop r11                   ; Przywr�� warto�� rejestru r11
      pop r10                   ; Przywr�� warto�� rejestru r10
      pop r9                    ; Przywr�� warto�� rejestru r9
      pop r8                    ; Przywr�� warto�� rejestru r8
      pop rcx                   ; Przywr�� warto�� rejestru rcx
      pop rdx                   ; Przywr�� warto�� rejestru rdx
      pop rsi                   ; Przywr�� warto�� rejestru rsi
      pop rdi                   ; Przywr�� warto�� rejestru rdi
      pop rbp                   ; Przywr�� warto�� rejestru rbp
      ret                       ; Powr�t z procedury
MonteCarloAsm ENDP
END