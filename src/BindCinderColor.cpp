#include "BindCinderColor.h"

#include "cinder/Color.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    
	void bindCinderColor( lua_State* state ){
        
		module( state ) [
                                   class_< Color >("Color")
                                   .def(constructor<>())
                                   .def(constructor<float, float, float >())
                                   .def_readwrite("r", &Color::r)
                                   .def_readwrite("g", &Color::g)
                                   .def_readwrite("b", &Color::b),
                                   
                                   class_< ColorA >("ColorA")
                                   .def(constructor<>())
                                   .def(constructor<float, float, float, float >())
                                   .def_readwrite("r", &ColorA::r)
                                   .def_readwrite("g", &ColorA::g)
                                   .def_readwrite("b", &ColorA::b)
                                   .def_readwrite("a", &ColorA::a)
                                   ];
	}
    
}}
