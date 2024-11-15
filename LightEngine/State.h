#pragma once

class Gun;

class State {
protected:
    Gun* mGun;
public:
    explicit State(Gun* gun) 
    {
        mGun = gun;
    }
    virtual ~State() {}

    virtual void Update(float deltaTime) = 0;
    virtual void Start() = 0;
};

