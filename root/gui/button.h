#include <TQObject.h>
#include <RQ_OBJECT.h>
#include <otherClass.h>
#include <TView.h>
#include <TCanvas.h>
class TGWindow;
class TGMainFrame;
class TRootEmbeddedCanvas;
class MyMainFrame {
   RQ_OBJECT("MyMainFrame")
private:
  TGMainFrame         *fMain;
  TRootEmbeddedCanvas *fEcanvas;
  TCanvas *fCanvas;
  otherClass* ocPtr;
  TView* view;
public:
  MyMainFrame(const TGWindow *p,UInt_t w,UInt_t h);
  virtual ~MyMainFrame();
  void DoDraw();
  void DoPrint();
  void DoView();
  void DoZoom();
};
