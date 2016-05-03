//
//  TrackView.h
//  TrackCylinder
//
//  Created by John Lindner on 4/30/16.
//  Copyright © 2016 John Lindner. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#include <vector>
#import "triangle.hpp"

using namespace std;

enum indices {X,Y,Z};
const short DIM = 3;                // 3 dimensional space
const short SIDES = 3;              // triangles have 3 sides

const short N_VERTICES = 42;
const short N_TRIANGLES = 80;


class randomWalker
{
public:
    int num_choices_taken;
    int *path;
    randomWalker(int num_points){
        path = new int [num_points];
        num_choices_taken = num_points; };
};



//enum Vertex { UP, RIGHT, BOT_RIGHT, BOT_LEFT, LEFT}

//double verticies[N][]




double vertex0[N_VERTICES][DIM] = // from Mathematica
{{0, 0, -1.},
    {0, 0, 1.},
    {-0.894427, 0, -0.447214},
    {0.894427, 0, 0.447214},
    {0.723607, -0.525731, -0.447214},
    {0.723607, 0.525731, -0.447214},
    {-0.723607, -0.525731, 0.447214},
    {-0.723607, 0.525731, 0.447214},
    {-0.276393, -0.850651, -0.447214},
    {-0.276393, 0.850651, -0.447214},
    {0.276393, -0.850651, 0.447214},
    {0.276393, 0.850651, 0.447214},
    {0, 1., 0},
    {-0.587785, 0.809017, 0},
    {-0.262866, 0.809017, 0.525731},
    {-0.587785, -0.809017, 0},
    {0, -1., 0},
    {-0.262866, -0.809017, 0.525731},
    {0.587785, 0.809017, 0},
    {0.262866, 0.809017, -0.525731},
    {-0.850651, 0, 0.525731},
    {-0.951057, 0.309017, 0},
    {-0.951057, -0.309017, 0},
    {0.688191, -0.5, 0.525731},
    {0.587785, -0.809017, 0},
    {0.951057, -0.309017, 0},
    {-0.425325, -0.309017, 0.850651},
    {-0.425325, 0.309017, 0.850651},
    {0.425325, 0.309017, -0.850651}, {-0.16246, 0.5, -0.850651}, {-0.688191, 0.5, -0.525731}, {-0.525731, 0, -0.850651}, {-0.16246, -0.5, -0.850651}, {-0.688191, -0.5, -0.525731}, {0.688191, 0.5, 0.525731}, {0.951057, 0.309017, 0}, {0.262866, -0.809017, -0.525731}, {0.425325, -0.309017, -0.850651}, {0.850651, 0, -0.525731}, {0.16246, -0.5, 0.850651}, {0.525731, 0, 0.850651}, {0.16246, 0.5, 0.850651}};

int triangleVertices[N_TRIANGLES][SIDES] = // from Mathematica
{
    {13, 12, 9},
    {16, 15, 8},
    {18, 12, 11},
    {21, 20, 7},
    {24, 23, 10},
    {26, 20, 6},
    {28, 19, 5},
    {30, 13, 9},
    {31, 29, 0},
    {33, 32, 8},
    {34, 18, 11},
    {22, 15, 6},
    {36, 16, 8},
    {37, 32, 0},
    {38, 28, 5},
    {25, 35, 3},
    {39, 17, 10},
    {40, 23, 3},
    {41, 34, 11},
    {27, 14, 7},
    {14, 13, 7},
    {12, 14, 11},
    {14, 12, 13},
    {17, 16, 10},
    {15, 17, 6},
    {17, 15, 16},
    {19, 18, 5},
    {12, 19, 9},
    {19, 12, 18},
    {22, 21, 2},
    {20, 22, 6},
    {22, 20, 21},
    {25, 24, 4},
    {23, 25, 3},
    {25, 23, 24},
    {27, 26, 1},
    {20, 27, 7},
    {27, 20, 26},
    {29, 28, 0},
    {19, 29, 9},
    {29, 19, 28},
    {21, 30, 2},
    {13, 21, 7},
    {21, 13, 30},
    {30, 31, 2},
    {29, 30, 9}, {30, 29, 31}, {31, 33, 2}, {32, 31, 0}, {31, 32, 33}, {35, 34, 3}, {18, 35, 5}, {35, 18, 34}, {33, 22, 2}, {15, 33, 8}, {33, 15, 22}, {24, 36, 4}, {16, 24, 10}, {24, 16, 36}, {36, 37, 4}, {32, 36, 8}, {36, 32, 37}, {37, 38, 4}, {28, 37, 0}, {37, 28, 38}, {38, 25, 4}, {35, 38, 5}, {38, 35, 25}, {26, 39, 1}, {17, 26, 6}, {26, 17, 39}, {39, 40, 1}, {23, 39, 10}, {39, 23, 40}, {40, 41, 1}, {34, 40, 3}, {40, 34, 41}, {41, 27, 1}, {14, 41, 11}, {41, 14, 27}};

#define SQR(x) ((x)*(x))

@interface TrackView : NSView
{
    NSPoint projection[N_VERTICES];     // 2D shadow of points
    
    double magnify;                     // scale projection
    double eyePoint;
    
    double vertex[N_VERTICES][DIM];
    long double R[DIM][DIM];            // total (cumulative) rotation matrix
    
    double theta;                       // for virtual track cylinder
    NSPoint oldMousePoint;
    
    
    
    vector <triangle> triangleList;
    vector <int> path ;
    
}

- (void)awakeFromNib;
- (void)updateRotationMatrix;
- (void)updateVertices;
- (void)drawRect:(NSRect)dirtyRect;
- (void)drawFace:(int)n;
-(void)initialiseTriangleList;
-(IBAction)reset:(id)sender;

-(void)PathGenerator: (int) start;

- (void)mouseDown:(NSEvent *)theEvent;
- (void)mouseDragged:(NSEvent *)theEvent;

@end
