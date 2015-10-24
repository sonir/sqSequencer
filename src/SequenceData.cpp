//
//  Sequence.cpp
//  yagiSys
//
//  Created by sonir on 6/16/15.
//
//

#include "SequenceData.h"

using namespace std;


void SequenceData::print(){

    
    cout << "finished:" << finished << endl;
    cout << "st:" << st << endl;
    cout << "qtm_count:" << qtm_count << endl;
    
    for(int i=0; i<qtm_count; i++){
        
        quantum q = quantums[i];
        
        cout << "--Quantm " << i << " --" << endl;
        cout << "delta:" << q.delta << endl;
        cout << "command:" << q.cmd << endl;
        cout << "param1a:" << q.param[0] << endl;
        cout << "param1b:" << q.param[1] << endl;
        cout << "param1c:" << q.param[2] << endl;
        cout << "param2a:" << q.param[3] << endl;
        cout << "param2b:" << q.param[4] << endl;
        cout << "param2c:" << q.param[5] << endl;
        cout << "param3a:" << q.param[6] << endl;
        cout << "param3b:" << q.param[7] << endl;
        
    }
    
    
}