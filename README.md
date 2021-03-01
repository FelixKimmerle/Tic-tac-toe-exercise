# Tic-tac-toe

In dieser Aufgabe werden sie das Spiel Tic-tac-toe programmieren.
Ausserdem werden sie zwei verschiedene Versionen einer Ai programmieren gegen die sie dann spielen koennen.

## Vorbereitung

* Windows: Gehen sie auf [Codeblocks download windows](https://www.codeblocks.org/downloads/binaries/) und laden sie eine Version herunter die den mingw compiler mitbringt. Fuer die meinsten sollte *codeblocks-XX.XXmingw-setup.exe* die richtige sein.
  
* Linux: Wenn sie eine Debian nahe distribution wie Debian, Ubuntu oder Popos verwenden koennen sie Codeblocks einfach installieren in dem sie ```sudo apt install codeblocks``` in eine Konsole eingeben. Wenn sie eine andere Distribution verwenden müssen sie sich auf der download Seite selbst informieren [Codeblocks download linux](https://www.codeblocks.org/downloads/binaries/#imagesoslinux48pnglogo-linux-32-and-64-bit).

Oeffnen sie dann die Projektdatei Tic-tac-toe.cbp mit Codeblocks. Entweder mit Doppelklick auf die Datei oder in Codeblocks mit *File -> Open* und suchen sie dann die Projektdatei.

## Der vorhandene Code

Ich habe den Code in mehrere Dateien aufgeteilt.
Um die Aufgabe zu loesen müssen sie auch nicht verstehen wie es funktioniert.
Falls es sie trozdem interresiert koennen sie es hier nachlesen [Splitting code into several files](http://cse230.artifice.cc/lecture/splitting-code.html#:~:text=C%2B%2B%20offers%20a%20very%20simplistic,was%20written%20in%20one%20file.).

## Die Move Klasse

Schauen sie zuerst in die Datei: Move.h und Move.cpp. Diese Klasse repraesentiert einen *Zug* im Spiel. Ein *Zug* in Tic-tac-toe besteht daraus an eine Position im Feld sein Zeichen zu setzen. Wir speichern die Position mithilfe von zwei *int's*. Einen fuer die Zeile und einen fuer die Spalte. Die *print* Funktion müssen sie nicht verstehen!

## Die State Klasse

Schauen wir nun in die Datei: State.h

### Enum Player

Wir verwenden den Typ Player um zu speichern ob eine Zelle frei, mit einem Kreuz oder einem Kreis belegt ist. In diesem Fall steht `Player::None` fuer eine leere Zelle, `Player::Cross` fuer eine, mit einem Kreuz belegten Zelle und `Player::Nought` fier eine, mite einem Kreis belegte Zelle.

### 2D Array field

In der Vorlesung wurden eindimensionale Arrays vorgestellt. Wir verwenden hier nun einen zweidimensionalen Array um das Feld zu speichern. Man verwendet diese fast gennau so wie die normalen Arrays.

Hier wird das feld erstellt mit der groesse 3x3. Also insgesammt gibt es neun Zellen:

```c++
Player field[3][3];
```

Zugreifen kann man indem man die Koordinaten in die eckigen Klammern schreibt:

```c++
Player player = field[1][1];
```

in diesem Beispiel bekommt man die mittlere Zelle des Tic-tac-toe Feldes.

Wir verwenden die erste Komponente fuer die Spalten und die zweite fuer die Zeilen. (So wie in der Mathematik bei Matrizen).
Bsp:

```c++
Player player = field[0][0];
```

hier bekommen wir das Feld links oben.

Zuweisungen funktionieren auch intuitiv:

```c++
field[2][2] = Player::Cross;
```

hier besetzen wir die untere rechte Zelle mit einem Kreuz.

Der folgen Tabelle koennen sie alle Koordinaten entnehmen:

|     | 0      | 1      | 2      |
| --- | ------ | ------ | ------ |
| 0   | [0][0] | [1][0] | [2][0] |
| 1   | [0][1] | [1][1] | [2][1] |
| 2   | [0][2] | [1][2] | [2][2] |

### Die restlichen Daten

```c++
Player turn;
```

Speichert den Spieler der gerade am Zug ist.

```c++
Player winner;
```

Speichert den Gewinner im aktuellen Zustand. Solange keiner gewonnen hat oder es unentschieden steht sollte `winner == Player::None` gelten.

```c++
int moves;
```

Speichert die anzahl an Zuegen die gespielt wurden. Diese Zahl benoetigen wir um ein unentschieden zu erkennen. Wenn neun Zuege gespielt wurden und kein Gewinner feststeht haben wir ein unentschieden.

### Die Funktionen

Die Funktionen: *print*, *print_empty_line* und *print_line* müssen sie nicht verstehen. Diese sind nur dazu da, das Feld "shoen" in der Konsole auszugeben.

Die restlichen Funktionen werden sie in den folgenden Aufgaben selber in der Datei: *State.cpp* implementieren.

## Aufgabe 1

In C++ müssen wir alle Membervariablen im Konstruktor initialisieren da sie nicht automatisch auf 0 (oder ihren Standartwert) gesetzt werden. Implementieren sie den Konstruktor der Klasse State in der Datei *State.cpp*. *Hinweis*: In Tic-tac-toe macht immer Kreuz den ersten Zug.

<details>
  <summary>Lösungen</summary>
  
  Sie müssen die Anzahl der Zuege auf 0 setzen:
  
  ```c++
  moves = 0;
  ```

  Sie müssen den Spieler der gerade am Zug ist auf den Kreuz Spieler setzen:

  ```c++
  turn = Player::Cross;
  ```

  Sie müssen den momentanen Gewinner auf None setzen:

  ```c++
  winner = Player::None;
  ```
  
  Ausserdem müssen sie jede Zelle im Feld auf None setzen damit das Feld leer ist.

  ```c++
for (int row = 0; row < 3; row++)
{
    for (int column = 0; column < 3; column++)
    {
        field[column][row] = Player::None;
    }
}
  ```

</details>

Nun koennen sie sich in der main Funtion in der Datei: *main.cpp* ein State Objekt erstellen und die *print* Funktion aufrufen. Dann sollten sie ein leeres Feld sehen.

<details>
  <summary>Lösung</summary>
  
  ```c++
  State state;
  state.print();
  ```
  
</details>

Sie koennen nun das Programm uebersetzen und ausfuehren.
Es sollte in der Konsole folgende Ausgabe vorhanden sein:

<details>
  <summary>Ausgabe</summary>

```text
    a   b   c  
  +---+---+---+
1 |   |   |   |
  +---+---+---+
2 |   |   |   |
  +---+---+---+
3 |   |   |   |
  +---+---+---+
  ```

</details>

## Aufgabe 2

In dieser Aufgabe sollen sie die Funktionen *execute*, *read_move* und *has_ended* implementieren.
Zuerst betrachten wir die Funktion *execute*. Diese bekommt einen Parameter move. Wie der Name schon sagt soll diese Funktion den Zug ausfuehren. Das bedeutet, sie soll die Zelle, die durch das Move Objekt gegeben ist, auf den Spieler setzen der gerade am Zug ist. Zudem soll die Funktion den move counter um eins erhoehen und den Spieler der gerade am Zug ist wechseln.

<details>
  <summary>Lösung: execute</summary>

Zuerst setzen wir die Zelle auf den Spieler der am Zug ist:

```c++
field[move.get_column()][move.get_row()] = turn;
```

Dann wechseln wir den Spieler der am Zug ist.
Wir koennen hier davon ausgehen, dass die variable turn immer entweder `Player::Cross` oder `Player::Nought` ist und nie `Player::None`.

```c++
if (turn == Player::Cross)
{
    turn = Player::Nought;
}
else if (turn == Player::Nought)
{
    turn = Player::Cross;
}
```

Und noch den move counter um eins erhoehen:

```c++
moves++;
```

oder:

```c++
moves += 1;
```

oder:

```c++
moves = move + 1;
```

oder:

```c++
++moves;
```

</details>

Die Funktion *read_move* soll vom Benutzer so lange einen Zug abfragen bis dieser eine gueltige eingabe getaetigt hat. Die Eingabe soll aus zwei Zeichen bestehen. Als erstes ein Buchstabe der die Spalte angibt. 'a' fuer die erste Spalte. 'b' fuer die zweite. 'c' fuer die dritte Spalte. Und das zweite Zeichen soll die Zeile bestimmen. '1' fuer die erste Zeile. '2' fuer die zweite Zeile. '3' fuer die dritte Zeile. (Es funktioniert gennau gleich wie bei Schach). Alle koordinaten koennen sie folgender Tabelle entnehmen:

|   | a  | b  | c  |
|---|----|----|----|
| 1 | a1 | b1 | c1 |
| 2 | a2 | b2 | c2 |
| 3 | a3 | b3 | c3 |

Dies soll es dem Nutzer ein wenig einfacher machen seine Zuege einzugeben. Ausserdem verschleiert es die Tatsache das wir intern bei 0 anfangen zu zaehlen. 

Hinweis: Sie koennen einen Buchstaben (char) ganz einfach zur Spaltennummer umrechnen in dem sie folgendes berechnen:

```c++
std::string input = "a2"; //Diesen Text sollten sie von der Konsole einlesen.
int column = input[0] - 'a'; 
//column hat jetzt den Wert 0
```

Ganz gennau so koennen sie auch eine Buchstaben zur Zeilennummer umrechnen:

```c++
std::string input = "a2"; //Diesen Text sollten sie von der Konsole einlesen.
int row = input[1] - '1'; 
//row hat jetzt den Wert 1
```

Da der Nutzer aber auch falsche eingaben taetigen kann müssen wir die Eingaben ueberpruefen.
Ueberpruefen sie:

* Die Eingabe hat die Laenge 2
* Die eingelesene und umgerechnete Spaltenzahl ist 0,1 oder 2
* Die eingelesene und umgerechnete Zeilenzahl ist 0,1 oder 2
* Die Zelle an der eingelesenen Position ist leer

Wenn alle diese Aussagen wahr sind, wandeln sie die eingelesene Position in ein Move Objekt um und rufen sie die Funktion *execute* auf.
Ausserdem sollte bei einer ungueltigen Eingabe das Programm so lange nach einer neuen Eingabe fragen bis eine gueltige Eingabe getaetigt wurde.

<details>
  <summary>Lösung: read_move</summary>

```c++
//As long as we dont have a valid input we try ask the user for an input.
while (true)
{
    std::cout << "Enter square: ";
    std::string input;
    std::cin >> input;
    if (input.size() == 2) //Check if the input is in the right format.
    {
        int column = input[0] - 'a'; //Convert character to the position in the alphabet.
        int row = input[1] - '1';    //Convert numeric character to its value.

        if (column >= 0 && column < 3 && row >= 0 && row < 3) //Check if the position is on the field.
        {
            if (field[column][row] == Player::None) //Check if the position is empty.
            {
                execute(Move(column, row)); //Execute the move.
                break;                      //Break out of the while loop because we got a valid input.
            }
        }
    }
    std::cout << "Invalid input!" << std::endl;
}
```

</details>

Nun fehlt nur noch die Funktion *has_ended*. Da wir bis jetzt noch keine Moeglichkeit haben einen Sieger festzustellen geben wir hier erstmal dann true zurueck wenn neun Zuege gespielt wurden. Also jede Zelle gefuellt ist. 

<details>
  <summary>Lösung: has_ended</summary>

```c++
return (moves == 9);
```

</details>

Um den geschriebenen Code zu testen schreiben wir in der main Funktion eine while Schleife, die so lange laufen soll, wie das Spiel nicht vorbei ist. Im Schleifenkoerper rufen wir die Funktion read_move auf und geben anschliessend mithilfe der print Funktion das Feld auf der Konsole aus.

<details>
  <summary>Lösung</summary>

```c++
while (!state.has_ended())
{
    //Read a move from the user.
    state.read_move();
    //Print the updated state.
    state.print();
}
```

</details>

Wenn sie jetzt das Programm starten sollten sie, abwechselnd mit Kreuz und mit Kreis ihre Zuege spielen koennen. Eine moegliche Ausgabe koennte sein:

<details>
  <summary>Ausgabe</summary>

  ```text
      a   b   c  
    +---+---+---+
1 |   |   |   |
    +---+---+---+
2 |   |   |   |
    +---+---+---+
3 |   |   |   |
    +---+---+---+
Enter square: b2
      a   b   c  
    +---+---+---+
1 |   |   |   |
    +---+---+---+
2 |   | X |   |
    +---+---+---+
3 |   |   |   |
    +---+---+---+
Enter square: a1
      a   b   c  
    +---+---+---+
1 | O |   |   |
    +---+---+---+
2 |   | X |   |
    +---+---+---+
3 |   |   |   |
    +---+---+---+
Enter square: c1
      a   b   c  
    +---+---+---+
1 | O |   | X |
    +---+---+---+
2 |   | X |   |
    +---+---+---+
3 |   |   |   |
    +---+---+---+
Enter square: b1
      a   b   c  
    +---+---+---+
1 | O | O | X |
    +---+---+---+
2 |   | X |   |
    +---+---+---+
3 |   |   |   |
    +---+---+---+
Enter square: c3
      a   b   c  
    +---+---+---+
1 | O | O | X |
    +---+---+---+
2 |   | X |   |
    +---+---+---+
3 |   |   | X |
    +---+---+---+
Enter square: 
  ```

Und so weiter bis eben das Feld voll ist.

</details>

## Aufgabe 3

Nun müssen wir noch feststellen ob ein Spieler gewonnen hat. Dazu müssen wir aber nicht nach jedem Zug das ganze Feld analysieren sonder es reicht die Zeile, Spalte und eventuell Diagonale ueberpruefen in denen das letzte Zeichen gesetzt wurde.

Hinweis: Um zu testen ob eine Zelle sich in der Diagonalen befindet müssen wir nur prüfen ob die Spalte gleich der Zeile ist.
Um zu testen ob die Zelle sich in der Gegendiagonalen befindet müssen wir nur testen ob: Zeile + Spalte = 2 ist. [Diagonale Wikipedia](https://en.wikipedia.org/wiki/Main_diagonal) <- Achtung hier wird bei 1 angefangen zu Zaehlen. Wir fangen mit 0 an zu Zaehlen.

Ergaenzen sie die Methode update_winner.

* Testen sie die Spalte auf drei gleiche Zeichen
* Testen sie die Zeile auf drei gleiche Zeichen
* Testen sie ob das neue Zeichen auf der Diagonalen liegt und testen sie gegebenenfalls die Diagonale auf drei gleiche Zeichen.
* Testen sie ob das neue Zeichen auf der Gegen-Diagonalen liegt und testen sie gegebenenfalls die Gegen-Diagonale auf drei gleiche Zeichen.

Wenn sie drei gleiche gefunden haben, setzen sie die Variable ```winner``` auf den siegreichen Spieler. Wenn sie keinen Sieger gefunden haben soll die Variable ```winner``` unveraendert bleiben.

<details>
  <summary>Lösung Pruefe Spalte</summary>

Dies koennen wir z.b. so umsetzen:

```c++
//Check the column
if (field[changed_column][0] != Player::None &&
        field[changed_column][0] == field[changed_column][1] &&
        field[changed_column][1] == field[changed_column][2])
{
    winner = field[changed_column][0];
}
```

Es wird zuerst getestet ob die erste Zelle leer ist. Denn ist dies der Fall koennen in der Spalte ja keine 3 glaichen Zeichen sein. Dann wird getestet ob das erste Element gleich dem Zweiten ist. Und so weiter.

</details>

<details>
  <summary>Lösung Pruefe Zeile</summary>


```c++
//Check the row
if (field[0][changed_row] != Player::None &&
        field[0][changed_row] == field[1][changed_row] &&
        field[1][changed_row] == field[2][changed_row])
{
    winner = field[0][changed_row];
}
```

Funktioniert analog zum Testen der Spalte.

</details>

<details>
  <summary>Lösung Pruefe Diagonale</summary>


```c++
//Check if the changed cell is on the diagonal. See: https://en.wikipedia.org/wiki/Main_diagonal
if (changed_column == changed_row)
{
    //Check the diagonal
    if (field[0][0] != Player::None &&
        field[0][0] == field[1][1] &&
        field[1][1] == field[2][2])
    {
        winner = field[0][0];
    }
}
```

Funktioniert gleich wie die Zeile, Spalten tests. Aber wir pruefen zuerst noch ob die geaenderte Zelle ueberhaupt auf der Diagonalen liegt.

</details>

<details>
  <summary>Lösung Pruefe Gegen-Diagonale</summary>


```c++
//Check if the changed cell is on the anti diagonal. See: https://en.wikipedia.org/wiki/Main_diagonal#Antidiagonal
if (changed_column + changed_row == 2)
{
    //Check the anti diagonal
    if (field[2][0] != Player::None &&
        field[2][0] == field[1][1] &&
        field[1][1] == field[0][2])
    {
        winner = field[2][0];
    }
}
```

Analog zur Diagonale.

</details>

<br>

Rufen sie in der Methode ```execute_move``` die Methode ```update_winner``` auf.

<details>
  <summary>Lösung Aufrufen</summary>

```c++
update_winner(move);
```

Dies muss nach der tatsaechlichen veraenderung des Feldes geschehen.


</details>

<br>

Nun müssen wir noch das Spiel beenden wenn ein Spieler gewonnen hat. Dazu müssen wir die Methode has_ended bearbeiten.

<details>
  <summary>Lösung has_ended</summary>


```c++
//We have a winner or the whole field is filled, so we have a draw.
return (winner != Player::None) || (moves == 9);
```

</details>

<br>

Wir wollen nun noch den gewinner auf der Konsole ausgeben. Schreiben sie den Code in der main Funktion nach der while Schleife. Verwenden sie die Methode ```get_winner```.

<details>
  <summary>Lösung Konsolenausgabe</summary>

Man kann hier ein switch-case verwenden. Sie koennen aber auch if-else verwenden.

```c++
Player winner = state.get_winner();

switch (winner)
{
case Player::None:
    std::cout << "Draw!" << std::endl;
    break;
case Player::Cross:
    std::cout << "Cross won!" << std::endl;
    break;
case Player::Nought:
    std::cout << "Nought won!" << std::endl;
    break;
}
```

</details>

<br>

Nun sollten sie gegen sich selber spielen koennen. Um die ```update_winner``` Methode zu testen sollten Sie ein paar Spiele spielen.

## Aufgabe 4

### Aufgabe 4.1 Zufall

Im ersten schritt wollen wir eine ganz banale AI die einfach zufaellige Zuege spielt. Dazu muessen wir zuerst einen Seed setzen da sonnst der Computer bei gleicher Eingabe auch immer das gleiche spielt. So waere er viel zu einfach zu besiegen da man sich nur ein Spiel merken muss das man schon einmal gewonnen hat.

Um den Seed zu setzen verwenden wir:

```c++
srand(time(0));
```

```time(0)``` gibt die Anzahl an Sekunden seit 01.01.1970 00:00 zurueck. Das ist fuer unsere Zwecke zufaellig genug.
Dies rufen wir ganz am Anfang unseres Programmes in der main Funktion auf. 

Nun gehen wir in der Mehtode ```generate_move```. Dort wollen wir Zuerst alle moeglichen legalen Zuege finden und dann zufaellig einen auswaehlen.

Um alle legalen Zuege zu finden iterieren wir ueber alle Zellen im Feld und testen ob die Zelle gleich Player::Empty ist.

Speichern sie alle legalen Zuege in einem ```std::vector<Move>```.
Fuehren sie dannach einen zufaelligen Zug aus dem vector aus.

<details>
  <summary>Lösung zufaellige Zug generierung</summary>


```c++
std::vector<Move> possible_moves;

for (int row = 0; row < 3; row++)
{
    for (int column = 0; column < 3; column++)
    {
        if (field[column][row] == Player::None)
        {
            possible_moves.push_back(Move(column, row));
        }
    }
}
execute(possible_moves[rand() % possible_moves.size()]);
```

</details>
<br>

Nun muessen wir noch die main Funktion abaendern sodass in jedem zweiten Zug der Computer einen zufaelligen Zug spielt. Nach dem aufrufen der Methode ```read_move``` muessen sie nochmal testen ob das Spiel nicht eventuell im letzten Zug beendet wurde. Dann koennen sie ```generate_move``` aufrufen.


<details>
  <summary>Lösung main</summary>


```c++
while (!state.has_ended())
{
    //Read a move from the user.
    state.read_move();

    if (!state.has_ended())
    {
        //Execute a computer move.
        state.generate_move();
    }

    //Print the updated state.
    state.print();
}
```

</details>
<br>

Nun koennen sie ein paar Spiele spielen, sollten aber keine Probleme damit haben zu gewinnen.

### Aufagabe 4.2 Ein Zug in die Zukunft

Nun wollen wir den Computer ein wenig Schlauer machen. Wenn der Computer zwei gleiche in einer Zeile/Spalte/Diagonalen hat, die dritte Zelle frei ist und er am Zug ist, wollen wir dass der Computer den gewinnenden Zug spielt. Ausserdem wollen wir, dass wenn der menschliche Gegner im naechsten Zug gewinnen kann, der Computer die so gut es geht vereitelt.

Dazu benoetigen wir eine neue Methode ```has_winning_move```. Diese soll true zurueck geben wenn der Spieler der am Zug ist im naechsten Zug gewinnen kann. Diese Methode wurde noch nicht von mir angelegt da wir sie nur fuer diese Aufgabe benoetigen. Legen sie also eine Defenition in der *State.hpp* Datei an und eine Deklaration in der *State.cpp* Datei an.

<details>
  <summary>Lösung header Datei</summary>

Da wir die Methode ausschlieslich innerhalb der State Klasse verwenden sollte die Methode im ```private``` Block sein.

```c++
bool has_winning_move();
```

</details>

<details>
  <summary>Lösung cpp Datei</summary>

Die richtige Implementirung folgt gleich.

```c++
bool State::has_winning_move()
{
  return false;
}
```

</details>
<br>

Um herauszufinden ob ein Spieler einen Zug hat der direkt zum Sieg fuehrt muessen wir auch wieder ueber alle moeglichen legalen Zuege iterieren. Dieses Mal muessen wir aber die Zuege alle ausprobieren und pruefen ob der Spieler der am Zug war gewonnen hat.

Hinweis: sie koennen den kompletten Zustand kopieren mit ```State next_state = *this;```. Um einen Zug auszuprobieren sollten sie eine Kopie vom aktuellen Zustand erzeugen und auf der Kopie den Zug ausfuehren.

<details>
  <summary>Lösung has_winning_move</summary>


```c++
bool State::has_winning_move()
{
    if (winner == Player::None) // If we already have a winner then we return false
    {
        for (int row = 0; row < 3; row++)
        {
            for (int column = 0; column < 3; column++)
            {
                if (field[column][row] == Player::None)
                {
                    State next_state = *this; // Create Copy
                    Move move(column, row);
                    next_state.execute(move); // Execute the move on the copy
                    if (next_state.get_winner() == turn)
                    {
                        return true; // Found winning move
                    }
                }
            }
        }
    }
    return false;
}
```

</details>
<br>

Jetzt muessen wir die ```generate_move``` Methode noch erweitern.

Wir wollen die Menge der legalen Zuege in drei Kategorien einteilen: gewinnende Zuege, gute Zuege und moegliche Zuege. In den gewinnenden Zuegen sind alle Zuege mit denen wir sofort gewinnen. In den guten Zuegen sind alle Zuege bei denen der Gegner nicht mit seinem naechsten Zug gewinnen kann.

Wir benoetigen im Folgenden also drei Vektoren ```std::vector<Move>```.

```c++
std::vector<Move> winning_moves;
std::vector<Move> good_moves;
std::vector<Move> possible_moves;
```

Nun muessen wir auch wieder jeden legalen Zug auf einer Kopie des aktuellen Zustandes ausprobieren. Wenn der Spieler der gerade am Zug ist nach dem Ausfruehren eines Zugs der Gewinner ist fuegen wir den Zug zu den winning_moves hinzu. Wenn dies nicht der Fall ist und der Gegner im naechsten Zug keinen gewinnenden Zug hat dann fuegen wir den Zug zu dem good_moves hinzu. Ausserdem fuegen wir jeden legalen Zug zu possible_moves hinzu. Dannach schauen wir ob wir mindestens einen Zug in den winning_moves haben. Wenn ja fuerhen wir einen der Zuege aus. Wenn nicht schauen wir ob wir einen Zug in good_moves haben. Wenn ja fuehren wir einen davon aus. Wenn die alles nicht der Fall ist fuehren wir einen Zug aus possible_moves aus.


<details>
  <summary>Lösung generate_move</summary>


```c++
void State::generate_move()
{
    std::vector<Move> winning_moves;
    std::vector<Move> good_moves;
    std::vector<Move> possible_moves;

    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            if (field[column][row] == Player::None)
            {
                State next_state = *this;
                Move move(column, row);
                next_state.execute(move);

                if(next_state.get_winner() == turn)
                {
                    winning_moves.push_back(move);
                }
                else if(!next_state.has_winning_move())
                {
                    good_moves.push_back(move);
                }

                possible_moves.push_back(move);
            }
        }
    }
    if (!winning_moves.empty())
    {
        execute(winning_moves[rand() % winning_moves.size()]);
    }
    else if (!good_moves.empty())
    {
        execute(good_moves[rand() % good_moves.size()]);
    }
    else
    {
        execute(possible_moves[rand() % possible_moves.size()]);
    }
}
```

</details>
<br>

Nun sollte es um eineiges Schwieriger sein gegen den Computer zu gewinnen. Es ist aber immer noch moeglich. Immer dann wenn der menschliche Spieler zwei verschiedene gewinnende Zuege in seinen naechsten Zug hat, Spielt der Computer einen zufaelligen Zug und verliert. Das liegt daran dass der Computer nicht weiter als einene Zug in die Zukunft schauen kann. Und somit die erstellung von Zwickmuehlen nicht verhiendern kann. Dies werden wir in der folgenden Aufgabe aendern.

### Aufgabe 4.3 Perfektes Spiel

In dieser Aufgabe werden wir den Minimax algorithmus implementieren. Schauen sie sich dazu dieses Video bis 5:15 (dannach wird alpha-beta pruning erklaert dies benoetigen wir hier noch nicht) an [Algorithms Explained – minimax and alpha-beta pruning](https://www.youtube.com/watch?v=l-hh51ncgDI).

Wichtig: Wir benoetigen KEINE *static evaluation* da ein Tic-tac-toe Spiel maximal 9 Zuege lang ist und wir somit den Search Tree ganz durchrechnen koennen.

Hinweis: In Tic-tac-toe gibt es nur 3 bewertungen: -1 fuer einen verlorenen Zustand, 0 fuer ein Unentschieden und 1 fuer einen gewonnen Zustand.

Wir implementieren den Algorithmus in der Methode ```minimax```.
Beginnen wir mit dem Rekursionsende. Also ein Zustand der entweden von einem Spieler gewonnen wurde oder unentschieden ist.

Testen sie zuerste ob es einen Gewinner gibt. Wenn ja geben sie -1 zurueck. Wir muessen in diesem Fall nicht einmal testen wer gewonnen hat. Denn wenn z.b. Spieler Kreuz am Zug ist aber schon ein Gewinner feststeht, dann hat spieler Kreis im letzten Zug gewonnen. Und der Kreuz Spieler hat verloren.

Wenn es noch keinen Gewinner gibt aber schon 9 Zuege gespielt wurden geben sie 0 zurueck da es sich um eine Unentschieden handelt.


<details>
  <summary>Lösung Rekursionsende</summary>


```c++
int State::minimax()
{
    if (winner != Player::None)
    {
        return -1;
    }
    else if (moves == 9)
    {
        return 0;
    }
    //...
}
```

</details>
<br>

Nun implementieren wir den rekursiven Teil. Zuerst benoetigen wir eine Variable in der wir unseren Maximalen score speichern. Diese Variable koennen wir mit -1 initialisieren da wir definitv nichts schlechteres finden werden als -1. Nun muessen wir, wie schon in der Vorherigen Aufgabe, ueber alle legalen Zuege iterieren und diese auf einer Kopie ausprobieren. Aber nachdem wir den Zug ausprobiert haben rufen wir auf den neuen Zustand die minimax Methode auf. Den zurueckgegebenen Wert des minimax aufrufs negieren wir (also wir wechseln das Vorzeichen). Da ein guter naechster Zug von Gegner ja schlecht fuer uns ist und ein Schlechter naechster Zug vom Gegener gut fuer uns ist. Wenn der Gegner im naechsten Zug gewinnen kann gibt uns der minimax aufruf eine 1 zurueck. Wir negieren die 1 zu -1 (also ein Verloren). Dann schauen wir ob der Score dieses Zuges besser (groesser) als der bisherige maximale Score. Wenn dies der Fall ist updaten wir den maximalen Score. Am Ende der Methode geben wir den maximalen Score zurueck.

<details>
  <summary>Lösung minimax</summary>


```c++
int State::minimax()
{
    if (winner != Player::None)
    {
        return -1;
    }
    else if (moves == 9)
    {
        return 0;
    }

    int max_score = -1;

    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            if (field[column][row] == Player::None)
            {
                //Copy the whole state.
                State next_state = *this;
                Move move(column, row);
                //Execute the move.
                next_state.execute(move);
                //Call the minimax function on the new state.
                int score_next_state = -next_state.minimax();

                if (score_next_state > max_score)
                {
                    max_score = score_next_state;
                }
            }
        }
    }

    return max_score;
}
```

</details>
<br>

Nun muessen wir diese *bewertungs Funktion* in der ```generate_move``` Methode verwenden. 
Wir werden diese Methode neu schreiben. Zuerst benoetigen wir einen Vektor der die Menge an besten Zuegen speichert. Wir machen das da es mehrere Zuege geben kann die die gleiche Bewertung haben (vor allem da wir ja nur drei verschiedene Bewertungen haben). Wenn wir dann einen zufaelligen Zug aus der Liste auswaehlen, spielt der Computer bei gleicher Eingabe nicht immer den gleichen Zug.
Wir benoetigen zudem auch nochmal eine Variable um den maximalen Score zu speichern.
Dann iterieren wir ueber alle legalen Zuege und fuehren diesen Zug auf einer Kopie des aktuellen Zustandes aus. Dann rufen wir die minimax Methode auf dem neuen Zustand auf und negieren auch wieder den Wert. Nun pruefen wir ob der neue Score groesser ist als der bisherige maximale Score. Wenn ja, dann leeren wir unseren Vektor an besten Zuegen da diese alle schlechter sind als unser aktueller Zug. Ausserdem updaten wir den bisherigen maximalen Score. Unabhaenig davon testen wir ob die neue Score gleich dem Maximalen ist. Wenn dies der Fall ist fuegen wir den neuen Zug zur liste bester Zuege hinzu.

Wenn wir durch alle legalen Zuege iteriert sind muessen wir nur noch einen zufaeligen Zug aus dem Vektor ausfuerhen. Optional kann man den Zug auch mit ```move.print()``` auf der Konsole ausgeben.

Hinweis: wir benoetigen die Methode ```has_winning_move``` nicht mehr. Sie koennen sie also entfernen.

<details>
  <summary>Lösung minimax</summary>


```c++
void State::generate_move()
{
    std::vector<Move> best_moves;
    int best_score = -1;

    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            if (field[column][row] == Player::None) //Check if the move is possible.
            {
                Move move(column, row);
                State next_state = *this; //Copy the whole state
                next_state.execute(move); //Execute the move
                int score_next_state = -next_state.minimax();

                if (score_next_state > best_score) //Check if we have a new best move.
                {
                    best_moves.clear(); //Clear the vector because all moves saved are worse than the new move.
                    best_score = score_next_state;
                }
                if (score_next_state == best_score)
                {
                    best_moves.push_back(move); //Add the move to the vector of equaly good moves.
                }
            }
        }
    }
    Move move = best_moves[rand() % best_moves.size()]; //Select a random move from the vector of the best moves.
    std::cout << "Computer played: ";
    move.print(); //Print the move so you can see what the Ai played.
    std::cout << std::endl;
    execute(move);
}
```

</details>
<br>

Wenn sie alles richtig gemacht haben. Sollte es jetzt unmoeglich sein gegen den Computer zu gewinnen. Wenn sie keine Fehler machen koennen sie ein Unentschieden erreichen. Ansonnsten verlieren sie.

## Interessante erweiterungen

* Sie koennen in der main Funktion den Aufruf ```state.read_move();``` durch ```state.generate_move();``` ersetzen. Dann spielt der Computer gegen sich selbst. Ein solches Spiel wird immer als Unentschieden ausgehen.

* Aendern sie die Zugreihenfolge so dass der Computer den ersten Zug hat also als Kreuz spielt. Und sie als Kreis spielen. (Achtung: Sie muessen die Konsolen ausgabe des Feldes auch anpassen sonnst sehen sie nicht was der Computer gespielt hat.)

* Lassen sie die AI aus Aufgabe 4.2 gegen die AI aus Aufgabe 4.3 Spielen.

* Wenn sie den die Methode ```generate_moves``` auf ein leeres Feld aufrufen. Berechnet die minimax Mehtode alle moeglichen Spielverlaufe. Sie koennen hier mitzaehlen wie viele verschiedene Spiele es gibt bei denen Kreuz oder Kreis gewinnt oder es ein unentschieden gibt.

* Schauen sie das Video [Algorithms Explained – minimax and alpha-beta pruning](https://www.youtube.com/watch?v=l-hh51ncgDI) zu Ende und implementieren sie alpha-beta pruning. (Loesung dazu gibt es bald hier!)
