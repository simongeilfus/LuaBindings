#include "BindCinderArea.h"

#include "cinder/Area.h"
#include "cinder/Rect.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    
	void bindCinderArea( lua_State* state ){
        
		module( state ) [
                                   
                                   class_< Area >("Area")
                                   .def(constructor<>())
                                   .def(constructor<const Area &>())
                                   .def(constructor<const Rectf &>())
                                   .def(constructor<Vec2i, Vec2i>())
                                   .def(constructor<int32_t, int32_t, int32_t, int32_t>())
                                   ];
	}

}}
