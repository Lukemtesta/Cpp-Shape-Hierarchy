//
//  Geometry.h
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

#include <iostream>
#include <vector>
#include <list>

typedef std::pair<double, double> Vector;

namespace Maths
{
    class Geometry
    {
        public:
                    Geometry();
                    virtual ~Geometry() = 0;
    
        protected:
                    std::vector<std::vector<double> > DeriveAffineTransform(Vector& startPt, Vector& endPt);
                    Vector& ApplyAffineTransform(Vector& pt, std::vector< std::vector<double> >& M);
        
                    double Mean( std::list<double>& data);
        
                    // Calculate Look Vector For Each Displacement Instance. Returns List-based accumulator for each vector
                    // Sorted in order of favourite look direction
                    std::list<double> TemporalLookVector( std::list<double>& data, Vector& initialVector);
    };
    
    class DSP
    {
        public:
                    DSP(double samplingFrequency, double bufferSize);
                    virtual ~DSP() = 0;
        
        protected:
                    std::vector<double> FFT(std::vector<double>& data);
        
                    // Generates Ideal Frequency Filter. The last calculated filter is stored in this class.
                    std::vector<double> IdealFilter(int centre, int bandwidth);
        
                    // Applies FFT then multiplication operator
                    std::vector<double> ApplySpectralFilter( std::vector<double>::const_iterator& data, std::vector<double>& filter );
        
                    // Applies multiplication operator
                    std::vector<double> ApplyTemporalFilter( std::vector<double>::const_iterator& data, std::vector<double>& filter );
        
                    // Calculate Expectation Frequency of data, at index N, with index bandwidth K
                    double Expectation(std::vector<double>& data, int centre, int bandwidth);
        
        private:
                    // Override explicit Default Definition
                    DSP();
        
                    double Fsa;
                    double frequencyResolution;
        
    };
}