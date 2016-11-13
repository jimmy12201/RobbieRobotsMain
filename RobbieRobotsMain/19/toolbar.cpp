#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <iostream>

using namespace std;

const int bsize = 36; // size of each square button in pixels

class Toolbar : public Fl_Pack {
public:
    Toolbar(int X,int Y,int W,int H):Fl_Pack(X,Y,W,H) {
      type(Fl_Pack::HORIZONTAL);    // horizontal packing of buttons
      box(FL_UP_FRAME);          // Default up, down & then up when clicked
      spacing(4);            // spacing between buttons in pixels
      end();
    }

    // Add a button to the toolbar - *name is the tooltip, *img is the loaded picture,
    //   *cb is the callback handler, and *data is the void* data for the callback
    void AddButton(const char *name, Fl_PNG_Image *img=0, 
                   Fl_Callback *cb=0, void *data=0) {
        begin();
          Fl_Button *b = new Fl_Button(0,0,bsize,bsize);
          b->box(FL_UP_BOX);    // buttons won't have 'edges'
          b->clear_visible_focus();
          if ( name ) b->tooltip(name);
          if ( img  ) b->image(img);
          if ( cb   ) b->callback(cb,data);
        end();
    }
}; 
void New_CB(Fl_Widget*,void*) {
    cout << "New..." << endl;
} 
void Open_CB(Fl_Widget*,void*) {
    cout << "Open..." << endl;
} 
void Save_CB(Fl_Widget*,void*) {
    cout << "Save..." << endl;
} 
void Cut_CB(Fl_Widget*,void*) {
    cout << "Cut..." << endl;
} 
void Copy_CB(Fl_Widget*,void*) {
    cout << "Copy..." << endl;
} 
void Paste_CB(Fl_Widget*,void*) {
    cout << "Paste..." << endl;
} 
int main() {
    // Create Window
    Fl_Window win(720,486,"toolbar demo");
    win.begin();

      // Load toolbar button images
      Fl_PNG_Image *open_png = new Fl_PNG_Image{"open.png"};
      Fl_PNG_Image *save_png = new Fl_PNG_Image{"save.png"};
      Fl_PNG_Image *new_png  = new Fl_PNG_Image{"new.png"};
      Fl_PNG_Image *cut_png = new Fl_PNG_Image{"cut.png"};
      Fl_PNG_Image *copy_png = new Fl_PNG_Image{"copy.png"};
      Fl_PNG_Image *paste_png = new Fl_PNG_Image{"paste.png"};

      // Create the toolbar
      Toolbar toolbar(0,0,win.w(),bsize);
      toolbar.AddButton("New", new_png, New_CB);
      toolbar.AddButton("Open", open_png, Open_CB);
      toolbar.AddButton("Save", save_png, Save_CB);
      toolbar.AddButton("Cut", cut_png, Cut_CB);
      toolbar.AddButton("Copy", copy_png, Copy_CB);
      toolbar.AddButton("Paste", paste_png, Paste_CB);
    win.end();
    win.show();
    return(Fl::run());
}
