//
//  triangle.cpp
//  TrackCylinder
//
//  Created by Avi on 5/2/16.
//  Copyright © 2016 John Lindner. All rights reserved.
//

#include "triangle.hpp"


triangle::triangle()
{
    myVerticies.x = 0;
    myVerticies.y = 0;
    myVerticies.z = 0;
    
    
    for (int i = 0; i < 3; i++)
    {
        verticies temp(0,0,0);
        
        neighbours.push_back(temp);
        
        neighbourIndex[i] = 0;
    }
    
    
    
}

triangle::triangle(verticies myVertex, vector <verticies> nbr, int index[3])
{
    
    myVerticies.x = myVertex.x;
    myVerticies.y = myVertex.y;
    myVerticies.z = myVertex.z;
    
    
    for ( int i = 0; i < 3; i++)
    {
        verticies temp (nbr[i].x, nbr[i].y, nbr[i].z);
        neighbours.push_back(temp);
        neighbourIndex[i] = index[i];
    }
    
    
}


