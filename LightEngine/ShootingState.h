#pragma once
#include "State.h"
#include "gun.h"

class ShootingState : public State {
    Gun* mGun;
public:
    explicit ShootingState(Gun* gun) : State(gun) {}
    void Update(float deltaTime) override;
    void Start() override;
};
