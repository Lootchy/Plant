#include "EmptyState.h"


void EmptyState::Update(float deltaTime) {
    if (mGun->mAmmo < 0) {
        mGun->SetState(Gun::StateLabel::Empty);
    }
    if (mGun->GetCurrentState() == Gun::StateLabel::Empty) {
        if (mGun->mAmmo > 0) {
            mGun->SetState(Gun::StateLabel::Idle);
        }
    }
}

void EmptyState::Start() {
    std::cout << "Gun is in Empty state" << std::endl;
}