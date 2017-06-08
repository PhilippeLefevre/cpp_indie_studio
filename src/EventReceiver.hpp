//
// EventReceiver.hpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Thu Jun  8 22:21:33 2017 Philippe Lefevre
// Last update Thu Jun  8 23:19:17 2017 Philippe Lefevre
//

#ifndef EVENTRECEIVER_HPP_
# define EVENTRECEIVER_HPP_

#include <irrlicht.h>
#include "driverChoice.h"
using namespace irr;

class MyEventReceiver : public IEventReceiver
{
public:
        virtual bool OnEvent(const SEvent& event)
        {
                if (event.EventType == irr::EET_KEY_INPUT_EVENT)
                {
                        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
                }
                return (false);
        }

        virtual bool IsKeyDown(EKEY_CODE keyCode) const
        {
                return (KeyIsDown[keyCode]);
        }

        MyEventReceiver()
        {
                for (u32 i=0; i < KEY_KEY_CODES_COUNT; ++i)
                KeyIsDown[i] = false;
        }

private:
        bool KeyIsDown[KEY_KEY_CODES_COUNT];
};


#endif /* !EVENTRECEIVER_HPP_ */
