// dllmain.cpp: Definiuje punkt wej�cia dla aplikacji DLL.
#include "pch.h"

// Deklaracja funkcji MonteCarloCpp eksportowanej jako dynamiczna biblioteka DLL
extern "C" __declspec(dllexport) int __stdcall MonteCarloCpp(int randX[], int randY[],
    int n,
    int slope, int intercept,
    int startX, int endX,
    int minY, int maxY)
{
    int area = 0;  // Zmienna przechowuj�ca obliczon� powierzchni�
    int c = 0;    // Zmienna przechowuj�ca liczb� punkt�w znajduj�cych si� pod krzyw�

    // P�tla przechodz�ca przez wszystkie punkty
    for (int i = 0; i < n; ++i)
    {
        // Oblicz warto�� funkcji liniowej dla danego punktu
        int fx = slope * randX[i] + intercept;

        // Sprawd�, czy punkt znajduje si� nad lub pod krzyw�, zwi�ksz lub zmniejsz licznik
        if (randY[i] > 0 && randY[i] <= fx)
        {
            ++c;
        }
        else if (randY[i] < 0 && randY[i] >= fx)
        {
            --c;
        }
    }

    // Oblicz powierzchni� na podstawie liczby punkt�w pod krzyw� i parametr�w obszaru
    area = (endX - startX) * (maxY - minY) * c / n;

    // Zwr�� obliczon� powierzchni�
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

