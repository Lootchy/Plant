#pragma once
#include "State.h"
#include "gun.h"


class ReloadingState : public State {
public:
	explicit ReloadingState(Gun* gun) : State(gun) {}
	void Update(float deltatime) override;
	void Start() override;
};
