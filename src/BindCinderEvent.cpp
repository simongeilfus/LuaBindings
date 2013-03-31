#include "BindCinderApp.h"

#include "cinder/app/AppBasic.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    
    void bindCinderEvents( lua_State* state ){
        
		module( state ) [
                                   class_<Event>("Event"),
                                   
                                   class_<MouseEvent,Event>("MouseEvent")
                                   .def(constructor<>())
                                   .def( "getX", &MouseEvent::getX )
                                   .def( "getY", &MouseEvent::getY )
                                   .def( "getPos", &MouseEvent::getPos )
                                   .def( "isLeft", &MouseEvent::isLeft )
                                   .def( "isRight", &MouseEvent::isRight )
                                   .def( "isMiddle", &MouseEvent::isMiddle )
                                   .def( "isLeftDown", &MouseEvent::isLeftDown )
                                   .def( "isRightDown", &MouseEvent::isRightDown )
                                   .def( "isMiddleDown", &MouseEvent::isMiddleDown )
                                   .def( "isShiftDown", &MouseEvent::isShiftDown )
                                   .def( "isAltDown", &MouseEvent::isAltDown )
                                   .def( "isControlDown", &MouseEvent::isControlDown )
                                   .def( "isMetaDown", &MouseEvent::isMetaDown )
                                   .def( "isAccelDown", &MouseEvent::isAccelDown )
                                   .def( "getWheelIncrement", &MouseEvent::getWheelIncrement )
                                   .def( "getNativeModifiers", &MouseEvent::getNativeModifiers )
                                   ];
	}
    
}}
