#include "BindCinderTriMesh.h"

#include "cinder/TriMesh.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    static void appendVertices( TriMesh& mesh, const std::vector<Vec3f>& vertices )
    {
        mesh.appendVertices( &vertices[0], vertices.size() );
    }
    static void appendNormals( TriMesh& mesh, const std::vector<Vec3f>& normals )
    {
        mesh.appendNormals( &normals[0], normals.size() );
    }
    static void appendIndices( TriMesh& mesh, std::vector<uint32_t>& indices )
    {
        mesh.appendIndices( &indices[0], indices.size() );
    }
    static void appendTexCoords( TriMesh& mesh, const std::vector<Vec2f>& texCoords )
    {
        mesh.appendTexCoords( &texCoords[0], texCoords.size() );
    }
    
    void bindCinderTriMesh( lua_State* state ){
        
        module( state ) [
                                    class_< TriMesh >("TriMesh")
                                   .def(constructor<>())
                                   .def( "clear", &TriMesh::clear )
                                   .def( "hasNormals", &TriMesh::hasNormals )
                                   .def( "hasColorsRGB", &TriMesh::hasColorsRGB )
                                   .def( "hasColorsRGBA", &TriMesh::hasColorsRGBA )
                                   .def( "hasTexCoords", &TriMesh::hasTexCoords )
                                   
                                   .def( "appendVertex", &TriMesh::appendVertex )
                                   .def( "appendVertices", ( void(TriMesh::*)(const Vec3f*,size_t) ) &TriMesh::appendVertices )
                                   .def( "appendVertices", ( void(TriMesh::*)(const Vec4d*,size_t) ) &TriMesh::appendVertices )
                                   .def( "appendVertices", appendVertices )
                                   .def( "appendNormal", &TriMesh::appendNormal )
                                   .def( "appendNormals", ( void(TriMesh::*)(const Vec3f*,size_t) ) &TriMesh::appendNormals )
                                   .def( "appendNormals", ( void(TriMesh::*)(const Vec4d*,size_t) ) &TriMesh::appendNormals )
                                   .def( "appendNormals", appendNormals )
                                   .def( "appendColorRgb", ( void(TriMesh::*)(const Color&) ) &TriMesh::appendColorRgb )
                                   .def( "appendColorRgba", ( void(TriMesh::*)(const ColorA&) ) &TriMesh::appendColorRgba )
                                   .def( "appendTexCoord", &TriMesh::appendTexCoord )
                                   
                                   .def( "appendColorsRgb", &TriMesh::appendColorsRgb )
                                   .def( "appendColorsRgba", &TriMesh::appendColorsRgba )
                                   .def( "appendTexCoords", &TriMesh::appendTexCoords )
                                   .def( "appendTexCoords", appendTexCoords )
                                   
                                   .def( "appendTriangle", &TriMesh::appendTriangle )
                                   .def( "appendIndices", &TriMesh::appendIndices )
                                   .def( "appendIndices", appendIndices )
                                   
                                   .def( "getNumIndices", &TriMesh::getNumIndices )
                                   .def( "getNumTriangles", &TriMesh::getNumTriangles )
                                   .def( "getNumVertices", &TriMesh::getNumVertices )
                                   
                                   .def( "getTriangleVertices", &TriMesh::getTriangleVertices )
                                   
                                   .def( "getVertices", ( std::vector<Vec3f>&(TriMesh::*)() ) &TriMesh::getVertices )
                                   .def( "getVertices", ( const std::vector<Vec3f>&(TriMesh::*)() const ) &TriMesh::getVertices )
                                   .def( "getNormals", ( std::vector<Vec3f>&(TriMesh::*)() ) &TriMesh::getNormals )
                                   .def( "getNormals", ( const std::vector<Vec3f>&(TriMesh::*)() const ) &TriMesh::getNormals )
                                   .def( "getColorsRGB", ( std::vector<Color>&(TriMesh::*)() ) &TriMesh::getColorsRGB )
                                   .def( "getColorsRGB", ( const std::vector<Color>&(TriMesh::*)() const ) &TriMesh::getColorsRGB )
                                   .def( "getColorsRGBA", ( std::vector<ColorA>&(TriMesh::*)() ) &TriMesh::getColorsRGBA )
                                   .def( "getColorsRGBA", ( const std::vector<ColorA>&(TriMesh::*)() const ) &TriMesh::getColorsRGBA )
                                   .def( "getTexCoords", ( std::vector<Vec2f>&(TriMesh::*)() ) &TriMesh::getTexCoords )
                                   .def( "getTexCoords", ( const std::vector<Vec2f>&(TriMesh::*)() const ) &TriMesh::getTexCoords )
                                   .def( "getIndices", ( std::vector<uint32_t>&(TriMesh::*)() ) &TriMesh::getIndices )
                                   .def( "getIndices", ( const std::vector<uint32_t>&(TriMesh::*)() const ) &TriMesh::getIndices )
                                   
                                   .def( "calcBoundingBox", ( AxisAlignedBox3f(TriMesh::*)() const ) &TriMesh::calcBoundingBox )
                                   .def( "calcBoundingBox", ( AxisAlignedBox3f(TriMesh::*)(const Matrix44f &) const ) &TriMesh::calcBoundingBox )
                                   
                                   .def( "read", &TriMesh::read )
                                   .def( "write", &TriMesh::write )
                                   
                                   .def( "recalculateNormals", &TriMesh::recalculateNormals )
                                   
                                   
                                         ];
    }
    
}}