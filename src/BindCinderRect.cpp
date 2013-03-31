#include "BindCinderRect.h"

#include "cinder/Rect.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    void bindCinderRect( lua_State* state ){
        
        module( state ) [
                                   
                                   class_< Rectf >("Rectf")
                                   .def(constructor<>())
                                   .def(constructor<const std::vector<Vec2f> &>())
                                   .def(constructor<const Area &>())
                                   .def(constructor<const Rectf &>())
                                   .def(constructor<Vec2f, Vec2f>())
                                   .def(constructor<float, float, float, float>())
                                   ];
    }
    
}}
