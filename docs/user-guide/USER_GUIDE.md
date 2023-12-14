# User Guide

## Set Up
In the terminal, navigate to the build folder. This can be done with the  `cd build/ ` command. 
Then use the `cmake ..` command to build the entire program. 
Next, navigate to the app folder inside of build and then compile the actual simulation. This can be done with the following commands `cd app` then `make`.
To run the simulation executable run the `./main` command.

### Troubleshooting
If you run into errors with building the program, remove the build folder and add the directory back. Start from the root directory and run `rm -rf build/` then `mkdir build`, then follow the instructions above.

## The Simulation

### Creating the Simulation
At the start of the simulation, you will be prompted to use either a default simulation, or create a custom simulation. The default simulation has 12 robots: one of each type/ size, and an extra large robot of each type. The default building has 6 rooms: two of each size, with one medium sized room designated to not be cleaned. If you choose to create a custom simulation, you can pick how many robots and rooms you would like, and you can specify the types and sizes of each.

### Running the Simulation
When running the simulation, you will be presented with a menu of seven options. You can Create new task, Print Available Robots, Print Available Rooms, Set Room To DO NOT CLEAN, Make all clean rooms dirty, Charge all robots, and Exit the App / Simulation.   

The way to send robots to clean a room is by selecting the first option, Create new task. This will prompt you to select the room you would like to be cleaned. The simulation will automatically send the correct amount of robots to clean the room. If there are not enough robots available to clean that room, the room is already clean, or it has been designated as a room the robots cannot clean, an error messege will come up.   

The second option, Print Available Robots, will tell you all of the robots that are not currently cleaning a room. Each robot will print in their ID order. The simulation will say each robots ID, size, type, its probability of failure, and how much battery it has left.  

The third option, Print Available Rooms, will print each room in their ID order. The simulation will print each rooms ID, size, how long it takes for it to be mopped, vacuumed, and scrubbed, and its status. A room can either be clean, dirty, cleaning, or Do Not Clean.  

Sometimes, you might not want robots to go into a certain room for various reasons. You can acheive this by choosing the fourth option, Set Room To DO NOT CLEAN. This will prompt you for the ID of the room you would like to set to Do Not Clean. After you have set this, it cannot be undone without restarting the program.  

After some time, the rooms that the robots have cleaned may get dirty again, and you may want them to clean them again. Choosing the fifth option, Make all clean rooms dirty, will set the status of all rooms (other than those set to Do Not Clean) to dirty.   

Our robots are very smart, but they cannot charge themselves, so you will need to plug them in. The sixth option, Charge all robots, will start charging all of the robots that are not currently cleaning a room. They charge at a rate of 10 battery per second.   

When you are done with the simulation and want to exit, choose option seven, Exit the App / Simulation.  
