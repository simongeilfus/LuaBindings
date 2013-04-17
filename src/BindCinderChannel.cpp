#include "BindCinderChannel.h"

#include "cinder/Channel.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    void setChannel8uV( Channel8u::Iter& iter, int value ){
        iter.v() = value;
    }
    void setChannel16uV( Channel16u::Iter& iter, int value ){
        iter.v() = value;
    }
    void setChannel32fV( Channel32f::Iter& iter, float value ){
        iter.v() = value;
    }
    
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
                         .def( "copyFrom", ( void(Channel8u::*)(const Channel8u&,const Area&, const Vec2i) ) &Channel8u::copyFrom )
                         
                         .def( "getIter", ( Channel8u::Iter(Channel8u::*)() ) &Channel8u::getIter )
                         .def( "getIter", ( Channel8u::Iter(Channel8u::*)(const Area&) ) &Channel8u::getIter ),
                         
                         
                         class_< Channel8u::Iter >("Channel8uIter")
                         .def(constructor<Channel8u&, const Area &>())
                         
                         .def( "v", &setChannel8uV )
                         //.def( "v", ( uint8_t&(Channel8u::Iter::*)( int32_t, int32_t ) const ) &Channel8u::Iter::v )
                         //.def( "v", ( uint8_t&(Channel8u::Iter::*)( int32_t, int32_t ) const ) &Channel8u::Iter::vClamped )
                         
                         .def( "x", ( int32_t&(Channel8u::Iter::*)() const ) &Channel8u::Iter::x )
                         .def( "y", ( int32_t&(Channel8u::Iter::*)() const ) &Channel8u::Iter::y )
                         .def( "getPos", ( Vec2i&(Channel8u::Iter::*)() const ) &Channel8u::Iter::getPos )
                         
                         .def( "pixel", ( bool(Channel8u::Iter::*)() ) &Channel8u::Iter::pixel )
                         .def( "line", ( bool(Channel8u::Iter::*)() ) &Channel8u::Iter::line )
                         
                         .def( "getWidth", ( int32_t(Channel8u::Iter::*)() ) &Channel8u::Iter::getWidth )
                         .def( "getHeight", ( int32_t(Channel8u::Iter::*)() ) &Channel8u::Iter::getHeight ),
                         
                         
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
                         
                         .def( "setPixel", ( void(Channel16u::*)(Vec2i,unsigned char) ) &Channel16u::setValue )
                         
                         .def( "copyFrom", ( void(Channel16u::*)(const Channel16u&,const Area&) ) &Channel16u::copyFrom )
                         .def( "copyFrom", ( void(Channel16u::*)(const Channel16u&,const Area&, const Vec2i) ) &Channel16u::copyFrom )
                         
                         .def( "getIter", ( Channel16u::Iter(Channel16u::*)() ) &Channel16u::getIter )
                         .def( "getIter", ( Channel16u::Iter(Channel16u::*)(const Area&) ) &Channel16u::getIter ),
                         
                         
                         class_< Channel16u::Iter >("Channel16uIter")
                         .def(constructor<Channel16u&, const Area &>())
                         
                         .def( "v", &setChannel16uV )
                         //.def( "v", ( uint16_t&(Channel16u::Iter::*)( int32_t, int32_t ) const ) &Channel16u::Iter::v )
                         //.def( "v", ( uint16_t&(Channel16u::Iter::*)( int32_t, int32_t ) const ) &Channel16u::Iter::vClamped )
                         
                         .def( "x", ( int32_t&(Channel16u::Iter::*)() const ) &Channel16u::Iter::x )
                         .def( "y", ( int32_t&(Channel16u::Iter::*)() const ) &Channel16u::Iter::y )
                         .def( "getPos", ( Vec2i&(Channel16u::Iter::*)() const ) &Channel16u::Iter::getPos )
                         
                         .def( "pixel", ( bool(Channel16u::Iter::*)() ) &Channel16u::Iter::pixel )
                         .def( "line", ( bool(Channel16u::Iter::*)() ) &Channel16u::Iter::line )
                         
                         .def( "getWidth", ( int32_t(Channel16u::Iter::*)() ) &Channel16u::Iter::getWidth )
                         .def( "getHeight", ( int32_t(Channel16u::Iter::*)() ) &Channel16u::Iter::getHeight ),
                         
                         
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
                         
                         .def( "setPixel", ( void(Channel32f::*)(Vec2i,unsigned char) ) &Channel32f::setValue )
                         
                         .def( "copyFrom", ( void(Channel32f::*)(const Channel32f&,const Area&) ) &Channel32f::copyFrom )
                         .def( "copyFrom", ( void(Channel32f::*)(const Channel32f&,const Area&, const Vec2i) ) &Channel32f::copyFrom )
                         
                         .def( "getIter", ( Channel32f::Iter(Channel32f::*)() ) &Channel32f::getIter )
                         .def( "getIter", ( Channel32f::Iter(Channel32f::*)(const Area&) ) &Channel32f::getIter ),
                         
                         
                         class_< Channel32f::Iter >("Channel32fIter")
                         .def(constructor<Channel32f&, const Area &>())
                         
                         .def( "v", &setChannel32fV )
                         //.def( "v", ( float&(Channel32f::Iter::*)( int32_t, int32_t ) const ) &Channel32f::Iter::v )
                         //.def( "v", ( float&(Channel32f::Iter::*)( int32_t, int32_t ) const ) &Channel32f::Iter::vClamped )
                         
                         .def( "x", &Channel32f::Iter::x )
                         .def( "y", &Channel32f::Iter::y )
                         .def( "getPos", &Channel32f::Iter::getPos )
                         
                         .def( "pixel", ( bool(Channel32f::Iter::*)() ) &Channel32f::Iter::pixel )
                         .def( "line", ( bool(Channel32f::Iter::*)() ) &Channel32f::Iter::line )
                         
                         .def( "getWidth", &Channel32f::Iter::getWidth )
                         .def( "getHeight", &Channel32f::Iter::getHeight )
                         
                         
                         ];
    }
    
}}
