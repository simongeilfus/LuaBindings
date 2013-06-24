#include "BindCinderQuaternion.h"

#include "cinder/Quaternion.h"

#include <luabind/luabind.hpp>
#include <luabind/operator.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    void bindCinderQuaternion( lua_State* state ){
        
        // Export cinder Vector Types
        //-------------------------------------------------------------------------------------------
        module( state ) [
                         class_<Quatf>("Quatf")
                         .def(constructor<>())
                         .def(constructor<Quatf>())
                         .def(constructor<float,float,float,float>())
                         .def(constructor<const Vec3f&,float>())
                         .def(constructor<const Vec3f&,const Vec3f&>())
                         .def(constructor<float,float,float>())
                         .def(constructor<const Matrix33f &>())
                         .def(constructor<const Matrix44f &>())
                         .def_readwrite("v", &Quatf::v)
                         .def_readwrite("w", &Quatf::w)
                         
                         
                         .def( "getAxis", &Quatf::getAxis )
                         .def( "getAngle", &Quatf::getAngle )
                         
                         .def( "getPitch", &Quatf::getPitch )
                         .def( "getYaw", &Quatf::getYaw )
                         .def( "getRoll", &Quatf::getRoll )
                         
                         .def( "dot", &Quatf::dot )
                         
                         .def( "length", &Quatf::length )
                         .def( "lengthSquared", &Quatf::lengthSquared )
                         
                         .def( "inverse", &Quatf::inverse )
                         
                         .def( "normalize", &Quatf::normalize )
                         
                         .def( "normalized", &Quatf::normalized )
                         .def( "log", &Quatf::log )
                         .def( "exp", &Quatf::exp )
                         
                         .def( "inverted", &Quatf::inverted )
                         
                         .def( "invert", &Quatf::invert )
                         
                         .def( "set", (void(Quatf::*)(float,float,float,float) ) &Quatf::set )
                         .def( "set", (void(Quatf::*)(const Vec3f &,const Vec3f &) ) &Quatf::set )
                         .def( "set", (void(Quatf::*)(const Vec3f &,float) ) &Quatf::set )
                         .def( "set", (void(Quatf::*)(float,float,float) ) &Quatf::set )
                              
                         .def( "set", &Quatf::getAxisAngle )
                         
                         .def( "set", &Quatf::toMatrix33 )
                         .def( "set", &Quatf::toMatrix44 )
                        
                         .def( "set", &Quatf::lerp )
                         .def( "set", &Quatf::slerpShortestUnenforced )
                         
                         .def( "set", &Quatf::slerp )
                         .def( "set", &Quatf::squadShortestEnforced )
                         
                         .def( "set", &Quatf::squad )
                         .def( "set", &Quatf::spline )
                         
                         .def( "set", (void(Quatf::*)(const Matrix33<float> &)) &Quatf::set )
                         .def( "set", (void(Quatf::*)(const Matrix44<float> &)) &Quatf::set )
                         
                         .def(const_self + other<Quatf>())
                         .def(const_self - other<Quatf>())
                         .def(const_self * other<Quatf>())
                         .def(const_self * other<float>())
                         .def(const_self * other<Vec3f>())
                         .def(const_self == other<Quatf>())
                         .scope [
                                 def( "identity", &Quatf::identity )
                                 ]
                         
                         /*
                                   .def(constructor<float, float>())
                                   .def(constructor<Vec2f>())
                                   .def(constructor<Vec2i>())
                                   .def_readwrite("x", &Vec2f::x)
                                   .def_readwrite("y", &Vec2f::y)
                                   .def(const_self + other<Vec2f>())
                                   .def(const_self - other<Vec2f>())
                                   .def(const_self * other<Vec2f>())
                                   .def(const_self * other<float>())
                                   .def(const_self / other<Vec2f>())
                                   .def(const_self / other<float>())
                                   .def(const_self == other<Vec2f>())
                                   // TODO .def(const_self < other<Vec2f>())
                                   // TODO .def(const_self <= other<Vec2f>())
                                   .def(self * float())
                                   .def(self / float())
                                   .def( "set", ( void(Vec2f::*)(float, float) ) &Vec2f::set )
                                   .def( "set", ( void(Vec2f::*)(const Vec2f &) ) &Vec2f::set )
                                   .def( "dot", &Vec2f::dot )
                                   .def( "cross", &Vec2f::cross )
                                   .def( "distance", &Vec2f::distance )
                                   .def( "distanceSquared", &Vec2f::distanceSquared )
                                   .def( "length", &Vec2f::length )
                                   .def( "normalize", &Vec2f::normalize )
                                   .def( "normalized", &Vec2f::normalized )
                                   .def( "safeNormalize", &Vec2f::safeNormalize )
                                   .def( "safeNormalized", &Vec2f::safeNormalized )
                                   .def( "rotate", &Vec2f::rotate )
                                   .def( "lengthSquared", &Vec2f::lengthSquared )
                                   .def( "limit", &Vec2f::limit )
                                   .def( "limited", &Vec2f::limited )
                                   .def( "invert", &Vec2f::invert )
                                   .def( "inverse", &Vec2f::inverse )
                                   .def( "lerp", &Vec2f::lerp )
                                   .def( "xx", &Vec2f::xx )
                                   .def( "xy", &Vec2f::xy )
                                   .def( "yx", &Vec2f::yx )
                                   .def( "yy", &Vec2f::yy )
                                   .def( "xxx", &Vec2f::xxx )
                                   .def( "xxy", &Vec2f::xxy )
                                   .def( "xyx", &Vec2f::xyx )
                                   .def( "xyy", &Vec2f::xyy )
                                   .def( "yxx", &Vec2f::yxx )
                                   .def( "yxy", &Vec2f::yxy )
                                   .def( "yyx", &Vec2f::yyx )
                                   .def( "yyy", &Vec2f::yyy )
                                   .scope [
                                           def( "max", &Vec2f::max ),
                                           def( "zero", &Vec2f::zero ),
                                           def( "one", &Vec2f::one )
                                           ]
                                   ,
                                   
                                   class_< Vec2i >("Vec2i")
                                   .def(constructor<>())
                                   .def(constructor<int, int >())
                                   .def(constructor<Vec2f>())
                                   .def(constructor<Vec2i>())
                                   .def_readwrite("x", &Vec2i::x)
                                   .def_readwrite("y", &Vec2i::y)
                                   .def(const_self + other<Vec2i>())
                                   .def(const_self - other<Vec2i>())
                                   .def(const_self * other<Vec2i>())
                                   .def(const_self / other<Vec2i>())
                                   .def(const_self == other<Vec2i>())
                                   // TODO .def(const_self < other<Vec2i>())
                                   // TODO .def(const_self <= other<Vec2i>())
                                   .def(self * float())
                                   .def(self / float())
                                   .def( "set", ( void(Vec2i::*)(int, int) ) &Vec2i::set )
                                   .def( "set", ( void(Vec2i::*)(const Vec2i &) ) &Vec2i::set )
                                   .def( "dot", &Vec2i::dot )
                                   .def( "cross", &Vec2i::cross )
                                   .def( "distance", &Vec2i::distance )
                                   .def( "distanceSquared", &Vec2i::distanceSquared )
                                   .def( "length", &Vec2i::length )
                                   .def( "normalize", &Vec2i::normalize )
                                   .def( "normalized", &Vec2i::normalized )
                                   .def( "safeNormalize", &Vec2i::safeNormalize )
                                   .def( "safeNormalized", &Vec2i::safeNormalized )
                                   .def( "rotate", &Vec2i::rotate )
                                   .def( "lengthSquared", &Vec2i::lengthSquared )
                                   .def( "limit", &Vec2i::limit )
                                   .def( "limited", &Vec2i::limited )
                                   .def( "invert", &Vec2i::invert )
                                   .def( "inverse", &Vec2i::inverse )
                                   .def( "lerp", &Vec2i::lerp )
                                   .def( "lerpEq", &Vec2i::lerpEq )
                                   .def( "xx", &Vec2i::xx )
                                   .def( "xy", &Vec2i::xy )
                                   .def( "yx", &Vec2i::yx )
                                   .def( "yy", &Vec2i::yy )
                                   .def( "xxx", &Vec2i::xxx )
                                   .def( "xxy", &Vec2i::xxy )
                                   .def( "xyx", &Vec2i::xyx )
                                   .def( "xyy", &Vec2i::xyy )
                                   .def( "yxx", &Vec2i::yxx )
                                   .def( "yxy", &Vec2i::yxy )
                                   .def( "yyx", &Vec2i::yyx )
                                   .def( "yyy", &Vec2i::yyy )
                                   
                                   .scope [
                                           def( "max", &Vec2i::max ),
                                           def( "zero", &Vec2i::zero ),
                                           def( "one", &Vec2i::one )
                                           ],
                                   
                                   class_<Vec3f >("Vec3f")
                                   .def(constructor<>())
                                   .def(constructor<float, float, float>())
                                   .def(constructor<Vec3f>())
                                   .def(constructor<Vec2f, float>())
                                   .def(constructor<Vec2i, float>())
                                   .def_readwrite("x", &Vec3f::x)
                                   .def_readwrite("y", &Vec3f::y)
                                   .def_readwrite("z", &Vec3f::z)
                                   .def(const_self + other<Vec3f>())
                                   .def(const_self - other<Vec3f>())
                                   .def(const_self * other<Vec3f>())
                                   .def(const_self * other<float>())
                                   .def(const_self / other<Vec3f>())
                                   .def(const_self / other<float>())
                                   .def(const_self == other<Vec3f>())
                                   // TODO .def(const_self < other<Vec3f>())
                                   // TODO .def(const_self <= other<Vec3f>())
                                   .def(self * float())
                                   .def(self / float())
                                   .def( "set", ( void(Vec3f::*)(float, float, float) ) &Vec3f::set )
                                   .def( "set", ( void(Vec3f::*)(const Vec3f &) ) &Vec3f::set )
                                   .def( "dot", &Vec3f::dot )
                                   .def( "cross", &Vec3f::cross )
                                   .def( "distance", &Vec3f::distance )
                                   .def( "distanceSquared", &Vec3f::distanceSquared )
                                   .def( "length", &Vec3f::length )
                                   .def( "normalize", &Vec3f::normalize )
                                   .def( "normalized", &Vec3f::normalized )
                                   .def( "safeNormalize", &Vec3f::safeNormalize )
                                   .def( "safeNormalized", &Vec3f::safeNormalized )
                                   .def( "rotate", &Vec3f::rotate )
                                   .def( "lengthSquared", &Vec3f::lengthSquared )
                                   .def( "limit", &Vec3f::limit )
                                   .def( "limited", &Vec3f::limited )
                                   .def( "invert", &Vec3f::invert )
                                   .def( "inverse", &Vec3f::inverse )
                                   .def( "lerp", &Vec3f::lerp )
                                   .def( "lerpEq", &Vec3f::lerpEq )
                
                                   .def( "xx", &Vec3f::xx )
                                   .def( "xy", &Vec3f::xy )
                                   .def( "xz", &Vec3f::xz )
                                   .def( "yx", &Vec3f::yx )
                                   .def( "yy", &Vec3f::yy )
                                   .def( "yz", &Vec3f::yz )
                                   .def( "zx", &Vec3f::zx )
                                   .def( "zy", &Vec3f::zy )
                                   .def( "zz", &Vec3f::zz )
                                   
                                   .def( "xxx", &Vec3f::xxx )
                                   .def( "xxy", &Vec3f::xxy )
                                   .def( "xxz", &Vec3f::xxz )
                                   .def( "xyx", &Vec3f::xyx )
                                   .def( "xyy", &Vec3f::xyy )
                                   .def( "xyz", &Vec3f::xyz )
                                   .def( "xzx", &Vec3f::xzx )
                                   .def( "xzy", &Vec3f::xzy )
                                   .def( "xzz", &Vec3f::xzz )
                                   .def( "yxx", &Vec3f::yxx )
                                   .def( "yxy", &Vec3f::yxy )
                                   .def( "yxz", &Vec3f::yxz )
                                   .def( "yyx", &Vec3f::yyx )
                                   .def( "yyy", &Vec3f::yyy )
                                   .def( "yyz", &Vec3f::yyz )
                                   .def( "yzx", &Vec3f::yzx )
                                   .def( "yzy", &Vec3f::yzy )
                                   .def( "yzz", &Vec3f::yzz )
                                   .def( "zxx", &Vec3f::zxx )
                                   .def( "zxy", &Vec3f::zxy )
                                   .def( "zxz", &Vec3f::zxz )
                                   .def( "zyx", &Vec3f::zyx )
                                   .def( "zyy", &Vec3f::zyy )
                                   .def( "zyz", &Vec3f::zyz )
                                   .def( "zzx", &Vec3f::zzx )
                                   .def( "zzy", &Vec3f::zzy )
                                   .def( "zzz", &Vec3f::zzz )
                                   
                                   .scope [
                                           def( "max", &Vec3f::max ),
                                           def( "zero", &Vec3f::zero ),
                                           def( "one", &Vec3f::one ),
                                           def( "xAxis", &Vec3f::xAxis ),
                                           def( "yAxis", &Vec3f::yAxis ),
                                           def( "zAxis", &Vec3f::zAxis )
                                           ]
                                   */
                                   ];
    }
}}
