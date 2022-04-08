// 1-liner: simple example of drawing a track
// read track data from track.txt

{
  // set up a geometry
  gSystem->Load("libGeom"); // load geometry routines
  new TGeoManager("world", "track example"); // define global
                                                     // geometry
                                                     // manager
  TGeoMaterial *mat = new TGeoMaterial("Vacuum", 0, 0,0); // define
                                                          // vacuum
                                                          // material
  TGeoMedium *med = new TGeoMedium("Vacuum", 1, mat); // define medium
                                                      // made of
                                                      // vacuum
  TGeoVolume *top = gGeoManager->MakeBox("Top", med, 50.0, 50.0, 50.0);
  // defines a box, destined to be the top volume
  gGeoManager->SetTopVolume(top); // make top the top volume

  // open the data file
  ifstream in;
  in.open("track.txt");

  // read in the data
  const Int_t n = 1000;
  Int_t index[n];
  Double_t x[n], y[n], z[n];
  Int_t nl = 0;
  while (1) {
    in >> index[nl] >> x[nl] >> y[nl] >> z[nl];
    if (!in.good()) break;
    printf("%f %f %f %f\n", index[nl], x[nl], y[nl], z[nl]);
    nl++;
  }
  printf(" found %d points\n",nl);

  // close the input file
  in.close();

  Int_t track_index = gGeoManager->AddTrack(13,0,0); // create a track
  TVirtualGeoTrack *track = gGeoManager->GetTrack(track_index); // get its pointer
  for (Int_t i = 0; i < nl; i++) {
    track->AddPoint(x[i], y[i], z[i], (Double_t)(index[i]));
  }

  gGeoManager->CloseGeometry(); // we are finished with creating the geometry

  track->Draw();
}
