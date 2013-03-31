#include "BindCinderGl.h"

#include "cinder/TriMesh.h"
#include "cinder/Camera.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/Vbo.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    static void begin( GLenum type ){ glBegin( type ); }
    static void end(){ glEnd(); }
    
    
    static void draw( const gl::Texture &texture )
    {
        if( texture )
            gl::draw( texture, Area( texture.getCleanBounds() ), texture.getCleanBounds() );
    }
    
    static void draw( const gl::Texture &texture, const Vec2f &pos )
    {
        if( texture )
            gl::draw( texture, texture.getCleanBounds(), Rectf( pos.x, pos.y, pos.x + texture.getCleanWidth(), pos.y + texture.getCleanHeight() ) );
    }
    
    static void draw( const gl::Texture &texture, const Rectf &rect )
    {
        if( texture )
            gl::draw( texture, texture.getCleanBounds(), rect );
    }
    
    static void draw( const gl::Texture &texture, const Area &srcArea, const Rectf &destRect )
    {
        if( texture )
            gl::draw( texture, srcArea, destRect );
    }
    static void draw( const gl::VboMesh &vbo )
    {
        if( vbo )
            gl::draw( vbo );
    }
    
    static void drawRange( const gl::VboMesh &vbo, size_t startIndex, size_t indexCount, int vertexStart, int vertexEnd )
    {
        if( vbo )
            gl::drawRange( vbo, startIndex, indexCount, vertexStart, vertexEnd );
    }
    
    static void drawArrays( const gl::VboMesh &vbo, GLint first, GLsizei count )
    {
        if( vbo )
            gl::drawArrays( vbo, first, count );
    }
    
    void bindCinderGL( lua_State* state ){
        
        // GL
        //-------------------------------------------------------------------------------------------
        
        module( state, "gl" ) [
                                         
                                         def( "isExtensionAvailable", gl::isExtensionAvailable ),
                                         def( "clear", gl::clear ),
                                         def( "setMatrices", gl::setMatrices ),
                                         def( "setModelView", gl::setModelView ),
                                         def( "setProjection", gl::setProjection ),
                                         def( "pushModelView", ( void(*) () ) gl::pushModelView ),
                                         def( "popModelView", gl::popModelView ),
                                         def( "pushMatrices", gl::pushMatrices ),
                                         def( "popMatrices", gl::popMatrices ),
                                         def( "multModelView", gl::multModelView ),
                                         def( "multProjection", gl::multProjection ),
                                         def( "getModelView", gl::getModelView ),
                                         def( "getProjection", gl::getProjection ),
                                         def( "setMatricesWindowPersp", ( void(*) (int, int, float, float, float, bool) ) gl::setMatricesWindowPersp ),
                                         def( "setMatricesWindowPersp", ( void(*) (const Vec2i &, float, float, float, bool) ) gl::setMatricesWindowPersp ),
                                         def( "setMatricesWindow", ( void(*) (int, int, bool) ) gl::setMatricesWindow ),
                                         def( "setMatricesWindow", ( void(*) (const Vec2i&, bool) ) gl::setMatricesWindow ),
                                         def( "getViewport", gl::getViewport ),
                                         def( "setViewport", gl::setViewport ),
                                         def( "translate", ( void(*) (float, float) ) gl::translate ),
                                         def( "translate", ( void(*) (float, float, float) ) gl::translate ),
                                         def( "scale", ( void(*) (float, float) ) gl::scale ),
                                         def( "scale", ( void(*) (float, float, float) ) gl::scale ),
                                         def( "rotate", ( void(*) (const Vec3f &) ) gl::rotate ),
                                         def( "rotate", ( void(*) (const Quatf &) ) gl::rotate ),
                                         def( "rotate", ( void(*) (float) ) gl::rotate ),
                                         def( "Begin", begin ),
                                         def( "End", end ),
#if ! defined( CINDER_GLES )
                                         def( "vertex", ( void(*) (float, float) ) gl::vertex ),
                                         def( "vertex", ( void(*) (float, float, float) ) gl::vertex ),
#endif // ! defined( CINDER_GLES )
                                         def( "color", ( void(*) (float, float, float) ) gl::color ),
                                         def( "color", ( void(*) (float, float, float, float) ) gl::color ),
                                         def( "color", ( void(*) (const Color &) ) gl::color ),
                                         def( "color", ( void(*) (const ColorA &) ) gl::color ),
                                         def( "enable", gl::enable ),
                                         def( "disable", gl::disable ),
                                         def( "enableAlphaBlending", gl::enableAlphaBlending ),
                                         def( "disableAlphaBlending", gl::disableAlphaBlending ),
                                         def( "enableAdditiveBlending", gl::enableAdditiveBlending ),
                                         def( "enableAlphaTest", gl::enableAlphaTest ),
                                         def( "disableAlphaTest", gl::disableAlphaTest ),
#if ! defined( CINDER_GLES )
                                         def( "enableWireframe", gl::enableWireframe ),
                                         def( "disableWireframe", gl::disableWireframe ),
#endif // ! defined( CINDER_GLES )
                                         def( "disableDepthRead", gl::disableDepthRead ),
                                         def( "disableDepthWrite", gl::disableDepthWrite ),
                                         def( "enableDepthRead", gl::enableDepthRead ),
                                         def( "enableDepthWrite", gl::enableDepthWrite ),
                                         def( "drawLine",  ( void (*)(const Vec2f&, const Vec2f&) ) gl::drawLine ),
                                         def( "drawLine", ( void (*)(const Vec3f&, const Vec3f&) ) gl::drawLine ),
                                         def( "drawCube", ( void (*)(const Vec3f&, const Vec3f&) ) gl::drawCube ),
                                         def( "drawColorCube", gl::drawColorCube ),
                                         def( "drawStrokedCube",  ( void (*)(const Vec3f&, const Vec3f&) ) gl::drawStrokedCube ),
                                         def( "drawSphere", gl::drawSphere ),
                                         def( "drawSolidCircle", gl::drawSolidCircle ),
                                         def( "drawStrokedCircle", gl::drawStrokedCircle ),
                                         def( "drawSolidRect", ( void (*)(const Rectf&) ) gl::drawSolidRect ),
                                         def( "drawSolidRect", ( void (*)(const Rectf&, bool) ) gl::drawSolidRect ),
                                         def( "drawStrokedRect", gl::drawStrokedRect ),
                                         def( "drawCoordinateFrame", gl::drawCoordinateFrame ),
                                         def( "drawVector", gl::drawVector ),
                                         def( "drawFrustum", gl::drawFrustum ),
                                         def( "drawTorus", gl::drawTorus ),
                                         def( "drawCylinder", gl::drawCylinder ),
                                         def( "draw", ( void (*) ( const class PolyLine<Vec2f> & ) ) gl::draw ),
                                         def( "draw", ( void (*) ( const class PolyLine<Vec3f> & ) ) gl::draw ),
                                         def( "draw", ( void (*) ( const class Path2d &, float ) ) gl::draw ),
                                         def( "draw", ( void (*) ( const class Shape2d &, float ) ) gl::draw ),
#if ! defined( CINDER_GLES )
                                         //def( "drawSolid", gl::drawSolid ),
                                         def( "draw", ( void (*) ( const gl::VboMesh & ) ) draw ),
                                         def( "drawRange", ( void (*) (const TriMesh &, size_t, size_t) )  drawRange ),
                                         def( "drawRange", ( void (*) ( const gl::VboMesh &, size_t, size_t, int, int ) ) drawRange ),
                                         def( "drawArrays", drawArrays ),
#endif // !
                                         def( "drawBillboard", gl::drawBillboard ),
                                         def( "draw", ( void (*) ( const gl::Texture & ) ) draw ),
                                         def( "draw", ( void (*) ( const gl::Texture &, const Vec2f & ) ) draw ),
                                         def( "draw", ( void (*) ( const gl::Texture&, const Rectf& ) ) draw ),
                                         def( "draw", ( void (*) ( const gl::Texture &, const Area &, const Rectf & ) ) draw ),
                                         def( "drawString", gl::drawString ),
                                         def( "drawStringCentered", gl::drawStringCentered ),
                                         def( "drawStringRight", gl::drawStringRight )
                                         ];
        
        class GLEnums {};
        
        module( state ) [
                                   class_< GLEnums >("GL").enum_("constants")
                                   [
                                    value( "GL_POINTS", (int) GL_POINTS ),
                                    value( "GL_LINES", (int) GL_LINES ),
                                    value( "GL_LINE_LOOP", (int) GL_LINE_LOOP ),
                                    value( "GL_LINE_STRIP", (int) GL_LINE_STRIP ),
                                    value( "GL_TRIANGLES", (int) GL_TRIANGLES ),
                                    value( "GL_TRIANGLE_STRIP", (int) GL_TRIANGLE_STRIP ),
                                    value( "GL_TRIANGLE_FAN", (int) GL_TRIANGLE_FAN ),
                                    value( "GL_QUADS", (int) GL_QUADS ),
                                    value( "GL_QUAD_STRIP", (int) GL_QUAD_STRIP ),
                                    value( "GL_POLYGON", (int) GL_POLYGON ),
                                    
                                    value( "GL_NEVER", (int) GL_NEVER ),
                                    value( "GL_LESS", (int) GL_LESS ),
                                    value( "GL_EQUAL", (int) GL_EQUAL ),
                                    value( "GL_LEQUAL", (int) GL_LEQUAL ),
                                    value( "GL_GREATER", (int) GL_GREATER ),
                                    value( "GL_NOTEQUAL", (int) GL_NOTEQUAL ),
                                    value( "GL_GEQUAL", (int) GL_GEQUAL ),
                                    value( "GL_ALWAYS", (int) GL_ALWAYS ),
                                    
                                    value( "GL_TEXTURE0", (int) GL_TEXTURE0 ),
                                    value( "GL_TEXTURE1", (int) GL_TEXTURE1 ),
                                    value( "GL_TEXTURE2", (int) GL_TEXTURE2 ),
                                    value( "GL_TEXTURE3", (int) GL_TEXTURE3 ),
                                    value( "GL_TEXTURE4", (int) GL_TEXTURE4 ),
                                    value( "GL_TEXTURE5", (int) GL_TEXTURE5 ),
                                    value( "GL_TEXTURE6", (int) GL_TEXTURE6 ),
                                    value( "GL_TEXTURE7", (int) GL_TEXTURE7 ),
                                    value( "GL_TEXTURE8", (int) GL_TEXTURE8 ),
                                    value( "GL_TEXTURE9", (int) GL_TEXTURE9 ),
                                    
                                    value( "GL_TEXTURE_2D", (int) GL_TEXTURE_2D ),
                                    value( "GL_TEXTURE_RECTANGLE_ARB", (int) GL_TEXTURE_RECTANGLE_ARB ),
                                    value( "GL_CLAMP", (int) GL_CLAMP ),
                                    value( "GL_REPEAT", (int) GL_REPEAT ),
                                    value( "GL_CLAMP_TO_EDGE", (int) GL_CLAMP_TO_EDGE ),
                                    value( "GL_NEAREST", (int) GL_NEAREST ),
                                    value( "GL_LINEAR", (int) GL_LINEAR ),
                                    value( "GL_NEAREST_MIPMAP_NEAREST", (int) GL_NEAREST_MIPMAP_NEAREST ),
                                    value( "GL_LINEAR_MIPMAP_NEAREST", (int) GL_LINEAR_MIPMAP_NEAREST ),
                                    value( "GL_NEAREST_MIPMAP_LINEAR", (int) GL_NEAREST_MIPMAP_LINEAR ),
                                    value( "GL_LINEAR_MIPMAP_LINEAR", (int) GL_LINEAR_MIPMAP_LINEAR ),
                                    
                                    value( "GL_RGB", (int) GL_RGB ),
                                    value( "GL_RGBA", (int) GL_RGBA ),
                                    value( "GL_LUMINANCE", (int) GL_LUMINANCE )
                                    ]
                                   ];
    }
    
}}
