# Testergebnisse


Audiodatei: "Hallo Welt mit Sinus"

Testergebnisse für erste funktionsfähige Version. (Mu variieren)

| block size    | delay     | filter taps   | mu    | AEC erfolgreich   | Sprache vorhanden | Sinus vorhanden   | 
| :--------:    | :---:     | :---------:   | :-:   | :------------:    | :---------------: | :-------------:   |
| 64            | 93 ms     | 256           | 0,18  | nein              | ---               | ---               |
| 64            | 93 ms     | 256           | 0,17  | ja                | gedämpft          | kaum              |
| 64            | 93 ms     | 256           | 0,05  | ja                | keine Änderung    | keine Änderung    |
| 64            | 93 ms     | 256           | 0,001 | ja                | gedämpft  | sehr langsame Anpassung, ohne besseres Ergebnis |
| 64            | 93 ms     | 256           | 0,1   | ja                | gedämpft          | kaum, bestes Ergebnis              |




Testergebnisse für eine größere block size. (block size muss eine Zweierpotenz sein)

| block size    | delay     | filter taps   | mu    | AEC erfolgreich   | Sprache vorhanden | Sinus vorhanden   |
| :--------:    | :---:     | :---------:   | :-:   | :------------:    | :---------------: | :-------------:   |
| 64            | 93 ms     | 256           | 0,1   | ja                | gedämpft          | kaum              |
| 128           | 93 ms     | 256           | 0,1   | ja                | keine Änderung    |                   |
| 128           | 93 ms     | 512           | 0,1   | nein              | ---               | ---               |



Testergebnisse mit einer reduzierten Abtastfrequenz.

| block size    | delay     | filter taps   | mu    | AEC erfolgreich   | Sprache vorhanden | Sinus vorhanden   |
| :--------:    | :---:     | :---------:   | :-:   | :------------:    | :---------------: | :-------------:   |
|               |  ms       |               |       |                   |                   |                   |
|               |  ms       |               |       |                   |                   |                   |

Testergebnisse mit fixed-point.

| block size    | delay     | filter taps   | mu    | AEC erfolgreich   | Sprache vorhanden | Sinus vorhanden   |
| :--------:    | :---:     | :---------:   | :-:   | :------------:    | :---------------: | :-------------:   |
|               |  ms       |               |       |                   |                   |                   |
|               |  ms       |               |       |                   |                   |                   |


