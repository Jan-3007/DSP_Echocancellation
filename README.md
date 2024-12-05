# Projekt "echo cancellation"


### Aufgabenbereich 1: Mathematik und Testdatenerzeugung

Berabeiter: Maileen, Eric, Marvin
1. Algorithmus mathematisch entwerfen
    - Blockschaltbild, ...
2. Algorithmus in Python testen
    - Test des LMS Filters (LMS Algorithmus + FIR Filter)
    - Test um einen CFAR erweitern (+ Wahrscheinlichkeitsdichtefunktion & Co)
3. Testdaten erstellen oder herunterladen
    - Bsp. .wav files
    - zum nachbilden des realen Szenarios
    - Option 1: files mit Echo aus dem Internet herunterladen
    - Option 2: Audio files herunterladen/erzeugen und per Audioprogramm oder mit Python ein Echo darüber legen (Parameter: Verzögerung, Dämpfung)



### Aufgabenbereich 2: Implementierung des Algorithmus

Bearbeiter: Jan, Rouven
1. (vorerst nicht umsetzen)Algorithmus in einem Konsoleprogramm für PC implementieren
    - bereits die CMSIS-DSP Bib. wenn möglich verwenden
    - Test über Python mit den .wav files aus Aufgabenbereich 1 
        - wenn das echo erst mit Python erzeugt wurde, ist es möglich das originale file mit dem verarbeiteten file zu vergleichen
2. Algorithmus auf dem Board implementieren
    - DAC in Betrieb nehmen
    - circular buffer implementieren
    - CFAR implementieren
    - LMS Filter implementieren



### Präsentation

1. Vortrag
    - Wo wird AEC im Alltag gebraucht
    - kurze ERklärung zur Funktionsweise (siehe Vorlesung und Signalflussbild) des LMS Filters
    - Gesamtübersicht der Komponenten und kurze Erläuterungen zu den einzelnen Komponenten (z.B. Circular Buffer)
    - Darstellung des im Versuch nachgebildeten Szenarios
2. Vorführung des Programms auf dem Board

