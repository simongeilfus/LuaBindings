#include "BindCinderFont.h"

#include "cinder/Font.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    
    void bindCinderFont( lua_State* state ){
        
        module( state ) [
                                   class_< Font >("Font")
                                   .def(constructor<>())
                                   .def(constructor<const std::string &, float>())
                                   .def(constructor<DataSourceRef, float>())
                                   .def( "getName", &Font::getName )
                                   .def( "getFullName", &Font::getFullName )
                                   .def( "getSize", &Font::getSize )
                                   .def( "getLeading", &Font::getLeading )
                                   .def( "getAscent", &Font::getAscent )
                                   .def( "getDescent", &Font::getDescent )
                                   .def( "getNumGlyphs", &Font::getNumGlyphs )
                                   .def( "getGlyphIndex", &Font::getGlyphIndex )
                                   .def( "getGlyphChar", &Font::getGlyphChar )
                                   .def( "getGlyphs", &Font::getGlyphs )
                                   .def( "getGlyphShape", &Font::getGlyphShape )
                                   .def( "getGlyphBoundingBox", &Font::getGlyphBoundingBox )
                                   ];
    }
    
}}
