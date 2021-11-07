/*
Eine Elternklasse Autos
-Kindklassen Fahrertyp1, Fahrertyp2, Fahrertyp3
-Alle Autos haben individuell Spawn, Richtung, Reaktionszeit, TimeStamp, wann sie gespawnt wurden
-Alle Autos habe gleiche Beschleunigung, Bremsung
-aus Beschleunigung, Bresmung-> zweimal integrieren nach Zeit-> Weg
-Wenn Weg bekannt ist-> Annahme für Abmaße der Kreuzung treffen-> mit Geschwindigkeit auf Zeit schließen, die abgelaufen sein muss damit
das Auto die Kreuzung passiert hat

Start des Programms->while-schleife->wurde Programm beendet, sonst:
->Zufallszahl initialisieren (timeStamp setzen sonst falsch)
->if-Abfrage über die die Zufallszahl
->entscheiden, 1. welcher Fahrertyp, 2. welcher Spawn, 3. welche Richtung
->erstellen von vektoren / listen (was ist eigentlich der Unterschied?)
->Insgesamt 4*3*3=36 listen(jeder spawn hat dann drei Richtungen und drei Fahrertypen, U-turn geht nicht)
->Füllen der Vektoren mit den jeweiligen Fahrertypen
->Größe der Listen von vornherein festlegen-> Stau über die betrachtet Grenze ist egal

Wenn Simulation beginnt
->irgendetwas wie einen Timer starten, am besten so wie const int
->Verschiedene Fälle unterscheiden:
1. Auto ist erstes Element der Liste + Ampel ist grün: Auto darf fahren, also läuft der interne Counter immer weiter runter, wenn interner Counter = 0 ist,
hat das Auto die Kreuzung passiert
->der interne Counter wird bestimmt aus der Integration der Beschleunigung und ist dann für jeden Fahrertyp unterschiedlich groß-> gibt einfach an, wie
lange das Auto im Idealfall über die Kreuzung brauchen würde und wird immer gestoppt wenn Ampel rot ist, der Vordermann noch nicht gefahren ist,
oder das Abbiegen nicht möglich ist.
2. Auto ist nicht erstes Element der Liste + Ampel ist grün: Auto darf erst nach Ablauf der Reaktionszeit des Vordermannes + Abstandszuschlag "fahren"
->counter wird erst dann wieder runter gezählt, wenn vorderes Auto weg ist
3. Ampel ist rot -> bei allen Autos stoppt der Counter
4. Auto muss links abbiegen, also Verkehr auf Gegenpsur passieren lassen->Überprüfen, ob in der Liste "von gegenüber" Autos gespeichert sind, bei denen
der Counter so weit fortgeschritten ist, dass sie die Kreuzung auch schon erreicht haben.
->wenn das nicht der Fall ist Counter weiter runter laufen lassen
Gibt bestimmt noch viele mehr

Bibliothek mit Integralen suchen -> Beschleunigung dauernd integrieren und dann aktuelle Geschwindigkeit erhalten->damit kann dann der zurückgelegte Weg
bestimmt werden
Für jedes mögliche Szenario die Länge des Weges bestimmen und dann davon immer den Counter abziehen, dann sollte das irwie passen


Annahmen für geometrische Abmaße der Kreuzung:
Auto: L = 4.5m , B = 2m
Ost-West-Achse: Spur vor der Ampel: L = 2*40m = 80m, B = 4m + 4m + 4m = 12m
Nord-Sued-Achse: Spur vor der Ampel L = 2*40m = 80m , B = 2*4
Kreuzung-Größe: L = 8+8+4+4= 24, B = 16


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
Wenn die Ampel rot ist ergibt sich ein ungefährer Bremsweg von 34,7199 m bei einer konstanten Bremsbeschleunigung von 1 m/s^2.
Das Auto steht dann nach 8,333 sek.

Wenn das Auto anfährt bräuchte es 17,34 m um auf 30km/h zu beschleunigen.
Das dauert 4,165 sek.
*/