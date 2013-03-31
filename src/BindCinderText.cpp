#include "BindCinderText.h"

#include "cinder/Text.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    void bindCinderText( lua_State* state ){
        
        module( state ) [
                                   
                                   // Export TextLayout
                                   //-------------------------------------------------------------------------------------------
                                   class_< TextLayout >("TextLayout")
                                   .def(constructor<>())
                                   .def( "clear", ( void(TextLayout::*) (const Color & ) ) &TextLayout::clear )
                                   .def( "clear", ( void(TextLayout::*) (const ColorA & ) ) &TextLayout::clear )
                                   .def( "addLine", &TextLayout::addLine )
                                   .def( "addCenteredLine", &TextLayout::addCenteredLine )
                                   .def( "addRightLine", &TextLayout::addRightLine )
                                   .def( "append", &TextLayout::append )
                                   .def( "setFont", &TextLayout::setFont )
                                   .def( "setColor",  ( void(TextLayout::*) (const Color & ) ) &TextLayout::setColor )
                                   .def( "setColor", ( void(TextLayout::*) (const ColorA & ) ) &TextLayout::setColor )
                                   .def( "setLeadingOffset", &TextLayout::setLeadingOffset )
                                   .def( "setBorder", &TextLayout::setBorder )
                                   .def( "render", &TextLayout::render ),
                                   
                                   // Export TextBox
                                   //-------------------------------------------------------------------------------------------
                                   class_< TextBox >("TextBox")
                                   .def(constructor<>())
                                   .enum_("constants")
                                   [
                                    value( "LEFT", (int) TextBox::LEFT ),
                                    value( "CENTER", (int) TextBox::CENTER ),
                                    value( "RIGHT", (int) TextBox::RIGHT ),
                                    value( "GROW", (int) TextBox::GROW )
                                    ]
                                   .def( "size", ( TextBox&(TextBox::*)( Vec2i ) )&TextBox::size )
                                   .def( "size", ( TextBox&(TextBox::*)( int, int ) ) &TextBox::size )
                                   .def( "getSize", &TextBox::getSize )
                                   .def( "setSize", &TextBox::setSize )
                                   .def( "text", &TextBox::text )
                                   .def( "getText", &TextBox::getText )
                                   .def( "setText", &TextBox::setText )
                                   .def( "appendText", &TextBox::appendText )
                                   .def( "font", &TextBox::font )
                                   .def( "getFont", &TextBox::getFont )
                                   .def( "setFont", &TextBox::setFont )
                                   .def( "alignment", &TextBox::alignment )
                                   .def( "getAlignment", &TextBox::getAlignment )
                                   .def( "setAlignment", &TextBox::setAlignment )
                                   .def( "color", &TextBox::color )
                                   .def( "getColor", &TextBox::getColor )
                                   .def( "setColor", &TextBox::setColor )
                                   .def( "backgroundColor", &TextBox::backgroundColor )
                                   .def( "getBackgroundColor", &TextBox::getBackgroundColor )
                                   .def( "setBackgroundColor", &TextBox::setBackgroundColor )
                                   .def( "premultiplied", &TextBox::premultiplied )
                                   .def( "getPremultiplied", &TextBox::getPremultiplied )
                                   .def( "setPremultiplied", &TextBox::setPremultiplied )
                                   .def( "ligate", &TextBox::ligate )
                                   .def( "getLigate", &TextBox::getLigate )
                                   .def( "setLigate", &TextBox::setLigate )
                                   .def( "measure", &TextBox::measure )
                                   .def( "render", &TextBox::render )
                                   ];
    }
    
}}
