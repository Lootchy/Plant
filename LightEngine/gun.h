#pragma once
#include <iostream>
#include <string>

class State;
class PlantEntity;
class Gun {
public:
	enum class StateLabel {
		Idle,
		Shooting,
		Reloading,
		Empty,

		StateCount
	};
	static const int STATE_COUNT = (int)StateLabel::StateCount;

private:
	int mAmmo;
	int mCapacity;
	bool mIsReloading;
	bool mIsShooting;
	float mReloadTime;
	float mShootTime;
	float mReloadProgress;
	float mShootProgress;
	StateLabel mStateLabel = StateLabel::Idle;

	State* mStates[STATE_COUNT];    // Tableau de pointeurs vers les états
	State* mCurrentState = nullptr; // Pointeur vers l'état actuel

	int mTransition[STATE_COUNT][STATE_COUNT] = {
		// Idle, Shooting, Reloading, Empty
		{0, 1, 1, 1}, // Idle
		{1, 0, 0, 1}, // Shooting
		{1, 0, 0, 0}, // Reloading
		{1, 1, 0, 0}  // Empty
	};

public:
	friend class EmptyState;
	friend class ShootingState;
	friend class ReloadingState;
	friend class IdleState;
	Gun(int capacity, float reloadTime, float shootTime);
	~Gun();
	bool SetState(StateLabel to);
	void Update(float deltaTime);
	bool Shoot();
	bool Reload();
	void TransitionTo(StateLabel newstate);
	StateLabel GetLabel() { return mStateLabel; }
	StateLabel GetCurrentState();
};
std::ostream& operator<<(std::ostream& os, Gun::StateLabel state);