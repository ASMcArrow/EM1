#ifndef PhysicsList_h
#define PhysicsList_h

#include "G4VModularPhysicsList.hh"
#include "globals.hh"

class DetectorConstruction;
class PhysicsListMessenger;
class G4VPhysicsConstructor;

class PhysicsList: public G4VModularPhysicsList
{
  public:
    PhysicsList(DetectorConstruction* geometry);
   ~PhysicsList();

    virtual void ConstructProcess();

    G4double GetCSDARange(G4double energy);
      
  private:    
    DetectorConstruction* Geometry;
};

#endif

