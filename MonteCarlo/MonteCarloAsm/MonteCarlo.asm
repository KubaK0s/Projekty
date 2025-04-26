;Wersja 1.0 Jakub Kos AEI Informatyka rok III sem IV
;G³ównym za³o¿eniem projektu jest wykorzystanie algorytmu Monte Carlo do obliczenia ca³ki dla podanej funkcji.
;Wartoœæ ca³ki jest przybli¿on¹ wartoœci¹ pola pod krzyw¹, które jest obliczane za pomoc¹ algorytmu.
;Algorytm polega na wygenerowaniu podanej iloœci losowych punktów w zadanym obszarze, przez który przechodzi nasza funkcja.
;Nasze pole(ca³ka) jest to jej stosunek do wyznaczonego pola, do stosunku liczby punktów pod krzyw¹ do liczby wszystkich wylosowanych punktów.

.DATA
.CODE

MonteCarloAsm PROC EXPORT
   push rbp                   ; Zachowaj wartoœæ wskaŸnika bazowego
   push rdi                   ; Zachowaj wartoœæ rejestru indeksu docelowego
   push rsi                   ; Zachowaj wartoœæ rejestru indeksu Ÿród³owego
   push rdx                   ; Zachowaj wartoœæ rejestru danych
   push rcx                   ; Zachowaj wartoœæ rejestru licznika
   push r8                    ; Zachowaj wartoœæ ogólnego rejestru 8
   push r9                    ; Zachowaj wartoœæ ogólnego rejestru 9
   push r10                   ; Zachowaj wartoœæ ogólnego rejestru 10
   push r11                   ; Zachowaj wartoœæ ogólnego rejestru 11
   push r12                   ; Zachowaj wartoœæ ogólnego rejestru 12
   push r13                   ; Zachowaj wartoœæ ogólnego rejestru 13
   push r14                   ; Zachowaj wartoœæ ogólnego rejestru 14
   push r15                   ; Zachowaj wartoœæ ogólnego rejestru 15

   mov r11, rcx               ; Skopiuj pierwszy argument (randX) do rejestru r11
   mov r12, rdx               ; Skopiuj drugi argument (randY) do rejestru r12
   mov edi, [r9]              ; Skopiuj trzeci argument (slope) do rejestru EDI
   mov r10d, r8d              ; Skopiuj czwarty argument (n) do rejestru r10d
   mov esi, [r9 + 4]          ; Skopiuj pi¹ty argument (intercept) do rejestru ESI
   mov edx, [r9 + 8]          ; Skopiuj szósty argument (startX) do rejestru EDX
   mov ecx, [r9 + 12]         ; Skopiuj siódmy argument (endX) do rejestru ECX
   mov r8d, [r9 + 16]         ; Skopiuj ósmy argument (minY) do rejestru r8d
   mov r9d, [r9 + 20]         ; Skopiuj dziewi¹ty argument (maxY) do rejestru r9d
   push rdx
   mov rax, 4
   mul r10
   mov r10, rax               ; n *= 4
   mov r13, 0                 ; Inicjalizacja zmiennej pomocniczej c na 0
   pop rdx

   mov r14, 0                 ; Inicjalizacja zmiennej pomocniczej i na 0
   ForLoop:
      cmp r14, r10            ; Porównanie i z n
      jge EndLoop             ; Jeœli i >= n, zakoñcz pêtlê

      mov r15d, [r11 + r14]   ; Wczytaj randX[i] do rejestru r15
      mov rax, rdi            ; fx = slope
      push rdx
      mul r15                 ; fx *= randX[i]
      pop rdx
      add rax, rsi            ; fx += intercept

      mov r15d, [r12 + r14]   ; Wczytaj randY[i] do rejestru r15

      cmp r15, 0              ; Porównaj randY[i] z 0
      jle Elif                ; Jeœli randY[i] <= 0, przejdŸ do Elif
      cmp r15, rax            ; Porównaj randY[i] z fx
      jg Elif                 ; Jeœli randY[i] > fx, przejdŸ do Elif
      inc r13                 ; Zwiêksz zmienn¹ pomocnicz¹ c
      jmp Continue            ; PrzejdŸ do etykiety Continue

      Elif:
         cmp r15, 0           ; Porównaj randY[i] z 0
         jge Continue         ; Jeœli randY[i] >= 0, przejdŸ do Continue
         cmp r15, rax         ; Porównaj randY[i] z fx
         jl Continue          ; Jeœli randY[i] < fx, przejdŸ do Continue
         dec r13              ; Zmniejsz zmienn¹ pomocnicz¹ c
         jmp Continue         ; PrzejdŸ do etykiety Continue

      Continue:
         add r14, 4           ; Inkrementuj i o 4 (przesuniêcie o 4 bajty, poniewa¿ dane to liczby 32-bitowe)
         jmp ForLoop          ; Powrót do pocz¹tku pêtli

   EndLoop:
      mov rax, rcx         ; Przenieœ wartoœæ rcx (randX) do rax
      sub rax, rdx         ; Odejmij wartoœæ rdx (startX) od rax
      sub r9, r8           ; Odejmij wartoœæ r8 (minY) od r9 (maxY)
      mul r9               ; Pomnó¿ rax przez r9 (maxY - minY)
      mul r13              ; Pomnó¿ wynik przez r13 (liczbê punktów spe³niaj¹cych warunki)
      mov r8, 4            ; Przenieœ wartoœæ 4 do r8 (dzielnik)
      mul r8               ; Pomnó¿ przez r8 (dzielnik)
      cmp r10, 0           ; Porównaj n (iloœæ punktów) z 0
      je Zero              ; Jeœli n = 0, przejdŸ do etykiety Zero
      div r10              ; Podziel przez r10 (iloœæ punktów)
      jmp Return           ; PrzejdŸ do etykiety Return

   Zero:
      mov rax, 0

   Return:
      pop r15                   ; Przywróæ wartoœæ rejestru r15
      pop r14                   ; Przywróæ wartoœæ rejestru r14
      pop r13                   ; Przywróæ wartoœæ rejestru r13
      pop r12                   ; Przywróæ wartoœæ rejestru r12
      pop r11                   ; Przywróæ wartoœæ rejestru r11
      pop r10                   ; Przywróæ wartoœæ rejestru r10
      pop r9                    ; Przywróæ wartoœæ rejestru r9
      pop r8                    ; Przywróæ wartoœæ rejestru r8
      pop rcx                   ; Przywróæ wartoœæ rejestru rcx
      pop rdx                   ; Przywróæ wartoœæ rejestru rdx
      pop rsi                   ; Przywróæ wartoœæ rejestru rsi
      pop rdi                   ; Przywróæ wartoœæ rejestru rdi
      pop rbp                   ; Przywróæ wartoœæ rejestru rbp
      ret                       ; Powrót z procedury
MonteCarloAsm ENDP
END