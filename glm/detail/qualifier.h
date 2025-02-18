#ifndef GLM_DETAIL_QUALIFIER_H
#define GLM_DETAIL_QUALIFIER_H

#include "setup.h"

/*
    anything starting with _glm_ is private namespace
    anything starting with glm_ is public namespace
    
*/

typedef float glm_float;
typedef double glm_double;
typedef int glm_int;
typedef unsigned int glm_uint;
typedef bool glm_bool;

#define _GLM4(_1, _2, _3, _4) glm_ ## _1 ## _ ## _2 ## _ ## _3 ## _ ## _4
#define _GLM3(_1, _2, _3, _4) glm_ ## _1 ## _ ## _2 ## _ ## _3
#define _GLM2(_1, _2, _3, _4) glm_ ## _1 ## _ ## _2
#define _GLM1(_1, _2, _3, _4) glm_ ## _1

#define _GLMN(_1, _2, _3, _4, N, ...) _GLM##N(_1, _2, _3, _4)
#define glm(...) _GLMN(__VA_ARGS__, 4, 3, 2, 1, 0)

#define glm_vec(L, T) glm(T##L)
#define glm_mat(C, R, T) glm(T##C##x##R)
#define glm_quat(T) glm(quat_##T)

#ifdef USING_NAMESPACE_GLM
#define vec(L, T) glm_vec(L, T)
#define mat(C, R, T) glm_mat(C, R, T)
#define quat(T) glm_quat(T)
#endif /* GLM_USING_NAMESPACE */

#define GLM_CREATE_VEC(L, T, ...)    GLM_CREATE_VEC##L (T, __VA_ARGS__)
#define GLM_CREATE_MAT(C, R, T, ...) GLM_CREATE_MAT##C##X##R (T, __VA_ARGS__)
#define GLM_CREATE_QUAT(T, ...)      GLM_CREATE_QUAT (T, __VA_ARGS__)

#define GLM_AUTO_TYPE GLM_ENABLED
#define glm_auto(identifier, expression) __typeof__((expression)) identifier = expression;

typedef enum glm_type
{
    GLM_TYPE_FLOAT,
    GLM_TYPE_FLOAT1,
    GLM_TYPE_FLOAT2,
    GLM_TYPE_FLOAT3,
    GLM_TYPE_FLOAT4,
    GLM_TYPE_DOUBLE,
    GLM_TYPE_DOUBLE1,
    GLM_TYPE_DOUBLE2,
    GLM_TYPE_DOUBLE3,
    GLM_TYPE_DOUBLE4,
    GLM_TYPE_INT,
    GLM_TYPE_INT1,
    GLM_TYPE_INT2,
    GLM_TYPE_INT3,
    GLM_TYPE_INT4,
    GLM_TYPE_UINT,
    GLM_TYPE_UINT1,
    GLM_TYPE_UINT2,
    GLM_TYPE_UINT3,
    GLM_TYPE_UINT4,
    GLM_TYPE_BOOL,
    GLM_TYPE_BOOL1,
    GLM_TYPE_BOOL2,
    GLM_TYPE_BOOL3,
    GLM_TYPE_BOOL4,
} glm_type;

/*
#define GLM_TYPE_VEC1 GLM_TYPE_FLOAT1
#define GLM_TYPE_VEC2 GLM_TYPE_FLOAT2
#define GLM_TYPE_VEC3 GLM_TYPE_FLOAT3
#define GLM_TYPE_VEC4 GLM_TYPE_FLOAT4
#define GLM_TYPE_DVEC1 GLM_TYPE_DOUBLE1
#define GLM_TYPE_DVEC2 GLM_TYPE_DOUBLE2
#define GLM_TYPE_DVEC3 GLM_TYPE_DOUBLE3
#define GLM_TYPE_DVEC4 GLM_TYPE_DOUBLE4
#define GLM_TYPE_IVEC1 GLM_TYPE_INT1
#define GLM_TYPE_IVEC2 GLM_TYPE_INT2
#define GLM_TYPE_IVEC3 GLM_TYPE_INT3
#define GLM_TYPE_IVEC4 GLM_TYPE_INT4
#define GLM_TYPE_UVEC1 GLM_TYPE_UINT1
#define GLM_TYPE_UVEC2 GLM_TYPE_UINT2
#define GLM_TYPE_UVEC3 GLM_TYPE_UINT3
#define GLM_TYPE_UVEC4 GLM_TYPE_UINT4
#define GLM_TYPE_BVEC1 GLM_TYPE_BOOL1
#define GLM_TYPE_BVEC2 GLM_TYPE_BOOL2
#define GLM_TYPE_BVEC3 GLM_TYPE_BOOL3
#define GLM_TYPE_BVEC4 GLM_TYPE_BOOL4
*/

/*
*   Define glm_type_t members from internal convention to external.
*/

#define GLM_TYPEOF(x) \
(_Generic(x, \
glm_float:  GLM_TYPE_FLOAT, \
glm_double:  GLM_TYPE_DOUBLE, \
glm_int:  GLM_TYPE_INT, \
glm_uint:  GLM_TYPE_UINT, \
glm_bool:  GLM_TYPE_BOOL \
))

bool GLM_API
glm_is_scalar (glm_type T)
{
    return
    T == GLM_TYPE_FLOAT ||
    T == GLM_TYPE_DOUBLE ||
    T == GLM_TYPE_INT ||
    T == GLM_TYPE_UINT ||
    T == GLM_TYPE_BOOL;
}

bool GLM_API
glm_is_tvec1 (glm_type T)
{
    return
    T == GLM_TYPE_FLOAT1 ||
    T == GLM_TYPE_DOUBLE1 ||
    T == GLM_TYPE_INT1 ||
    T == GLM_TYPE_UINT1 ||
    T == GLM_TYPE_BOOL1;
}

bool GLM_API
glm_is_tvec2 (glm_type T)
{
    return
    T == GLM_TYPE_FLOAT2 ||
    T == GLM_TYPE_DOUBLE2 ||
    T == GLM_TYPE_INT2 ||
    T == GLM_TYPE_UINT2 ||
    T == GLM_TYPE_BOOL2;
}

bool GLM_API
glm_is_tvec3 (glm_type T)
{
    return
    T == GLM_TYPE_FLOAT3 ||
    T == GLM_TYPE_DOUBLE3 ||
    T == GLM_TYPE_INT3 ||
    T == GLM_TYPE_UINT3 ||
    T == GLM_TYPE_BOOL3;
}

bool GLM_API
glm_is_tvec4 (glm_type T)
{
    return
    T == GLM_TYPE_FLOAT4 ||
    T == GLM_TYPE_DOUBLE4 ||
    T == GLM_TYPE_INT4 ||
    T == GLM_TYPE_UINT4 ||
    T == GLM_TYPE_BOOL4;
}

bool GLM_API
glm_is_vec (glm_type T)
{
    return
    glm_is_tvec1(T) ||
    glm_is_tvec2(T) ||
    glm_is_tvec3(T) ||
    glm_is_tvec4(T);
}

#endif /* GLM_DETAIL_QUALIFIER_H */
