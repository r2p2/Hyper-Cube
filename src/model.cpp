#include "model.h"

Model::Model(const Point& position, const Point& orientation)
: Object3D(position, orientation)
, Renderable()
{}

Model::~Model()
{}
