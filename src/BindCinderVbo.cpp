#include "BindCinderVbo.h"

#include "cinder/gl/Vbo.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    static void unbindBuffers( gl::VboMesh& vbo )
    {
        vbo.unbindBuffers();
    }
    
    void bindCinderVbo( lua_State* state ){
        
        
        module( state, "gl" ) [
                                         
                                         
                                         // Export gl::VboMesh
                                         //-------------------------------------------------------------------------------------------
                                         class_< gl::VboMesh >("VboMesh")
                                         .def(constructor<>())
                                         .def(constructor<const TriMesh &, gl::VboMesh::Layout>())
                                         .def(constructor<const TriMesh2d &, gl::VboMesh::Layout>())
                                         .def(constructor<size_t, size_t, gl::VboMesh::Layout, GLenum>())
                                         .def( "getNumIndices", &gl::VboMesh::getNumIndices )
                                         .def( "getNumVertices", &gl::VboMesh::getNumVertices )
                                         .def( "getPrimitiveType", &gl::VboMesh::getPrimitiveType )
                                         .def( "getLayout", &gl::VboMesh::getLayout )
                                         .def( "bindIndexBuffer", &gl::VboMesh::bindIndexBuffer )
                                         .def( "enableClientStates", &gl::VboMesh::enableClientStates )
                                         .def( "disableClientStates", &gl::VboMesh::disableClientStates )
                                         .def( "bindAllData", &gl::VboMesh::bindAllData )
                                         .def( "bufferIndices", &gl::VboMesh::bufferIndices )
                                         .def( "bufferPositions", ( void(gl::VboMesh::*) ( const std::vector<Vec3f> & ) ) &gl::VboMesh::bufferPositions )
                                         .def( "bufferNormals", &gl::VboMesh::bufferNormals )
                                         .def( "bufferTexCoords2d", &gl::VboMesh::bufferTexCoords2d )
                                         .def( "bufferColorsRGB", &gl::VboMesh::bufferColorsRGB )
                                         .def( "bufferColorsRGBA", &gl::VboMesh::bufferColorsRGBA )
                                         .def( "mapVertexBuffer", &gl::VboMesh::mapVertexBuffer )
                                         .def( "getIndexVbo", &gl::VboMesh::getIndexVbo )
                                         .def( "getStaticVbo", &gl::VboMesh::getStaticVbo )
                                         .def( "getDynamicVbo", &gl::VboMesh::getDynamicVbo )
                                         .def( "setCustomStaticLocation", &gl::VboMesh::setCustomStaticLocation )
                                         .def( "setCustomDynamicLocation", &gl::VboMesh::setCustomDynamicLocation )
                                         .def( "getTexCoordOffset", &gl::VboMesh::getTexCoordOffset )
                                         .def( "setTexCoordOffset", &gl::VboMesh::setTexCoordOffset )
                                         .def( "reset", &gl::VboMesh::reset )
                                         .def( "unbindBuffers", &unbindBuffers )
                
                                         .enum_("constants")[
                                                             value( "NONE", (int) gl::VboMesh::NONE ),
                                                             value( "STATIC", (int) gl::VboMesh::STATIC ),
                                                             value( "DYNAMIC", (int) gl::VboMesh::DYNAMIC ),
                                                             value( "ATTR_INDICES", (int) gl::VboMesh::ATTR_INDICES ),
                                                             value( "ATTR_POSITIONS", (int) gl::VboMesh::ATTR_POSITIONS ),
                                                             value( "ATTR_NORMALS", (int) gl::VboMesh::ATTR_NORMALS ),
                                                             value( "ATTR_COLORS_RGB", (int) gl::VboMesh::ATTR_COLORS_RGB ),
                                                             value( "ATTR_COLORS_RGBA", (int) gl::VboMesh::ATTR_COLORS_RGBA ),
                                                             value( "ATTR_TEXCOORDS2D_0", (int) gl::VboMesh::ATTR_TEXCOORDS2D_0 ),
                                                             value( "ATTR_TEXCOORDS2D_1", (int) gl::VboMesh::ATTR_TEXCOORDS2D_1 ),
                                                             value( "ATTR_TEXCOORDS2D_2", (int) gl::VboMesh::ATTR_TEXCOORDS2D_2 ),
                                                             value( "ATTR_TEXCOORDS2D_3", (int) gl::VboMesh::ATTR_TEXCOORDS2D_3 ),
                                                             value( "ATTR_TEXCOORDS3D_0", (int) gl::VboMesh::ATTR_TEXCOORDS3D_0 ),
                                                             value( "ATTR_TEXCOORDS3D_1", (int) gl::VboMesh::ATTR_TEXCOORDS3D_1 ),
                                                             value( "ATTR_TEXCOORDS3D_2", (int) gl::VboMesh::ATTR_TEXCOORDS3D_2 ),
                                                             value( "ATTR_TEXCOORDS3D_3", (int) gl::VboMesh::ATTR_TEXCOORDS3D_3 ),
                                                             value( "ATTR_TOTAL", (int) gl::VboMesh::ATTR_TOTAL ),
                                                             value( "ATTR_MAX_TEXTURE_UNIT", (int) gl::VboMesh::ATTR_MAX_TEXTURE_UNIT ),
                                                             value( "INDEX_BUFFER", (int) gl::VboMesh::INDEX_BUFFER ),
                                                             value( "STATIC_BUFFER", (int) gl::VboMesh::STATIC_BUFFER ),
                                                             value( "DYNAMIC_BUFFER", (int) gl::VboMesh::DYNAMIC_BUFFER ),
                                                             value( "TOTAL_BUFFERS", (int) gl::VboMesh::TOTAL_BUFFERS )
                                                             ]
                                         .scope[
                                                
                                                // Export gl::VboMesh::Layout
                                                //-------------------------------------------------------------------------------------------
                                                class_< gl::VboMesh::Layout >("Layout")
                                                .enum_("constants")
                                                [
                                                 value( "CUSTOM_ATTR_FLOAT", (int) gl::VboMesh::Layout::CUSTOM_ATTR_FLOAT ),
                                                 value( "CUSTOM_ATTR_FLOAT2", (int) gl::VboMesh::Layout::CUSTOM_ATTR_FLOAT2 ),
                                                 value( "CUSTOM_ATTR_FLOAT3", (int) gl::VboMesh::Layout::CUSTOM_ATTR_FLOAT3 ),
                                                 value( "CUSTOM_ATTR_FLOAT4", (int) gl::VboMesh::Layout::CUSTOM_ATTR_FLOAT4 ),
                                                 value( "TOTAL_CUSTOM_ATTR_TYPES", (int) gl::VboMesh::Layout::TOTAL_CUSTOM_ATTR_TYPES )
                                                 ]
                                                .def(constructor<>())
                                                .def( "isDefaults", &gl::VboMesh::Layout::isDefaults )
                                                .def( "hasNormals", &gl::VboMesh::Layout::hasNormals )
                                                .def( "hasStaticNormals", &gl::VboMesh::Layout::hasStaticNormals )
                                                .def( "hasDynamicNormals", &gl::VboMesh::Layout::hasDynamicNormals )
                                                .def( "setStaticNormals", &gl::VboMesh::Layout::setStaticNormals )
                                                .def( "setDynamicNormals", &gl::VboMesh::Layout::setDynamicNormals )
                                                .def( "hasColorsRGB", &gl::VboMesh::Layout::hasColorsRGB )
                                                .def( "hasStaticColorsRGB", &gl::VboMesh::Layout::hasStaticColorsRGB )
                                                .def( "hasDynamicColorsRGB", &gl::VboMesh::Layout::hasDynamicColorsRGB )
                                                .def( "setStaticColorsRGB", &gl::VboMesh::Layout::setStaticColorsRGB )
                                                .def( "setDynamicColorsRGB", &gl::VboMesh::Layout::setDynamicColorsRGB )
                                                .def( "hasColorsRGBA", &gl::VboMesh::Layout::hasColorsRGBA )
                                                .def( "hasStaticColorsRGBA", &gl::VboMesh::Layout::hasStaticColorsRGBA )
                                                .def( "hasDynamicColorsRGBA", &gl::VboMesh::Layout::hasDynamicColorsRGBA )
                                                .def( "setStaticColorsRGBA", &gl::VboMesh::Layout::setStaticColorsRGBA )
                                                .def( "setDynamicColorsRGBA", &gl::VboMesh::Layout::setDynamicColorsRGBA )
                                                .def( "hasTexCoords2d", &gl::VboMesh::Layout::hasTexCoords2d )
                                                .def( "hasStaticTexCoords2d", &gl::VboMesh::Layout::hasStaticTexCoords2d )
                                                .def( "hasDynamicTexCoords2d", &gl::VboMesh::Layout::hasDynamicTexCoords2d )
                                                .def( "setStaticTexCoords2d", &gl::VboMesh::Layout::setStaticTexCoords2d )
                                                .def( "setDynamicTexCoords2d", &gl::VboMesh::Layout::setDynamicTexCoords2d )
                                                .def( "hasStaticTexCoords", &gl::VboMesh::Layout::hasStaticTexCoords )
                                                .def( "hasDynamicTexCoords", &gl::VboMesh::Layout::hasDynamicTexCoords )
                                                .def( "hasTexCoords", &gl::VboMesh::Layout::hasTexCoords )
                                                .def( "hasTexCoords3d", &gl::VboMesh::Layout::hasTexCoords3d )
                                                .def( "hasStaticTexCoords3d", &gl::VboMesh::Layout::hasStaticTexCoords3d )
                                                .def( "hasDynamicTexCoords3d", &gl::VboMesh::Layout::hasDynamicTexCoords3d )
                                                .def( "setStaticTexCoords3d", &gl::VboMesh::Layout::setStaticTexCoords3d )
                                                .def( "setDynamicTexCoords3d", &gl::VboMesh::Layout::setDynamicTexCoords3d )
                                                .def( "hasIndices", &gl::VboMesh::Layout::hasIndices )
                                                .def( "hasStaticIndices", &gl::VboMesh::Layout::hasStaticIndices )
                                                .def( "hasDynamicIndices", &gl::VboMesh::Layout::hasDynamicIndices )
                                                .def( "setStaticIndices", &gl::VboMesh::Layout::setStaticIndices )
                                                .def( "setDynamicIndices", &gl::VboMesh::Layout::setDynamicIndices )
                                                .def( "hasPositions", &gl::VboMesh::Layout::hasPositions )
                                                .def( "hasStaticPositions", &gl::VboMesh::Layout::hasStaticPositions )
                                                .def( "hasDynamicPositions", &gl::VboMesh::Layout::hasDynamicPositions )
                                                .def( "setStaticPositions", &gl::VboMesh::Layout::setStaticPositions )
                                                .def( "setDynamicPositions", &gl::VboMesh::Layout::setDynamicPositions )
                                                .def( "addDynamicCustomFloat", &gl::VboMesh::Layout::addDynamicCustomFloat )
                                                .def( "addDynamicCustomVec2f", &gl::VboMesh::Layout::addDynamicCustomVec2f )
                                                .def( "addDynamicCustomVec3f", &gl::VboMesh::Layout::addDynamicCustomVec3f )
                                                .def( "addDynamicCustomVec4f", &gl::VboMesh::Layout::addDynamicCustomVec4f )
                                                ],
                                         
                                         class_< gl::Vbo >("Vbo")
                                         .def(constructor<>())
                                         .def(constructor<GLenum>())
                                         ];
    }
}}
