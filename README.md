# Sharknado

This was an extended programming assignment for a course called introduction to software engineering.
It is a simple game emulating the ecosystem of an ocean, where tuna fish have
to survive by avoiding the sharks, eating at coral reefs and reproducing in caves.
Sharks can attack tuna fish and other sharks but cannot reproduce.
Sharknados appear every 15 time ticks, sweeping away all animals that are not in
a cave.

## Getting Started

### Installation

Download all the files onto a folder, cd into the folder and type the command below in the terminal:
```
g++ -o program PA4.cpp Model.cpp View.cpp CartPoint.cpp CartVector.cpp Cave.cpp CoralReef.cpp Fish.cpp GameCommand.cpp GameObject.cpp Sharknado.cpp Shark.cpp Tuna.cpp
```

For separate compilation and linking, use the '-c' option in g++ to compile individual source files and link everything at the end:
```
g++ -c PA4.cpp
g++ -c Model.cpp
// ... repeat this for all files
g++ -o program PA4.o Model.o //... list all files here
```

The executable takes no arguments to run:
```
./program
```

### How to Play

Players can enter game commands through the command line interface to create game
objects and instruct fish to perform actions.
Entering a new command increments the clock by one tick.
At every tick, the state of the game is displayed using ASCII graphics.

### Game commands

Below is a list of possible actions, each accompanied by a sample command used to execute the action

- "Swim": fish with ID moves to location (X,Y)
 ```
 s ID X Y 
 ```
 
- "eat": fish with ID1 starts eating at coral reef with ID2
```
e ID1 ID2
```

- "float": fish with ID stops doing whatever it is doing and floats at its location
```
f ID
```

- "zoom": fish with ID1 starts hiding at cave with ID2
```
z ID1 ID2
```

- "Attack": fish with ID1 attacks the fish with ID2
```
a ID1 ID2
```

- "Create new objects": creates new object with specified TYPE, ID at location (X,Y)
```
n TYPE ID X Y
```

- "go": advance one timestep by updating each object
```
g
```

- "run": repeat go command until something happens, or 5 timesteps have passed.
```
r
```

- "quit": terminates the program
```
q
```
  
### Object types

There are 4 object types, each of which have an associated letter
* R: coral reef
* C: cave
* T: tuna
* S: shark

### Display

The game display has a grid size of 20. The x and y axis repectively display the column and row positions in increments of 2.
The objects are displayed with its TYPE followed by its ID, for example:
* R1: coralreef with ID of 1

The asterisk is used to denote the presence of multiple objects in that position.
The time is shown at the top of the display.

Shown below is a sample display for reference.
```
Time: 5
20R1. . . . . . . . . R3
  . . . . . . . . . . . 
16. . . . . . . . . . . 
  . . . . . . . T1. . . 
12. . . . . . . . . . . 
  . . . . . * . . . . . 
8 . . . . . . . . . . . 
  . . . . . . . . . . . 
4 . . . . . . . . . . . 
  . . . * . . . . . . . 
0 . . C1. . . . . . . R2
  0   4   8   12  16  20
```

### Rules
Coming soon! (Easy to figure out afer a few games)
