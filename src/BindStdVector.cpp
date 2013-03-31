#include "BindStdVector.h"

#include "cinder/Vector.h"
#include "cinder/Color.h"

using namespace std;
using namespace ci;

namespace lua { namespace Bindings {
    
	void bindStdVector( lua_State* state ){
        bindStdVector<float>( state, "vector_float" );
        bindStdVector<int>( state, "vector_int" );
        bindStdVector<uint32_t>( state, "vector_uint32_t" );
        bindStdVector<string>( state, "vector_string" );
        bindStdVector<Vec2i>( state, "vector_Vec2i" );
        bindStdVector<Vec2f>( state, "vector_Vec2f" );
        bindStdVector<Vec3f>( state, "vector_Vec3f" );
        bindStdVector<Color>( state, "vector_Color" );
        bindStdVector<ColorA>( state, "vector_ColorA" );
    }
}}
