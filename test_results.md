# Testergebnisse


Audiodatei: "Hallo Welt mit Sinus"

Frei gewählte Startparameter:
    - Abtastfrequenz fs = 48 kHz (höchste sinnvolle verfügbare fs, 96 kHz ist definitv zu schnell)
    - block size = 64 samples (eine übliche block size)
    - Filterlänge = 1024 (Empfohlene Minimallänge)
    - mu = 0,1 (nach Zwischentests frei festgelegt)


gemessene Verzögerung durch das Mikrofon: 94 ms
maximal kompensierbare Verzögerung durch den Filter: $$\frac{taps}{f_{s}} = delay$$
$$\frac{256}{48\ kHz} = 5,34\ ms$$
$$\frac{512}{48\ kHz} = 10,67\ ms$$
$$\frac{1024}{48\ kHz} = 21,34\ ms$$

Daher wird das Referenzsignal um 92 ms verzögert, um in jedem Fall ein Ergebnis beaobachten zu können.

Ziel der Tests ist es die Filterlänge zu maximieren und so die Wirkung des LMS-Algorithmus zu untersuchen und verbessern.


## Abhängigkeit von mu
Testergebnisse für verschiedene Werte von mu

| sampling freq.    | block size    | delay     | filter taps   | mu    | AEC erfolgreich   | Sprache vorhanden | Sinus vorhanden   | Auslastung    | Kommentar     |
| :------------:    | :--------:    | :---:     | :---------:   | :-:   | :------------:    | :---------------: | :-------------:   | :--------:    | :-------:     |
| 48 kHz            | 64 samples    | 92 ms     | 1024          | 0,1   | nein              | ---               | ---               | ---           | AEC zu langsam|
| 48 kHz            | 64 samples    | 92 ms     | 512           | 0,1   | nein              | ---               | ---               | ---           | AEC zu langsam|
| 48 kHz            | 64 samples    | 92 ms     | 256           | 0,1   | ja                | gedämpft          | nur Anfang & Ende | 86 %          | bestes Ergebnis  |
| 48 kHz            | 64 samples    | 92 ms     | 256           | 0,2   | nein              | ---               | ---               | ---           |               |
| 48 kHz            | 64 samples    | 92 ms     | 256           | 0,01  | ja                | gedämpft          | nur Anfang & Ende | 86 %          | Anpassung sehr langsam   |
| 48 kHz            | 64 samples    | 92 ms     | 256           | 0,17  | ja                | gedämpft          | nur Anfang & Ende | 86 %          |               |
| 32 kHz            | 64 samples    | 92 ms     | 256           | 0,1   | ja                | gedämpft          | nur Anfang & Ende | 58 %          |               |
| 32 kHz            | 64 samples    | 92 ms     | 256           | 0,5   | ja                | mehr gedämpft     | nur Anfang & Ende | 58 %          | bestes Ergebnis  |
| 32 kHz            | 64 samples    | 92 ms     | 256           | 0,8   | nein              | ---               | ---               | ---           |               |
| 32 kHz            | 64 samples    | 92 ms     | 256           | 1,0   | nein              | ---               | ---               | ---           |               |
| 8 kHz             | 64 samples    | 88 ms     | 256           | 0,1   | ja                | leicht gedämpft   | nur Anfang & Ende | 14,5 %        |               | 
| 8 kHz             | 64 samples    | 88 ms     | 256           | 0,5   | ja                | gedämpft          | nur Anfang & Ende | 14,5 %        | bestes Ergebnis  | 
| 8 kHz             | 64 samples    | 88 ms     | 256           | 0,6   | ja                | gedämpft          | noch hörbar       | 14,5 %        |               | 
| 8 kHz             | 64 samples    | 88 ms     | 256           | 1,0   | nein              | ---               | ---               | ---           |               | 
| 8 kHz             | 64 samples    | 88 ms     | 256           | 1,2   | nein              | ---               | ---               | ---           |               | 
| 8 kHz             | 64 samples    | 88 ms     | 256           | 0,8   | nein              | ---               | ---               | ---           |               | 
| 8 kHz             | 64 samples    | 88 ms     | 512           | 0,1   | ja                | leicht gedämpft   | nur Anfang & Ende | 28,8 %        |               | 
| 8 kHz             | 64 samples    | 88 ms     | 512           | 1,0   | nein              | ---               | ---               |               |               | 
| 8 kHz             | 64 samples    | 88 ms     | 512           | 0,8   | nein              | ---               | ---               |               |               | 
| 8 kHz             | 64 samples    | 88 ms     | 512           | 0,2   | ja                | gedämpft          | nur Anfang & Ende | 28,8 %        | bestes Ergebnis  | 
| 8 kHz             | 64 samples    | 88 ms     | 512           | 0,3   | ja                | gedämpft          | noch hörbar       | ----          |               | 
| 8 kHz             | 64 samples    | 88 ms     | 1024          | 0,1   | ja                | leicht gedämpft   | nur Anfang & Ende | 57,5 %        | bestes Ergebnis  | 
| 8 kHz             | 64 samples    | 88 ms     | 1024          | 0,5   | nein              | ---               | ---               | ---           |               | 
| 8 kHz             | 64 samples    | 88 ms     | 1024          | 0,3   | nein              | ---               | ---               | ---           |               | 
| 8 kHz             | 64 samples    | 88 ms     | 1024          | 0,2   | ja                | leicht gedämpft   | noch hörbar       | 57,5 %        |               | 






## Abhängigkeit von der block size
Testergebnisse für eine größere block size. (block size muss eine Zweierpotenz sein) @48kHz

| block size    | delay     | filter taps   | mu    | AEC erfolgreich   | Sprache vorhanden | Sinus vorhanden   | Auslastung    | Kommentar     |
| :--------:    | :---:     | :---------:   | :-:   | :------------:    | :---------------: | :-------------:   | :--------:    | :-------:     |
| 64 samples    | 92 ms     | 256           | 0,1   | ja                | gedämpft          | nur Anfang & Ende | 86 %          |               |
| 128 samples   | 92 ms     | 256           | 0,1   | ja                | keine Änderung    | keine Änderung    | 86 %          | zeitliche Verzögerung  |
| 128 samples   | 92 ms     | 512           | 0,1   | nein              | ---               | ---               | ---           |               |






## Abhängigkeit von der Abtastfrequenz
Testergebnisse mit einer reduzierten Abtastfrequenz.

gemessene Verzögerung durch das Mikrofon: 94 ms
maximal kompensierbare Verzögerung durch den Filter: taps/fs

| filter taps \ fs     | 48 kHz    | 32 kHz    | 8 kHz     |
| :-------------------:     | :----:    | :----:    | :---:     |
| 256                       | 5,34 ms   | 8 ms      | 32 ms     |
| 512                       | 10,67 ms  | 16 ms     | 64 ms     |
| 1024                      | 21,34 ms  | 32 ms     | 128 ms    |
| 2048                      | 42,67 ms  | 64 ms     | 256 ms    |



| sampling freq.    | block size    | delay     | filter taps   | mu    | AEC erfolgreich   | Sprache vorhanden | Sinus vorhanden   | Auslastung    | Kommentar     |
| :------------:    | :--------:    | :---:     | :---------:   | :-:   | :------------:    | :---------------: | :-------------:   | :--------:    | :-------:     |
| 48 kHz            | 64            | 92 ms     | 256           | 0,1   | ja                | gedämpft          | nur Anfang & Ende | 86 %          |               |
| 48 kHz            | 64            | 92 ms     | 512           | 0,1   | nein              | ---               | ---               | ---           |               |
| 32 kHz            | 64            | 92 ms     | 256           | 0,1   | ja                | gedämpft          | nur Anfang & Ende | 58 %          |               |
| 32 kHz            | 64            | 92 ms     | 512           | 0,1   | nein              | ---               | ---               | ---           |               |
| 8 kHz             | 64            | 88 ms     | 256           | 0,1   | ja                | leicht gedämpft   | nur Anfang & Ende | 14,5 %        |               |
| 8 kHz             | 64            | 88 ms     | 512           | 0,1   | ja                | leicht gedämpft   | nur Anfang & Ende | 28,8 %        |               |
| 8 kHz             | 64            | 88 ms     | 1024          | 0,1   | ja                | leicht gedämpft   | nur Anfang & Ende | 57,5 %        |               |
| 8 kHz             | 64            | 88 ms     | 2048          | 0,1   | nein              | ---               | ---               | ---           |               |







## Abhängigkeit vom Datentyp
Testergebnisse mit fixed-point.

| block size    | delay     | filter taps   | mu    | AEC erfolgreich   | Sprache vorhanden | Sinus vorhanden   | Kommentar     |
| :--------:    | :---:     | :---------:   | :-:   | :------------:    | :---------------: | :-------------:   | :-------:     |
|               |  ms       |               |       |                   |                   |                   |               |
|               |  ms       |               |       |                   |                   |                   |               |


