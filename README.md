# Tic-tac-toe

In dieser Aufgabe werden Sie das Spiel Tic-tac-toe programmieren.
Außerdem werden Sie zwei verschiedene Versionen einer AI programmieren, gegen die Sie dann spielen können. Bitte versuchen Sie immer zuerst die Aufgabe selber zu lösen und schauen erst dann in die Lösung. Die hier angegeben Lösungen sind nur möglichkeiten. Wenn Sie es anderst gemacht haben bedeutet das auf keinen Fall das es falsch sein muss.

Wenn ihnen Fehler auffallen, Sie Fragen haben oder wissen wollen ob ihre Lösung auch richtig ist, schreiben sie mir gerne eine E-Mail an st166635@stud.uni-stuttgart.de oder klicken sie <a href="mailto:st166635@stud.uni-stuttgart.de">hier!</a> 

## Vorbereitung

* Windows: Gehen Sie auf [Codeblocks download Windows](https://www.codeblocks.org/downloads/binaries/) und laden Sie eine Version herunter die den mingw Compiler mitbringt. Für die meisten sollte *codeblocks-XX.XXmingw-setup.exe* die richtige sein.

* Linux: Wenn Sie eine Debian nahe Distribution wie Debian, Ubuntu oder Popos verwenden können Sie Codeblocks einfach installieren in dem Sie ```sudo apt install codeblocks``` in eine Konsole eingeben. Wenn Sie eine andere Distribution verwenden müssen Sie sich auf der download Seite selbst informieren [Codeblocks download Linux](https://www.codeblocks.org/downloads/binaries/#imagesoslinux48pnglogo-linux-32-and-64-bit).

Öffnen Sie dann die Projektdatei Tic-tac-toe.cbp mit Codeblocks. Entweder mit Doppelklick auf die Datei oder in Codeblocks mit *File -> Open* und suchen Sie dann die Projektdatei.

## Der vorhandene Code

Ich habe den Code in mehrere Dateien aufgeteilt.
Um die Aufgabe zu lösen müssen Sie auch nicht verstehen wie es funktioniert.
Falls es Sie trotzdem interesSiert können Sie es hier nachlesen [Splitting code into several files](http://cse230.artifice.cc/lecture/splitting-code.html#:~:text=C%2B%2B%20offers%20a%20very%20simplistic,was%20written%20in%20one%20file.).

## Die Move Klasse

Schauen Sie zuerst in die Datei: Move.h und Move.cpp. Diese Klasse repräsentiert einen *Zug* im Spiel. Ein *Zug* in Tic-tac-toe besteht daraus an eine Position im Feld sein Zeichen zu setzen. Wir speichern die Position mithilfe von zwei *int's*. Einen für die Zeile und einen für die Spalte. Die *print* Funktion müssen Sie nicht verstehen!

## Die State Klasse

Schauen wir nun in die Datei: State.h

### Enum Player

Wir verwenden den Typ Player um zu speichern, ob eine Zelle frei, mit einem Kreuz oder einem Kreis belegt ist. In diesem Fall steht 'Player::None' für eine leere Zelle, 'Player::Cross' für eine, mit einem Kreuz belegten Zelle und 'Player::Nought' für eine, mit einem Kreis belegte Zelle.

### 2D Array field

In der Vorlesung wurden eindimensionale Arrays vorgestellt. Wir verwenden hier nun einen zweidimensionalen Array, um das Feld zu speichern. Man verwendet diese fast genau so wie die normalen Arrays.

Hier wird das Feld erstellt mit der größe 3×3. Also insgesamt gibt es neun Zellen:

```c++
Player field[3][3];
```

Zugreifen kann man, indem man die Koordinaten in die eckigen Klammern schreibt:

```c++
Player player = field[1][1];
```

In diesem Beispiel bekommt man die mittlere Zelle des Tic-tac-toe Feldes.

Wir verwenden die erste Komponente für die Spalten und die zweite für die Zeilen. (So wie in der Mathematik bei Matrizen).
Bsp:

```c++
Player player = field[0][0];
```

Hier bekommen wir das Feld links oben.

Zuweisungen funktionieren auch intuitiv:

```c++
field[2][2] = Player::Cross;
```

Hier besetzen wir die untere rechte Zelle mit einem Kreuz.

Der folgen Tabelle können Sie alle Koordinaten entnehmen:

|     | 0      | 1      | 2      |
| --- | ------ | ------ | ------ |
| 0   | [0][0] | [1][0] | [2][0] |
| 1   | [0][1] | [1][1] | [2][1] |
| 2   | [0][2] | [1][2] | [2][2] |

### Die restlichen Daten

```c++
Player turn;
```

Speichert den Spieler, der gerade am Zug ist.

```c++
Player winner;
```

Speichert den Gewinner im aktuellen Zustand. Solange keiner gewonnen hat oder es unentschieden steht, sollte 'winner == Player::None' gelten.

```c++
int moves;
```

Speichert die Anzahl an Zügen, die gespielt wurden. Diese Zahl benötigen wir, um ein unentschieden zu erkennen. Wenn neun Züge gespielt wurden und kein Gewinner feststeht, haben wir ein unentschieden.

### Die Funktionen

Die Funktionen: *print*, *print_empty_line* und *print_line* müssen Sie nicht verstehen. Diese sind nur dazu da, das Feld "schön" in der Konsole auszugeben.

Die restlichen Funktionen werden Sie in den folgenden Aufgaben selber in der Datei: *State.cpp* implementieren.

## Aufgabe 1

In C++ müssen wir alle Membervariablen im Konstruktor initialiSieren da Sie nicht automatisch auf 0 (oder ihren Standardwert) gesetzt werden. Implementieren Sie den Konstruktor der Klasse State in der Datei *State.cpp*. *Hinweis*: In Tic-tac-toe macht immer Kreuz den ersten Zug.

<details>
  <summary>Lösungen</summary>
  
Sie müssen die Anzahl der Züge auf 0 setzen:

```c++
moves = 0;
```

Sie müssen den Spieler der gerade am Zug ist auf den Kreuz-Spieler setzen:

```c++
turn = Player::Cross;
```

Sie müssen den momentanen Gewinner auf None setzen:

```c++
winner = Player::None;
```

Außerdem müssen Sie jede Zelle im Feld auf None setzen damit das Feld leer ist.

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

Nun können Sie sich in der main Funktion in der Datei: *main.cpp* ein State Objekt erstellen und die *print* Funktion aufrufen. Dann sollten Sie ein leeres Feld sehen.

<details>
  <summary>Lösung</summary>
  
  ```c++
  State state;
  state.print();
  ```
  
</details>

Sie können nun das Programm übersetzen und ausführen.
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

In dieser Aufgabe sollen Sie die Funktionen *execute*, *read_move* und *has_ended* implementieren.
Zuerst betrachten wir die Funktion *execute*. Diese bekommt einen Parameter move. Wie der Name schon sagt, soll diese Funktion den Zug ausführen. Das bedeutet, Sie soll die Zelle, die durch das Moveobjekt gegeben ist, auf den Spieler setzen der gerade am Zug ist. Zudem soll die Funktion den move counter um eins erhöhen und den Spieler der gerade am Zug ist wechseln.

<details>
  <summary>Lösung: execute</summary>

Zuerst setzen wir die Zelle auf den Spieler der am Zug ist:

```c++
field[move.get_column()][move.get_row()] = turn;
```

Dann wechseln wir den Spieler der am Zug ist.
Wir können hier davon ausgehen, dass die variable turn immer entweder 'Player::Cross' oder 'Player::Nought' ist und nie 'Player::None'.

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

Und noch den move counter um eins erhöhen:

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

Die Funktion *read_move* soll vom Benutzer so lange einen Zug abfragen bis dieser eine gültige Eingabe getätigt hat. Die Eingabe soll aus zwei Zeichen bestehen. Als Erstes ein Buchstabe der die Spalte angibt. 'a' für die erste Spalte. 'b' für die Zweite. 'c' für die dritte Spalte. Und das zweite Zeichen soll die Zeile bestimmen. '1' für die erste Zeile. '2' für die zweite Zeile. '3' für die dritte Zeile. (Es funktioniert genau gleich wie bei Schach). Alle Koordinaten können Sie folgender Tabelle entnehmen:

|   | a  | b  | c  |
|---|----|----|----|
| 1 | a1 | b1 | c1 |
| 2 | a2 | b2 | c2 |
| 3 | a3 | b3 | c3 |

Dies soll es dem Nutzer ein wenig einfacher machen seine Züge einzugeben. Außerdem verschleiert es die Tatsache das wir intern bei 0 anfangen zu zählen.

Hinweis: Sie können einen Buchstaben (char) ganz einfach zur Spaltennummer umrechnen in dem Sie folgendes berechnen:

```c++
std::string input = "a2"; //Diesen Text sollten Sie von der Konsole einlesen.
int column = input[0] - 'a'; 
//column hat jetzt den Wert 0
```

Ganz genau so können Sie auch einen Buchstaben zur Zeilennummer umrechnen:

```c++
std::string input = "a2"; //Diesen Text sollten Sie von der Konsole einlesen.
int row = input[1] - '1'; 
//row hat jetzt den Wert 1
```

Da der Nutzer aber auch falsche Eingaben, tätigen kann, müssen wir die Eingaben überprüfen.
Überprüfen Sie:

* Die Eingabe hat die Länge 2
* Die eingelesene und umgerechnete Spaltenzahl ist 0,1 oder 2
* Die eingelesene und umgerechnete Zeilenzahl ist 0,1 oder 2
* Die Zelle an der eingelesenen Position ist leer

Wenn alle diese Aussagen wahr sind, wandeln Sie die eingelesene Position in ein Move-objekt um und rufen Sie die Funktion *execute* auf.
Außerdem sollte bei einer ungültigen Eingabe das Programm so lange nach einer neuen Eingabe fragen bis eine gültige Eingabe getätigt wurde.

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

Nun fehlt nur noch die Funktion *has_ended*. Da wir bis jetzt noch keine Moeglichkeit haben einen Sieger festzustellen geben wir hier erstmal dann true zurueck, wenn neun Züge gespielt wurden. Also jede Zelle gefüllt ist.

<details>
  <summary>Lösung: has_ended</summary>

```c++
return (moves == 9);
```

</details>

Um den geschriebenen Code zu testen, schreiben wir in der main Funktion eine while Schleife, die so lange laufen soll, wie das Spiel nicht vorbei ist. Im Schleifenkörper rufen wir die Funktion read_move auf und geben anschließend mithilfe der print Funktion das Feld auf der Konsole aus.

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

Wenn Sie jetzt das Programm starten sollten Sie, abwechselnd mit Kreuz und mit Kreis ihre Züge spielen können. Eine mögliche Ausgabe könnte sein:

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

Nun müssen wir noch feststellen, ob ein Spieler gewonnen hat. Dazu müssen wir aber nicht nach jedem Zug das ganze Feld analySieren, sondern es reicht die Zeile, Spalte und eventuell Diagonale überprüfen, in denen das letzte Zeichen gesetzt wurde.

Hinweis: Um zu testen, ob eine Zelle sich in der Diagonalen befindet, müssen wir nur prüfen, ob die Spalte gleich der Zeile ist.
Um zu testen, ob die Zelle sich in der Gegendiagonalen befindet, müssen wir nur testen ob: Zeile + Spalte = 2 ist. [Diagonale Wikipedia](https://en.wikipedia.org/wiki/Main_diagonal) <- Achtung hier wird bei 1 angefangen zu zählen. Wir fangen mit 0 an zu Zählen.

Ergänzen Sie die Methode update_winner.

* Testen Sie die Spalte auf drei gleiche Zeichen
* Testen Sie die Zeile auf drei gleiche Zeichen
* Testen Sie, ob das neue Zeichen auf der Diagonalen liegt und testen Sie gegebenenfalls die Diagonale auf drei gleiche Zeichen.
* Testen Sie, ob das neue Zeichen auf der Gegen-Diagonalen liegt und testen Sie gegebenenfalls die Gegen-Diagonale auf drei gleiche Zeichen.

Wenn Sie drei gleiche gefunden haben, setzen Sie die Variable ```winner``` auf den Siegreichen Spieler. Wenn Sie keinen Sieger gefunden haben soll die Variable ```winner``` unveraendert bleiben.

<details>
  <summary>Lösung Pruefe Spalte</summary>

Dies können wir z.b. so umsetzen:

```c++
//Check the column
if (field[changed_column][0] != Player::None &&
        field[changed_column][0] == field[changed_column][1] &&
        field[changed_column][1] == field[changed_column][2])
{
    winner = field[changed_column][0];
}
```

Es wird zuerst getestet, ob die erste Zelle leer ist. Denn ist dies der Fall können in der Spalte ja keine 3 gleichen Zeichen sein. Dann wird getestet, ob das erste Element gleich dem Zweiten ist. Und so weiter.

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

Funktioniert gleich wie die Zeile, Spalten Tests. Aber wir prüfen zuerst noch ob die geänderte Zelle überhaupt auf der Diagonalen liegt.

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

Rufen Sie in der Methode ```execute_move``` die Methode ```update_winner``` auf.

<details>
  <summary>Lösung Aufrufen</summary>

```c++
update_winner(move);
```

Dies muss nach der tatsächlichen Veränderung des Feldes geschehen.


</details>

<br>

Nun müssen wir noch das Spiel beenden, wenn ein Spieler gewonnen hat. Dazu müssen wir die Methode has_ended bearbeiten.

<details>
  <summary>Lösung has_ended</summary>


```c++
//We have a winner or the whole field is filled, so we have a draw.
return (winner != Player::None) || (moves == 9);
```

</details>

<br>

Wir wollen nun noch den Gewinner auf der Konsole ausgeben. Schreiben Sie den Code in der main Funktion nach der while Schleife. Verwenden Sie die Methode ```get_winner```.

<details>
  <summary>Lösung Konsolenausgabe</summary>

Man kann hier ein switch-case verwenden. Sie können aber auch if-else verwenden.

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

Nun sollten Sie gegen sich selber spielen können. Um die ```update_winner``` Methode zu testen, sollten Sie ein paar Spiele spielen.

## Aufgabe 4

### Aufgabe 4.1 Zufall

Im ersten Schritt wollen wir eine ganz banale AI die einfach zufällige Züge spielt. Dazu müssen wir zuerst einen Seed setzen da sonst der Computer bei gleicher Eingabe auch immer das Gleiche spielt. So wäre er viel zu einfach zu beSiegen da man sich nur ein Spiel merken muss, das man schon einmal gewonnen hat.

Um den Seed zu setzen, verwenden wir:

```c++
srand(time(0));
```

```time(0)``` gibt die Anzahl an Sekunden seit 01.01.1970 00:00 zurück. Das ist für unsere Zwecke zufällig genug.
Dies rufen wir ganz am Anfang unseres Programmes in der main Funktion auf.

Nun gehen wir in der Methode ```generate_move```. Dort wollen wir zuerst alle möglichen legalen Züge finden und dann zufällig einen auswählen.

Um alle legalen Züge zu finden iterieren wir über alle Zellen im Feld und testen, ob die Zelle gleich Player::Empty ist.

Speichern Sie alle legalen Zuege in einem Vektor.
Fuehren Sie dannach einen zufaelligen Zug aus dem Vektor aus.

<details>
  <summary>Lösung zufällige Zug generierung</summary>


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

Nun muessen wir noch die main Funktion abaendern, sodass in jedem zweiten Zug der Computer einen zufälligen Zug spielt. Nach dem Aufrufen der Methode ```read_move``` müssen Sie nochmal testen, ob das Spiel nicht eventuell im letzten Zug beendet wurde. Dann können Sie ```generate_move``` aufrufen.


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

Nun können Sie ein paar Spiele spielen, sollten aber keine Probleme damit haben zu gewinnen.

### Aufagabe 4.2 Ein Zug in die Zukunft

Nun wollen wir den Computer ein wenig schlauer machen. Wenn der Computer zwei gleiche in einer Zeile/Spalte/Diagonalen hat, die dritte Zelle frei ist und er am Zug ist, wollen wir, dass der Computer den gewinnenden Zug spielt. Außerdem wollen wir, dass wenn der menschliche Gegner im nächsten Zug gewinnen kann, der Computer die so gut es geht vereitelt.

Dazu benötigen wir eine neue Methode ```has_winning_move```. Diese soll true zurueck geben, wenn der Spieler der am Zug ist im nächsten Zug gewinnen kann. Diese Methode wurde noch nicht von mir angelegt da wir Sie nur für diese Aufgabe benötigen. Legen Sie also eine Definition in der *State.hpp* Datei an und eine Deklaration in der *State.cpp* Datei an.

<details>
  <summary>Lösung header Datei</summary>

Da wir die Methode ausschließlich innerhalb der State Klasse verwenden sollte die Methode im ```private``` Block sein.

```c++
bool has_winning_move();
```

</details>

<details>
  <summary>Lösung cpp Datei</summary>

Die richtige Implementierung folgt gleich.

```c++
bool State::has_winning_move()
{
  return false;
}
```

</details>
<br>

Um herauszufinden, ob ein Spieler einen Zug hat der direkt zum Sieg führt müssen wir auch wieder über alle möglichen legalen Züge iterieren. Dieses Mal müssen wir aber die Züge alle ausprobieren und prüfen ob der Spieler der am Zug war gewonnen hat.

Hinweis: Sie können den kompletten Zustand kopieren mit ```State next_state = *this;```. Um einen Zug auszuprobieren, sollten Sie eine Kopie vom aktuellen Zustand erzeugen und auf der Kopie den Zug ausführen.

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

Jetzt müssen wir die ```generate_move``` Methode noch erweitern.

Wir wollen die Menge der legalen Züge in drei Kategorien einteilen: gewinnende Züge, gute Züge und mögliche Züge. In den gewinnenden Zügen sind alle Züge mit denen wir sofort gewinnen. In den guten Zügen sind alle Züge, bei denen der Gegner nicht mit seinem nächsten Zug gewinnen kann.

Wir benötigen im Folgenden also drei Vektoren.

```c++
std::vector<Move> winning_moves;
std::vector<Move> good_moves;
std::vector<Move> possible_moves;
```

Nun müssen wir auch wieder jeden legalen Zug auf einer Kopie des aktuellen Zustandes ausprobieren. Wenn der Spieler der gerade am Zug ist, nach dem Ausführen eines Zugs der Gewinner ist, fügen wir den Zug zu den winning_moves hinzu. Wenn dies nicht der Fall ist und der Gegner im nächsten Zug keinen gewinnenden Zug hat, dann fügen wir den Zug zu dem good_moves hinzu. Außerdem fügen wir jeden legalen Zug zu possible_moves hinzu. Danach schauen wir, ob wir mindestens einen Zug in den winning_moves haben. Wenn ja, führen wir einen der Züge aus. Wenn nicht schauen wir, ob wir einen Zug in good_moves haben. Wenn ja, führen wir einen davon aus. Wenn die alles nicht der Fall ist, führen wir einen Zug aus possible_moves aus.


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

Nun sollte es, um einiges schwieriger sein gegen den Computer zu gewinnen. Es ist aber immer noch möglich. Immer dann, wenn der menschliche Spieler zwei verschiedene gewinnende Züge in seinen nächsten Zug hat, Spielt der Computer einen zufälligen Zug und verliert. Das liegt daran, dass der Computer nicht weiter als einen Zug in die Zukunft schauen kann. Und somit die Erstellung von Zwickmühlen nicht verhindern kann. Dies werden wir in der folgenden Aufgabe ändern.

### Aufgabe 4.3 Perfektes Spiel

In dieser Aufgabe werden wir den Minimax Algorithmus implementieren. Schauen Sie sich dazu dieses Video bis 5:15 (danach wird alpha-beta pruning erklärt dies benötigen wir hier noch nicht) an [Algorithms Explained – minimax and alpha-beta pruning](https://www.youtube.com/watch?v=l-hh51ncgDI).

Wichtig: Wir benötigen KEINE *static evaluation* da ein Tic-tac-toe Spiel maximal 9 Züge lang ist und wir somit den Search Tree ganz durchrechnen können.

Hinweis: In Tic-tac-toe gibt es nur 3 Bewertungen: -1 für einen verlorenen Zustand, 0 für ein Unentschieden und 1 für einen gewonnen Zustand.

Wir implementieren den Algorithmus in der Methode ```minimax```.
Beginnen wir mit dem Rekursionsende. Also ein Zustand, der entweder von einem Spieler gewonnen wurde oder unentschieden ist.

Testen Sie zuerst, ob es einen Gewinner gibt. Wenn ja, geben Sie -1 zurück. Wir müssen in diesem Fall nicht einmal testen, wer gewonnen hat. Denn wenn z.b. Spieler Kreuz am Zug ist aber schon ein Gewinner feststeht, dann hat Spieler Kreis im letzten Zug gewonnen. Und der Kreuz-Spieler hat verloren.

Wenn es noch keinen Gewinner gibt, aber schon 9 Züge gespielt wurden geben Sie 0 zurück da es sich um eine Unentschieden handelt.


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

Nun implementieren wir den rekursiven Teil. Zuerst benötigen wir eine Variable, in der wir unseren Maximalen Score speichern. Diese Variable können wir mit -1 initialiSieren da wir definitiv nichts Schlechteres finden werden als -1. Nun müssen wir, wie schon in der vorherigen Aufgabe, über alle legalen Züge iterieren und diese auf einer Kopie ausprobieren. Aber nachdem wir den Zug ausprobiert haben rufen wir auf den neuen Zustand die minimax Methode auf. Den zurückgegebenen Wert des minimax Aufrufs negieren wir (also wir wechseln das Vorzeichen). Da ein guter nächster Zug von Gegner ja schlecht für uns ist und ein Schlechter nächster Zug vom Gegner gut für uns ist. Wenn der Gegner im nächsten Zug gewinnen kann, gibt uns der minimax Aufruf eine 1 zurück. Wir negieren die 1 zu -1 (also ein Verloren). Dann schauen wir ob der Score dieses Zuges besser (größer) als der bisherige maximale Score. Wenn dies der Fall ist, updaten wir den maximalen Score. Am Ende der Methode geben wir den maximalen Score zurück.

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

Nun müssen wir diese *bewertungs Funktion* in der ```generate_move``` Methode verwenden.
Wir werden diese Methode neu schreiben. Zuerst benötigen wir einen Vektor der die Menge an besten Zügen speichert. Wir machen das da es mehrere Züge geben kann, die die gleiche Bewertung haben (vor allem da wir ja nur drei verschiedene Bewertungen haben). Wenn wir dann einen zufälligen Zug aus der Liste auswählen, spielt der Computer bei gleicher Eingabe nicht immer den gleichen Zug.
Wir benötigen zudem auch nochmal eine Variable, um den maximalen Score zu speichern.
Dann iterieren wir über alle legalen Züge und führen diesen Zug auf einer Kopie des aktuellen Zustandes aus. Dann rufen wir die minimax Methode auf dem neuen Zustand auf und negieren auch wieder den Wert. Nun prüfen wir ob der neue Score größer ist als der bisherige maximale Score. Wenn ja, dann leeren wir unseren Vektor an besten Zügen da diese alle schlechter sind als unser aktueller Zug. Außerdem updaten wir den bisherigen maximalen Score. Unabhängig davon testen wir, ob die neue Score gleich dem Maximalen ist. Wenn dies der Fall ist, fügen wir den neuen Zug zur Liste bester Züge hinzu.

Wenn wir durch alle legalen Züge iteriert sind, müssen wir nur noch einen zufälligen Zug aus dem Vektor ausführen. Optional kann man den Zug auch mit ```move.print()``` auf der Konsole ausgeben.

Hinweis: wir benötigen die Methode ```has_winning_move``` nicht mehr. Sie können Sie also entfernen.

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

Wenn Sie alles richtig gemacht haben, sollte es jetzt unmöglich sein gegen den Computer zu gewinnen. Wenn Sie keine Fehler machen können Sie ein Unentschieden erreichen, ansonsten verlieren Sie.

## Interessante Erweiterungen

* Sie können in der main Funktion den Aufruf ```state.read_move();``` durch ```state.generate_move();``` ersetzen. Dann spielt der Computer gegen sich selbst. Ein solches Spiel wird immer Unentschieden ausgehen.

* Ändern Sie die Zugreihenfolge so, dass der Computer den ersten Zug hat also als Kreuz spielt. Und Sie als Kreis spielen. (Achtung: Sie müssen die Konsolen Ausgabe des Feldes auch anpassen sonst sehen Sie nicht was der Computer gespielt hat.)

* Lassen Sie die AI aus Aufgabe 4.2 gegen die AI aus Aufgabe 4.3 Spielen.

* Wenn Sie den die Methode ```generate_moves``` auf ein leeres Feld aufrufen. Berechnet die minimax Methode alle möglichen Spiel verlaufe. Sie können hier mitzählen wie viele verschiedene Spiele es gibt bei denen Kreuz oder Kreis gewinnt oder es ein unentschieden gibt.

* Schauen Sie das Video [Algorithms Explained – minimax and alpha-beta pruning](https://www.youtube.com/watch?v=l-hh51ncgDI) zu Ende und implementieren Sie alpha-beta pruning. (Lösung dazu gibt es [hier!](https://github.com/FelixKimmerle/Tic-tac-toe-alpha-beta-pruning))

Lösungen für das ganze Blatt gibt es [hier!](https://github.com/FelixKimmerle/Tic-tac-toe-solution)