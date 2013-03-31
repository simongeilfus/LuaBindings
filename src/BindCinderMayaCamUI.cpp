#include "BindCinderMayaCamUI.h"

#include "cinder/MayaCamUI.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    
    void bindCinderMayaCamUI( lua_State* state ) {
        
        module( state ) [
                                   class_< MayaCamUI >("MayaCamUI")
                                   .def(constructor<>())
                                   .def(constructor< const CameraPersp & >())
                                   .def( "mouseDown", &MayaCamUI::mouseDown )
                                   .def( "mouseDrag", &MayaCamUI::mouseDrag )
                                   .def( "getCamera", &MayaCamUI::getCamera )
                                   .def( "setCurrentCam", &MayaCamUI::setCurrentCam )
                                   ];
    }
    
}}
