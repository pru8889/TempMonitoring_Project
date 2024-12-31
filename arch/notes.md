# Design decision

* Temperature doesn't change rapidly in a msec range. Hence, I will go with a cyclic task to reduce the load on the system
* Why 2 tasks for adc and temp monitor is due to unavailability of the runtime capabilities of the micro controller


## Todo

[ ] To crosscheck if bare metal OS does have a OS scheduler

[x] Write init notes mentioning that config of ADC is out of scope of the task

## Dec 24 todo list
[x] Read HW version from input 
[x] Create enums to read HW version from O or 1
[ ] Check file names hint: Change hello.c to init or something
[ ] Fix bug considering float values

## Dec 25 todo list
[x] Create Cmake project
[x] Update Cmake project to add adcsampling
[x] Basic skeleton for adc created
[ ] Create function for adc sampling 
[ ] Based on HW rev change sampling rate

## Dec 30 todo list
[x] Start with adding new files
[ ] !!!testing needs to be done

## Dec 31 todo list
[ ] Create a new repo and test if you can build the SW
[x] Adc sampling logic with HW variation completed
[ ] Change file name of hello.c to run.c may be
[ ] Change variable name if they look to be developed by copilot
[ ] Create a static array to provide adc values and feed it to adc sampling for testing and real time cases
## Interview questions
[ ] Ask about job description and what is expected from your role
[ ] Why did you choose float because you want the decimal values to be saved while doing the average 
