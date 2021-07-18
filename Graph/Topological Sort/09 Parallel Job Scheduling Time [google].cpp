// https://leetcode.com/discuss/interview-question/353830/google-phone-screen-parallel-job-scheduling

/*
There are N processes with some processes having dependencies on other processes 
(meaning if a process P1 is dependent on process P2, then P1 can only be started after P2 is complete). 
Assume that there won't be a cyclic dependency in the inputs.

Each process has a time duration (in sec) given by Duration array.
Processes can be run in parallel. We need to find the minimum time such that all processes are completed.

TestCase:
There are 4 processes -
A (Duration: 2 sec), B (Duration: 3 sec), C (Duration: 4 sec) and D (Duration: 5 sec)

B is dependent on A
C is dependent on A
D is dependent on B & C

In this case, min time would be 11 sec.
*/


/*
This que is same as:
https://leetcode.com/problems/time-needed-to-inform-all-employees/
*/