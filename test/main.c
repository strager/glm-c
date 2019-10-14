#include <stdio.h>
//#include <glm/detail/type_scalar.h>
//#include <glm/detail/type_vec1.h>
//#include <glm/glm_old.h>

typedef union {
    int data[1];
    struct { int x; };
} ivec1, int_vec1;
typedef union {
    int data[2];
    struct { int x, y; };
} ivec2, int_vec2;
typedef union {
    int data[3];
    struct { int x, y, z; };
} ivec3, int_vec3;
typedef union {
    int data[4];
    struct { int x, y, z, w; };
} ivec4, int_vec4;

typedef union {
    float data[1];
    struct { float x; };
} fvec1, float_vec1;
typedef union {
    float data[2];
    struct { float x, y; };
} fvec2, float_vec2;
typedef union {
    float data[3];
    struct { float x, y, z; };
} fvec3, float_vec3;
typedef union {
    float data[4];
    struct { float x, y, z, w; };
} fvec4, float_vec4;

#define glm_vec(L, T) T##_vec##L

#define GLM_CONVERT_TVECN(T, IN) \
    ({ \
        __typeof__((IN)) _in = (IN); \
        _Generic( \
            (char(*)[sizeof _in / sizeof _in.x])0, \
            char(*)[1]: (glm_vec(1, T)) { _in.data[0] }, \
            char(*)[2]: (glm_vec(2, T)) { _in.data[0], _in.data[1] }, \
            char(*)[3]: (glm_vec(3, T)) { _in.data[0], _in.data[1], _in.data[2] }, \
            char(*)[4]: (glm_vec(4, T)) { _in.data[0], _in.data[1], _in.data[2], _in.data[3] } \
        ); \
    })

#define GLM_CONVERT_TYPE_X(T, IN) \
    __typeof__(_Generic( \
        (IN), \
        int: (glm_vec(1, T)) {}, /* doesn't work, yo. */ \
        default: _Generic( \
            (char(*)[sizeof (IN) / sizeof (IN).x])0, \
            char(*)[1]: (glm_vec(1, T)) {}, \
            char(*)[2]: (glm_vec(2, T)) {}, \
            char(*)[3]: (glm_vec(3, T)) {}, \
            char(*)[4]: (glm_vec(4, T)) {} \
        ) \
    ))

#define VEC_WIDTH(vec) (sizeof (vec) / sizeof (vec).x)

#define VEC_TYPE(element_type, width) \
    __typeof__(_Generic( \
        (char(*)[(width)])0, \
        char(*)[1]: (glm_vec(1, element_type)) {}, \
        char(*)[2]: (glm_vec(2, element_type)) {}, \
        char(*)[3]: (glm_vec(3, element_type)) {}, \
        char(*)[4]: (glm_vec(4, element_type)) {} \
    ))

#define CAT_V2(T, LHS, RHS) \
        (((union { \
            struct { \
                GLM_CONVERT_TYPE_X(T, LHS) left;   \
                GLM_CONVERT_TYPE_X(T, RHS) right;  \
            } input; \
            VEC_TYPE( \
                T, \
                (VEC_WIDTH(LHS) + VEC_WIDTH(RHS)) > 4 \
                    ? 4 \
                    : (VEC_WIDTH(LHS) + VEC_WIDTH(RHS)) \
            ) output; \
        }) { .input = { .left = GLM_CONVERT_TVECN(T, LHS), .right = GLM_CONVERT_TVECN(T, RHS) } }) .output)


int main(int argc, char** argv) {

    //vec3 lhs = {3, 4, 9};
    ivec1 lhs = {42};
    ivec2 rhs = {5, 6};

    ivec3 x = CAT_V2(int, lhs, rhs);
    //printf("<%d %d %d %d>\n", x.x, x.y, x.z, x.w);
    printf("<%d %d %d>\n", x.x, x.y, x.z);

    fvec2 y = GLM_CONVERT_TVECN(float, rhs);
    printf("<%f %f>\n", y.x, y.y);

    fvec3 x2 = CAT_V2(float, lhs, rhs);
    printf("<%f %f %f>\n", x2.x, x2.y, x2.z);

    return 0;
}
