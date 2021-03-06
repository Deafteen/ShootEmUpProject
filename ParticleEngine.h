#pragma once
#include <list>
#include "Engine.h"
#include "Star.h"

class ParticleEngine : public Engine {
	std::list<Star*> StarList;
	EngineManager* engineManager;
public:
	ParticleEngine(void);
	ParticleEngine(EngineManager*);
	~ParticleEngine(void);

	void launch();
	void process();
};

