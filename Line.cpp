//
//  Line.cpp
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

#include "Line.h"

// ----------------------------------------------- Constructors ------------------------------------------

// Explicit Default Constructor
Line::Line() : Polygon() {};


// Store End Points of Line
Line::Line(const Vector& pt1, const Vector& pt2) : Polygon()
{
    Polygon* tempPLYGN = this;
    BaseShape* tempSHAPE = this;
    
    std::vector<Vector> endPoints( *new Vector(pt1), *new Vector(pt2) );
    Vector centre( (pt2.first - pt1.first)/2, (pt2.second - pt1.second)/2 );
    
    *tempPLYGN = endPoints;
    *tempSHAPE = centre;
};


// Store Line Centre and Width
Line::Line(const Vector& centre, double width)
{
    Polygon* tempPLYGN = this;
    BaseShape* tempSHAPE = this;
    
    std::vector<Vector> endPoints( *new Vector(  (width/2)-centre.first, (width/2)-centre.second ), *new Vector(  (width/2)+centre.first, (width/2)+centre.second ) );

    *tempPLYGN = endPoints;
    *tempSHAPE = centre;
};

    
// Explicit Destructor
Line::~Line() { std::cout << "Deleting [Line]" << std::endl; };

