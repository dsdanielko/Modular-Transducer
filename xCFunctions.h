#ifndef SYS_HEADERS
#include <stdint.h>
#endif

#ifndef FUNCTIONDECS_H_
#define FUNCTIONDECS_H_

#ifndef TRANSDUCER_COUNT
#define TRANSDUCER_COUNT 8
#endif
#ifndef DATA_LENGTH
#define DATA_LENGTH 22
#endif

//struct definitions
typedef struct
{
    //topRatio is the frequency of pp
    unsigned int frequency;
    //testLength is number of bursts in the test
    short testLength;
    //burstLength is the number of pulses per burst
    short burstLength;
    //brf is the burst repetition frequency
    short brf;
    //pulseLength is the number of cycles per pulse
    short pulseLength;
    //prf is the pulse repetition frequency (10000Hz max)
    short prf;
    //phase is an array of how many ticks each pp is out of phase where 0 is no shift
    short phase;//0 to 49 or FULL_WIDTH - 1
    //burstWait is how many ticks to wait after each burst
    unsigned int burstWait;
    //pulseWait is how many ticks to wait after each pulse
    unsigned int pulseWait;
} ppStruct;

typedef struct
{
    //magRatio is an array of pwm 'on' period in a 50 tick waveperiod for every transducer
    short magRatio;//0 to 50
} pwmStruct;

void dataProcessor(ppStruct ppD[TRANSDUCER_COUNT], pwmStruct pwmD[TRANSDUCER_COUNT]);

void dataCapture(unsigned int data[DATA_LENGTH]);

void clkSet();

void pwmDrive(pwmStruct pwmD1, pwmStruct pwmD2,
        out buffered port:1 p1, out buffered port:1 p2, streaming chanend synchPulse);

void freqDrive(ppStruct ppD1, ppStruct ppD2, out buffered port:4 p, streaming chanend synchPulse);

#endif /* FUNCTIONDECS_H_ */