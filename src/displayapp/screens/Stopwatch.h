#pragma once

#include <lvgl/src/lv_core/lv_obj.h>
#include <cstdint>
#include "Screen.h"
#include "components/brightness/BrightnessController.h"

namespace Pinetime {
    namespace Applications {
        namespace Screens {
            class Stopwatch : public Screen {
                public:
                Stopwatch(DisplayApp* app);
                ~Stopwatch() override;
                bool Refresh() override;
                bool OnButtonPushed() override;
                bool OnTouchEvent(TouchEvents event) override;

                //void OnValueChanged();
                private:
                bool running = true;

                lv_obj_t * label_time;
            };
        }
    }
}
