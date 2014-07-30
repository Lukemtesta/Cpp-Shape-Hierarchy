//
//  Line.h
//  Cpp_Revision
//

/*

Copyright (c) 2014 Luke Marcus Biagio Testa
All rights reserved.

Redistribution and use in source and binary forms are permitted
provided that the above copyright notice and this paragraph are
duplicated in all such forms and that any documentation,
advertising materials, and other materials related to such
distribution and use acknowledge that the software was developed
by the Luke Marcus Biagio Testa. The name of the
Luke Marcus Biagio Testa may not be used to endorse or promote products derived
from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 * 
 */

#include "Polygon.h"

class Line : public Polygon
{
    public:
            // Constructors
            Line();
            Line(const Vector& pt1, const Vector& pt2);
            Line(const Vector& centre, double width);
    
            // Destructors
            virtual ~Line();
    
};



// --------------------------------------- Test Code -------------------------------------------


/*
Line* line = new Line();
line->print();

line = new Line( *new Vector(14, -4), *new Vector(15, 315) );
line->print();
BaseShape* temp = new BaseShape ( (BaseShape&) *line );
temp->print();

line = new Line( *new Vector(14, -4), 15 );
line->print();
temp = new BaseShape ( (BaseShape&) *line );
temp->print();
*/