//#include <iostream>
//#include <ranges>
//
//
//bool isInRange(int value) {
//    std::ranges::view::iota(0, 4)  // Tworzy widok zakresu od 0 do 3
//        | std::ranges::views::transform([](int x) { return x == value; })  // Por�wnuje warto�� z ka�dym elementem zakresu
//        | std::ranges::views::drop_while([](bool x) { return !x; })  // Pomija elementy do pierwszego dopasowania
//        | std::ranges::views::take(1)  // Pobiera tylko jeden element
//        | std::ranges::views::common  // Konwertuje widok na sekwencj�
//        | std::ranges::views::empty();  // Sprawdza, czy sekwencja jest pusta
//
//    return !std::ranges::empty();  // Zwraca true, je�li warto�� znajduje si� w zakresie, w przeciwnym razie false
//}
