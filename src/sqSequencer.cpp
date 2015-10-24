#include "sqSequencer.h"

using namespace std;

void sqSequencer::setup(){
    
    
}

void sqSequencer::update(){
    
    int seq_count = (int)sequences.size();
    time(&now); // get now time
    now_usec = chrono.getTime();
    
    SequenceData *s;
    
    for(int i=0; i<seq_count; i++){
        
        s = &sequences[i]; //Get sequence to process
        if( !s->finished && (s->st <= now)){ //If it was not played and time has came.
#ifdef DEBUG
            cout << "SEQ[" << i << "] start time has came. execute." << endl;
#endif
            execute(s); // If the time quantum, do it
            if(checkTheSequenceIsFinished(&sequences[i])){
                #ifdef DEBUG
                cout << "the seq [" << i << "] was  finised" << endl;
                #endif
            }
            
        }
        
    }
    
}


void sqSequencer::execute(SequenceData *s){

    
//    if(s->st_usec == -1) s->st_usec = chrono.getTime();
    if(s->st_usec == -1) s->st_usec = (chrono_t)s->st*MSEC_TO_CHRONO*MSEC_TO_CHRONO;
    
    chrono_t elapse = chrono.elapsed(s->st_usec,now_usec);
    
    //Process all quantum
    for(int i=0; i<s->qtm_count; i++){
        
        quantum *q = &s->quantums[i];
        if(q->done==true)continue;
        
        if(elapse >= (q->delta*MSEC_TO_CHRONO)){ //if the quantum time was came
#ifdef DEBUG
            cout << fixed << "bang" << elapse << ":" <<  q->delta*MSEC_TO_CHRONO << endl;
#endif
            //Process the bang quantum.
            executeOneQuantum(q);
            q->done=true; //flg the quantum was finished.
            
        }
        
    }
    
}

void sqSequencer::executeOneQuantum(quantum *q){

    
    if(q->cmd==TEST){
        
        cout << "SEQ: test was invoked" << endl;
        
    }


}

bool sqSequencer::checkTheSequenceIsFinished(SequenceData *s){
 
    int queue_count = 0;
    
    for(int i=0; i<s->qtm_count; i++){
        
        quantum *q = &s->quantums[i];
        if(q->done==false)queue_count++;
        
    }
    
    if(queue_count==0){
        s->finished=true; //If queue is nothing, the sequence is finished.
        return true;
    }else return false;
    
}