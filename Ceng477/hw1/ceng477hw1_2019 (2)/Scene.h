#ifndef _SCENE_H_
#define _SCENE_H_

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>


#include "Ray.h"
#include "defs.h"

// Forward declarations to avoid cyclic references
class Camera;
class PointLight;
class Material;
class Shape;

using namespace std;

// Class to hold everything related to a scene.
class Scene
{
public:
	int maxRecursionDepth;			// Maximum recursion depth
	float intTestEps;				// IntersectionTestEpsilon. You will need this one while implementing intersect routines in Shape class
	float shadowRayEps;				// ShadowRayEpsilon. You will need this one while generating shadow rays.
	Vector3f backgroundColor;		// Background color
	Vector3f ambientLight;			// Ambient light radiance

	vector<Camera *> cameras;		// Vector holding all cameras
	vector<PointLight *> lights;	// Vector holding all point lights
	vector<Material *> materials;	// Vector holding all materials
	vector<Vector3f> vertices;		// Vector holding all vertices (vertex data)
	vector<Shape *> objects;		// Vector holding all shapes

	Scene(const char *xmlPath);		// Constructor. Parses XML file and initializes vectors above. Implemented for you.

	void renderScene(void);			// Method to render scene, an image is created for each camera in the scene. You will implement this.

private:
    // Write any other stuff here
		ReturnVal getPoint(Ray ray); //return the nearest point intersect with ray
		float getDistance(Vector3f a, Vector3f b);
		Vector3f colorize(ReturnVal &point, int maxDepth, Ray & ray);
		Vector3f GetUnitVectorWith2Point(Vector3f a,Vector3f b);
		Vector3f FindDiffuseAndSpecular(PointLight &light, ReturnVal &point,Vector3f &pTol,Ray & ray);
		float dotproduct(Vector3f a, Vector3f b);

};

#endif
