/*
Eine Elternklasse Autos
-Kindklassen Fahrertyp1, Fahrertyp2, Fahrertyp3
-Alle Autos haben individuell Spawn, Richtung, Reaktionszeit, TimeStamp, wann sie gespawnt wurden
-Alle Autos habe gleiche Beschleunigung, Bremsung
-aus Beschleunigung, Bresmung-> zweimal integrieren nach Zeit-> Weg
-Wenn Weg bekannt ist-> Annahme f�r Abma�e der Kreuzung treffen-> mit Geschwindigkeit auf Zeit schlie�en, die abgelaufen sein muss damit
das Auto die Kreuzung passiert hat

Start des Programms->while-schleife->wurde Programm beendet, sonst:
->Zufallszahl initialisieren (timeStamp setzen sonst falsch)
->if-Abfrage �ber die die Zufallszahl
->entscheiden, 1. welcher Fahrertyp, 2. welcher Spawn, 3. welche Richtung
->erstellen von vektoren / listen (was ist eigentlich der Unterschied?)
->Insgesamt 4*3*3=36 listen(jeder spawn hat dann drei Richtungen und drei Fahrertypen, U-turn geht nicht)
->F�llen der Vektoren mit den jeweiligen Fahrertypen
->Gr��e der Listen von vornherein festlegen-> Stau �ber die betrachtet Grenze ist egal

Wenn Simulation beginnt
->irgendetwas wie einen Timer starten, am besten so wie const int
->Verschiedene F�lle unterscheiden:
1. Auto ist erstes Element der Liste + Ampel ist gr�n: Auto darf fahren, also l�uft der interne Counter immer weiter runter, wenn interner Counter = 0 ist,
hat das Auto die Kreuzung passiert
->der interne Counter wird bestimmt aus der Integration der Beschleunigung und ist dann f�r jeden Fahrertyp unterschiedlich gro�-> gibt einfach an, wie
lange das Auto im Idealfall �ber die Kreuzung brauchen w�rde und wird immer gestoppt wenn Ampel rot ist, der Vordermann noch nicht gefahren ist,
oder das Abbiegen nicht m�glich ist.
2. Auto ist nicht erstes Element der Liste + Ampel ist gr�n: Auto darf erst nach Ablauf der Reaktionszeit des Vordermannes + Abstandszuschlag "fahren"
->counter wird erst dann wieder runter gez�hlt, wenn vorderes Auto weg ist
3. Ampel ist rot -> bei allen Autos stoppt der Counter
4. Auto muss links abbiegen, also Verkehr auf Gegenpsur passieren lassen->�berpr�fen, ob in der Liste "von gegen�ber" Autos gespeichert sind, bei denen
der Counter so weit fortgeschritten ist, dass sie die Kreuzung auch schon erreicht haben.
->wenn das nicht der Fall ist Counter weiter runter laufen lassen
Gibt bestimmt noch viele mehr

Bibliothek mit Integralen suchen -> Beschleunigung dauernd integrieren und dann aktuelle Geschwindigkeit erhalten->damit kann dann der zur�ckgelegte Weg
bestimmt werden
F�r jedes m�gliche Szenario die L�nge des Weges bestimmen und dann davon immer den Counter abziehen, dann sollte das irwie passen


Annahmen f�r geometrische Abma�e der Kreuzung:
Auto: L = 4.5m , B = 2m
Ost-West-Achse: Spur vor der Ampel: L = 2*40m = 80m, B = 4m + 4m + 4m = 12m
Nord-Sued-Achse: Spur vor der Ampel L = 2*40m = 80m , B = 2*4
Kreuzung-Gr��e: L = 8+8+4+4= 24, B = 16


Damit ergeben sich folgende Fahrtwege:
Links-Rechts/Rechts-Links = 104m
Unten-Oben/Oben-Unten = 96m

Links-Unten/Rechts-Oben = 91,142
Links-Oben/Rechts-Unten = 95,142

Oben-Rechts/Unten-Links = 103,142
Oben-Links/Unten-Rechts = 95,142
Nord-Sued/ Sued-Nord: 180m

Es wird angenommen, dass die Fahrzeuge mit einer Geschwindigkeit v0 = 30km/h = 8,3333 m/s 40m vor der Ampel ankommen.
mit x(t)= (1/2)a*t^2+ v0*t + x0, mit x0 = 0 und v(t) = a*t + v0
Wenn die Ampel rot ist ergibt sich ein ungef�hrer Bremsweg von 34,7199 m bei einer konstanten Bremsbeschleunigung von 1 m/s^2.
Das Auto steht dann nach 8,333 sek.

Wenn das Auto anf�hrt br�uchte es 17,34 m um auf 30km/h zu beschleunigen.
Das dauert 4,165 sek.
*/