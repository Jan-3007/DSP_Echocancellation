# Projekt "echo cancellation"


### Aufgabenbereich 1: Mathematik und Testdatenerzeugung

Berabeiter: Maileen, Eric, Marvin
1. Algorithmus mathematisch entwerfen
    - Blockschaltbild, ...
    - in Python testen
2. Testdaten erstellen oder herunterladen
    - Bsp. .wav files
    - Option 1: files mit Echo aus dem Internet herunterladen
    - Option 2: Audio files herunterladen/erzeugen und per Audioprogramm oder mit Python ein Echo darüber legen (Parameter: Verzögerung, Dämpfung)



### Aufgabenbereich 2: Implementierung des Algorithmus

Bearbeiter: Jan, Rouven
1. Algorithmus in einem Konsoleprogramm für PC implementieren
    - bereits die CMSIS-DSP Bib. wenn möglich verwenden
    - Test über Python mit den .wav files aus Aufgabenbereich 1 
        - wenn das echo erst mit Python erzeugt wurde, ist es möglich das originale file mit dem verarbeiteten file zu vergleichen
2. Algorithmus auf dem Board implementieren
    - möglichst den Code aus 1. übernehmen
    - notwendige zusätzliche Hardware des Boards in Betrieb nehmen



### Präsentation

1. Vortrag
    - kurze Übersicht zu den einzelnen Arbeitsschritten
2. Vorführung des Programms auf dem Board
    - benötigt: Kabel, Lautsprecher, Mikrofon(?)
    - Audio mit Echo wird beispielsweise von dem Pythonprogramm in Echtzeit erzeugt

