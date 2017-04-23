The objective is to create your player to fight other students on the world famous (or infamous) Filler board.
The concept is simple: two players gain points by placing on a board, one after the other,
the game piece obtained by the game master (in the form of an executable Ruby program).
The game ends when the game piece cannot be placed anymore.

Mandatory part<br/>
• In this game, two players fight each other. They play one after the other.<br/>
• The goal is to collect as many points as possible by placing the highest number of
pieces on the the game board.<br/>
• The board is defined by X columns and N lines, it will then become X*N cells.<br/>
• At the beginning of each turn, you will receive your game piece.<br/>
• A game piece is defined by X columns and N lines, so it will be X*N cells. Inside
each game piece, will be included a shape of one or many cells.<br/>
• To be able to place a piece on the board, it is mandatory that one, and only one
cell of the shape (in your piece) covers the cell of a shape placed previously (your
territory).<br/>
• The shape must not exceed the dimensions of the board.<br/>
• When the game starts, the board already contains one shape.<br/>
• The game stops at the first error: either when a game piece cannot be placed
anymore or it has been wrongly placed.<br/>

Example:
$>./filler_vm -p1 user1 -p2 user2 -v -f samples/w1.flr<br/>
$$$ exec p1 : [user1]<br/>
$$$ exec p2 : [user2]<br/>
Plateau 14 30:<br/>
012345678901234567890123456789<br/>
000 ..............................<br/>
001 ..............................<br/>
002 ..............................<br/>
003 ..............................<br/>
004 ......X.......................<br/>
005 ..............................<br/>
006 ..............................<br/>
007 ..........................O...<br/>
008 ..............................<br/>
009 ..............................<br/>
010 ..............................<br/>
011 ..............................<br/>
012 ..............................<br/>
013 ..............................<br/>
Piece 3 6:<br/>
.****.<br/>
**....<br/>
*.....<br/>
<got (O) : [7 24] (7,24)<br/>
Plateau 14 30:<br/>
012345678901234567890123456789<br/>
000 ..............................<br/>
001 ..............................<br/>
002 ..............................<br/>
003 ..............................<br/>
004 ......X.......................<br/>
005 ..............................<br/>
006 ..............................<br/>
007 .........................oooo.<br/>
008 ........................oo....<br/>
009 ........................o.....<br/>
010 ..............................<br/>
011 ..............................<br/>
012 ..............................<br/>
013 ..............................<br/>
Piece 3 8:<br/>
......*.<br/>
......**<br/>
.......*<br/>
<got (X) : [4 0] (4,0)<br/>
Plateau 14 30:<br/>
012345678901234567890123456789<br/>
000 ..............................<br/>
001 ..............................<br/>
002 ..............................<br/>
003 ..............................<br/>
004 ......x.......................<br/>
005 ......xx......................<br/>
006 .......x......................<br/>
007 .........................OOOO.<br/>
008 ........................OO....<br/>
009 ........................O.....<br/>
010 ..............................<br/>
011 ..............................<br/>
012 ..............................<br/>
013 ..............................<br/>
[...]<br/>
== X fin : 175 [1018918090]<br/>
== O fin : 168 [1018918090]<br/>

In bonus folder you can find the program to visualize the game.<br/>
to use bonuse write:  >./filler_vm -p1 user1 -p2 user2 -v -f maps/map0X | ./bonus [-t 1-10]<br/>
-t sets the time update.

Subject of project:<br/>
https://cdn.intra.42.fr/pdf/pdf/884/filler.en.pdf
