#include <chrono>
#include <Windows.h>
#include "gun.h"
#include "ShootingState.h"
#include "ReloadingState.h"
#include "EmptyState.h"
#include "IdleState.h"



Gun::Gun(int capacity, float reloadTime, float shootTime)
	: mCapacity(capacity), mReloadTime(reloadTime), mShootTime(shootTime) {
	mAmmo = mCapacity;
	mShootProgress = 0;
	mReloadProgress = 0;

	// Initialisation des objets d’état dans le tableau
	mStates[(int)StateLabel::Shooting] = new ShootingState(this);
	mStates[(int)StateLabel::Reloading] = new ReloadingState(this);
	mStates[(int)StateLabel::Empty] = new EmptyState(this);
	mStates[(int)StateLabel::Idle] = new IdleState(this);

	// Initialisation de l’état actuel
	mStateLabel = StateLabel::Idle;
	mCurrentState = mStates[(int)StateLabel::Idle];
	mCurrentState->Start();
	std::cout << "Gun Create" << std::endl;
}

Gun::~Gun() {
	// Libération des objets d'état
	for (int i = 0; i < STATE_COUNT; ++i) {
		delete mStates[i];
	}
}

bool Gun::SetState(StateLabel to) {
	if (mTransition[(int)mStateLabel][(int)to] == 0) {
		return false;
	}
	mStateLabel = to;
	mCurrentState = mStates[(int)mStateLabel];
	mCurrentState->Start();
	return true;
}

bool Gun::Shoot() {
	if (SetState(StateLabel::Shooting) && mAmmo > 0) {
		mShootProgress = mShootTime;
		
		std::cout << "Bam" << std::endl;
		mAmmo -= 1;
		if (mAmmo <= 0) {
			SetState(StateLabel::Empty);
		}
		return true;
	}

	else { return false; }
}

bool Gun::Reload() {
	if (SetState(StateLabel::Reloading)) {
		std::cout << "Reloading..." << std::endl;
		mReloadProgress = mReloadTime;
		mAmmo = mCapacity;
		std::cout << "Ammo left : " << mAmmo << std::endl;
		return true;
	}
}

void Gun::Update(float deltaTime) {
	if (mCurrentState) {
		mCurrentState->Update(deltaTime);
	}
}

Gun::StateLabel Gun::GetCurrentState() {
	return mStateLabel;
}

void Gun::TransitionTo(StateLabel newstate) {
	if (SetState(newstate)) {
		switch (newstate) {
		case StateLabel::Idle:
			std::cout << "Transitioned to Idle state." << std::endl;
			break;
		case StateLabel::Shooting:
			std::cout << "Transitioned to Shooting state." << std::endl;
			break;
		case StateLabel::Reloading:
			std::cout << "Transitioned to Reloading state." << std::endl;
			break;
		case StateLabel::Empty:
			std::cout << "Transitioned to Empty state." << std::endl;
			break;
		}
	}
}

std::ostream& operator<<(std::ostream& os, Gun::StateLabel state) {
	switch (state) {
	case Gun::StateLabel::Idle:      return os << "Idle";
	case Gun::StateLabel::Shooting:  return os << "Shooting";
	case Gun::StateLabel::Reloading: return os << "Reloading";
	case Gun::StateLabel::Empty:     return os << "Empty";
	default:                         return os << "Unknown";
	}
}