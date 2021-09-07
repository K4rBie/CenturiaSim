# Centuria Rzymska

## Opis funkcji

Program będzie symulował w rzucie z góry ruchy i formacje centurii dowodzonej przez centuriona (setnika), czyli gracza, który będzie wydawał rozkazy przy pomocy GUI, ale nie będzie fizyczną postacią na mapie.

Centuria rzymska posiadała 10 contuberni. Każde contubernium składało się z 8 legionistów. Zamierzam zasymulować łańcuch dowodzenia, w którym każdy legionista trzyma się swojego dowódcy decanusa i pozycjonuje się w ramach swojego contubernium, a każdy decanus ustala pozycję swojego iddziału wewnątrz centurii, oraz również swoją własną w oddziale. Poprawna formacja będzie sumą tych niezależnych działań dwóch typów żołnierzy.

Algorytm poruszania się żołnierzy jest algorytmem stada, gdzie na każdego z nich działają siły przyciągania do oczekiwanych pozycji (w przypadku legionistów są to pozycje w pobliżu swojego dowódcy, w przypadku decanusa są to pozycje wynikające z wybranej formacji); oraz odpychania od innych żołnierzy oraz obiektów statycznych na mapie. Dlatego uzyskanie oczekiwanej formacji jest złożeniem tych ruchów i wymaga odpowiedniego doboru parametrów.

## Interakcja

Za pomocą dostępnych z lewej strony przycisków, użytkownik może wybrać jeden z 3 szyków, jakie ma zaprogramowanie Centuria: 

* linię,
* czworobok
* testudo

Po zmianie szyku następuje reorganizacja oddziału według nowych wytycznych. Środek formacji można wybrać klikając prawym przyciskiem myszy na ziemi.
Dodatkowo,  ma możliwość uruchomienia i zatrzymania symulacji w dowolnym momencie.
