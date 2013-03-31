#include "BindCinderGlslProg.h"

#include "cinder/gl/GlslProg.h"

#include <luabind/luabind.hpp>
#include <luabind/operator.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    SafeShader::SafeShader( ci::DataSourceRef vertexShader, ci::DataSourceRef fragmentShader, ci::DataSourceRef geometryShader,
           GLint geometryInputType, GLint geometryOutputType, GLint geometryOutputVertices)
    {
        
        try {
            mObj = shared_ptr<Obj>( new Obj );
            
            mObj->mHandle = glCreateProgram();
            
            if ( vertexShader )
                loadShader( vertexShader->getBuffer(), GL_VERTEX_SHADER_ARB );
            
            if( fragmentShader )
                loadShader( fragmentShader->getBuffer(), GL_FRAGMENT_SHADER_ARB );
            
            if( geometryShader ) {
                loadShader( geometryShader->getBuffer(), GL_GEOMETRY_SHADER_EXT );
                
                glProgramParameteriEXT(mObj->mHandle, GL_GEOMETRY_INPUT_TYPE_EXT, geometryInputType);
                glProgramParameteriEXT(mObj->mHandle, GL_GEOMETRY_OUTPUT_TYPE_EXT, geometryOutputType);
                glProgramParameteriEXT(mObj->mHandle, GL_GEOMETRY_VERTICES_OUT_EXT, geometryOutputVertices);
            }
            
            link();
        }
        catch( gl::GlslProgCompileExc exc ){
            cout << exc.what() << endl;
        }
    }
    
    SafeShader::SafeShader( const char *vertexShader, const char *fragmentShader, const char *geometryShader, GLint geometryInputType, GLint geometryOutputType, GLint geometryOutputVertices)
    {
        try {
            mObj = shared_ptr<Obj>( new Obj );
            
            mObj->mHandle = glCreateProgram();
            
            if ( vertexShader )
                loadShader( vertexShader, GL_VERTEX_SHADER_ARB );
            
            if( fragmentShader )
                loadShader( fragmentShader, GL_FRAGMENT_SHADER_ARB );
            
            if( geometryShader ) {
                loadShader( geometryShader, GL_GEOMETRY_SHADER_EXT );
                
                glProgramParameteriEXT(mObj->mHandle, GL_GEOMETRY_INPUT_TYPE_EXT, geometryInputType);
                glProgramParameteriEXT(mObj->mHandle, GL_GEOMETRY_OUTPUT_TYPE_EXT, geometryOutputType);
                glProgramParameteriEXT(mObj->mHandle, GL_GEOMETRY_VERTICES_OUT_EXT, geometryOutputVertices);
            }
            
            link();
        }
        catch( gl::GlslProgCompileExc exc ){
            cout << exc.what() << endl;
        }
        
    }
    
    
    void bindCinderGlslProg( lua_State* state ) {
        
        module( state, "gl" ) [
                                         class_< gl::GlslProg >("GlslProgBase")
                                         ];
        
        module( state, "gl" ) [
                                         class_< SafeShader, gl::GlslProg >("GlslProg")
                                         .def(constructor<>())
                                         .def(constructor<DataSourceRef>())
                                         .def(constructor<DataSourceRef, DataSourceRef>())
                                         .def(constructor<DataSourceRef, DataSourceRef, DataSourceRef>())
                                         .def(constructor<DataSourceRef, DataSourceRef, DataSourceRef, GLint, GLint, GLint>())
                                         .def(constructor<const char *>())
                                         .def(constructor<const char *, const char *>())
                                         .def(constructor<const char *, const char *, const char *>())
                                         .def(constructor<const char *, const char *, const char *, GLint, GLint, GLint>())
                                         //.def( const_self == other<gl::GlslProg::unspecified_bool_type>() )
                                         .def( "bind", &SafeShader::bind )
                                         .def( "unbind", &SafeShader::unbind )
                                         
                                         .def( "getHandle", &SafeShader::getHandle )
                                         //.def( "uniform", ( void(SafeShader::*) ( const std::string &, int) ) &SafeShader::uniform )
                                         .def( "uniform", ( void(SafeShader::*) ( const std::string &, float  ) ) &SafeShader::uniform )
                                         .def( "uniform", ( void(SafeShader::*) ( const std::string &, const Vec2i &) ) &SafeShader::uniform )
                                         .def( "uniform", ( void(SafeShader::*) ( const std::string &, const Vec2f & ) ) &SafeShader::uniform )
                                         .def( "uniform", ( void(SafeShader::*) ( const std::string &, const Vec3f & ) ) &SafeShader::uniform )
                                         .def( "uniform", ( void(SafeShader::*) ( const std::string &, const Vec4f & ) ) &SafeShader::uniform )
                                         .def( "uniform", ( void(SafeShader::*) ( const std::string &, const Color & ) ) &SafeShader::uniform )
                                         .def( "uniform", ( void(SafeShader::*) ( const std::string &, const ColorA & ) ) &SafeShader::uniform )
                                         .def( "uniform", ( void(SafeShader::*) ( const std::string &, const Matrix44f &, bool ) ) &SafeShader::uniform )
                                         .def( "getUniformLocation", &SafeShader::getUniformLocation )
                                         .def( "getAttribLocation", &SafeShader::getAttribLocation )
                                         .def( "getShaderLog", &SafeShader::getShaderLog )
                                         ];
    }
    
    
}}
