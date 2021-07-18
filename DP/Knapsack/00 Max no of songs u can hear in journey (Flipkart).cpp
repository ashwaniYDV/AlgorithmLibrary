/*
You are going on a journey. The journey is of eactly T no of minutes.
You have a playliast of songs with time given in minutes.
Return the max number of songs you can hear in T minutes. The selected song should be fully heard.

Example:
T = 5
playlist = [2, 3, 5, 4, 1]
*/


/*
Solution:

It is a 0-1 knapsack problem with 
Knapsack capacity = Journey time T
Weight array = Playlist array
Value array = [1, 1, 1, 1, ...]
*/
