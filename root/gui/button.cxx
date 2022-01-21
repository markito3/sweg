#include <iostream>
#include <TApplication.h>
#include <TGClient.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TRandom.h>
#include <TGButton.h>
#include <TRootEmbeddedCanvas.h>
#include <TGeoManager.h>
#include <TView.h>
#include <TAxis3D.h>
#include "button.h"
#include "otherClass.h"

MyMainFrame::MyMainFrame(const TGWindow *p,UInt_t w,UInt_t h) {
  // Create a main frame
  fMain = new TGMainFrame(p,w,h);
  // Create canvas widget
  fEcanvas = new TRootEmbeddedCanvas("Ecanvas",fMain,500,500);
  fMain->AddFrame(fEcanvas, new TGLayoutHints(kLHintsExpandX| kLHintsExpandY,
                                              10,10,10,1));

  // Create a horizontal frame widget with buttons
  TGHorizontalFrame *hframe = new TGHorizontalFrame(fMain,200,40);

  TGTextButton *draw = new TGTextButton(hframe,"&Draw");
  draw->Connect("Clicked()","MyMainFrame",this,"DoDraw()");
  hframe->AddFrame(draw, new TGLayoutHints(kLHintsCenterX,5,5,3,4));

  TGTextButton *viewButton = new TGTextButton(hframe,"&View");
  viewButton->Connect("Clicked()","MyMainFrame",this,"DoView()");
  hframe->AddFrame(viewButton, new TGLayoutHints(kLHintsCenterX,5,5,3,4));

  TGTextButton *zoomButton = new TGTextButton(hframe,"&Zoom");
  zoomButton->Connect("Clicked()","MyMainFrame",this,"DoZoom()");
  hframe->AddFrame(zoomButton, new TGLayoutHints(kLHintsCenterX,5,5,3,4));

  TGTextButton *print = new TGTextButton(hframe,"&Print");
  print->Connect("Clicked()","MyMainFrame",this,"DoPrint()");
  hframe->AddFrame(print, new TGLayoutHints(kLHintsCenterX,5,5,3,4));

  ocPtr = new otherClass;
  TGTextButton *printOther = new TGTextButton(hframe,"&PrintOther");
  printOther->Connect("Clicked()","otherClass",ocPtr,"DoPrintOther()");
  hframe->AddFrame(printOther, new TGLayoutHints(kLHintsCenterX,5,5,3,4));

  TGTextButton *exit = new TGTextButton(hframe,"&Exit",
                                        "gApplication->Terminate(0)");
  hframe->AddFrame(exit, new TGLayoutHints(kLHintsCenterX,5,5,3,4));
  fMain->AddFrame(hframe, new TGLayoutHints(kLHintsCenterX,2,2,2,2));
  // Set a name to the main frame
  fMain->SetWindowName("Simple Example");
  // Map all subwindows of main frame
  fMain->MapSubwindows();
  // Initialize the layout algorithm
  fMain->Resize(fMain->GetDefaultSize());
  // Map main frame
  fMain->MapWindow();
}
void MyMainFrame::DoDraw() {
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

  // put in axes
  TAxis3D *axes = new TAxis3D();
  axes->Draw();

  //  create the view
  Float_t rangePar = 15.0;
  view = TView::CreateView(1,0,0);
  view->SetRange(-rangePar, -rangePar, -rangePar, rangePar, rangePar, rangePar);

  fCanvas = fEcanvas->GetCanvas();
  fCanvas->Update();
}

void MyMainFrame::DoView() {
  Float_t rangePar = 30.0;
  view->SetRange(-rangePar, -rangePar, -rangePar, rangePar, rangePar, rangePar);
  fCanvas->Modified();
  fCanvas->Update();
}

void MyMainFrame::DoZoom() {
  view->Zoom();
  fCanvas->Modified();
  fCanvas->Update();
}

void MyMainFrame::DoPrint() {
  std::cout << "Hello world.\n" ;
}

MyMainFrame::~MyMainFrame() {
  // Clean up used widgets: frames, buttons, layouthints
  delete ocPtr;
  fMain->Cleanup();
  delete fMain;
}

void example() {
  // Popup the GUI...
  new MyMainFrame(gClient->GetRoot(),200,200);
}

int main(int argc, char **argv) {
  TApplication theApp("App",&argc,argv);
  example();
  theApp.Run();
  return 0;
}
