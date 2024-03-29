#pragma once

#include "StateMachine/StateInterface.h"

#include "State.generated.h"


DECLARE_MULTICAST_DELEGATE_OneParam(FStateNotifyDelegate, class UState*);
DECLARE_MULTICAST_DELEGATE_TwoParams(FStateNotifyTickDelegate, class UState*, float);

UCLASS(abstract, blueprintable, BlueprintType)
class STATEMACHINEEX_API UState
	: public UObject
	, public IStateInterface
{
	GENERATED_BODY()


public:
	virtual class UWorld* GetWorld() const override;


public:
	UPROPERTY(Category = "State", VisibleInstanceOnly, BlueprintReadOnly)
	uint8 StateId;

	UPROPERTY(Category = "State", VisibleInstanceOnly, BlueprintReadOnly)
	EStateStatus Status = EStateStatus::Inactive;

	UPROPERTY(Category = "State", VisibleInstanceOnly, BlueprintReadOnly, Transient)
	TObjectPtr<class UStateMachine> StateMachine;

	UPROPERTY(Category = "State", VisibleInstanceOnly, BlueprintReadWrite)
	bool bPaused;

	UPROPERTY(DuplicateTransient)
	TObjectPtr<class UInputComponent> InputComponent;


public:
	UFUNCTION(Category = "State Machine", BlueprintCallable, BlueprintPure)
	virtual class APlayerController* GetOwningPlayer() const;

	UFUNCTION(Category = "State Machine", BlueprintCallable, BlueprintPure)
	virtual class APawn* GetOwningPlayerPawn() const;


public:
	UState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());


public:
	FStateNotifyDelegate OnStateEnter;
	FStateNotifyTickDelegate OnStateTick;
	FStateNotifyDelegate OnStateExit;


protected:
	virtual UObject* ConstructState_Implementation(class UStateMachine* StateMachine) override;
	virtual class UStateMachine* GetStateMachine_Implementation() const override { return StateMachine; }
	virtual uint8 GetStateId_Implementation() const override { return StateId; }
	virtual EStateStatus GetStatus_Implementation() const override { return bPaused ? EStateStatus::Paused : Status; }
	virtual void SetStatus_Implementation(EStateStatus InStatus) override { Status = InStatus; }
	virtual void EnterState_Implementation() override;
	virtual void TickState_Implementation(float DeltaSeconds) override;
	virtual void ExitState_Implementation() override;
	virtual void Restart_Implementation() override;
};
