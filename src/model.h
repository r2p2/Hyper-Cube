#ifndef __model_h__
#define __model_h__

#include "Object3D.h"
#include "renderable.h"

class Model : public Object3D, public Renderable
{
public:
	Model (const Point& /*position*/, const Point& /*orientation*/);
	virtual ~Model ();
};

#endif /* __model_h__  */
