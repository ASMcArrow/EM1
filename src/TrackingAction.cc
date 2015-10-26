#include "TrackingAction.hh"
#include "G4Track.hh"
#include "G4TrackStatus.hh"

void TrackingAction::PreUserTrackingAction(const G4Track*)
{}

void TrackingAction::Reset()
{
    G4cout << "sumTrack is " << sumTrack/cm << " numTrack is " << numTrack << G4endl;
    G4cout << (G4double)((sumTrack/cm)/numTrack) << G4endl;

    std::ofstream file;
    file.open("ProjRanges_opt4_78_1km.txt", std::ios_base::app | std::ios_base::out);
    file << i << " " << (G4double)((sumTrack/cm)/numTrack) << "\n";
    file.close();

    sumTrack = 0;
    numTrack = 0;
    i = i + 1;
}

void TrackingAction::PostUserTrackingAction(const G4Track* aTrack)
{
    if (aTrack->GetTrackID() == 1)
    {
        G4ThreeVector length = aTrack->GetPosition() - G4ThreeVector(0*m, 0*m, 1*mm);
        numTrack = numTrack + 1;
        sumTrack = sumTrack + length.z();

        //        G4ThreeVector length = aTrack->GetPosition() - G4ThreeVector(0*m, 0*m, 1*mm);
        //        numTrack = numTrack + 1;
        //        sumTrack = sumTrack + length.mag();
    }
}


