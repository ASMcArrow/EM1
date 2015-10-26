#ifndef DETECTORCONSTRUCTION_H
#define DETECTORCONSTRUCTION_H

#include "G4VUserDetectorConstruction.hh"
#include "G4Material.hh"

class G4LogicalVolume;
class G4VPhysicalVolume;

using namespace CLHEP;

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
    DetectorConstruction() {}
    ~DetectorConstruction() {}

    G4VPhysicalVolume* Construct();

    G4LogicalVolume* GetWaterLogic()
    { return WLogic; }

 // void ConstructSDandField();
 // This method is used in multi-threaded applications to build
 // per-worker non-shared objects: SensitiveDetectors and Field managers

private:
    void InitializeMaterials();
    std::map <std::string, G4Material*> MaterialMap;

    G4LogicalVolume* WLogic;

};

#endif
