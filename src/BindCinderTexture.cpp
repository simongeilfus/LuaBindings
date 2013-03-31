#include "BindCinderTexture.h"

#include "cinder/gl/Texture.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    void bindCinderTexture( lua_State* state ){
        
        
        module( state, "gl" ) [
                                         
                                         
                                         // Export Texture
                                         //-------------------------------------------------------------------------------------------
                                         class_< gl::Texture >("Texture")
                                         .def(constructor<>())
                                         .def(constructor< int, int, gl::Texture::Format >())
                                         .def(constructor< const unsigned char*, int, int, int, gl::Texture::Format >())
                                         .def(constructor<ImageSourceRef>())
                                         .def(constructor<ImageSourceRef, gl::Texture::Format >())
                                         .def(constructor<const Surface8u &>())
                                         .def(constructor<const Surface8u &, gl::Texture::Format >())
                                         .def(constructor<const Surface32f &>())
                                         .def(constructor<const Surface32f &, gl::Texture::Format >())
                                         .def(constructor< GLenum, GLuint, int, int, bool >())
                                         .def( "setDoNotDispose", &gl::Texture::setDoNotDispose )
                                         .def( "setWrap", &gl::Texture::setWrap )
                                         .def( "setWrapS", &gl::Texture::setWrapS )
                                         .def( "setWrapT", &gl::Texture::setWrapT )
                                         .def( "setMinFilter", &gl::Texture::setMinFilter )
                                         .def( "setMagFilter", &gl::Texture::setMagFilter )
                                         .def( "setCleanTexCoords", &gl::Texture::setCleanTexCoords )
                                         .def( "getWidth", &gl::Texture::getWidth )
                                         .def( "getHeight", &gl::Texture::getHeight )
                                         .def( "getCleanWidth", &gl::Texture::getCleanWidth )
                                         .def( "getCleanHeight", &gl::Texture::getCleanHeight )
                                         .def( "getSize", &gl::Texture::getSize )
                                         .def( "getAspectRatio", &gl::Texture::getAspectRatio )
                                         .def( "getBounds", &gl::Texture::getBounds )
                                         .def( "getCleanBounds", &gl::Texture::getCleanBounds )
                                         .def( "getLeft", &gl::Texture::getLeft )
                                         .def( "getRight", &gl::Texture::getRight )
                                         .def( "getTop", &gl::Texture::getTop )
                                         .def( "getBottom", &gl::Texture::getBottom )
                                         .def( "getMaxU", &gl::Texture::getMaxU )
                                         .def( "getMaxV", &gl::Texture::getMaxV )
                                         .def( "getAreaTexCoords", &gl::Texture::getAreaTexCoords )
                                         .def( "getInternalFormat", &gl::Texture::getInternalFormat )
                                         .def( "getId", &gl::Texture::getId )
                                         .def( "getTarget", &gl::Texture::getTarget )
                                         .def( "isFlipped", &gl::Texture::isFlipped )
                                         .def( "setFlipped", &gl::Texture::setFlipped )
                                         .def( "enableAndBind", &gl::Texture::enableAndBind )
                                         .def( "disable", &gl::Texture::disable )
                                         .def( "bind", &gl::Texture::bind )
                                         .def( "unbind", &gl::Texture::unbind )
                                         .scope[
                                                
                                                // Export Texture::Format
                                                //-------------------------------------------------------------------------------------------
                                                class_< gl::Texture::Format >("Format")
                                                .def(constructor<>())
                                                .def( "setTarget", &gl::Texture::Format::setTarget )
#ifndef CINDER_GLES
                                                .def( "setTargetRect", &gl::Texture::Format::setTargetRect )
#endif
                                                .def( "enableMipmapping", &gl::Texture::Format::enableMipmapping )
                                                .def( "setInternalFormat", &gl::Texture::Format::setInternalFormat )
                                                .def( "setAutoInternalFormat", &gl::Texture::Format::setAutoInternalFormat )
                                                .def( "setWrap", &gl::Texture::Format::setWrap )
                                                .def( "setWrapS", &gl::Texture::Format::setWrapS )
                                                .def( "setWrapT", &gl::Texture::Format::setWrapT )
                                                .def( "setMinFilter", &gl::Texture::Format::setMinFilter )
                                                .def( "setMagFilter", &gl::Texture::Format::setMagFilter )
                                                .def( "getTarget", &gl::Texture::Format::getTarget )
                                                .def( "hasMipmapping", &gl::Texture::Format::hasMipmapping )
                                                .def( "getInternalFormat", &gl::Texture::Format::getInternalFormat )
                                                .def( "isAutoInternalFormat", &gl::Texture::Format::isAutoInternalFormat )
                                                .def( "getWrapS", &gl::Texture::Format::getWrapS )
                                                .def( "getWrapT", &gl::Texture::Format::getWrapT )
                                                .def( "getMinFilter", &gl::Texture::Format::getMinFilter )
                                                .def( "getMagFilter", &gl::Texture::Format::getMagFilter )
                                                ]
                                         ];
    }
    
}}
