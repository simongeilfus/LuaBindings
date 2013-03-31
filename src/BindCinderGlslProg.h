#pragma once

extern "C" {
#include <lua/lua.h>
}


#include "cinder/gl/GlslProg.h"

namespace lua {

	namespace Bindings {

        
        class SafeShader : public ci::gl::GlslProg {
        public:
            SafeShader(){}
            SafeShader( ci::DataSourceRef vertexShader, ci::DataSourceRef fragmentShader = ci::DataSourceRef(), ci::DataSourceRef geometryShader = ci::DataSourceRef(),
                   GLint geometryInputType = GL_POINTS, GLint geometryOutputType = GL_TRIANGLES, GLint geometryOutputVertices = 0);
            
            SafeShader( const char *vertexShader, const char *fragmentShader = 0, const char *geometryShader = 0, GLint geometryInputType = GL_POINTS, GLint geometryOutputType = GL_TRIANGLES, GLint geometryOutputVertices = 0);
            
            void bindCinder(){ if( *this ) ci::gl::GlslProg::bind(); }
            
            void unbind(){ if( *this ) ci::gl::GlslProg::unbind(); }
        };
        
		void bindCinderGlslProg( lua_State* state );
        
        
	
    };

}

