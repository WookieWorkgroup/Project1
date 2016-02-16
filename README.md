# Project1
Project1 for CS303

Term now has a constructor that takes a string. This works in every case, except for when a polynomial starts with a negative term.
Ex:
3X^3+4X^4+5X^5 reads in just fine as three distinct terms 3X^3, 4X^4, and 5X^5
3X^3-4X^4-5X^5 reads in just fine as three distinct terms 3X^3, -4X^4, and -5X^5
-3X^3+4X^4 does not read in fine. It comes in as -3X^3 and nothing else.

I'm still having problems getting the Terms to read in properly. If either of you want to take a look at reading in the Polynomials, that would be superb.
