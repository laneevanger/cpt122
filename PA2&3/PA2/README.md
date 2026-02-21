# Important
uses windows only commands for clean and pause

# Project

all of the file formatting was done after completion so its not perfect, 
it'll be to standard on the next PA when I actually build code with it in mind
and know how to do it properly

DELETE was being a keyword for some reason so its DEL now in main

for some reason load wants all items to be inserted at front so the list reveses
itself every time it load stores because store is never stated to read backwards

I seperated PA2 and PA3's functions into seperate files for 1 function per file and
even with the gaurd code it started erroring wit a struct type redefinition error
so I combined the files to prevent debugging an error I didn't plan for when 
creating my functions originally 

I think most input fields allow no input but it doesnt break the program so im not
going to wrap every input in a repeat case, just the ones that break logic (artist 
names)

the testing framework is kinda weak cuz most options wont even let you select them
when the list is empty

## Testing

if it runs it works (assert stuff)