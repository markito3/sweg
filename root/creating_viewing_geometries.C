// not a very usefule macro, depends on the na49.root files, which I
// could not find after a cursory search


{
   //
   // This macro generates
   // a  Canvas 
   // with 2 views of the NA49 detector.
   //
   gROOT->Reset();
   c1 = new TCanvas("c1","The NA49 canvas",200,10,700,780);

   gBenchmark->Start("na49view");

   all = new TPad("all","A Global view of NA49",0.02,0.02,0.48,0.82,28);
   tof = new TPad("tof","One Time Of Flight element",0.52,0.02,0.98,0.82,28);
   all->Draw();
   tof->Draw();
   na49title = new TPaveLabel(0.1,0.86,0.9,0.98,"Two views of the NA49 detector");
   na49title->SetFillColor(32);
   na49title->Draw();
   //
   nageom = new TFile("na49.root");
   TGeometry *n49 =(TGeometry*)gROOT->FindObject("na49");
   n49->SetBomb(1.2);
   n49->cd();     //Set current geometry
   all->cd();     //Set current pad
   n49->Draw();
   c1->Update();
   tof->cd();
   TOFR1->Draw();
   c1->Update();

   gBenchmark->Show("na49view");

   // To have a better and dynamic view of any of these pads,
   // you can click with the middle button of your mouse to select it.
   // Then select "View with x3d" in the VIEW menu of the Canvas.
   // Once in x3d, you are in wireframe mode by default.
   // You can switch to:
   //   - Hidden Line mode by typing E
   //   - Solid mode by typing R
   //   - Wireframe mode by typing W
   //   - Stereo mode by clicking S (and you need special glasses)
   //   - To leave x3d type Q
}

