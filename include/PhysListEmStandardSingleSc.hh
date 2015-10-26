#ifndef PhysListEmStandardSingleSc_h
#define PhysListEmStandardSingleSc_h 1

#include "G4VPhysicsConstructor.hh"
#include "globals.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class PhysListEmStandardSingleSc : public G4VPhysicsConstructor
{
public:
  PhysListEmStandardSingleSc(G4int ver = 1);

  // obsolete
  PhysListEmStandardSingleSc(G4int ver, const G4String& name);

  virtual ~PhysListEmStandardSingleSc();

  virtual void ConstructParticle();
  virtual void ConstructProcess();

private:
  G4int  verbose;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif






