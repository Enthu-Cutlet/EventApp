attribute vec3 aPositionVertex;
void main(){
    gl_Position= gl_ModelProjectionMatrix * vec4(aPositionVertex);
}
