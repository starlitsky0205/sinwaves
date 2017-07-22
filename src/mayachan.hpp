//
//  mayachan.hpp
//  623
//
//  Created by maya on 2017/06/20.
//
//

#ifndef mayachan_hpp
#define mayachan_hpp

#include <stdio.h>
#include "ofMain.h"
#include <iostream>


class Mayachan{
    
    public:
    float x,y,m,pos;
    
    Mayachan();  //constructor 
    void setup();
    void update();
    void draw();
  };

#endif /* mayachan_hpp */
