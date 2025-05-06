# morse
A morse en-/descryption program made in C

# To Do

Tabelle: https://dk0ru.github.io/downloads/m21-morse-code.pdf

## Kommandozeilenoptionen
- `-h/--help` soll die Benutzung des Programms erklären
- `--programmer-info` soll im JSON-Format die Authorinformationen zeigen:
  - Vorname, Name, Studiengang, Kontakt-E-Mail
- `-e/--encode` als Schalten soll Enkodieren (und optional sein)
- `-d/--decode` als Schalter soll Dekodieren
- `-o, --out` soll in Datei weiterleiten
- `--slash-wordspacer` soll statt (3x Space) zwischen Wörter (1x Space / 1x Space) setzen

## Kodierung
- A-Z | a-z | 0-9 | .,:;? | =-+ | _()/@
- nicht gefundene Zeichen werden als * gezeigt
- Buchstaben trennt 1x Space
- Wörter trennt 3x Space
- \n wird ignoriert