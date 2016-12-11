# CPS305 Data Structures and Algorithms - Assignment

TLDR: Find and print a path in an n by m matrix from a start('s') to end('e') using certain restrictions/rules
      Project was done in C

Summary:
--------

Given: A matrix, M, supplied by the user.
       User's M has the following characteristics:
         -it must be at least a 2x2 matrix
         -it must be at most a 20x20 matrix
         -it need not be square
       Each cell of User's M contains one of the following characters:
         o  an occupied cell
         .  an unoccupied cell
         s  the start cell
         e  the end cell

Task:  Write a program named Pathfinder.c that prints a path through M starting 
       at cell s, and ending at cell e, in accordance with the Rule below. If 
       multiple such paths exist, any path is acceptable; if no such path exists, 
       print "NO PATHS"
       Pathfinder reads user's M from stdin, and must consider cell [0,0] to be 
       the upper-left-hand corner of M.

Rule:  From cell [i,j], the next cell in the path is cell X, where all 
       these conditions hold for X:
           -X is one of [i+1,j], or [i-1,j], or [i,j+1], or [i,j-1], 
	   -X is an unoccupied cell
           -X is NOT already on the path 
           -X is within the user's given M 

Output: Print the path, followed by the ASCII drawing of M, with the path 
       cells indicated by the "*" character. Your output must be like that 
       of "Example Run" near the end of this file.
       
Given:

Approach:
---------
Start at cell s, and explore along every path of unoccupied cells. 
If, during exploration, you encounter cell e, then a solution exists 
(because cell e is reachable from cell s using only unoccupied cells.) 
If you never encounter cell e, then no path exists from s to e.

General Algorithm (which your code must follow):
-----------------------------------------------
  Do this once at the beginning:
    -create an empty Container of cells to explore
    -add the start cell to the Container
  Do this each subsequent step:
    -Container empty? If yes, report "NO PATHS" and end program
    -Take a cell out of Container
    -Has this cell already been recorded? If yes, then we've already
     explored from this cell, so skip the rest of this step and
     continue with the next step.
    -Is this cell the end cell? If so, we've found a path, so
     print it and end program.
    -The cell is a not-previously-explored, non-end cell that is
     reachable from the start cell. Explore it as follows:
          -identify all appropriate adjacent cells in M
          -add these identified cells to the Container
    -Record that this cell has been explored (so it won't be explored
     again).
