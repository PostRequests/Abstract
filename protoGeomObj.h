#pragma once
class protoGeomObj
{
public:
	virtual protoGeomObj* clone() = 0;
	virtual void info() = 0; 
	virtual ~protoGeomObj() = default;
};

