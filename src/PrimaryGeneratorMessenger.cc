#include "PrimaryGeneratorMessenger.hh"
#include "G4UIdirectory.hh"
#include "PrimaryGeneratorAction.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"

#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

PrimaryGeneratorMessenger::PrimaryGeneratorMessenger(PrimaryGeneratorAction* Gun)
    :G4UImessenger(), Action(Gun)
{
    GunDir = new G4UIdirectory("/gun/");
    GunDir->SetGuidance("gun control");

    EnergyCmd = new G4UIcmdWithADoubleAndUnit("/gun/setEnergy", this);
    EnergyCmd->SetGuidance("set/reset energy defined in PrimaryGenerator");
    EnergyCmd->SetParameterName("Energy",true);
    EnergyCmd->SetDefaultValue(1*MeV);
    EnergyCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
}

PrimaryGeneratorMessenger::~PrimaryGeneratorMessenger()
{
    delete EnergyCmd;
    delete GunDir;
}

void PrimaryGeneratorMessenger::SetNewValue(G4UIcommand* command,
                                            G4String newValue)
{ 
    if (command == EnergyCmd)
    {
        Action->SetDefaultKinematic(EnergyCmd->GetNewDoubleValue(newValue));
    }
}

