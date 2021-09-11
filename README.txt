/******************************************************************\
* Project Name: Personality Test                                  *
* Author: Jasper Mesenbrink                                       *
* CWID: 10875480                                                  *
* Date: 9/10/21                                                   *
* Description: a program that takes in a question text file and   *
* determines a personality from the answers given.                *
\*****************************************************************/

tests ran on questions file:
1. A regex was run on each line to determine if it was a question or not.
The regex followed the format: "([0-9]+ [A-z] [A-z] .+)".
Any line that matched the regex was taken in as a question.

2. The integer in the first spot of the file (the number of questions)
had to match the number of questions that the program received / stored in the questions vector.