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
  TGeoVolume *top = gGeoManager->MakeBox("Top", med, 100.0, 100.0, 100.0);
  // defines a box, destined to be the top volume
  
  TGeoSphere *sphere = new TGeoSphere(0.0, 10.0, 0.0, 180.0, 0.0, 360.0);
  // defines the shape of a sphere
  TGeoVolume *sphereVac = new TGeoVolume("bubble", sphere, med);
  // defines the volume bubble as a sphere made of vacuum
  TGeoTranslation* trans[3];
  trans[0] = new TGeoTranslation(-50.0, -50.0, -50.0);
  trans[1] = new TGeoTranslation(0.0, 0.0, 0.0);
  trans[2] = new TGeoTranslation(50.0, 50.0, 50.0);
  for (int i = 0; i < 3; i++) {
    top->AddNode(sphereVac, i, trans[i]); // add the ball to the
					    // world volume
  }

  TGeoTube *tube = new TGeoTube(0.0, 10., 100.); // shape
  TGeoVolume *tubeVac = new TGeoVolume("cylinder", tube, med); // volume
  TGeoRotation *rot = new TGeoRotation("rotname", 135.0, 15.0, 0.0);
  TGeoCombiTrans *combi = new TGeoCombiTrans("combiname", 70.0, -70.0, 0.0, rot);
  top->AddNode(tubeVac, 1, combi);

  gGeoManager->SetTopVolume(top); // make top the top volume
  gGeoManager->CloseGeometry(); // we are finished with creating the geometry

  top->SetLineColor(kMagenta); // set color
  gGeoManager->SetTopVisible(); // allow top volume to be seen
  top->Draw(); // draw it

  // draw some axes
  TAxis3D *axes = new TAxis3D();
  axes->Draw();

}
