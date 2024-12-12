# Design decision

* Temperature doesn't change rapidly in a msec range. Hence, I will go with a cyclic task to reduce the load on the system
* Why 2 tasks for adc and temp monitor is due to unavailability of the runtime capabilities of the micro controller


## Todo

[ ] To crosscheck if bare metal OS does have a OS scheduler

[x] Write init notes mentioning that config of ADC is out of scope of the task


## Interview questions
[ ] Ask about job description and what is expected from your role
