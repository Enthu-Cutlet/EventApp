#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#define GL_GLEXT_PROTOTYPES

class VertexBuffer
{
public:
    VertexBuffer(GLvoid *data, GLsizeiptr size, GLenum mode, GLsizei count, GLsizei stride);
    ~VertexBuffer();
    GLuint getBufferID();
    void configureVertexAttributes(GLint vertexPosition);
    void renderVertexBuffer();
private:
    GLuint _bufferID;
    GLenum _mode;
    GLsizei _count;
    GLsizei _stride;
};

#endif // VERTEXBUFFER_H
