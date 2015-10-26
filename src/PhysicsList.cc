#include "PhysicsList.hh"
#include "G4EmProcessOptions.hh"

#include "G4EmStandardPhysics.hh"
#include "G4EmStandardPhysics_option1.hh"
#include "G4EmStandardPhysics_option2.hh"
#include "G4EmStandardPhysics_option3.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4EmStandardPhysicsSS.hh"
#include "G4EmLivermorePhysics.hh"
#include "G4EmPenelopePhysics.hh"
#include "G4EmLowEPPhysics.hh"
#include "G4StoppingPhysics.hh"

#include "DetectorConstruction.hh"

#include "G4LossTableManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

#include "G4BosonConstructor.hh"
#include "G4LeptonConstructor.hh"
#include "G4MesonConstructor.hh"
#include "G4BosonConstructor.hh"
#include "G4BaryonConstructor.hh"
#include "G4IonConstructor.hh"
#include "G4ShortLivedConstructor.hh"
#include "G4UserLimits.hh"
#include "G4EmStandardPhysics_option4.hh"

#include "PhysListEmStandardSingleSc.hh"

PhysicsList::PhysicsList(DetectorConstruction* geometry): Geometry(geometry)
{
    defaultCutValue = 1*km;
    SetCutsWithDefault();
    G4EmParameters* emParameters = G4EmParameters::Instance();
    emParameters->SetMaxEnergy(300*MeV);
    emParameters->SetLossFluctuations(true);
    emParameters->SetMinEnergy(1*eV);
    emParameters->SetNumberOfBinsPerDecade(50);
    // emParameters->SetBuildCSDARange(true);
    emParameters->SetApplyCuts(true);
    // emParameters->SetVerbose(true);

    // G4UserLimits* userLimits =  G4UserLimits(DBL_MAX, DBL_MAX, DBL_MAX, 0., 0.);

    RegisterPhysics(new G4EmStandardPhysics_option4);
   // RegisterPhysics(new PhysListEmStandardSingleSc);
    RegisterPhysics(new G4StoppingPhysics);
}

PhysicsList::~PhysicsList()
{}

void PhysicsList::ConstructProcess()
{
    G4VModularPhysicsList::ConstructProcess();
}

G4double PhysicsList::GetCSDARange(G4double val)
{
    G4LogicalVolume* wBox = Geometry->GetWaterLogic();
    const G4MaterialCutsCouple* couple = wBox->GetMaterialCutsCouple();
    const G4Material* water = wBox->GetMaterial();

    G4ParticleDefinition* part =  G4ParticleTable::GetParticleTable()->FindParticle("proton");
    G4double range = G4LossTableManager::Instance()->GetCSDARange(part,val,couple);

    return range;
}
