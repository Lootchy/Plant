#pragma once
#include "State.h"
#include "gun.h"

class EmptyState : public State {
public:
	explicit EmptyState(Gun* gun) : State(gun) {}
	void Update(float deltatime) override;
	void Start() override;
};