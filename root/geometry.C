{

  //
  // example developed in chapter 18
  //

  //  gROOT->Reset();
  // for some reason, Reset is not a good thing here, perhaps because
  // of global object gGeoManager. It causes problems when trying to
  // repeat the macro within the same ROOT session

  gSystem->Load("libGeom"); // load geometry routines
  new TGeoManager("world", "the simplest geometry"); // define global
						     // geometry
						     // manager
  TGeoMaterial *mat = new TGeoMaterial("Vacuum", 0, 0,0); // define
							  // vacuum
							  // material
  TGeoMedium *med = new TGeoMedium("Vacuum", 1, mat); // define medium
						      // made of
						      // vacuum
  TGeoVolume *top = gGeoManager->MakeBox("Top", med, 10.0, 10.0, 10.0);
  // define a box, destined to be the top volume
  gGeoManager->SetTopVolume(top); // make top the top volume
  gGeoManager->CloseGeometry(); // we are finished with creating the geometry

  top->SetLineColor(kMagenta); // set color
  gGeoManager->SetTopVisible(); // allow top volume to be seen
  top->Draw(); // draw it
}
