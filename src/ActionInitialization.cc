#include "ActionInitialization.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "TrackingAction.hh"


void ActionInitialization::BuildForMaster() const
{}

void ActionInitialization::Build() const
{
    SetUserAction(Primary);
    SetUserAction(TrAction);
}

