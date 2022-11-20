# M3OEP-achase4
Amanuel Chase

ADDED INSTALLATIONS:
- matplotlib for the graphing done in graph.py

The program starts in C++. This program is meant to simulate your bank balance over an inputted amount of months, using a selected dividend percentage. The Person Class is used to store personal information, while the Savings Class is meant to store your banking information, including the Person Object that holds your personal information. The simulation can be run as many times as the user wants, and they can put in different values for their balance, dividend percentage, and the amount of months that they want to calculate. After the user is done running simulations, the program will display a graph comparing data from the simulations. 

I decided to use python for the graphing because of how easy it is to plot data using the matplotlib library.

Concepts from module 3: 
- Use of multiple programming languages
- Passing information from one language to another via command line argument

Bugs: 
- While the program does validate zip code entries by making sure they Are 5 numbers long, zip codes starting with 0 don't get accepted.
- graph.py is not plotting the data correctly when 2 or more simulations are plotted together. Differing y values cause the y-axis values to fluctuate incorrectly

Expansion: 
- The next step for this program would be making it more user friendly through the use of graphics, menues, or a website. In otherwords, being able to use the program outside of clion. I beleive that the graphics module will make this possible. 

Citations:
- Just for learning how to make graphs with matplotlib: https://stackabuse.com/matplotlib-plot-multiple-line-plots-same-and-different-scales/ 

Grade I deserve:
- +40 for main program complexity. While the bulk of the code was written in other modules, the additions I have added for this open ended project use many concepts from module 3, the program is very interactive, and all user input is validated. 
- +20 for use of other programming languages. This is in the form of graph.py, and python program that is graphing the data collected from the C++ portion of the program. It makes sense to use python for graphing, as the matplotlib library makes it very easy to plot data. For that reason, it is used in the main program in a way that makes sense, and use of the language is designed well. 
- +2 for use of command line arguments. This is in the form of calling graph.py from the main program in C++, in order to graph the data gathered in main. 
- -5 For expected work. Style and documentation, as well as the recorded video follow all of the rubric guidlines. However, respitory commits do not span 7 days and significant contributions are not made on 3 seperate days. Project work began on Thursday afternoon 10/27, and ended on Sunday night 10/30. Meaning, respitory commits are spread over more than 3 days
 
Final grade: 57
