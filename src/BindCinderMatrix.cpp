#include "BindCinderMatrix.h"

#include "cinder/Matrix.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    void bindCinderMatrix( lua_State* state ){
        
        module( state ) [
                                   class_<Matrix22f >("Matrix22f")
                                   .def(constructor<>()),
                                   class_<Matrix33f >("Matrix33f")
                                   .def(constructor<>())
                                   .def( "setToNull", &Matrix33f::setToNull )
                                   .def( "setToIdentity", &Matrix33f::setToIdentity )
                                   .def( "rotate",  ( void(Matrix33f::*) (const Vec3f &, float) ) &Matrix33f::rotate ),
                                   class_<Matrix44f >("Matrix44f")
                                   .def(constructor<>())
                                   .def( "setToNull", &Matrix44f::setToNull )
                                   .def( "setToIdentity", &Matrix44f::setToIdentity )
                                   .def( "translate",  ( void(Matrix44f::*) (const Vec3f &) ) &Matrix44f::translate )
                                   .def( "translate",  ( void(Matrix44f::*) (const Vec4f &) ) &Matrix44f::translate )
                                   .def( "rotate",  ( void(Matrix44f::*) (const Vec3f &) ) &Matrix44f::rotate )
                                   .def( "transformPoint",  ( Vec3f(Matrix44f::*) (const Vec3f &) ) &Matrix44f::transformPoint )
                                   .def( "transformPointAffine",  ( Vec3f(Matrix44f::*) (const Vec3f &) ) &Matrix44f::transformPointAffine )
                                   .def( "transformVec",  ( Vec3f(Matrix44f::*) (const Vec3f &) const ) &Matrix44f::transformVec )
                                   .def( "transformVec",  ( Vec4f(Matrix44f::*) (const Vec4f &) const ) &Matrix44f::transformVec )

                                   ];
    }
    
}}
