Sobol Sequence: ENSAE project by Etienne Vergnaud (June 2013)
etienne.vergnaud@ensae.fr

Aim of the project: 
- create Sobol sequence
- compare it with low-discrepancy sequences
- test the efficiency of these sequences
Full report available in French in the same repo.

Run this project:
Open Sobol.sln in Microsoft Visual C++ (written with the 2010 version)

List of code files:
Conversions (.cpp/.h): write integer numbers in Gray code
FBin: Binary fraction object
Halton: Build a Halton sequence (low-discrepancy sequence)
LCG: Linear congruencial generator
main: Read the prime numbers and call functions from WriteInFiles 
Polynomials: Read the primitive polynomials from a text file
Sobol: Build the Sobol sequence
Split: split function
WriteInFiles: Functions to write 2D or 3D sequences in txt files that can be read by LateX for visualization


List of text/csv files:
1-1000000.csv: 1000000 first prime numbers
polynomials.txt: 21200 first primitive polynomials

