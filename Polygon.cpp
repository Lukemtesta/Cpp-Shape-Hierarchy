//
//  Polygon.cpp
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


// ----------------------- Constructors --------------------


// Default constructor
Polygon::Polygon() : BaseShape(), Vertices(NULL) {};


// Copy Constructor : Deep Copy
Polygon::Polygon( const Polygon& Shape ) : BaseShape( (BaseShape&) Shape )
{
    Vertices = Shape.Vertices;
};


// Store Vertices using iterators. Stores front -> back
Polygon::Polygon( const Vector& pt, std::vector<Vector>& newVertices) : BaseShape(pt)
{
    Vertices = &newVertices;
};


// ------------------------ Destructor ----------------------


Polygon::~Polygon() { delete Vertices; std::cout << "Deleting [Polygon]" << std::endl; };


// ------------------------ Override Operators --------------


// Deep Copy
Polygon& Polygon::operator =( const Polygon& Shape )
{
    Vertices = Shape.Vertices;
    (BaseShape&) *this = (BaseShape&) Shape;

    return *this;
};


// Appends Deep Copy for Exception Safety : Manual Vertices Copy
Polygon& Polygon::operator +=( const std::vector<Vector>& newVertices )
{
    // Create Temp Copy of Dynamic Vector List
    std::vector<Vector> temp(newVertices);
    
    // set this vector size to minimize insert time
    Vertices->reserve( (temp.size() + Vertices->size())  );
    
    // store temp to this
    for ( std::vector<Vector>::const_iterator it = temp.begin() ; it != temp.end() ; it++ )
        Vertices->push_back(*it);
    
    // Update Center
    averageCenter();
    
    return *this;
};


// Deep Copy for Exception Safety : Manual Vertices Copy
Polygon& Polygon::operator =( const std::vector<Vector>& newVertices )
{
    if( Vertices != NULL )
        Vertices->clear();
    else
        Vertices = new std::vector<Vector>;
    
    // set this vector size to minimize insert time
    Vertices->reserve( newVertices.size() );
    
    // store temp to this
    for ( std::vector<Vector>::const_iterator it = newVertices.begin() ; it != newVertices.end() ; it++ )
        Vertices->push_back(*it);
    
    // Update Center
    averageCenter();
    
    return *this;
};



// Scale All Vertices
Polygon& Polygon::operator *=( double scale )
{
    for (std::vector<Vector>::iterator it(Vertices->begin()); it != Vertices->end(); it++)
    {
        it->first *= scale;
        it->second *= scale;
    }
    
    return *this;
};


// Scale All Vertices
Polygon& Polygon::operator /=( double scale )
{
    for (std::vector<Vector>::iterator it(Vertices->begin()); it != Vertices->end(); it++)
    {
        it->first /= scale;
        it->second /= scale;
    }
    
    return *this;
};



// ------------------------------ Member Functions -------------------------


// Return clone copy
BaseShape* Polygon::clone()
{
    BaseShape* ptr = new Polygon(*this);
    
    return ptr;
};

// Calculate Center of Mass of Polygon assuming equal weighted vertices
Vector Polygon::averageCenter()
{
    Vector Size;
    std::vector<Vector>::const_iterator it;
    
    for( it = Vertices->begin() ; it != Vertices->end(); it++)
    {
        Size.first = it->first;
        Size.second = it->second;
    }
    
    Size.first /= Vertices->size();
    Size.second /= Vertices->size();
    
    BaseShape::operator=(Size);
    
    std::cout << "Average Center [POLYGON]: " << Size.first << "," << Size.second << std::endl;
    
    return Size;
};


