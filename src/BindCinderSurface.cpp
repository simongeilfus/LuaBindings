#include "BindCinderSurface.h"

#include "cinder/Surface.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    void bindCinderSurface( lua_State* state ){
        
        module( state ) [
                         class_< Surface8u >("Surface8u")
                         .def(constructor<>())
                         .def(constructor< int32_t, int32_t, bool, SurfaceChannelOrder >())
                         .def(constructor< ImageSourceRef, const SurfaceConstraints &, bool>())
                         
                         .def( "getWidth", &Surface8u::getWidth )
                         .def( "getHeight", &Surface8u::getHeight )
                         .def( "getSize", &Surface8u::getSize )
                         .def( "getAspectRatio", &Surface8u::getAspectRatio )
                         .def( "getBounds", &Surface8u::getBounds )
                         .def( "hasAlpha", &Surface8u::hasAlpha )
                         .def( "isPremultiplied", &Surface8u::isPremultiplied )
                         .def( "setPremultiplied", &Surface8u::setPremultiplied )
                         .def( "getRowBytes", &Surface8u::getRowBytes )
                         .def( "getPixelInc", &Surface8u::getPixelInc )
                         
                         .def( "clone", ( Surface8u(Surface8u::*)( bool ) const ) &Surface8u::clone )
                         .def( "clone", ( Surface8u(Surface8u::*)( const Area&, bool )const ) &Surface8u::clone )
                         
                         .def( "getChannel", ( Channel8u&(Surface8u::*)( uint8_t ) ) &Surface8u::getChannel )
                         
                         .def( "getChannelRed", ( Channel8u&(Surface8u::*)() ) &Surface8u::getChannelRed )
                         .def( "getChannelGreen", ( Channel8u&(Surface8u::*)() ) &Surface8u::getChannelGreen )
                         .def( "getChannelBlue", ( Channel8u&(Surface8u::*)() ) &Surface8u::getChannelBlue )
                         .def( "getChannelAlpha", ( Channel8u&(Surface8u::*)() ) &Surface8u::getChannelAlpha )
                         
                         .def( "getPixel", ( ColorA(Surface8u::*)(Vec2i) const ) &Surface8u::getPixel )
                         .def( "setPixel", ( void(Surface8u::*)(Vec2i,const Color8u&) ) &Surface8u::setPixel )
                         .def( "setPixel", ( void(Surface8u::*)(Vec2i,const ColorA8u&) ) &Surface8u::setPixel )
                         
                         .def( "copyFrom", ( void(Surface8u::*)(const Surface8u&,const Area&) ) &Surface8u::copyFrom )
                         .def( "copyFrom", ( void(Surface8u::*)(const Surface8u&,const Area&, const Vec2i) ) &Surface8u::copyFrom )
                         
                         .def( "areaAverage", ( Color(Surface8u::*)(const Area&) ) &Surface8u::areaAverage ),
                         
                         
                         class_< Surface8u::Iter >("Surface8uIter")
                         .def(constructor<Surface8u&, const Area &>())
                         ,

                         
                         class_< Surface16u >("Surface16u")
                         .def(constructor<>())
                         .def(constructor< int32_t, int32_t, bool, SurfaceChannelOrder >())
                         .def(constructor< ImageSourceRef, const SurfaceConstraints &, bool>())
                         
                         .def( "getWidth", &Surface16u::getWidth )
                         .def( "getHeight", &Surface16u::getHeight )
                         .def( "getSize", &Surface16u::getSize )
                         .def( "getAspectRatio", &Surface16u::getAspectRatio )
                         .def( "getBounds", &Surface16u::getBounds )
                         .def( "hasAlpha", &Surface16u::hasAlpha )
                         .def( "isPremultiplied", &Surface16u::isPremultiplied )
                         .def( "setPremultiplied", &Surface16u::setPremultiplied )
                         .def( "getRowBytes", &Surface16u::getRowBytes )
                         .def( "getPixelInc", &Surface16u::getPixelInc )
                         
                         .def( "clone", ( Surface16u(Surface16u::*)( bool ) const ) &Surface16u::clone )
                         .def( "clone", ( Surface16u(Surface16u::*)( const Area&, bool )const ) &Surface16u::clone )
                         
                         .def( "getChannel", ( Channel16u&(Surface16u::*)( uint8_t ) ) &Surface16u::getChannel )
                         
                         .def( "getChannelRed", ( Channel16u&(Surface16u::*)() ) &Surface16u::getChannelRed )
                         .def( "getChannelGreen", ( Channel16u&(Surface16u::*)() ) &Surface16u::getChannelGreen )
                         .def( "getChannelBlue", ( Channel16u&(Surface16u::*)() ) &Surface16u::getChannelBlue )
                         .def( "getChannelAlpha", ( Channel16u&(Surface16u::*)() ) &Surface16u::getChannelAlpha )
                         
                         .def( "getPixel", ( ColorA(Surface16u::*)(Vec2i) const ) &Surface16u::getPixel )
                         .def( "setPixel", ( void(Surface16u::*)(Vec2i,const ColorT<uint16_t>&) ) &Surface16u::setPixel )
                         .def( "setPixel", ( void(Surface16u::*)(Vec2i,const ColorAT<uint16_t>&) ) &Surface16u::setPixel )
                         
                         .def( "copyFrom", ( void(Surface16u::*)(const Surface16u&,const Area&) ) &Surface16u::copyFrom )
                         .def( "copyFrom", ( void(Surface16u::*)(const Surface16u&,const Area&, const Vec2i) ) &Surface16u::copyFrom )
                         
                         .def( "areaAverage", ( Color(Surface16u::*)(const Area&) ) &Surface16u::areaAverage ),
                         
                         
                         class_< Surface32f >("Surface32f")
                         .def(constructor<>())
                         .def(constructor< int32_t, int32_t, bool, SurfaceChannelOrder >())
                         .def(constructor< ImageSourceRef, const SurfaceConstraints &, bool>())
                         
                         .def( "getWidth", &Surface32f::getWidth )
                         .def( "getHeight", &Surface32f::getHeight )
                         .def( "getSize", &Surface32f::getSize )
                         .def( "getAspectRatio", &Surface32f::getAspectRatio )
                         .def( "getBounds", &Surface32f::getBounds )
                         .def( "hasAlpha", &Surface32f::hasAlpha )
                         .def( "isPremultiplied", &Surface32f::isPremultiplied )
                         .def( "setPremultiplied", &Surface32f::setPremultiplied )
                         .def( "getRowBytes", &Surface32f::getRowBytes )
                         .def( "getPixelInc", &Surface32f::getPixelInc )
                         
                         .def( "clone", ( Surface32f(Surface32f::*)( bool ) const ) &Surface32f::clone )
                         .def( "clone", ( Surface32f(Surface32f::*)( const Area&, bool )const ) &Surface32f::clone )
                         
                         .def( "getChannel", ( Channel32f&(Surface32f::*)( uint8_t ) ) &Surface32f::getChannel )
                         
                         .def( "getChannelRed", ( Channel32f&(Surface32f::*)() ) &Surface32f::getChannelRed )
                         .def( "getChannelGreen", ( Channel32f&(Surface32f::*)() ) &Surface32f::getChannelGreen )
                         .def( "getChannelBlue", ( Channel32f&(Surface32f::*)() ) &Surface32f::getChannelBlue )
                         .def( "getChannelAlpha", ( Channel32f&(Surface32f::*)() ) &Surface32f::getChannelAlpha )
                         
                         .def( "getPixel", ( ColorA(Surface32f::*)(Vec2i) const ) &Surface32f::getPixel )
                         .def( "setPixel", ( void(Surface32f::*)(Vec2i,const Color&) ) &Surface32f::setPixel )
                         .def( "setPixel", ( void(Surface32f::*)(Vec2i,const ColorA&) ) &Surface32f::setPixel )
                         
                         .def( "copyFrom", ( void(Surface32f::*)(const Surface32f&,const Area&) ) &Surface32f::copyFrom )
                         .def( "copyFrom", ( void(Surface32f::*)(const Surface32f&,const Area&, const Vec2i) ) &Surface32f::copyFrom )
                         
                         .def( "areaAverage", ( Color(Surface32f::*)(const Area&) ) &Surface32f::areaAverage )
                         ];
    }
    
}}
