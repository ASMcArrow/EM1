#undef G4MULTITHREADED

#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif

#include "G4UImanager.hh"
#include "Randomize.hh"

#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "ActionInitialization.hh"
#include "G4Event.hh"
#include "TrackingAction.hh"
#include "PrimaryGeneratorMessenger.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "G4ios.hh"

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv) {

    G4Random::setTheEngine(new CLHEP::RanecuEngine);
    
#ifdef G4MULTITHREADED
    G4MTRunManager* runManager = new G4MTRunManager;
    runManager->SetNumberOfThreads(8);
#else
    G4RunManager* runManager = new G4RunManager;
#endif

    DetectorConstruction* det = new DetectorConstruction;
    runManager->SetUserInitialization(det);

    PhysicsList* phys = new PhysicsList(det);
    runManager->SetUserInitialization(phys);

    PrimaryGeneratorAction* primary = new PrimaryGeneratorAction;
    PrimaryGeneratorMessenger* messenger = new PrimaryGeneratorMessenger(primary);

    TrackingAction* trAction = new TrackingAction;
    runManager->SetUserInitialization(new ActionInitialization(primary, trAction));

    runManager->Initialize();

    G4UImanager* UI = G4UImanager::GetUIpointer();

    for (G4int i = 1; i <= 300; i++)
    {
        std::stringstream ss;
        ss << i;
        G4String istr = ss.str();

        G4String command = "/gun/setEnergy "+istr+" MeV";
        UI->ApplyCommand(command);
        runManager->BeamOn(1000000);
        trAction->Reset();

//        std::ofstream file;
//        file.open("CSDARanges_78.txt", std::ios_base::app | std::ios_base::out);
//        file << i << " " << phys->GetCSDARange(G4double(i))/cm << "\n";
//        file.close();
    }


    delete runManager;
    return 0;
}

