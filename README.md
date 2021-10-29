# RubikCube
progetto programmazione fatto per piacere personale
incentrato sul simulare la rotazione del cubo di rubik tramite pulsanti
(senza animazioni per la mossa) con più visuali per comprendere come è messo il cubo
quella 2D è dall'alto e ogni faccia si ottiene ruotando il cubo a partire dal viola
sopra e rosso davanti, le tre visuali 3D si ottengono:
(tenendo il cubo con due dita guardando il bianco, il rosso e il blu, e l'altro dito dalla parte opposta.
(un dito sullo spigolo1 tra i centri bianco arancione e verde,
e l'altro dito sullo spigolo2 tra i centri rosso blu giallo))
1. (la grande sopra) guardando sopra il centro bianco, rosso, blu;
2. (la piccola) girando il cubo;
3. (la grande sotto) "tagliando" il cubo come se vedessimo l'interno di una stanza.

QUINDI se vuoi poter utilizzare il programma anche sfruttando un CUBO REALE devi assicurarti che:
* sopra ci sia la faccia bianca
* di fronte a te la faccia rossa
* a sinistra la faccia blu
e di conseguenza:
* a destra la faccia verde (verde e blu sono sempre facce opposte)
* la faccia dietro sia quella arancione (rosso e arancione sono sempre facce opposte)
* sotto ci sia la faccia gialla (bianco e giallo sono sempre facce opposte)


viene utilizzata la libreria SFML per la grafica in C++.

## libreria grafica SFML

da noi su Linux:

apri il terminale
(Ctrl + Alt + T)

scarica la libreria
`sudo apt-get install libsfml-dev`

per maggiori informazioni sulla libreria
<https://www.sfml-dev.org/learn.php>

per maggiori informazioni su come installare sfml su linux
<https://www.sfml-dev.org/tutorials/2.5/start-linux.php>

Oltre a questo assicurarsi di avere `g++` e `make` installati
scrivendo i comandi da terminale e se serve
installandoli secondo il metodo suggerito automaticamente.

## clonare il progetto

con il terminale aperto

spostati con il comando `cd` sulla cartella in cui vuoi clonare il progetto
(esempio Desktop: `cd Desktop` oppure Documents: `cd Documents`)

`git clone http://www.github.com/LiberaLongo/nonGravitar.git`

## compilare

con il terminale aperto

spostati sulla cartella del progetto
`cd RubikCube`

compilare
`make`
(per pulire: `make clean`, ma non è necessario per ricompilare)

NB: Il primo tentativo di strutturare i dati è stato con le matrici
    per eseguire il nuovo codice (non ancora funzionante)
    `make`
    ci sto ancora lavorando!

eventualmente rilanciare il gioco (rieseguendo il programma)
`./app`

### caso di errore nella compilazione

abbiamo notato che una funzione sfml
(sf::Text::setFillColor(...)) non sempre funziona
l'alternativa (sf::Text::setColor(...)) è deprecata
quindi se non dovesse funzionare è consigliato
scommentare la 
"//#define NON_FUNZIONA_FILL_COLOR"
in utils.hpp (riga 16)
togliendo le //
quindi risulta:
"#define NON_FUNZIONA_FILL_COLOR"

#
