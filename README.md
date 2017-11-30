You can find the challenge description in challenge.txt and the files related to code are in the code folder.

Once you have the code folder on your local PC, open the terminal and change directory to where the files are.

Although the code is in only one file, I have made a makefile for any changes in future.

Instructions to be followed:


### Using with a makefile :

1.) Run the following commands <br /> 
`make` <br />
`./output`

2.) Enter the inputs accordingly and press 0 to exit.

3.) To clear extra files, run the following command <br />
`make clean`
 
### Using without a makefile :

1.) Since I have only a single, we don't necessarily need a makefile so alternate command : <br /> 
`g++ -std=c++11 main.cpp`

2.) To input via console, run <br />
`./a.out`

3.) To use an input file <br />
`./a.out <input.txt> output.txt`

