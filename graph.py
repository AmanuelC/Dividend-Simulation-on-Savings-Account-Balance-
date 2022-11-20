import matplotlib.pyplot as plt
import sys

#Program that takes balance data provided by main.cpp to
#Graph and compare simulations

#BUG: graph.py is not plotting the data correctly when 2 or more simulations
#are plotted together. Differing y values cause the y-axis values to fluctuate incorrectly

#Get file name with data through command line argument
fileName = sys.argv[1]
myFile = open(fileName, "r")

#Initilize lists to hold simulation data for graphing
months = []
balances = []

#Set count to 0 to keep track of months
count = 0

#Initilize line to random string
line = "a"
#Create plot for graphing
fig, ax = plt.subplots()
#While the list of balances isn't empty, keep reading from it
while line != '':
    #Read line from file
    line = myFile.readline()
    #If the line isn't a '-' mark indicating the the end of the data for particular simulation,
    #Append the line representing the balance to the balances list, and the count representing
    #The corresponding month

    if line != '-\n':
        months.append(count)
        balances.append(line)
        count = count + 1
    #If the line is a '-' mark indicating the the end of the data for particular simulation,
    #Plot the current gathered months and balances on the graph
    #Clear months and balances list for next simulation data from file
    #Set count back to 0 for keeping track of months

    if line == '-\n':
        ax.plot(months, balances)
        months.clear()
        balances.clear()
        count = 0

#Label graph
plt.xlabel('Months')
plt.ylabel('Balance')
plt.title('Simulations')

#Display graph to user
plt.show()

#Close myFile
myFile.close()


