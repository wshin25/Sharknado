# Sharknado
This was an extended programming assignment for a course called introduction to software engineering.
It is a simple game emulating the ecosystem of an ocean, where tuna fish have
to survive by avoiding the sharks, eating at coral reefs and reproducing in caves.
Sharks can attack tuna fish and other sharks but cannot reproduce.
Sharknados appear every 15 time ticks, sweeping away all animals that are not in
a cave.
Players can enter game commands through the command line interface to create game
objects and instruct fish to perform actions.
Entering a new command increments the clock by one tick.
At every tick, the state of the game is displayed using ASCII graphics.

Game commands:
"Swim": s ID X Y
  - fish with ID moves to location (X,Y)
"eat": e ID1 ID2
  - fish with ID1 starts eating at coral reef with ID2
"float": f ID
  - fish with ID stops doing whatever it is doing and floats at its location
"zoom": z ID1 ID2
  - fish with ID1 starts hiding at cave with ID2
"Attack": a ID1 ID2
  - fish with ID1 attacks the fish with ID2
"Create new objects": n TYPE ID X Y
  - creates new object with specified TYPE, ID at location (X,Y)
"go": g
  - advance one timestep by updating each object
"run": r
  - repeat go command until something happens, or 5 timesteps have passed.
"quit": q
  - terminates the program
  
Object types:
R: coral reef
C: cave
T: tuna
S: shark

Game display:
size of the grid: 20

Object display: "<TYPE><ID>"
  - ex) R1: coralreef with ID of 1

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
0 . . c1. . . . . . . R2
  0   4   8   12  16  20
