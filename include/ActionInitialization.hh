#ifndef ActionInitialization_h
#define ActionInitialization_h

#include "G4VUserActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "TrackingAction.hh"

class DetectorConstruction;
class G4VSteppingVerbose;

class ActionInitialization : public G4VUserActionInitialization
{
public:
    ActionInitialization(PrimaryGeneratorAction* primary, TrackingAction* trAction) : Primary(primary), TrAction(trAction) {}
    virtual ~ActionInitialization() {}

    virtual void BuildForMaster() const;
    virtual void Build() const;

private:
    PrimaryGeneratorAction* Primary;
    TrackingAction* TrAction;


};

#endif


