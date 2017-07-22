//
//  mayachan.cpp
//  623
//
//  Created by maya on 2017/06/20.
//
//

#include "mayachan.hpp"


Mayachan::Mayachan(){
    //=void setup
    m=0;
    pos=0;
    //最少でok
   }

void Mayachan::update(){
    pos=pos+1;
    m=m+0.1;
    if(m>360){
        m=0;
    }
       }


void Mayachan::draw(){
    ofRotateX(m);
    for (x=-500;x<500;x=x+1){
    y=sin(x);
    ofSetColor(ofRandom(255), ofRandom(255),255);
    ofDrawCircle(15*x+pos,200*y,1.5);
    }
    
}
