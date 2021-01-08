#include "ApplicationList.h"
#include <lvgl/lvgl.h>
#include <array>
#include "Symbols.h"
#include "Tile.h"
#include "displayapp/Apps.h"
#include "../DisplayApp.h"

using namespace Pinetime::Applications::Screens;

// Start apps launcher menu
ApplicationList::ApplicationList(Pinetime::Applications::DisplayApp *app) :
        Screen(app),
        // All app screens are here (defined below)
        screens{app, {
                [this]() -> std::unique_ptr<Screen> { return CreateScreen1(); },
                [this]() -> std::unique_ptr<Screen> { return CreateScreen2(); },
                //[this]() -> std::unique_ptr<Screen> { return CreateScreen3(); } // new screen has to be created
          }
        } {}


ApplicationList::~ApplicationList() {
  lv_obj_clean(lv_scr_act());
}

// app refresh, dif return false, app will close
bool ApplicationList::Refresh() {
  if(running)
    running = screens.Refresh();
  return running;
}

// Button terminator, to close applist and go back to clock
bool ApplicationList::OnButtonPushed() {
  running = false;
  app->StartApp(Apps::Clock); // start clockapp
  return true;
}

// check whick app is pressed
bool ApplicationList::OnTouchEvent(Pinetime::Applications::TouchEvents event) {
  return screens.OnTouchEvent(event);
}

// App screens -------------------------------------------------------------------------------------

/*
  app screens are built with 6 gadgets in mind. They all consist of 2 things, an icon, and a call to start it

  symbols contain the icons, while the apps is the code to run (defined in Apps.h and DisplayApp.cpp)

  if title applications are None, it will just fill in empty space

  all icons are TEXT, new icons can be added in fonts folder (check readme for more info into how)
*/

// App screen 1
std::unique_ptr<Screen> ApplicationList::CreateScreen1() {
  std::array<Screens::Tile::Applications, 6> applications {
          {{Symbols::clock, Apps::Clock},
          {Symbols::music, Apps::Music},
          {Symbols::sun, Apps::Brightness},
          {Symbols::list, Apps::SysInfo},
          {Symbols::check, Apps::FirmwareValidation},
          {"C", Apps::Stopwatch}
          //{imgIcon, appToOpen}
          }


  };

  return std::unique_ptr<Screen>(new Screens::Tile(app, applications));
}

// appscreen 2

std::unique_ptr<Screen> ApplicationList::CreateScreen2() {
  std::array<Screens::Tile::Applications, 6> applications {
          {{Symbols::tachometer, Apps::Gauge},
           {Symbols::asterisk, Apps::Meter},
           {Symbols::paintbrush, Apps::Paint},
                  {Symbols::info, Apps::Notifications},
                  {Symbols::paddle, Apps::Paddle},
                  {"2", Apps::Twos}
          }
  };

  return std::unique_ptr<Screen>(new Screens::Tile(app, applications));
}

std::unique_ptr<Screen> ApplicationList::CreateScreen3() {
  std::array<Screens::Tile::Applications, 6> applications {
          {{"A", Apps::Meter},
           {"B", Apps::Gauge},
           {"C", Apps::Clock},
           {"D", Apps::Music},
           {"E", Apps::SysInfo},
           {"F", Apps::Brightness}
          }
  };

  return std::unique_ptr<Screen>(new Screens::Tile(app, applications));
}

