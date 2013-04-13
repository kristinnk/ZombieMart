class position_class {
public:
    int x;
    int y;
};

class bounding_box {
public:
    int x;
    int y;
    int w;
    int h;
};

#ifndef __collides_function
#define __collides_function

class utility_class {
public:
    bool collides( bounding_box a, bounding_box b ) 
    {
        if ( a.x < ( b.x + b.w ) && 
           ( a.x + a.w ) > b.x   && 
             a.y < ( b.y + b.h ) && 
           ( a.y + a.h ) > b.y ) {
            return true;
        } else {
            return false;
        }
    }
    
};


#endif

/*
function collides(a, b) {
  return a.x < b.x + b.width &&
         a.x + a.width > b.x &&
         a.y < b.y + b.height &&
         a.y + a.height > b.y;
}
*/