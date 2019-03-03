#include "vertexbuffer.h"

VertexBuffer::VertexBuffer(GLvoid *data, GLsizeiptr size, GLenum mode, GLsizei count, GLsizei stride)
{
    _mode= mode;
    _count= count;
    _stride= stride;
    glGenBuffers(1, &_bufferID);
    glBindBuffer(GL_ARRAY_BUFFER,_bufferID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}
GLuint VertexBuffer::getBufferID(){
    return _bufferID;
}
VertexBuffer::~VertexBuffer(){
    glDeleteBuffers(1, &_bufferID);
    _bufferID=0;
}
void VertexBuffer::renderVertexBuffer(){
    glDrawArrays(_mode, 0, _count);
}
void VertexBuffer::configureVertexAttributes(GLint vertexPosition){
    if (vertexPosition !=-1){
        glEnableVertexAttribArray(vertexPosition);
        glVertexAttribPointer(vertexPosition, 3, GL_FLOAT, GL_FALSE, _stride, NULL);
    }
}


