Lynn Le - 6646443813 - CSCI104 - HW2

#### Problem 1
 - Part a: 1, 2 (it should start in the line directly after the command/dependency line)
 - Part b: "clean" gets rid of all the files ending with ".o" and "~", and also the files "shape1" and "shape2". It does this by executing "rm -f *.o *~ shape1 shape2". "make shape1" executes "g++ -c -o shape.o shape.cpp -std=c++11 -ggdb", then "g++ -c -o shape1.o shape1.cpp -std=c++11 -ggdb", and finally "g++ -o shape1 shape1.o shape.o -std=c++11 -ggdb". This creates the files "shape1", "shape1.o", and "shape.o".
 - Part c: .PHONY explicitly tells "Make" that the actions/commands following it are not associated with files, so the command does not make any files after running them (like normal "Make" commands make an object file or something). It is also used to avoid conflict of external files/targets in the same directory of the same name (ie. if you had a file called "clean", .PHONY runs "make clean" as expected).
 - Part d: 2, 4

#### Problem 2
 - Part a: "README.md" is unmodified and the branch is up-to-date with master.
 - Part b: "README.md" is modified. "fun_problem.txt" is untracked.
 - Part c: "README.md" is still of modified status, and "fun_problem.txt" is considered a new file. Both are changes that have yet to be committed, so they are staged.
 - Part d: "README.md" and "fun_problem.txt" are both modified, and not staged. the branch is ahead of the master by 1 commit.
 - Part e: "README.md" is modified and staged, and "fun_problem.txt" no longer shows up as a change that needs to be staged. Because we used "git checkout" on it, we discarded the changes made, so "fun_problem.txt" is empty again, with noting in it; it's in the state it was before we made changes.
 - Part f: "README.md" is both staged AND modified, due to staging it before but not committing it, and then modifying it again but not staging it.
 - Part g: They should be seeing ">figure courtesy of the Pro Git book by Scott Chacon" because that's the top line and already there, "Markdown is easy" (which we added first), and "Markdown is too easy" (the last change with the last commit); no line breaks on the webpage viewer though. But if we commited and pushed the last change, then "Fancy git move" should be the last line,  since that was the last change we made.

#### Problem 3
 - I can only try

#### Problem 4
 - A correctly parenthesized expression can be defined as follows:
    - An empty string is a correctly parenthesized expression (has no parentheses at all).
    - A string "S0" consisting of only lowercase letters is a correctly parenthesized expression (has no parentheses at all).
       - S0 => 'a'-'z'
    - A string "S1" consiting of the concatonation of "(", a string "S", and ")" is a correctly parenthesized expression; where "S" is a correctly parenthesized expression itself.
       - S1 => (S)
    - A string "S2" consiting of the concatonation of "[", a string "S", and "]" is a correctly parenthesized expression; where "S" is a correctly parenthesized expression itself.
       - S2 => [S]

#### Problem 5
 - see: hw2q5.cpp
 - compile with: make
 - run with: ./hw2q5 hw2q5.txt 100000000
 - can use any file name or number in the arguments (I had a hw2q5_test.txt file I used for testing other stuff too)
 - OBSERVATIONS on recursion and iteration:
    - I used 100000000 iterations per run of the program, and I ran the program 10 times.
    - The average speed of the iterative loop was 3.185000e-08 seconds.
    - The average speed of the recursive loop was 5.322000e-08 seconds.
    - Which was faster: Iteration (on average, it is 2.137000e-08 seconds faster).
    - Percentage of how much faster it was (based on [100*(p2-p1)/p1]): 67.09576%

#### Problem 6
 - see: hw2q6_old.cpp
 - compile with: make
 - run with: ./hw2q5_old FILENAME.txt
 - CURRENTLY: WIP. Recursion is wonky, I can't seem to get recursion and backtracking right. I tried experimenting in hw2q6.cpp but it doesn't work so please use hw2q6_old.cpp, that one sort of works but only a little? I know it's not right anyway.