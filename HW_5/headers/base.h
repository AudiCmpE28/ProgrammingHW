//   #ifndef __BASE_H // Make sure to only declare these classes once
//   #define __BASE_H
//     class MainApp: public wxApp // MainApp is the class for our application
//     { 
//     // MainApp just acts as a container for the window,
//     public: // or frame in MainFrame
//       virtual bool OnInit();
//     };
    
//     class MainFrame: public wxFrame // MainFrame is the class for our window,
//     {
//     // It contains the window and all objects in it
//     public:
//       MainFrame( const wxString &title, const wxPoint &pos, const wxSize &size );
//       wxButton *HelloWorld;
//       void OnExit( wxCommandEvent& event );
  
//       DECLARE_EVENT_TABLE()
//     };
  
//     enum
//     {
//       BUTTON_Hello = wxID_HIGHEST + 1 // declares an id which will be used to call our button
//     };
 
//   #endif