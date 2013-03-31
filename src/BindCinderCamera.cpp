#include "BindCinderCamera.h"

#include "cinder/Camera.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    
	void bindCinderCamera( lua_State* state ) {
        
		module( state ) [
                                   
                                   // Export Camera
                                   //-------------------------------------------------------------------------------------------
                                   class_< Camera >("Camera")
                                   .def( "getEyePoint", &Camera::getEyePoint )
                                   .def( "setEyePoint", &Camera::setEyePoint )
                                   .def( "getCenterOfInterest", &Camera::getCenterOfInterest )
                                   .def( "setCenterOfInterest", &Camera::setCenterOfInterest )
                                   .def( "getCenterOfInterestPoint", &Camera::getCenterOfInterestPoint )
                                   .def( "setCenterOfInterestPoint", &Camera::setCenterOfInterestPoint )
                                   .def( "getWorldUp", &Camera::getWorldUp )
                                   .def( "setWorldUp", &Camera::setWorldUp )
                                   .def( "lookAt", ( void(Camera::*) ( const Vec3f & ) ) &Camera::lookAt )
                                   .def( "lookAt", ( void(Camera::*) ( const Vec3f &, const Vec3f & ) ) &Camera::lookAt )
                                   .def( "lookAt", ( void(Camera::*) ( const Vec3f &, const Vec3f &, const Vec3f & ) ) &Camera::lookAt )
                                   .def( "getViewDirection", &Camera::getViewDirection )
                                   .def( "setViewDirection", &Camera::setViewDirection )
                                   .def( "getOrientation", &Camera::getOrientation )
                                   .def( "setOrientation", &Camera::setOrientation )
                                   .def( "getFov", &Camera::getFov )
                                   .def( "setFov", &Camera::setFov )
                                   .def( "getAspectRatio", ( void(Camera::*) () ) &Camera::getAspectRatio )
                                   .def( "setAspectRatio", ( void(Camera::*) (float) )  &Camera::setAspectRatio )
                                   .def( "getNearClip", &Camera::getNearClip )
                                   .def( "setNearClip", &Camera::setNearClip )
                                   .def( "getFarClip", &Camera::getFarClip )
                                   .def( "setFarClip", &Camera::setFarClip )
                                   .def( "getProjectionMatrix", &Camera::getProjectionMatrix )
                                   .def( "getModelViewMatrix", &Camera::getModelViewMatrix )
                                   .def( "getInverseModelViewMatrix", &Camera::getInverseModelViewMatrix )
                                   .def( "generateRay", &Camera::generateRay )
                                   .def( "getBillboardVectors", &Camera::getBillboardVectors )
                                   .def( "worldToScreen", &Camera::worldToScreen )
                                   .def( "worldToEye", &Camera::worldToEye )
                                   .def( "worldToEyeDepth", &Camera::worldToEyeDepth )
                                   .def( "worldToNdc", &Camera::worldToNdc )
                                   // TODO .def( "getScreenRadius", &Camera::getScreenRadius )
                                   ,
                                   
                                   // Export CameraPersp
                                   //-------------------------------------------------------------------------------------------
                                   class_< CameraPersp, Camera >("CameraPersp")
                                   .def(constructor<>())
                                   .def(constructor<int, int, float>())	// constructs screen-aligned camera
                                   .def(constructor<int, int, float, float, float>())	// constructs screen-aligned camera
                                   
                                   .def( "setPerspective", &CameraPersp::setPerspective )
                                   .def( "isPersp", &CameraPersp::isPersp )
                                   // TODO .def( "getFrameSphere", &CameraPersp::getFrameSphere )
                                   ,
                                   
                                   // Export CameraPersp
                                   //-------------------------------------------------------------------------------------------
                                   class_< CameraOrtho, Camera >("CameraOrtho")
                                   .def(constructor<>())
                                   .def(constructor<float, float, float, float, float, float>())
                                   
                                   .def( "setOrtho", &CameraOrtho::setOrtho )
                                   .def( "isPersp", &CameraOrtho::isPersp )
                                   .def( "isPersp", &CameraOrtho::isPersp )
                                   
                                   
                                   ];
	}
}}
