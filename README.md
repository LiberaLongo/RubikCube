# RubikCube
progetto programmazione fatto per piacere personale
incentrato sul simulare la rotazione del cubo di rubik tramite pulsanti
(senza animazioni per la mossa) con più visuali per comprendere come è messo il cubo
quella 2D è dall'alto e ogni faccia si ottiene ruotando il cubo a partire dal viola
sopra e rosso davanti, le due 3D si ottengono tenendo il cubo con due dito guardando il bianco il rosso e il blu e l'altro dalla parte opposta
(spigolo1 tra i centri bianco arancione e verde
spigolo 2 tra i centri rosso blu giallo)

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

## clonare il progetto

con il terminale aperto

spostati con il comando `cd` sulla cartella in cui vuoi clonare il progetto
(esempio Desktop: `cd Desktop` oppure Documents: `cd Documents`)

`git clone http://www.github.com/LiberaLongo/nonGravitar.git`

## compilare

con il terminale aperto

spostati sulla cartella del progetto
`cd nonGravitar`

compilare
`make`
(per pulire: `make clean`, ma non è necessario per ricompilare)

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