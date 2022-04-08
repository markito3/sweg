void poly() {

  // create and open a canvas
  // name, title, wtopx, wtopy, ww, ww
  TCanvas *sky = new TCanvas( "sky", "Tornado", 0, 0, 700, 500 );
  sky->SetFillColor(14);

  // create a 3-D geometry
  TGeoMaterial *mat = new TGeoMaterial("Vacuum", 0, 0,0); // define
                                                          // vacuum
                                                          // material
  TGeoMedium *med = new TGeoMedium("Vacuum", 1, mat); // define medium
                                                      // made of
                                                      // vacuum
  TGeoVolume *top = gGeoManager->MakeBox("Top", med, 5.0, 5.0, 5.0);
  gGeoManager->SetTopVolume(top); // make top the top volume
  gGeoManager->CloseGeometry(); // we are finished with creating the geometry
  top->SetLineColor(kMagenta); // set color
  gGeoManager->SetTopVisible(); // allow top volume to be seen
  top->Draw(); // draw the box

  //  create the view
  TView *view = TView::CreateView(1,0,0);
  view->SetRange(-10, -10, -10, 10, 10, 10);
  
  // define some 3-D points
  int numberOfMarkers=4;
  float x, y, z;
  TPolyMarker3D *pm3d[4]; // array of polymarkers
  // set points
  for (int i = 0; i < numberOfMarkers; i++) {
    pm3d[i] = new TPolyMarker3D(1); // each polymarker has one marker
    x = 0.5 * i;
    y = i;
    z = i*i;
    pm3d[i]->SetPoint(0, x, y, z);
    pm3d[i]->SetMarkerSize(1);
    pm3d[i]->SetMarkerColor(i + 2); // custom color
    pm3d[i]->SetMarkerStyle(3);
    pm3d[i]->Draw();
  }

  // draw some axes
  TAxis3D *axes = new TAxis3D();
  axes->Draw();
  
  sky->Update();

}
