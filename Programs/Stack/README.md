

## lwIP-Projekt des RN ITS (HAW Hamburg)

Das lwIP (lightweight IP)-Projekt ist ein Open-Source-Stack zur Implementierung des TCP/IP-Protokolls, das speziell für eingebettete Systeme mit begrenztem Speicher und Ressourcen entwickelt wurde. Es ermöglicht die Netzwerkanbindung solcher Systeme, ohne dass die volle Komplexität und die Speicheranforderungen traditioneller TCP/IP-Stacks benötigt werden. lwIP unterstützt gängige Protokolle wie TCP, UDP, ICMP, DHCP und PPP und ist in C geschrieben, was es besonders anpassungsfähig macht. Durch seine modulare Struktur lässt es sich leicht in Systeme mit verschiedenen Hardware-Architekturen integrieren.

In einer Vorlesung kann lwIP auf mehreren Ebenen didaktisch genutzt werden. Einerseits bietet es eine hervorragende Möglichkeit, die Grundlagen der Internetprotokolle und Netzwerkkommunikation in einer praxisnahen Umgebung zu vermitteln. Studierende können die Funktionsweise des TCP/IP-Stacks verstehen, indem sie lwIP auf Mikrocontrollern oder Entwicklungskits wie STM32 Nucleo verwenden.


### Anmerkungen
1. Dies ist ein Beispiel Projekt das in eine Vorlesung vom Zeitumfang besprochen werden muss, daher wird für die Beschleunigung des Codings auf KI Support gesetzt und es ist nicht gänzlich vollständig. 
2. Die Live Coding Videos sind wirklich Live Coding Videos, sie sind nur dahingehend geschnitten um die Maximale Github Größe nicht zu überschreiten. 
3. Da wir mit Live-Coding-Videos arbeiten, wird die maximal zulässige Dateigröße bei GitHub (50 MB) häufig ausgeschöpft. Es kann daher gelegentlich zu Problemen mit dem `http.postBuffer` kommen. Sollte dies der Fall sein, kann der Puffer wie folgt vergrößert werden:

```bash
git config http.postBuffer 104857600
```

### LiveCoding Video 01

In diesem Schritt wird eine umfassende Einführung in die Nutzung von Git und die Entwicklung eines Projekts mit dem Lightweight IP-Stack gegeben. Zu Beginn wird erläutert, wie das Projekt von GitHub heruntergeladen und die Submodule initialisiert werden. Folgende Befehle sind hierbei zentral:

```bash
git clone https://github.com/Transport-Protocol/ITS-BRD-VSC 
git submodule init
git submodule update --recursive
```

Diese Befehle stellen sicher, dass alle benötigten Bibliotheken verfügbar sind. Das vorgefertigte Projekt enthält bereits alle wesentlichen externen Codeelemente für das ITS-BRD.

Im nächsten Schritt wird die Implementierung eines neuen Features durch das Erstellen eines Branches behandelt:

```bash
git checkout -b statemachine
oder
git checkout -b stm
```

Dies wechselt in einen neuen Entwicklungszweig für das Feature. Um bestehende Projekte nicht zu beeinträchtigen, wird empfohlen, ein neues Projekt zu erstellen. Dafür gibt es ein Skript (in bin) zum Beispiel namens „createNewProjectC.sh“ für MacOS, das den Prozess vereinfacht und sicherstellt, dass alle Werkzeuge auf dem neuesten Stand sind.

Anschließend wird der Übersetzungsprozess demonstriert. Die Wichtigkeit des vorherigen „Clean All“-Befehls wird betont, um Fehlerquellen zu minimieren. Es folgt die Präsentation des Uploads auf das Board, wobei die korrekte Nutzung technischer Hilfsmittel wie USB-Verlängerungen und eine stabile Stromversorgung des Boards erklärt wird.

Ein zentraler Teil des Videos ist die Entwicklung einer State Machine zur besseren Kontrolle des Codes. Der Referent stellt heraus, dass mindestens drei Tasks benötigt werden, die später erweiterbar sind. Eine Best-Practice-Lösung auf KI-Vorschlag-Basis werden vorgestellt, und der Einsatz von KI wie ChatGPT zur Unterstützung bei der Code-Generierung wird diskutiert. Eine Beispielimplementierung zeigt den Einsatz von Tasks, Funktionszeigern und das Task-Management.

Des Weiteren wird die Modul-Erstellung für GPIO-Pin-Ansteuerungen erläutert. Dabei wird gezeigt, wie man ein Modul für die LED-Steuerung mit Header- und Source-Dateien anlegt. Precompiler-Direktiven und die Strukturierung von Funktionen werden ebenso behandelt.

Zum Abschluss wird die Integration aller erstellten Elemente und die Durchführung von Commits gezeigt, um Änderungen zu dokumentieren. Die Lecture endet mit einer Zusammenfassung und dem Appell, Best Practices in der Versionierung und Dokumentation anzuwenden.
