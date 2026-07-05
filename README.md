# FactoryProto

> Ein Factory-Building-Survival-Game, in dem Lärm außerirdische Wellen auslöst – gebaut mit Unreal Engine 5.8.

![Engine](https://img.shields.io/badge/Unreal_Engine-5.8-0E1128?logo=unrealengine)
![Language](https://img.shields.io/badge/C%2B%2B_%7C_Blueprint-hybrid-00599C?logo=cplusplus)
![IDE](https://img.shields.io/badge/JetBrains-Rider-000000?logo=rider)
![Status](https://img.shields.io/badge/status-in_development-yellow)

---

## Über das Spiel

**FactoryProto** ist ein Indie-Factory-Survival-Game mit einem zentralen Twist: **Lärm zieht die Aliens an.** Jede Maschine, jedes Fördersystem, jede Produktionsstufe erzeugt Geräusche – und je lauter deine Fabrik, desto häufiger und heftiger rollen die Alien-Wellen heran. Der Kern des Spiels ist die Spannung zwischen **Expansion** (mehr produzieren, schneller wachsen) und **Tarnung** (leise bleiben, überleben).

### Setting & Narrative

Die Erde ist nach einer Alien-Invasion gefallen. Der Spieler baut inmitten der Ruinen eine Fabrik auf – nicht um zu bleiben, sondern um die Mittel für die **Flucht zum Mars** zu produzieren. Das Setting verbindet post-apokalyptische Industrie mit einem Hoffnungsschimmer am Horizont.

### Kernmechaniken

- **Noise-Wave-System** – Produktionslärm füllt einen Bedrohungswert, der Alien-Wellen triggert.
- **Factory-Building** – Modulare Maschinen, Förderbänder und Produktionsketten.
- **Tech-Tree** – Freischaltbare Technologien für effizientere und leisere Produktion.
- **Dynamische Beleuchtung** – Lichtstimmung verschiebt sich mit der herannahenden Alien-Welle für visuelles Wave-Feedback.
- **Save/Load** – Persistenter Spielstand.

---

## Art Direction

Die visuelle Richtung ist eine Synthese aus:

- **Satisfactory-artigem modularem Hard-Surface-Style** für Maschinen und Strukturen – klare, funktionale Industrieästhetik.
- **Selektiven Solarpunk-Farbakzenten** – warme, organische Farbtupfer als Kontrast zur kühlen Industrie und als Verweis auf die Mars-Hoffnung.
- **Dynamischen Lichtwechseln**, die an die Noise-getriggerte Alien-Wave-Mechanik gekoppelt sind – die Umgebung „reagiert" sichtbar auf die Bedrohung.

3D-Assets werden in **Blender** erstellt (u. a. auf einem Apple-Silicon-MacBook) und über Git ins Projekt synchronisiert. Für performantes Rendering wird **Nanite** eingesetzt.

---

## Tech Stack

| Bereich | Technologie |
|---|---|
| Engine | Unreal Engine 5.8 |
| Architektur | C++/Blueprint-Hybrid |
| IDE | JetBrains Rider |
| Build-Target | `DevelopmentEditor \| Win64` |
| UI-Framework | Common UI Plugin |
| Rendering | Nanite (Blender-importierte Assets) |
| Asset-Erstellung | Blender (inkl. Apple Silicon Mac) |
| Versionskontrolle | Git + Git LFS |
| Projektverwaltung | GitHub Projects (Kanban) |

---

## Projektstruktur

Das Projekt ist modular über **Plugins** organisiert. Aktuell in Entwicklung:

### `CLM_MenuSystem`

Ein Custom-Plugin für das Menü-System, aufgebaut auf dem **Common UI Plugin**. Enthält u. a. das Hauptmenü inklusive Quit-Confirmation-Dialog mit sauberem Input-Handling (Blocking von Hintergrund-Input während Dialogen).

### Kern-Gameplay-Klassen

- `AFactoryCharacter` – Spielercharakter (First-Person).

> Architektur-Hinweis: Neue C++-Klassen benötigen die korrekten **UHT-Makros** (`UCLASS`, `UPROPERTY`, etc.), damit sie im Content Browser sichtbar sind.

---

## Setup / Getting Started

### Voraussetzungen

- **Unreal Engine 5.8**
- **JetBrains Rider** (empfohlen) oder Visual Studio
- **Git** mit **Git LFS** (für Binärassets – vor dem Klonen `git lfs install` ausführen)
- Windows (primäres Build-Target `DevelopmentEditor | Win64`)

### Klonen & Öffnen

```bash
git lfs install
git clone https://github.com/DaScheibl/FactoryProto.git
cd FactoryProto
```

Anschließend die **`.uproject`-Datei direkt in Rider öffnen** (nicht den Umweg über eine `.sln`). Rider generiert die Projektdateien und indexiert die Symbole selbstständig.

### Build

Build-Konfiguration: **`DevelopmentEditor | Win64`**.

---

## Branching-Strategie

- **`master`** – stabiler Branch, immer buildbar.
- **`feature/*`** – Feature-Branches für neue Funktionalität, werden nach Fertigstellung in `master` gemerged.

> Git-Tipp: Achte auf die korrekte `user.email`-Konfiguration, damit Commits im Contribution-Graph richtig zugeordnet werden. Fehlerhafte Authorship lässt sich per interaktivem Rebase (`git rebase -i`) nachträglich korrigieren.

---

## Projektmanagement

Aufgaben werden über ein **GitHub Projects Kanban-Board** verwaltet, mit Custom Fields für:

- **Area** – betroffener Systembereich
- **Type** – Feature / Bug / Chore
- **Priority** – Dringlichkeit
- **Size** – Aufwandsschätzung

---

## Roadmap

### MVP (Early-Access-Scope)

Realistischer Launch-Pfad: **Early Access auf Steam**. Der MVP umfasst:

- [ ] Eine Map-Region
- [ ] Core Noise/Wave-Mechanik
- [ ] Basis-Tech-Tree
- [ ] Save/Load-Funktionalität
- [ ] Hauptmenü-System (`CLM_MenuSystem`) – *in Arbeit*

### Geplante Tooling-Ideen

- **Discord-to-GitHub Bug-Reporting-Bot** – für die spätere Playtesting-Phase; automatisiertes Erfassen von Bug-Reports aus Discord als GitHub Issues (discord.js oder Discord.Net).

---

## Lizenz

*(Lizenz noch festzulegen – z. B. proprietär für den kommerziellen Early-Access-Release, oder eine Wahl deiner Präferenz.)*

---

## Kontakt

**Entwickler:** DaScheibl
**Projekt:** FactoryProto – Indie-Factory-Survival-Game
