#ifndef TrackingAction_h
#define TrackingAction_h

#include "G4UserTrackingAction.hh"

#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"

class PrimaryGeneratorAction;

class TrackingAction : public G4UserTrackingAction {

public:
    TrackingAction()
    {
        sumTrack = 0;
        numTrack = 0;
        i=1;
    }

    ~TrackingAction()
    { }

    virtual void PreUserTrackingAction(const G4Track*);
    virtual void PostUserTrackingAction(const G4Track*);

    void Reset();

private:
    G4double sumTrack;
    G4int numTrack;
    G4int i;
};

#endif
