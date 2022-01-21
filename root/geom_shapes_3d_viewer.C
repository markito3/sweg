{
   //
   // To see the output of this macro, click  here 
   //
  gROOT->Reset(); // start from the beginning
  c1 = new TCanvas("c1","Geometry Shapes",200,10,700,500); // create a canvas to draw on

   //  Define some volumes
   //  These appear to be 
  brik = new TBRIK("BRIK","BRIK","void",200,150,150); // rectangular, right angles, what are the units?
   /* TRD1 is a trapezoid with the x dimension varying along z.
 It has 7 parameters:

     - name       name of the shape
     - title      shape's title
     - material  (see TMaterial)
     - dx1        half-length along x at the z surface positioned at -DZ
     - dx2        half-length along x at the z surface positioned at +DZ
     - dy         half-length along the y-axis
     - dz         half-length along the z-axis */
   trd1 = new TTRD1("TRD1","TRD1","void",200,50,100,100);
   /*  TRD2 is a trapezoid with both x and y dimensions varying along z.
 It has 8 parameters:

     - name       name of the shape
     - title      shape's title
     - material  (see TMaterial)
     - dx1        half-length along x at the z surface positioned at -DZ
     - dx2        half-length along x at the z surface positioned at +DZ
     - dy1        half-length along y at the z surface positioned at -DZ
     - dy2        half-length along y at the z surface positioned at +DZ
     - dz         half-length along the z-axis
*/
   trd2 = new TTRD2("TRD2","TRD2","void",200,50,200,50,100);
   trap = new TTRAP("TRAP","TRAP","void",190,0,0,60,40,90,15,120,80,180,15);
   para = new TPARA("PARA","PARA","void",100,200,200,15,30,30);
   gtra = new TGTRA("GTRA","GTRA","void",390,0,0,20,60,40,90,15,120,80,180,15);
   tube = new TTUBE("TUBE","TUBE","void",150,200,400);
   tubs = new TTUBS("TUBS","TUBS","void",80,100,100,90,235);
   cone = new TCONE("CONE","CONE","void",50,70,120,150,100);
   cons = new TCONS("CONS","CONS","void",50,100,100,200,300,90,270);

   /* cylindrical symmetry
      PCON is a polycone. It has the following parameters:

     - name       name of the shape
     - title      shape's title
     - material  (see TMaterial)
     - phi1       the azimuthal angle phi at which the volume begins (angles
                  are counted counterclockwise)
     - dphi       opening angle of the volume, which extends from
                  phi1 to phi1+dphi
     - nz         number of planes perpendicular to the z axis where
                  the dimension of the section is given -- this number
                  should be at least 2
     - rmin       array of dimension nz with minimum radius at a given plane
     - rmax       array of dimension nz with maximum radius at a given plane
     - z          array of dimension nz with z position of given plane
   */

   pcon = new TPCON("PCON","PCON","void",180,270,4);

   /* DefineSection(Int_t secNum, Float_t z, Float_t rmin, Float_t rmax)
 Defines section secNum of the polycone

     - rmin  radius of the inner circle in the cross-section

     - rmax  radius of the outer circle in the cross-section

     - z     z coordinate of the section
   */

   pcon->DefineSection(0,50,100,-200); // define first of four sections in that container
   pcon->DefineSection(1,50,80,-50);
   pcon->DefineSection(2,50,80,50);
   pcon->DefineSection(3,50,100,200);
   /* regular polygonal symmetry
 PGON is a polygon. It has the following parameters:

     - name       name of the shape
     - title      shape's title
     - material  (see TMaterial)
     - phi1       the azimuthal angle &phi at which the volume begins (angles
                  are counted counterclockwise)
     - dphi1      opening angle of the volume, which extends from phi1 to
                  phi1+dphi
     - npdv       number of sides of the cross section between the given
                  phi limits
     - nz         number of planes perpendicular to the z axis where
                  the dimension of the section is given -- this number
                  should be at least 2
     - rmin       array of dimension nz with minimum radius at a given plane
     - rmax       array of dimension nz with maximum radius at a given plane
     - z          array of dimension nz with z position of given plane
   */
   pgon = new TPGON("PGON","PGON","void",180,270,8,4);
   pgon->DefineSection(0,50,100,-200);
   pgon->DefineSection(1,50,80,-50);
   pgon->DefineSection(2,50,80,50);
   pgon->DefineSection(3,50,100,200);

   //  Set shapes attributes
   brik->SetLineColor(1);
   trd1->SetLineColor(2);
   trd2->SetLineColor(3);
   trap->SetLineColor(4);
   para->SetLineColor(5);
   gtra->SetLineColor(7);
   tube->SetLineColor(6);
   tubs->SetLineColor(7);
   cone->SetLineColor(2);
   cons->SetLineColor(3);
   pcon->SetLineColor(6);
   pgon->SetLineColor(2);

   //  Build the geometry hierarchy

   /*
 TNode(const char *name, const char *title, const char *shapename, Double_t x, Double_t y, Double_t z, const char *matrixname, Option_t *option)

 Node normal constructor.

    name    is the name of the node
    title   is title
    shapename is the name of the referenced shape
    x,y,z   are the offsets of the volume with respect to his mother
    matrixname  is the name of the rotation matrix

    This new node is added into the list of sons of the current node
   */

   // node contains positioning information

   node1 = new TNode("NODE1","NODE1","BRIK");
   node1->cd(); // set the current node to NODE1

   node2  = new TNode("NODE2","NODE2","TRD1",0,0,-1000); // add volume TRD1 to current node
   node3  = new TNode("NODE3","NODE3","TRD2",0,0,1000);
   node4  = new TNode("NODE4","NODE4","TRAP",0,-1000,0);
   node5  = new TNode("NODE5","NODE5","PARA",0,1000,0);
   node6  = new TNode("NODE6","NODE6","TUBE",-1000,0,0);
   node7  = new TNode("NODE7","NODE7","TUBS",1000,0,0);
   node8  = new TNode("NODE8","NODE8","CONE",-300,-300,0);
   node9  = new TNode("NODE9","NODE9","CONS",300,300,0);
   node10 = new TNode("NODE10","NODE10","PCON",0,-1000,-1000);
   node11 = new TNode("NODE11","NODE11","PGON",0,1000,1000);
   node12 = new TNode("NODE12","NODE12","GTRA",0,-400,700);

   // Draw this geometry in the current canvas
   node1->cd();
   node1->Draw();
   c1->Update(); // not sure why this is needed
   //
   //  Draw the geometry using the x3d viewver.
   //  Note that this viewver may also be invoked from the "View" menu in
   //  the canvas tool bar
   c1->x3d(); // deprecated version of call to 3d viewer
   //
   // once in x3d viewer, type m to see the menu.
   // For example typing r will show a solid model of this geometry.
}

// tags: root macro tutorial geometry shape
