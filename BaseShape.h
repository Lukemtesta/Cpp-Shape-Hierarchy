//
//  BaseShape.h
//  Cpp_Revision
//
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


#include <iostream>
#include <vector>


typedef std::pair<double,double> Vector;
typedef std::pair<double,std::pair<double,double> > Vector3;
typedef std::pair<std::pair<double,double>,std::pair<double,double> > Vector4;


// Abstract Class dependent on Graphic Library (e.g. openCV or openGL) for rendering. Only contains 1 pt so no need to instantiate
class BaseShape
{
    public:
                // Constructors
                BaseShape();
                BaseShape(const BaseShape& Shape);
                BaseShape(const Vector& pt );
    
                // Destructors
                virtual ~BaseShape();
    
    
                // Override Assignment Operator
                inline BaseShape& operator =(const BaseShape& Shape);

                // Center point manipulation
                inline BaseShape& operator =(const Vector& pt);
                inline BaseShape& operator +=( const Vector& offset );
                inline BaseShape& operator -=( const Vector& offset );
    
                // Orientation (axis-angle) not set in shape hierachy generation
                inline BaseShape& operator =(const Vector3& angle);
                inline BaseShape& operator +=(const Vector3& angle);
                inline BaseShape& operator -=(const Vector3& angle);
    
                // Colour as Vec4f for openGL
                inline BaseShape& operator =(const Vector4& colour);
                inline BaseShape& operator +=(const Vector4& colour);
                inline BaseShape& operator -=(const Vector4& colour);
    
                // AxisAngle Magnitude ( degrees )
                inline BaseShape& operator =(const float& angleMag);
                inline BaseShape& operator +=(const float& angleMag);
                inline BaseShape& operator -=(const float& angleMag);
    
    
                // Member Functions
                inline Vector getCentre() const;
                inline Vector3 getOrientation() const;
                inline Vector4 getColour() const;
                inline float getAngle() const;
    
                virtual void print() const;
    
    
                // Pure Virtual Member Pointers
                virtual BaseShape* clone() = 0;
                virtual int size() = 0;
                virtual std::vector<Vector> getVertices() = 0;
                //virtual void render() = 0;
    
    private:
    
                Vector3* Orientation;
                Vector* Centre;
                Vector4* Colour;
                float Angle;
};


// ----------------------------- Inline Members ---------------------------


// Returns Magnitude of AxisAngle
float BaseShape::getAngle() const
{
    return Angle;
};


Vector4 BaseShape::getColour() const
{
    if( Colour == NULL )
    {
        std::cerr << " No Angle " << std::endl;
        exit(0);
    }
    else
        return *Colour;
};


Vector3 BaseShape::getOrientation() const
{
    if( Orientation == NULL )
    {
        std::cerr << " No Angle " << std::endl;
        exit(0);
    }
    else
        return *Orientation;
};


Vector BaseShape::getCentre() const
{
    if( Centre == NULL )
    {
        std::cerr << " No Centre" << std::endl;
        exit(0);
    }
    else
        return *Centre;
};


// --------------------------- Inline Overrides -----------------------------


// Deep Copy : Exception Safe
BaseShape& BaseShape::operator=(const BaseShape& Shape)
{
    Centre = new Vector( *Shape.Centre );
    
    return *this;
};

// Manual Deep Copy
BaseShape& BaseShape::operator =( const Vector& pt )
{
    Centre = new Vector(pt);
    
    return *this;
};


// Offset Centre
BaseShape& BaseShape::operator +=( const Vector& offset )
{
    Centre->first += offset.first;
    Centre->second += offset.second;
    
    return *this;
};


// Offset Centre
BaseShape& BaseShape::operator -=( const Vector& offset )
{    
    Centre->first -= offset.first;
    Centre->second -= offset.second;
    
    return *this;
};


// Set Orientation
BaseShape& BaseShape::operator= (const Vector3& angle)
{
    Orientation = new Vector3( angle.first, *new std::pair<double,double>(angle.second.first, angle.second.second) );
    
    return *this;
};


// Offset Orientation
BaseShape& BaseShape::operator+= (const Vector3& angle)
{
    if (Orientation == NULL)
        Orientation = new Vector3( 0, *new std::pair<double,double>(0, 0) );
    
    Orientation->first += angle.first;
    Orientation->second.first += angle.second.first;
    Orientation->second.second += angle.second.second;
    
    return *this;
};


// Offset Orientation
BaseShape& BaseShape::operator-= (const Vector3& angle)
{
    if (Orientation == NULL)
        Orientation = new Vector3( 0, *new std::pair<double,double>(0, 0) );
    
    Orientation->first -= angle.first;
    Orientation->second.first -= angle.second.first;
    Orientation->second.second -= angle.second.second;
    
    return *this;
};


// Set Colour
BaseShape& BaseShape::operator= (const Vector4& colour)
{
    if( Colour == NULL )
        Colour = new Vector4( *new std::pair<double,double>(0,0), *new std::pair<double,double>(0,0) );
    
    Colour->first.first = colour.first.first;
    Colour->first.second = colour.first.second;
    Colour->second.first = colour.second.first;
    Colour->second.second = colour.second.second;
    
    return *this;
};


// Offset Colour
BaseShape& BaseShape::operator+= (const Vector4& colour)
{
    if( Colour == NULL )
        Colour = new Vector4( *new std::pair<double,double>(0,0), *new std::pair<double,double>(0,0) );
    
    Colour->first.first = colour.first.first;
    Colour->first.second = colour.first.second;
    Colour->second.first = colour.second.first;
    Colour->second.second = colour.second.second;
    
    return *this;
};


// Offset Colour
BaseShape& BaseShape::operator-= (const Vector4& colour)
{
    if( Colour == NULL )
        Colour = new Vector4( *new std::pair<double,double>(0,0), *new std::pair<double,double>(0,0) );
    
    Colour->first.first = colour.first.first;
    Colour->first.second = colour.first.second;
    Colour->second.first = colour.second.first;
    Colour->second.second = colour.second.second;
    
    return *this;
};



// Set Angle Magnitude
BaseShape& BaseShape::operator =(const float& angleMag)
{
    Angle = angleMag;
    
    return *this;
};


// Offset Angle Magnitude
BaseShape& BaseShape::operator +=(const float& angleMag)
{
    Angle += angleMag;
    
    return *this;
};


// Offset Angle Magnitude
BaseShape& BaseShape::operator -=(const float& angleMag)
{
    Angle -= angleMag;
    
    return *this;
};



// ----------------------------- Test Code --------------------------

/*
BaseShape* temp1 = new BaseShape();
std::cout << "temp1: ";
temp1->printCentre();

BaseShape* temp2 = new BaseShape( *new Vector(2,2) );
std::cout << "temp2: ";
temp2->printCentre();

temp1 = new BaseShape( *temp2 );
std::cout << "temp1: ";
temp1->printCentre();

temp1 = new BaseShape();
std::cout << "temp1: ";
temp1 = temp2;
temp1->printCentre();

temp2 = new BaseShape( *new Vector(3,3) );
std::cout << "temp1: ";
temp1 = temp2;
temp1->printCentre();
*/