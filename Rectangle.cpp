//
//  Rectangle.cpp
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

#include "Rectangle.h"


//------------------------------------------ Constructors -------------------------------------


// Explicit Default Constructor
Rectangle::Rectangle() : Polygon(), width(0), height(0) {};

// Copy Constructor
Rectangle::Rectangle( const Rectangle& Shape ) : Polygon ( (Polygon&) Shape ), width( Shape.width ), height ( Shape.height ) {};


Rectangle:: Rectangle( const Vector& pt, std::vector<Vector>& Vertices ) : Polygon ( pt, Vertices )
{
    width = Vertices[0].first - Vertices[1].first;
    height = Vertices[1].second - Vertices[3].second;
};


Rectangle::Rectangle( const Vector pt, const double w, const double h) : Polygon(), height(h), width(w)
{
    std::vector<Vector> Vertices;
    
    Vertices.push_back( *new Vector( pt.first - (width/2), pt.second - (height/2)  ) );
    Vertices.push_back( *new Vector( pt.first + (width/2), pt.second - (height/2)  ) );
    Vertices.push_back( *new Vector( pt.first - (width/2), pt.second + (height/2)  ) );
    Vertices.push_back( *new Vector( pt.first + (width/2), pt.second + (height/2)  ) );
    
    (Polygon&) *this = Vertices;    
};



// ---------------------------------------- Destructors -----------------------------------------


// Explicit Destructor
Rectangle::~Rectangle() { std::cout << "Deleting [RECTANGLE]" << std::endl; };



// ---------------------------------------- Overload Operators ----------------------------------


// Non-Exception Safe Deep Copy
Rectangle& Rectangle::operator =( const Rectangle& Shape )
{
    if ( !isEqual( *this, (Rectangle&) Shape ) )
    {
        this->width = Shape.width;
        this->height = Shape.height;
    
        // Execute Polymorphic Assignment Operator Member with Sliced Members
        (Polygon&) *this = (Polygon&) Shape;
    }
    
    return *this;
};





