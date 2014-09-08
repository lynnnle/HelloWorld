Lynn Le - 6646443813
CSCI104 - HW2

Problem 1
 - Part a: 
 - Part b: "clean" gets rid of all the files ending with ".o" and "~", and also the files "shape1" and "shape2". It does this by executing "rm -f *.o *~ shape1 shape2". "make shape1" executes "g++ -c -o shape.o shape.cpp -std=c++11 -ggdb", then "g++ -c -o shape1.o shape1.cpp -std=c++11 -ggdb", and finally "g++ -o shape1 shape1.o shape.o -std=c++11 -ggdb". This creates the files "shape1", "shape1.o", and "shape.o".
 - Part c: .PHONY explicitly tells "Make" that the actions/commands following it are not associated with files, so the command does not make any files after running them (like normal "Make" commands make an object file or something). It is also used to avoid conflict of external files/targets in the same directory of the same name (ie. if you had a file called "clean", .PHONY runs "make clean" as expected).
 - Part d: 2, 4

Problem 2
 - Part a: "README.md" is unmodified and the branch is up-to-date with master.
 - Part b: "README.md" is modified. "fun_problem.txt" is untracked.
 - Part c: "README.md" is still of modified status, and "fun_problem.txt" is considered a new file. Both are changes that have yet to be committed, so they are staged.
 - Part d: "README.md" and "fun_problem.txt" are both modified, and not staged. the branch is ahead of the master by 1 commit.
 - Part e: "README.md" is modified and staged, and "fun_problem.txt" no longer shows up as a change that needs to be staged. Because we used "git checkout" on it, we discarded the changes made, so "fun_problem.txt" is empty again, with noting in it; it's in the state it was before we made changes.
 - Part f: "README.md" is both staged AND modified, due to staging it before but not committing it, and then modifying it again but not staging it.
 - Part g: They SHOULD be seeing "Markdown is easy" and "Markdown is too easy", but not "Fancy git move" since that wasn't commited before we pushed. Hwoever, when trying to push, I got an "ERROR: Repository not found" and I'm assuming that's because it's a private repository.