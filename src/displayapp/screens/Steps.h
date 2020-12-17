#pragma once

#include <cstdint>
#include "Screen.h"
#include <lvgl/src/lv_core/lv_style.h>
#include <lvgl/src/lv_core/lv_obj.h>
//#include "bma421/bma4.h"
#include "drivers/BMA421.h"

namespace Pinetime {

  namespace Drivers {
    class BMA421;
  }

  namespace Applications {
    namespace Screens {

      class Steps : public Screen{
        public:
          Steps(DisplayApp* app, Pinetime::Drivers::BMA421& stepCounter);
          ~Steps() override;

          bool Refresh() override;
          bool OnButtonPushed() override;

        private:          

          Pinetime::Drivers::BMA421& stepCounter;

          lv_obj_t * lSteps;
          lv_obj_t * lActivity;
          lv_obj_t * lTapStatus;
          lv_obj_t * lTemp;
          lv_obj_t * lAccel;
          lv_obj_t * lirq;

          struct Pinetime::Drivers::accl_data_struct sens_data;

          bool running = true;

      };
    }
  }
}
