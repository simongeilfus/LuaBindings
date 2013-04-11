#include "BindCinderChannel.h"

#include "cinder/Channel.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    void bindCinderChannel( lua_State* state ){
        
        module( state ) [
                         class_< Channel8u >("Channel8u")
                         .def(constructor<>())
                         
                         .def( "getWidth", &Channel8u::getWidth )
                         .def( "getHeight", &Channel8u::getHeight )
                         .def( "getSize", &Channel8u::getSize )
                         .def( "getAspectRatio", &Channel8u::getAspectRatio )
                         .def( "getBounds", &Channel8u::getBounds )
                         .def( "getRowBytes", &Channel8u::getRowBytes )
                         
                         .def( "clone", ( Channel8u(Channel8u::*)( bool ) const ) &Channel8u::clone )
                         .def( "clone", ( Channel8u(Channel8u::*)( const Area&, bool )const ) &Channel8u::clone )
                         
                         .def( "setPixel", ( void(Channel8u::*)(Vec2i,unsigned char) ) &Channel8u::setValue )
                         
                         .def( "copyFrom", ( void(Channel8u::*)(const Channel8u&,const Area&) ) &Channel8u::copyFrom )
                         .def( "copyFrom", ( void(Channel8u::*)(const Channel8u&,const Area&, const Vec2i) ) &Channel8u::copyFrom ),
                         
                         
                         class_< Channel16u >("Channel16u")
                         .def(constructor<>())
                         
                         .def( "getWidth", &Channel16u::getWidth )
                         .def( "getHeight", &Channel16u::getHeight )
                         .def( "getSize", &Channel16u::getSize )
                         .def( "getAspectRatio", &Channel16u::getAspectRatio )
                         .def( "getBounds", &Channel16u::getBounds )
                         .def( "getRowBytes", &Channel16u::getRowBytes )
                         
                         .def( "clone", ( Channel16u(Channel16u::*)( bool ) const ) &Channel16u::clone )
                         .def( "clone", ( Channel16u(Channel16u::*)( const Area&, bool )const ) &Channel16u::clone )
                         
                         .def( "setPixel", ( void(Channel8u::*)(Vec2i,unsigned char) ) &Channel8u::setValue )
                         
                         .def( "copyFrom", ( void(Channel16u::*)(const Channel16u&,const Area&) ) &Channel16u::copyFrom )
                         .def( "copyFrom", ( void(Channel16u::*)(const Channel16u&,const Area&, const Vec2i) ) &Channel16u::copyFrom ),
                         
                         
                         class_< Channel32f >("Channel32f")
                         .def(constructor<>())
                         
                         .def( "getWidth", &Channel32f::getWidth )
                         .def( "getHeight", &Channel32f::getHeight )
                         .def( "getSize", &Channel32f::getSize )
                         .def( "getAspectRatio", &Channel32f::getAspectRatio )
                         .def( "getBounds", &Channel32f::getBounds )
                         .def( "getRowBytes", &Channel32f::getRowBytes )
                         
                         .def( "clone", ( Channel32f(Channel32f::*)( bool ) const ) &Channel32f::clone )
                         .def( "clone", ( Channel32f(Channel32f::*)( const Area&, bool )const ) &Channel32f::clone )
                         
                         .def( "setPixel", ( void(Channel8u::*)(Vec2i,unsigned char) ) &Channel8u::setValue )
                         
                         .def( "copyFrom", ( void(Channel32f::*)(const Channel32f&,const Area&) ) &Channel32f::copyFrom )
                         .def( "copyFrom", ( void(Channel32f::*)(const Channel32f&,const Area&, const Vec2i) ) &Channel32f::copyFrom )
                         
                         ];
    }
    
}}
