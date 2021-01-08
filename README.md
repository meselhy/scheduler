# scheduler
Messelhi's CPU Scheduler Simulator

There ara many simulation methods including :
- First Come, First Served Scheduling
- Shortest-Job-First Scheduling
- Priority Scheduling
- Round-Robin Scheduling 

The current version is only showing results for First Come First Served Scheduling & Round Robin Scheduling, so stay tuned for the others.


First you should compile the CPP file to be able to run it, to do so use this command line :
g++ cpu_simulator.cpp -o schedular

Then use this command to run the file:
Getopt is now implemented so to run the files you should use:
./schedular -f input.txt -o output.txt

Note: there must be input file for the processes in the same folder of the CPP file.
The input file may contain as many processes as you wish.
Note: There is an output text file for FCFS Scheduling that prints the results to it, it will be available for RR as well soon.

For any issues feel free to drop me a line.
