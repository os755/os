function runSJFPreemptive(processes) { 

let processQueue = copy(processes) 

let currentTime = 0 

let scheduledProcesses = [] 

let ganttChart = [] 

// While there are processes to execute 

while (some processes have remaining time) { 

// Find next process to execute 

let nextProcess = null 

let shortestRemainingTime = Infinity 

// Find available processes at current time 

for each process in processQueue { 

if (process.arrivalTime <= currentTime && process.remainingTime 

> 0) { 

if (process.remainingTime < shortestRemainingTime) { 

nextProcess = process 

shortestRemainingTime = process.remainingTime 

} 

} 

} 

// If no process available, jump to next arrival 

if (nextProcess === null) { 

currentTime = nextArrivalTime(processQueue) 

continue 

} 

// Process switch detected - update Gantt chart 

if (currentProcess changed) { 

update previous Gantt chart entry 

create new Gantt chart entry 

} 

// Execute process until next process arrives or current process 

finishes 

let runUntil = calculate_next_event_time() 

let executionTime = runUntil - currentTime 

nextProcess.remainingTime -= executionTime 

currentTime = runUntil 

// If process completed

if (nextProcess.remainingTime === 0) { 

update process metrics (finishTime, turnaroundTime, 

waitingTime) 

update Gantt chart 

add to completed processes 

} 

} 

return { ganttChart, scheduledProcesses } 

}
