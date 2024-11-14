#pragma once
#include "State.h"
#include "gun.h"


class IdleState : public State {
	Gun* mGun;
public:
	explicit IdleState(Gun* gun) : State(gun) {}
	void Update(float deltatime) override;
	void Start() override;
};