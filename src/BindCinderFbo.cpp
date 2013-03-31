#include "BindCinderFbo.h"

#include "cinder/gl/Fbo.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
        
	void bindCinderFbo( lua_State* state ) {
        
        module( state, "gl" ) [
                                         
                                         
                                         // Export gl::Fbo
                                         //-------------------------------------------------------------------------------------------
                                         class_< gl::Fbo >("Fbo")
                                         .def(constructor<>())
                                         .def(constructor< int, int, gl::Fbo::Format >())
                                         .def(constructor< int, int, bool, bool, bool >())
                                         .def( "getWidth", &gl::Fbo::getWidth )
                                         .def( "getHeight", &gl::Fbo::getHeight )
                                         .def( "getSize", &gl::Fbo::getSize )
                                         .def( "getBounds", &gl::Fbo::getBounds )
                                         .def( "getAspectRatio", &gl::Fbo::getAspectRatio )
                                         .def( "getFormat", &gl::Fbo::getFormat )
                                         .def( "getTarget", &gl::Fbo::getTarget )
                                         .def( "getTexture", &gl::Fbo::getTexture )
                                         .def( "getDepthTexture", &gl::Fbo::getDepthTexture )
                                         .def( "bindTexture", &gl::Fbo::bindTexture )
                                         .def( "unbindTexture", &gl::Fbo::unbindTexture )
                                         .def( "bindDepthTexture", &gl::Fbo::bindDepthTexture )
                                         .def( "bindFramebuffer", &gl::Fbo::bindFramebuffer )
                                         .scope [
                                                 def( "unbindFramebuffer", &gl::Fbo::unbindFramebuffer )
                                                 ]
                                         .def( "getId", &gl::Fbo::getId )
#if ! defined( CINDER_GLES )
                                         .def( "getResolveId", &gl::Fbo::getResolveId )
                                         .def( "blitTo", &gl::Fbo::blitTo )
                                         .def( "blitToScreen", &gl::Fbo::blitToScreen )
                                         .def( "blitFromScreen", &gl::Fbo::blitFromScreen )
#endif
                                         .def( "getMaxSamples", &gl::Fbo::getMaxSamples )
                                         .def( "getMaxAttachments", &gl::Fbo::getMaxAttachments )
                                         .scope[
                                                
                                                // Export gl::Fbo::Format
                                                //-------------------------------------------------------------------------------------------
                                                class_< gl::Fbo::Format >("Format")
                                                .def(constructor<>())
                                                .def( "setTarget", &gl::Fbo::Format::setTarget )
                                                .def( "setColorInternalFormat", &gl::Fbo::Format::setColorInternalFormat )
                                                .def( "setDepthInternalFormat", &gl::Fbo::Format::setDepthInternalFormat )
                                                .def( "setSamples", &gl::Fbo::Format::setSamples )
                                                .def( "setCoverageSamples", &gl::Fbo::Format::setCoverageSamples )
                                                .def( "enableColorBuffer", &gl::Fbo::Format::enableColorBuffer )
                                                .def( "enableDepthBuffer", &gl::Fbo::Format::enableDepthBuffer )
                                                .def( "enableMipmapping", &gl::Fbo::Format::enableMipmapping )
                                                .def( "setWrap", &gl::Fbo::Format::setWrap )
                                                .def( "setWrapS", &gl::Fbo::Format::setWrapS )
                                                .def( "setWrapT", &gl::Fbo::Format::setWrapT )
                                                .def( "setMinFilter", &gl::Fbo::Format::setMinFilter )
                                                .def( "setMagFilter", &gl::Fbo::Format::setMagFilter )
                                                .def( "getTarget", &gl::Fbo::Format::getTarget )
                                                .def( "getColorInternalFormat", &gl::Fbo::Format::getColorInternalFormat )
                                                .def( "getDepthInternalFormat", &gl::Fbo::Format::getDepthInternalFormat )
                                                .def( "getSamples", &gl::Fbo::Format::getSamples )
                                                .def( "getCoverageSamples", &gl::Fbo::Format::getCoverageSamples )
                                                .def( "hasColorBuffer", &gl::Fbo::Format::hasColorBuffer )
                                                .def( "getNumColorBuffers", &gl::Fbo::Format::getNumColorBuffers )
                                                .def( "hasDepthBuffer", &gl::Fbo::Format::hasDepthBuffer )
                                                .def( "hasDepthBufferTexture", &gl::Fbo::Format::hasDepthBufferTexture )
                                                .def( "hasMipMapping", &gl::Fbo::Format::hasMipMapping )
                                                
                                                ]
                                         ];
        
    }
    
}}
