#include "BindCinderSurface.h"

#include "cinder/Surface.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    void bindCinderSurface( lua_State* state ){
        
        module( state ) [
                                   //class_< Surface >("Surface")
                                   //.def(constructor<>()),
                                   class_< Surface8u >("Surface8u")
                                   .def(constructor<>()),
                                   class_< Surface16u >("Surface16u")
                                   .def(constructor<>()),
                                   class_< Surface32f >("Surface32f")
                                   .def(constructor<>())
                                   ];
    }
    
}}
