# cycle_start

  this is a task for the intership in JB

  the task is to code a function 'cycleStart' that find a start of the cycle in list and returns it.
  if there is no cycle, it returns NULL

  there are 2 .cpp files

  the file cycle_start.cpp contains a definition of function 'cycleStart',
  but a declaration of a list struct is in .h file

  the file unit_tests.cpp contains unit-tests and a 'main' function.
  it output OK to cerr in success way.
  and output failed test's number in case of failure.

  algorithm is simple:
  1 step: to find random cycle's element (element from cycle).
          for that it uses 2 ptr: the first go through the list with step 1, the second - with step 2.
          they meet in the cycle's element or in the end of the list.
          
  2 step: to find cycle's len.
          go throgh the cycle from the cycle's element to the cycle's element.

  3 step: to find start of the cycle.
          for that it uses 2 ptr: the first and the second ptr go throught the list with step 1,
          but the second ptr starts its path from 1 + cycle's len element (not index).
          they meet in the start of the cycle.
          
  time complexity estimation: O(n)
  
  memory complexity estimation: O(1)
