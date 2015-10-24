//#define DEBUG
#define MSEC_TO_CHRONO 1000

#include <stdio.h>
#include <iostream>
#include <vector>
#include <time.h>
#include "SequenceData.h"
#include "slNotice.h"

class sqSequencer {
    
    public:
        sqSequencer(){
            
            notice = slNotice::instance();
            
        }
        void setup();
        void update();
        void execute(SequenceData *s);
        virtual void executeOneQuantum(quantum *q);
        bool checkTheSequenceIsFinished(SequenceData *s);
    
        std::vector<SequenceData> sequences;
        time_t now;
        chrono_t now_usec;
        slChrono chrono;
        slNotice *notice;
        std::string str;

    
};