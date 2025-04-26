// dllmain.cpp: Definiuje punkt wejœcia dla aplikacji DLL.
#include "pch.h"

// Deklaracja funkcji MonteCarloCpp eksportowanej jako dynamiczna biblioteka DLL
extern "C" __declspec(dllexport) int __stdcall MonteCarloCpp(int randX[], int randY[],
    int n,
    int slope, int intercept,
    int startX, int endX,
    int minY, int maxY)
{
    int area = 0;  // Zmienna przechowuj¹ca obliczon¹ powierzchniê
    int c = 0;    // Zmienna przechowuj¹ca liczbê punktów znajduj¹cych siê pod krzyw¹

    // Pêtla przechodz¹ca przez wszystkie punkty
    for (int i = 0; i < n; ++i)
    {
        // Oblicz wartoœæ funkcji liniowej dla danego punktu
        int fx = slope * randX[i] + intercept;

        // SprawdŸ, czy punkt znajduje siê nad lub pod krzyw¹, zwiêksz lub zmniejsz licznik
        if (randY[i] > 0 && randY[i] <= fx)
        {
            ++c;
        }
        else if (randY[i] < 0 && randY[i] >= fx)
        {
            --c;
        }
    }

    // Oblicz powierzchniê na podstawie liczby punktów pod krzyw¹ i parametrów obszaru
    area = (endX - startX) * (maxY - minY) * c / n;

    // Zwróæ obliczon¹ powierzchniê
    return area;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

